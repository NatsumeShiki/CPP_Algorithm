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
int arr[4][4];
string s, str;
int pri[10];
bool st[10];
int res = 0;

bool check(){
  static int array[4][4] = {0};
  memset(array, 0, sizeof array);
  // for(int i = 0; i < 9; i++) cout << pri[i] << endl;
  for(int i = 0; i < 9; i++){
    int t = pri[i];
    int x = t / 3, y = t % 3;
    array[x][y] = arr[x][y];
    int cnt = 0;
    bool flag = false;
    for(int j = 0; j < 3; j++){
      if(array[x][j] == array[x][y]) cnt++;
      if(array[x][j] == 0) flag = true;
    }
    if(cnt > 1 && flag) return false;

    cnt = 0;
    flag = false;
    for(int j = 0; j < 3; j++){
      if(array[j][y] == array[x][y]) cnt++;
      if(array[j][y] == 0) flag = true;
    }
    if(cnt > 1 && flag) return false;

    if(x == y){
      cnt = 0;
      flag = false;
      for(int j = 0; j < 3; j++){
        if(array[j][j] == array[x][y]) cnt++;
        if(array[j][j] == 0) flag = true;
      }
      if(cnt > 1 && flag) return false;
    }

    if(x + y == 2){
      cnt = 0;
      flag = false;
      for(int j = 0; j < 3; j++){
        if(array[j][2 - j] == array[x][y]) cnt++;
        if(array[j][2 - j] == 0) flag = true;
      }
      if(cnt > 1 && flag) return false;
    }
  }
  return true;
}

void dfs(int u){

  if(u == 9){
    if(check()) res++;
    // exit(0);
    return;
  }

  for(int i = 0; i < 9; i++){
    if(st[i]) continue;
    st[i] = true;
    pri[u] = i;
    dfs(u + 1);
    st[i] = false;
  }

}

void solve(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      cin >> arr[i][j];

  dfs(0);

  int sum = 1;
  for(int i = 1; i <= 9; i++) sum *= i;

  // cout << res << " " << sum << endl;
  double ans = (double)res / sum;
  // cout << ans << endl;
  printf("%.10f\n", ans);
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