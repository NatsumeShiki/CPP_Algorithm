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
vector<vector<int>> alls(100);

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> m;
    while(m--){
      int x;
      cin >> x;
      // cout << x << endl;
      alls[i].push_back(x);
    }
  }

  int x;
  cin >> x;
  // cout << x << endl;
  vector<PII> res;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < alls[i].size(); j++){
      if(alls[i][j] == x){
        // cout << i + 1 << endl;
        res.push_back({alls[i].size(), i + 1});
        break;
      }
    }
  }
  sort(res.begin(), res.end());
  // cout << res.size() << endl;
  if(res.empty()) cout << 0 << endl;
  else{
    int t = res[0].first;
    int ans = 0;
    for(auto [a, b] : res) 
      if(a == t) 
        ans++;
    cout << ans << endl;
    for(auto [a, b] : res) 
      if(a == t) 
        cout << b << " ";
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}