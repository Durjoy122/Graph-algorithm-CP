#include<bits/stdc++.h>
using namespace std;
const int Maxn = 20009;

/*[💭] [💡] [🎈] */

vector <int> x[Maxn];
int a[Maxn];
int vmp = 0 , lyk = 0 , ans = 0 , cnt = 0;

void bfs(int vt) {
    queue <int> Q;
    a[vt] = 1;
    vmp++;
    Q.push(vt);
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(int i = 0; i < x[node].size(); i++) {
            int nxt = x[node][i];
            if(a[nxt] == 0) {
                if(a[node] == 1) {
                    a[nxt] = 2;
                    lyk++;
                }
                else {
                    a[nxt] = 1;
                    vmp++;
                }
                Q.push(nxt);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d" , &t);
    int y = 1;
    while(t--) {
      memset(a , 0 , sizeof a);
      int n;
      scanf("%d" , &n);
      for(int i = 0; i < n; i++) {
           int u , v;
           scanf("%d %d" , &u , &v);
           x[u].push_back(v);
           x[v].push_back(u);
      }
      vmp = 0 , lyk = 0 , ans = 0;
      for(int i = 0; i < Maxn; i++) {
          if(!x[i].empty() && a[i] == 0) {
              vmp = 0;
              lyk = 0;
              bfs(i);
              ans += max(vmp , lyk);
          }
      }
      printf("Case %d: %d\n", y++ , ans);
   }
   return 0;
}
