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
int cnt1[30], cnt2[30];

void solve(){
  memset(cnt1, 0, sizeof cnt1);
  memset(cnt2, 0, sizeof cnt2);
  cin >> n >> m >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] >= 'a' && s[i] <= 'z'){
      cnt1[s[i] - 'a']++;
    }
    else cnt2[s[i] - 'A']++;
  }

  int res = 0;
  for(int i = 0; i < 30; i++){
    int a = cnt1[i], b = cnt2[i];
    res += min(a, b);
    a = abs(a - b) / 2;
    if(m >= a){
      res += a;
      m -= a;
    }else{
      res += m;
      m = 0;
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

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}