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
PII lmin[M], rmin[M];
int res[M];
bool st[M];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    res[i] = 0;
    st[i] = false;
  }
  // lmin[0] = {0, 0}, rmin[n + 1] = {0, n + 1};
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    st[arr[i]] = true;
    // lmin[i] = {arr[i], i};
    // if(lmin[i - 1].first >= arr[i]) lmin[i] = lmin[i - 1];
  }
  // for(int i = n; i >= 1; i--){
  //   rmin[i] = {arr[i], i};
  //   if(rmin[i + 1].first >= arr[i]) rmin[i] = rmin[i + 1];
  // }

  int l = 1, r = n;
  for(int i = 1; i <= m; i++){
    while(l <= n && arr[l] < i) l++;
    while(r >= 1 && arr[r] < i) r--;
    if(!st[i]) continue;
    res[i] = (r - l + 1) * 2;
    // cout << l << " " << r << endl;
  }


  for(int i = 1; i <= m; i++){
    // if(!st[i]) res[i] = 0;
    cout << res[i] << " \n"[i == m];
  }
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