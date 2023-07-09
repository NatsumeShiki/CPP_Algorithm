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
    scanf("%d", &n);
    LL res = 0;
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
      res += abs(a[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; ){
      int j = i + 1;
      if(a[i] == 0) {
        i = j;
        continue;
      }else if(a[i] < 0){
        while(j < n && a[j] <= 0) j++;
      }else if(a[i] > 0){
        while(j < n && a[j] >= 0) j++;
      }
      a[cnt++] = a[i];
      i = j;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < cnt; i++) {
      if(a[i] > 0) cnt1++;
      else cnt2++;;
    }

    int ans;
    if(cnt1 >= cnt2) ans = cnt2;
    else ans = cnt1 + 1;

    printf("%lld %d\n", res, ans);
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