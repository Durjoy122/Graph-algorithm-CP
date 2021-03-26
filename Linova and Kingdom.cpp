#include<bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 10;

/*[💭] [💡] [🎈] */

vector <int> a[Maxn];
vector <int> x(Maxn);

int dfs(int u , int p , int h) {
     int cnt = 0;
     for(auto it : a[u]) {
        if(it == p) {
           continue;
        }
        cnt += dfs(it , u , h + 1);
     }
     x[u] = (cnt) - h;
     return cnt + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    m = n - m;
    for(int i = 0; i < n - 1; i++) {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(0 , 0 , 0);
    sort(x.begin() , x.begin() + n , greater<int>());
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans += x[i];
    }
    cout << ans <<"\n";
    return 0;
}
