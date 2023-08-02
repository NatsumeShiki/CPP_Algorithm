#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 2010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
string g[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> g[i];
  string s1 = g[0];
  string s2 = "";
  for(int i = 0; i < n; i++){
    if(g[0][i] == '0') s2 += '1';
    else s2 += '0';
  }
  
  int a = 0, b = 0;
  int c = 0, d = 0;
  for(int i = 0; i < n; i++) if(s1[i] == '1') c++;
  for(int i = 0; i < n; i++) if(s2[i] == '1') d++;
  for(int i = 0; i < n; i++){
    if(g[i] == s1) a++;
    else if(g[i] == s2) b++;
    else {
      puts("-1");
      return;
    }
  }

  if(a == n) cout << min(c, n - c) << endl;
  else if(b == n) cout << min(d, n - d) << endl;
  else cout << min(b + min(c, n - c), a + min(d, n - d)) << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}