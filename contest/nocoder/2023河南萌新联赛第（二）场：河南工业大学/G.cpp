#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;

bool check(int mid){
  int res = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] >= mid) res += (arr[i] - mid) * 2;
  }
  if(res >= m) return true;
  return false;
}

void solve(){
  cin >> n >> m;
  int l = 1, r = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    r = max(r, arr[i]);
  }
  while(l < r){
    int mid = l + r + 1 >> 1;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  // cout << l << endl;
  if(!check(l)) puts("-1");
  else cout << l << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}