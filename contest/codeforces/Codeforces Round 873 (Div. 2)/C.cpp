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
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, t;
int a[N], b[N], s[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int i = 0, j = 0;
    for(; i < n; i++){
      while(j < n && b[j] < a[i]) j++;
      s[i] = j;
    }
    while(i < n) s[i] = j;
    // for(int i = 0; i < n; i++) cout << s[i] << " ";
    // cout << endl;

    LL res = s[0];
    for(int i = 1; i < n; i++){
      res = res * (s[i] - i) % mod;
      // cout << (s[i] - i) << " ";
      }
    cout << res << endl;
    // cout << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}