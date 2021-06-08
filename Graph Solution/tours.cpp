#include<bits/stdc++.h>
using namespace std;
const int Maxn = 3001;

vector <int> V[Maxn];
bool vis[Maxn];
queue <int> Q;
int n , m;

int bfs(int source) {
   Q.push(source);
   int cnt = 0;
   while(Q.empty()) {
       int node = Q.front();
       Q.pop();
       if(vis[node] == false) {
           vis[node] = true;
           cnt++;
           for(int i = 0; i < V[node].size(); i++) {
               Q.push(V[node][i]);
           }
       }
   }
   return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        V[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
      vis[i] = false;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += bfs(i);
    }
    cout << ans <<"\n";
    return 0;
}
