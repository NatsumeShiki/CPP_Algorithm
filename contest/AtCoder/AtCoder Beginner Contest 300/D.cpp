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
vector<int> alls;
int primes[M], cnt;
bool st[M];

void init(int n){
  for(int i = 2; i <= n; i++){
    if(!st[i]) primes[cnt++] = i;
    for(int j = 0; primes[j] * i <= n; j++){
      st[primes[j] * i] = true;
      if(i % primes[j] == 0) break;
    }
  }
  // cout << cnt << endl;
  // for(int i = 0; i < cnt; i++) cout << primes[i] << endl;
}

void solve(){
  cin >> n;
  // cout << n << endl;
  set<int> S;
  // for(int i = 0; i < cnt; i++){
  //   if(primes[i] >= 1000) break;
  //   for(int j = i + 1; j < cnt; j++){
  //     int a = primes[i], b = primes[j];
  //     int t = a * a * b;
  //     for(int k = j + 1; k < cnt; k++){
  //       int c = primes[k];
  //       // cout << t * c * c << endl;
  //       if(t * c * c <= n) S.insert(t * c * c);
  //       else break;
  //     }
  //   }
  // }
  // cout << S.size() << endl;
  int res = 0;
  for(int i = 0; i < cnt; i++){
    for(int j = i + 1; j < cnt; j++){
      int t = primes[i] * primes[i] * primes[j];
      if(t > n) break;
      for(int k = j + 1; k < cnt; k++){
      // cout << t << endl;
        t *= primes[k];
        if(t > n) break;
        t *= primes[k];
        if(t > n) break;
        res++;
        // cout << t << endl;
      }
    }
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

  init(100000);
  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}