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

void solve(){
  int T;
  cin >> T;
  while(T--){
    int x1, x2, x3, y1, y2, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    int a = x2 - x1, b = y2 - y1;
    int c = x3 - x1, d = y3 - y1;
    int res = 0;
    if((a >= 0 && c >= 0) || (a <= 0 && c <= 0)) res += min(abs(a), abs(c));
    if((b >= 0 && d >= 0) || (b <= 0 && d <= 0)) res += min(abs(b), abs(d));
    res++;

    printf("%d\n", res);
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