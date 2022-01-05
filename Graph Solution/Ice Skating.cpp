#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

vector<int> g[maxn];
int used[maxn];

void dfs(int x) {
    used[x] = 1;
    for (int to : g[x]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        int x , y;
        cin >> x >> y;
        v.push_back(make_pair(x , y));
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i].first == v[j].first || v[i].second == v[j].second) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
            else {
                continue;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            cnt++;
            dfs(i);
        }
        else {
            continue;
        }
    }
    cout << cnt - 1 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
