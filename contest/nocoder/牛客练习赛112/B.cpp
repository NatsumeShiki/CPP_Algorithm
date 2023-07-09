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
int a[M];
bool st[M];
int cnt[35];

void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  LL res = 0;
  for(int i = 0, k = 0; i < n || k < n; ){
    if(i < n && !st[i]){
      for(int j = 0; j < 32; j++) 
        if(((a[i] >> j) & 1) == 0)
          cnt[j]++;
      st[i] = true;
    }
    // printf("%d %d\n", i, k);
    // for(int j = 0; j < 4; j++) printf("%d ", cnt[j]);
    // puts("");

    bool flag = true;
    for(int j = 0; j < 32; j++)
      if(cnt[j] == 0){
        flag = false;
        break;
      }
    if(flag){
      int x = n - i;
      if(x == 0) x = 1;
      res += x;
      for(int j = 0; j < 32; j++){
        if(((a[k] >> j) & 1) == 0)
          cnt[j]--;
        // printf("%d ", ((a[k] >> j) & 1) == 0);
      }
      // puts("");
      k++;
    }else{
      if(i < n) i++;
      else {
              for(int j = 0; j < 32; j++){
        if(((a[k] >> j) & 1) == 0)
          cnt[j]--;
        // printf("%d ", ((a[k] >> j) & 1) == 0);
      }
      // puts("");
      k++;
      }
    }
  }
  printf("%lld\n", res);
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