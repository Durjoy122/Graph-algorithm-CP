#include<bits/stdc++.h>
using namespace std;

vector <int> g[5]; /// adj[i] is a vector, which stores
bool vis[5]; /// To check if i'th node is visited or not.

void dfs(int source) {
   vis[source] = true;
   for(int i = 0; i < g[source].size(); i++) {
      int next = g[source][i];
        if(vis[next] == false) {
         dfs(next);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int nodes , edges;
   cin >> nodes >> edges;
   for(int i = 0; i < edges; i++) {
       int u , v;
       cin >> u >> v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(0);
   for(int i = 0; i < nodes; i++) {
      if(vis[i] == true) {
         cout <<"Node"<<" "<< i <<" " <<":"<< "is visited" <<"\n";
      }
      else {
         cout <<"Node"<<" "<< i <<" " <<":"<< " is not visited" <<"\n";
      }
   }
   return 0;
}
