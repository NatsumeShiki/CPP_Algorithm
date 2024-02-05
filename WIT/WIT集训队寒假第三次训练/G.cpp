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

void solve(){
  map<PII, int> mp;
  cin >> n;
  vector<PII> ve(n);
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    ve[i] = {a, b};
  }
  sort(all(ve));
  for(int i = 0; i < n; ){
    int j = i;
    while(j < n && ve[i].first == ve[j].first){
      j++;
    }
    // cout << j << endl;
    for(int a = i; a < j; a++){
      for(int b = a + 1; b < j; b++){
        mp[{ve[a].second ,ve[b].second}]++;
      }
    }

    i = j;
    // cout << i << endl;
  }

  int res = 0;
  for(auto [a, b] : mp){
    res += b * (b - 1) / 2;
  }
  cout << res << endl;
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
  while(T--){
    solve();
  }

  return 0;
}