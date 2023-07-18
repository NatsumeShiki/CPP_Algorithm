#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
map<int, int> mp;
PII point[N];
int x[N], y[N];

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++){
    cin >> point[i].x >> point[i].y;
  }

  int A, B;
  cin >> A;
  for(int i = 0; i < A; i++) cin >> x[i];
  x[A++] = n;
  cin >> B;
  for(int i = 0; i < B; i++) cin >> y[i];
  y[B++] = m;
  for(int i = 0; i < k; i++){
    int a = lower_bound(x, x + A, point[i].x) - x;
    int b = lower_bound(y, y + B, point[i].y) - y;
    mp[a * 1e9 + b]++;
  }

  int minv = 1e9, maxv = -1;
  for(auto item : mp){
    minv = min(minv, item.second);
    maxv = max(maxv, item.second);
  }
  if(mp.size() < A * B) minv = 0;
  cout << minv << " " << maxv << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}