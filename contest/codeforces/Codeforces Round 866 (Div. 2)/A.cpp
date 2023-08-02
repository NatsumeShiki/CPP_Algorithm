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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
bool stPre[N], stNe[N];

void solve(){
  memset(stPre, false, sizeof stPre);
  memset(stNe, false, sizeof stNe);
  string s;
  cin >> s;
  if(s == "_"){
    cout << 2 << endl;
    return;
  }
  if(s == "^"){
    cout << 1 << endl;
    return;
  }
  n = s.size();
  for(int i = 0; i < n; i++){
    if(i && s[i - 1] == '^') stPre[i] = true;
    if(i + 1 < n && s[i + 1] == '^') stNe[i] = true;
  }

  int res = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '_' && !stPre[i]) res++;
    if(i == n - 1 && s[i] == '_' && !stNe[i]) res++;
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