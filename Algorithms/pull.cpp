#include<bits/stdc++.h>
using namespace std;
const int Maxn = 2001;

/*[💭] [💡] [🎈] */

vector <int> a[Maxn];
int x[Maxn];
int p[Maxn] , c[Maxn] , h[Maxn];

int dfs(int v) {
    for(int it : a[v]) {
        h[it] = h[v] + 1;
        dfs(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int r = -1, cc = 1;
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        p[i]--;
        if(p[i] == -1) {
            r = i;
        }
        else {
           a[p[i]].push_back(i);
        }
    }
    dfs(r);
    for(int i = 0; i < n; i++) {
        int cv = -1;
        for(int j = 0; j < n; j++) {
            if(c[j] == 0 && (cv == -1 || h[j] < h[cv])) {
                cv = j;
            }
        }
        if(cv == -1) {
            cout <<"NO\n";
            return 0;
        }
        x[cv] = cc++;
        while(cv != -1) {
            c[cv]--;
            cv = p[cv];
        }
    }
    cout <<"YES\n";
    for(int i = 0; i < n; i++) {
        cout << x[i] <<" ";
    }
    cout <<"\n";
    return 0;
}
