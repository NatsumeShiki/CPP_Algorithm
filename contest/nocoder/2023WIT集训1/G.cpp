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

const int N = 50010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int s[N];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];

  while(m--){
    int x;
    cin >> x;
    x++;
    int l = 1, r = n;
    while(l < r){
      int mid = l + r >> 1;
      if(s[mid] < x) l = mid + 1;
      else r = mid;
    }

    cout << l << endl;
  }
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