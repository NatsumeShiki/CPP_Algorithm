#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int cnt[N][35];
int a[35];

bool check(int t, int mid, int k){
  int res = 0;
  for(int i = 0; i < 32; i++){
    a[i] = cnt[mid][i] - cnt[t - 1][i];
    if(a[i] == mid - t + 1) res += 1 << i;
  }
  // cout << mid << " " << res << endl;
  return res >= k;
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 32; j++)
      cnt[i][j] = 0;
  }
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    for(int j = 0; j < 32; j++){
      if(arr[i] >> j & 1) cnt[i][j]++;
      cnt[i][j] += cnt[i - 1][j];
    }
  }

  cin >> q;
  while(q--){
    int t, k;
    cin >> t >> k;
    int l = t, r = n;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(check(t, mid, k)) l = mid;
      else r = mid - 1;
    }
    if(check(t, l, k)) cout << l << " ";
    else cout << "-1 ";
  }
  cout << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}