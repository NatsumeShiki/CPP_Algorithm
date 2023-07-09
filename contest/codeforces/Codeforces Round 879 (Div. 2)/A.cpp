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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(x == 1) cnt1++;
      else cnt2++;
    }
    // printf("%d %d\n", cnt1, cnt2);
    int res = 0;
    if(cnt1 < cnt2){
      res = cnt2 - cnt1;
      res = (res + 1) / 2;
      cnt2 -= res;
      if(cnt2 % 2 == 1) res++;
    }else if(cnt2 % 2 == 1) res = 1;
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