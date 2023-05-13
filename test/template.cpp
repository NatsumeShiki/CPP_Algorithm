#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

#define x first
#define y second

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1010;
LL a[N][N], s[N][N];
int n, m, k, T;
PII trans[N];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= 1000; i++) s[i][0] = s[0][i] = -1e15;
    s[1][0] = s[0][1] = 0;
    for(int i = 1; i <= n; i++){    
        for(int j = 1; j <= m; j++){
            scanf("%lld", &a[i][j]);
            s[i][j] = max(s[i - 1][j], s[i][j - 1]) + a[i][j];
//             cout << s[i][j] << " ";
        }
//         cout << endl;
        }
    
    
    scanf("%d", &T);
    while(T--){
        LL res = -1e15;
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            trans[i] = {x, y};
        }
        if(res < 0) res = 0;
        printf("%lld\n", res + s[n][m]);
    }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}