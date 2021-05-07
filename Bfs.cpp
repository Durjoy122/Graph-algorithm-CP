#include<bits/stdc++.h>
using namespace std;
const int Mx = 111;

vector <int> g[Mx];
bool vis[Mx];
int dis[Mx];

void bfs(int source) {
   queue <int> Q;
   vis[source] = 1;
   dis[source] = 0;
   Q.push(source);
   while(!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for(int i = 0; i < g[node].size(); i++) {
         int next = g[node][i];
         if(vis[next] == 0) {
            vis[next] = 1; // Visit
            dis[next] = dis[next] + 1; // Update
            Q.push(next);//push Queue for Delete
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int nodes , edges;
   cin >> nodes >> edges;
   for(int i = 1; i <= edges; i++) {
       int u , v;
       cin >> u >> v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   int source;
   cin >> source;
   bfs(source);
   for(int i = 1; i <= nodes; i++) {
      cout <<"Distance"<<" "<< i <<" "<<"is :"<< dis[i] <<"\n";
   }
   return 0;
}
