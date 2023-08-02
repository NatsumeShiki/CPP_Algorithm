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
int n, m, k, t, q;
int arr[N];
vector<int> alls;
int height[N];
int s[N];
int maxv[N];

void solve(){
  cin >> n >> q >> k;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  height[0] = -1;
  for(int i = 1; i <= n; i++){
    cin >> height[i];
    maxv[i] = maxv[i - 1];
    if(height[i] == height[i - 1]){
      s[i] = s[i - 1] + 1;
    }else{
      s[i] = 1;
      if(s[i - 1] >= k) maxv[i] = i - 1;
    }
    // cout << s[i] << " " << maxv[i] << endl;
  }

  while(q--){
    cin >> m;
    int res = 0;
    if(s[m] >= k) {
      res = arr[m] - arr[m - k];
      // cout << 2 << endl;
    }else if(maxv[m] < k) {
      res = arr[m];
      // cout << 1 << endl;
    }else {
      res = arr[m] - arr[maxv[m] - k];
      // cout << 3 << endl;
    }
    cout << res << endl;
  }
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