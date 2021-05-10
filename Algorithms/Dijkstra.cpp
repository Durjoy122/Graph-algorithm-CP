#include<bits/stdc++.h>
using namespace std;
const int Maxn = 105;

struct node{
   int val;
   int cost;
};

vector <node> G[Maxn];
bool vis[Maxn];
int dist[Maxn];

class cmp{
public:
    bool operator() (node &A, node &B) {
        if(A.cost > B.cost) {
            return true;
        }
        return false;
    }
};

void dijkstra(int source) {
   priority_queue <node , vector <node>, cmp> PQ;
   PQ.push({source , 0});
   while(!PQ.empty()) {
      node current = PQ.top();
      PQ.pop();
      int val = current.val;
      int cost = current.cost;
      if(vis[val] == true) {
         continue;
      }
      dist[val] = cost;
      vis[val] = true;
      for(int i = 0; i < G[val].size(); i++) {
         int nxt = G[val][i].val;
         int nxtcost = G[val][i].cost;
         if(vis[nxt] == false) {
            PQ.push({nxt , cost + nxtcost});
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
       int u , v, w;
       cin >> u >> v >> w;
       G[u].push_back({v , w});
   }
   cout <<"Enter Source\n";
   int source;
   cin >> source;
   dijkstra(source);
   for(int i = 1; i <= nodes; i++) {
      cout <<"Node:" <<" "<< i <<" "<< "Distance"<<" "<<": "<< dist[i] <<"\n";
   }
   return 0;
}
