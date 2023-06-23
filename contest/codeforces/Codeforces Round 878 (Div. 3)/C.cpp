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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    LL res = 0;
    for(int i = 0, cnt = 1, j = 0; i < n; i++){
      if(a[i] > k){
        j = i + 1;
        cnt = 1;
        continue;
      }

      if(i - j + 1 >= m){
        res += cnt;
        cnt++;
      }
    }
    cout << res << endl;
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