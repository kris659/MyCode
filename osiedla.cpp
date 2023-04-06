// https://szkopul.edu.pl/problemset/problem/nldsb4EW1YuZykBlf4lcZL1Y/site/?key=statement

#include <iostream>
#include <vector>

using namespace std;

vector<bool> used, used_v;
vector<vector<pair<int,int>>> t;
vector<int> time_in;
vector<bool> answer;

int odp = 0;

int dfs(int index, int tim){
    used[index] = true;
    time_in[index] = tim;
    int minimum = tim;
    for(int i = 0; i < t[index].size(); i++){
        int in = t[index][i].first;
        
        if(!used[in]){
            used_v[t[index][i].second / 2] = true;
            answer[t[index][i].second / 2] = t[index][i].second % 2;
            int d = dfs(in, tim + 1);
            //if(d > tim) odp++;
            minimum = min(d, minimum);
        }
        else
            if(!used_v[t[index][i].second / 2]){
                minimum = min(minimum, time_in[in]);
                //cout << index << " " << t[index][i].first << " " << t[index][i].second << "\n";
                answer[t[index][i].second / 2] = !(t[index][i].second % 2);
            }
                
        
    }
    if(tim <= minimum) odp++;
    //cout << tim << " " << minimum << "\n";
    return minimum;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,m;
    
    cin >> n >> m;
    
    t.assign(n + 1, vector<pair<int,int>>());
    time_in.assign(n + 1, -1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        
        t[a].push_back({b, 2 * i});
        t[b].push_back({a, 2 * i + 1});
    }
    
    used.assign(n + 1,false);
    used_v.assign(m + 1,false);
    answer.assign(m, false);

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            //odp++;
            dfs(i, 1);
        }
    }
    cout << odp << "\n";
    for(int i = 0; i < m; i++){
        if(answer[i]) cout << '<';
        else cout << '>';
    }
    return 0;
}

