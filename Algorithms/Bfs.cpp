#include<bits/stdc++.h>
using namespace std;
const int Mx = 111;

vector <int> g[Mx]; /// adj[i] is a vector, which stores
bool vis[Mx]; /// To check if i'th node is visited or not.
int dis[Mx]; /// To store the distance from starting Node

void bfs(int source) {
   queue <int> Q;
   vis[source] = true;
   dis[source] = 0;
   Q.push(source);
   while(!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for(int i = 0; i < g[node].size(); i++) {
         int next = g[node][i];
         if(vis[next] == false) {
            vis[next] = true; // Visit
            dis[next] = dis[node] + 1; // Update
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
