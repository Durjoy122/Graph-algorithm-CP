#include<bits/stdc++.h>
using namespace std;
const int Mx = 100005;

vector <int> g[Mx];
double ans[Mx];

void dfs(int ind , int par) {
    ans[ind] = 1;
    int tot = 0;
    double sum = 0;
    for(int i = 0; i < g[ind].size(); i++) {
        int temp = g[ind][i];
        if(temp == par) {
            continue;
        }
        dfs(temp , ind);
        sum += ans[temp];
        tot++;
    }
    if(tot) {
        ans[ind] += sum / tot;
    }
}

int main() {
   int n;
   scanf("%d" , &n);
   for(int i = 1; i < n; i++) {
       int u , v;
        scanf("%d %d", &u, &v);
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(1 , 0);
   printf("%.9f" , ans[1] - 1);
   return 0;
}
