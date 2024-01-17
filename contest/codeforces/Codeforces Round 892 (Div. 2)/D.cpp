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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
 
void solve() {
  cin >> n;
  vector<PII> ve(n);
  for(int i = 0; i < n; i++){
    int l, r, a, b;
    cin >> l >> r >> a >> b;
    ve[i] = {l, b};
  }
  sort(all(ve));
  vector<PII> res;
  for(auto [l, r] : ve){
    if(res.size() && l <= res.back().y){
      res.back().y = max(res.back().y, r);
    }else{
      res.push_back({l, r});
    }
  }

  // for(auto [l, r] : res) cout << l << " " << r << endl;

  cin >> q;
  while(q--){
    int x;
    cin >> x;
    PII pi = make_pair(x + 1, 0);
    int index = lower_bound(res.begin(), res.end(), pi) - res.begin() - 1;
    if(index >= 0){
      x = max(x, res[index].y);
    }
    cout << x << " \n"[q == 0];
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
