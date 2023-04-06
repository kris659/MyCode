// https://szkopul.edu.pl/problemset/problem/dABzva_j1-BvzKMsyxkuRoue/site/?key=statement

#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<bool>> odwiedzone, pionowe, poziome, odp_poz, odp_pion;
vector<pair<int,int>> odw;
int odp_1 = 0, odp_2 = 0;

void DFS(int x, int y, int ox, int oy){
    odw.push_back({x,y});
    odwiedzone[y][x] = true;
    
    
    if(x < n - 1 && !pionowe[y][x]){
        if(!odwiedzone[y][x + 1]) DFS(x + 1, y, x, y);
        else    if(x + 1 != ox){
            pionowe[y][x] = true;
            odp_pion[y][x] = true;
            odp_2++;
        }
    }
    if(x > 0 && !pionowe[y][x - 1]){
        if(!odwiedzone[y][x - 1]) DFS(x - 1, y, x, y);
        else    if(x - 1 != ox){
            pionowe[y][x - 1] = true;
            odp_pion[y][x - 1] = true;
            odp_2++;
        }
    }
    if(y < m - 1 && !poziome[y][x]){
        if(!odwiedzone[y + 1][x]) DFS(x, y + 1, x, y);
        else    if(y + 1 != oy){
            poziome[y][x] = true;
            odp_poz[y][x] = true;
            odp_2++;
        }
    }
    if(y > 0 && !poziome[y - 1][x]){
        if(!odwiedzone[y - 1][x]) DFS(x, y - 1, x, y);
        else    if(y - 1 != oy){
            poziome[y - 1][x] = true;
            odp_poz[y - 1][x] = true;
            odp_2++;
        }
    }
}
void solve(){
    cin >> m >> n;
    
    odwiedzone.assign(m, vector<bool>(n, false));
    pionowe.assign(m, vector<bool>(n - 1, false));
    poziome.assign(m - 1, vector<bool>(n, false));
    odp_pion.assign(m, vector<bool>(n - 1, false));
    odp_poz.assign(m - 1, vector<bool>(n, false));
    
    for(int i = 0; i < m; i++){
        string a;
        cin >> a;
        for(int j = 0; j < n - 1; j++){
            if(a[j] == 'C') odp_1++;
            if(a[j] == 'C') odp_2++;
            pionowe[i][j] = (a[j] == 'C');
            odp_pion[i][j] = (a[j] == 'C');
        }
    }
    for(int i = 0; i < m - 1; i++){
        string a;
        cin >> a;
        for(int j = 0; j < n; j++){
            if(a[j] == 'C') odp_1++;
            if(a[j] == 'C') odp_2++;
            poziome[i][j] = (a[j] == 'C');
            odp_poz[i][j] = (a[j] == 'C');
        }
    }
    int x,y;
    x = n / 2; y = 0;
    
    DFS(x,y, -1, -1);

    for(int i = 0; i < odw.size(); i++){
        int x = odw[i].first, y = odw[i].second;
        
        if(x < n - 1 && !odwiedzone[y][x + 1]){
            DFS(x + 1, y, -1, -1);
            odp_pion[y][x] = false;
            odp_1--;
            odp_2--;
        }
        if(x > 0 && !odwiedzone[y][x - 1]){
            DFS(x - 1, y, -1, -1);
            odp_pion[y][x - 1] = false;
            odp_1--;
            odp_2--;
        }
        if(y < m - 1 && !odwiedzone[y + 1][x]){
            DFS(x, y + 1, -1, -1);
            odp_poz[y][x] = false;
            odp_1--;
            odp_2--;
        }
        if(y > 0 && !odwiedzone[y - 1][x]){
            DFS(x, y - 1, -1, -1);
            odp_poz[y - 1][x] = false;
            odp_1--;
            odp_2--;
        }
    }
    cout << odp_2 << " " << odp_1 << "\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n - 1; j++){
            if(odp_pion[i][j]) cout << 'Z';
            else cout << '.';
        }
        cout << "\n";
    }
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n; j++){
            if(odp_poz[i][j]) cout << 'Z';
            else cout << '.';
        }
        cout << "\n";
    }
}

int main()
{
    solve();
    return 0;
}
