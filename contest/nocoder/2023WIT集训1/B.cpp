#include<bits/stdc++.h>
using namespace std;

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

const int N = 1e8 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
// map<int, int> mp;
int s[N];

void solve(){
  scanf("%d%d", &n, &m);
  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    s[l]++, s[r + 1]--;
  }

  int res = n + 1;
  if(s[0] != 0) res--;
  for(int i = 1; i <= n; i++){
    s[i] += s[i - 1];
    if(s[i] > 0) res--;
  }

  cout << res << endl;

  // n++;
  // int last = 0, lastL = n + 1;
  // for(auto item : mp){
  //   last += item.y;
  //   if(last > 0 && lastL == n + 1) lastL = item.x;
  //   else if(last == 0){
  //     n -= (item.x - lastL);
  //     lastL = n + 1;
  //   }
  // }

  // cout << n << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}