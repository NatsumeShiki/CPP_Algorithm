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
bool st[N];

void solve(){
  string s, t;
  cin >> n >> m >> s >> t;
  for(int i = 0; i < n; i++) st[i] = false;
  memset(cnt1, 0, sizeof cnt1);
  memset(cnt2, 0, sizeof cnt2);

  for(int i = 0; i < n; i++){
    if(i - m - 1 >= 0) st[i - m - 1] = true;
    if(i - m >= 0) st[i - m] = true;
    if(i + m < n) st[i + m] = true;
    if(i + m + 1 < n) st[i + m + 1] = true;
  }

  for(int i = 0; i < n; i++){
    if(!st[i] && s[i] != t[i]){
      cout << "No\n";
      return;
    }
  }

  for(int i = 0; i < n; i++){
    cnt1[s[i] - 'a']++;
    cnt2[t[i] - 'a']++;
  }

  for(int i = 0; i < 30; i++){
    if(cnt1[i] != cnt2[i]){
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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