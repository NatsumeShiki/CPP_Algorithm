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

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N][N];
vector<int> alls;

void solve(){
  cin >> n >> m;
  int cnt = 1;
  if(n % 2 == 0){
    for(int i = 1; i <= m; i++)
      for(int j = 1; j <= n; j++)
        arr[j][i] = cnt++;
  }else if(m % 2 == 0){
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        arr[i][j] = cnt++;
  }else if(n <= m){
    for(int i = 1; i <= m; i += 2)
      for(int j = 1; j <= n; j++)
        arr[j][i] = cnt++;
    for(int i = 2; i <= m; i += 2)
      for(int j = 1; j <= n; j++)
        arr[j][i] = cnt++;
  }else{
    for(int i = 1; i <= n; i += 2)
      for(int j = 1; j <= m; j++)
        arr[i][j] = cnt++;
    for(int i = 2; i <= n; i += 2)
      for(int j = 1; j <= m; j++)
        arr[i][j] = cnt++;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}