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

void solve(){
  map<int, int> mp;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    mp[x]++;
  }

  int q;
  cin >> q;
  while(q--){
    int x, y;
    cin >> x >> y;
    if(x * x - 4 * y < 0){
      cout << 0 << " ";
      continue;
    }

    int t = sqrt(x * x - 4 * y);
    int a = (x + t) / 2, b = (x - t) / 2;
    // cout << a << " " << b << endl;
    if(a + b != x || a * b != y) cout << "0 ";
    else if(a == b) cout << mp[a] * (mp[a] - 1) / 2 << " ";
    else cout << mp[a] * mp[b] << " ";
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