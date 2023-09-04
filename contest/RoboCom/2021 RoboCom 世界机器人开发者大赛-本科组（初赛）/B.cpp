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
  int a, b, c, d, e;
  bool operator < (const edge &t) const{
    if(a != t.a) return a < t.a;
    if(b != t.b) return b < t.b;
    if(c != t.c) return c < t.c;
    return d < t.d;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
edge e[N];

int gcd(int a, int b){
  return b ? gcd(b, a % b) : a;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    int t = gcd(a, b);
    e[i] = {a / t, b / t, a, b, c};
  }

  sort(e, e + n);
  int res = 0;
  int cnt = 0;
  for(int i = 0; i < n; ){
    int j = i;
    bool flag = false;
    while(true){
      auto [a1, b1, c1, d1, e1] = e[i];
      auto [a2, b2, c2, d2, e2] = e[j];
      if(j == i) {
        res += e1;
        cnt++;
        if(e1 == 1) flag = true;
        j++;
        continue;
      }
      if(a1 != a2 || b1 != b2) break;
      if(e2 != 1){
        cnt++;
        res += e2;
        flag = false;
      }else{
        res +=e2;
        if(!flag) {
          flag = true;
          cnt++;
        }
      }
      j++;
      // cout << flag << " " << c1 << " " << c2 << endl;
    }
    i = j;
  }
  cout << res << " " << cnt << endl;
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