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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
char s[N];
int res[N][2];

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  cin >> s + 1;

  if(n == 1){
    puts("0");
    return;
  }

  for(int i = 2; i <= n; i++){
    res[i][0] = max(res[i - 1][0], res[i - 1][1]);
    if(s[i] != s[i - 1]) res[i][1] = res[i - 1][0] + arr[i] + arr[i - 1];
    // cout << res[i][0] << " " << res[i][1] << endl;
  }

  cout << max(res[n][0], res[n][1]) << endl;
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