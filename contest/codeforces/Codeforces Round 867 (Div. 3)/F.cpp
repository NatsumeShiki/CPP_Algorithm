#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
typedef long long LL;
const int N = 2e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int dist[N];
int n, m, c;
LL res;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int fa, int deep){
  LL d1 = 0, d2 = 0;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == fa) continue;
    int d = 1 + dfs(j, u, deep + 1);
    if(d >= d1) d2 = d1, d1 = d;
    else if(d > d2) d2 = d; 
  }

  res = max(res, d1 * m);
  res = max(res, (d1 + d2) * m - (deep + d2) * c);
  // cout << res << "  123" << endl;
  return d1;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m >> c;
    // cout << n << " " << m << " " << c << endl;
    memset(h, -1, sizeof h);
    idx = 0;
    for(int i = 0; i < n - 1; i++){
      int a, b;
      cin >> a >> b;
      add(a, b), add(b, a);
      // cout << a << " " << b << endl;
    }
    res = 0;
    dfs(1, -1, 0);
    cout << res << endl;
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


 