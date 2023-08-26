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

void solve(){
  string s;
  cin >> n >> s;
  cin >> m;
  int cnt = -1, t = -1;
  for(int i = 0; i < m; i++){
    int a, b;
    char c;
    cin >> a >> b >> c;
    if(a == 1) s[b - 1] = c, arr[b - 1] = i;
    else if(a == 2) cnt = i, t = 0;
    else cnt = i, t = 1;
  }
  if(cnt == -1) cout << s << endl;
  else{
    for(int i = 0; i < n; i++){
      if(cnt > arr[i]){
        if(t){
          if(s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
          else cout << (char)(s[i] - 32);
        }else{
          if(s[i] >= 'a' && s[i] <= 'z') cout << s[i];
          else cout << (char)(s[i] + 32);
        }
      }else{
        cout << s[i];
      }
    }
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
  while(T--){
    solve();
  }

  return 0;
}