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
  int a, b;
  bool operator < (const edge &t) const{
    if(a != t.a) {
      if(a == 0) return true;
      else if(t.a == 0) return false;
      else return a > t.a;
    }
    return b < t.b;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 3e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
edge e[N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    a %= m;
    e[i] = {a, i}; 
  }
  sort(e, e + n);

  for(int i = 0; i < n; i++) cout << e[i].b + 1 << " ";
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