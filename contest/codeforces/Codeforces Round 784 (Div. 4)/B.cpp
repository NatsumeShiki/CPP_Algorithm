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
    cin >> n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      a[x]++;
    }

      bool flag = false;
      for(int i = 1; i <= n; i++)
        if(a[i] >= 3){
          cout << i << " ";
          flag = true;
          break;
        }

      if(!flag) puts("-1");
      else puts("");
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