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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char arr[N][N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  char c = arr[0][n - 1];
  for(int i = n - 1; i > 0; i--) arr[0][i] = arr[0][i - 1];
  for(int i = 1; i < n; i++) arr[i - 1][0] = arr[i][0];
  for(int i = 1; i < n; i++) arr[n - 1][i - 1] = arr[n - 1][i];
  for(int i = n - 1; i > 1; i--) arr[i][n - 1] = arr[i - 1][n - 1];
  arr[1][n - 1] = c;
  for(int i = 0; i < n; i++) cout << arr[i] << endl;
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