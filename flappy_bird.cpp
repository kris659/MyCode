// https://szkopul.edu.pl/problemset/problem/eLy9p2a1VStZ4y9y-LdeB-8f/site/?key=statement

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, X;
    cin >> n >> X;
    vector<int> indeksy(n + 1, 0), dp_ile(n + 1, 0);
    vector<pair<int,int>> przeszkody(n + 1, {1e9,1e9}), dp_wysokosci(n + 1, {1e9,1e9});
    for(int i = 1; i <= n; i++){
        cin >> indeksy[i];
        int a,b;
        cin >> a >> b;
        przeszkody[i] = {a + 1e9,b + 1e9};
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int odleglosc = indeksy[i] - indeksy[i - 1];
        int maks, mini;
        
        mini = max(przeszkody[i].first + 1, dp_wysokosci[i - 1].first - odleglosc);
        maks = min(przeszkody[i].second - 1, dp_wysokosci[i - 1].second + odleglosc);
        if(mini % 2 != indeksy[i] % 2) mini++;
        if(maks % 2 != indeksy[i] % 2) maks--;
        if(maks < mini){
            cout << "NIE";
            return 0;
        }
        int ile = (odleglosc + (mini - dp_wysokosci[i - 1].first)) / 2;
        ans += ile;
        dp_wysokosci[i] = {mini, maks};
    }
    cout << ans;
    return 0;
}


