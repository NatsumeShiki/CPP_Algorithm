#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, t;
int arr[N];

void solve(){
  string s;
  cin >> s;
  LL n = s.size();
  LL res = 1;
  for(int i = 0; i < n / 2; i++){
  
    if(s[i] == '?' && s[n - i - 1] == '?') {
      res = res * 26 % mod;
    }
    else if(s[i] == '?' || s[n - i - 1] == '?') {
      continue;
    }else if(s[i] != s[n - i - 1]) {
      puts("0");
      return;
    }
  }
  if(n % 2 == 1 && s[n / 2] == '?') {
    res = res * 26 % mod;
  }
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}