#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];

void solve(){
  string s;
  cin >> s;
  int res = 0x3f3f3f3f3f3f3f3f;
  for(char c = 'a'; c <= 'z'; c++){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
      int a = c - 'a', b = s[i] - 'a';
      if(a > b) swap(a, b);
      // cout << abs(b - a) << " " << abs(a + 26 - b) << endl;
      // ans += min(min(abs(s[i] - c), abs('z' - s[i] + c - 'a' + 1)), abs(s[i] - 'a' + 1));
      ans += min(abs(b - a), abs(a + 26 - b));
    }
    res = min(ans, res);
    // return;
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}