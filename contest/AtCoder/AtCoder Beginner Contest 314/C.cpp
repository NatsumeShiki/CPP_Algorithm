#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<vector<int>> alls(N);

void solve(){
  cin >> n >> m;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    alls[arr[i]].push_back(i);
    // cout << arr[i] << endl;
  }

  for(int i = 1; i <= m; i++){
    if(alls[i].empty()) continue;
    int t = alls[i].size();
    char c = s[alls[i][t - 1]];
    // cout << t << " " << alls[i][0] << " " << c << endl;
    for(int j = t - 1; j > 0; j--){
      int a = alls[i][j], b = alls[i][j - 1];
      s[alls[i][j]] = s[b];
    }
    s[alls[i][0]] = c;

  }
  cout << s << endl;
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}