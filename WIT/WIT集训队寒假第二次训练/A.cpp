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
int n, m, k, t, q, b, s;
int arr[M];
// string s, str;

void solve(){
  cin >> n >> k >> b >> s;

  int cnt = 0, ans = s;
  for(int i = 0; i < n - 1; i++) {
    if(ans >= k){
      arr[i] = k;
      ans -= k;
      cnt++;
    }else{
      arr[i] = ans;
      ans = 0;
      break;
    }
  }

  arr[n - 1] = (b - cnt) * k;
  int res = (n - 1) * k + arr[n - 1];

  

  if(res > s){
    cout << -1 << endl;
    return;
  }
  res = s - res;
  for(int i = 0; i < n; i++){
    if(res >= k) {
      arr[i] += k - 1;
      res -= k - 1;
    }else{
      arr[i] += res;
      res = 0;
      break;
    }
  }
  if(res) {
    cout << -1 << endl;
  }else{
    for(int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
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