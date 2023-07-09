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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a = (1 << 20) - 1, b, c;
int op[M], cnt[M];

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> op[i] >> cnt[i];
  for(int i = 0; i < 20; i++){
    int x = 0, y = 1;
    for(int j = 1; j <= n; j++){
      int tmp = cnt[j] >> i & 1;
      if(op[j] == 1) x &= tmp, y &= tmp;
      else if(op[j] == 2) x |= tmp, y |= tmp;
      else if(op[j] == 3) x ^= tmp, y ^= tmp;
    }

    if(!x && !y) a -= (1 << i);
    if(x == 1 && y == 1) b += (1 << i);
    if(x == 1 && !y) c += (1 << i);
  }

  cout << 3 << endl;
  cout << 1 << " " << a << endl;
  cout << 2 << " " << b << endl;
  cout << 3 << " " << c << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}