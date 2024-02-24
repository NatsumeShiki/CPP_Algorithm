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

const int N = 2e5 + 10, M = 1e7 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int primes[M], cnt;
bool st[M];
int p[M];

void init(int n){
  st[1] = true;
  p[1] = 1;
  for(int i = 2; i <= n; i++){
    if(!st[i]) primes[cnt++] = i, p[i] = i;
    for(int j = 0; primes[j] * i <= n; j++){
      st[primes[j] * i] = true;
      p[primes[j] * i] = primes[j];
      if(i % primes[j] == 0) break;
    }
  }
}

void solve(){
  int l, r;
  cin >> l >> r;
  if(r <= 3){
    cout << -1 << endl;
    return;
  }

  if(l % 2 == 0 && l > 3){
    cout << "2 " << l - 2 << endl;
    return;
  }

  if(r % 2 == 0 && r > 3){
    cout << "2 " << r - 2 << endl;
    return;
  }

  for(int i = l; i <= r; i++){
    int a = p[i], b = i - p[i];
    // cout << i << endl;
    int t = a + b;
    if(b != 0){
      cout << a << " " << b << endl;
      return;
    }
    
  }

  cout << -1 << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init(1e7);
  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}