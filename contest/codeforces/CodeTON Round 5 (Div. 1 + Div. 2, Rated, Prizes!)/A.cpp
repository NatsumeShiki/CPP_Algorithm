#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
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
  cin >> n >> m;
  int cnt1 = 0, cnt2 = 0;
  while(n--){
    int x;
    cin >> x;
    cnt1 += x;
  }
  while(m--){
    int x;
    cin >> x;
    cnt2 += x;
  }

  if(cnt1 > cnt2) puts("Tsondu");
  else if(cnt1 < cnt2) puts("Tenzing");
  else puts("Draw");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}