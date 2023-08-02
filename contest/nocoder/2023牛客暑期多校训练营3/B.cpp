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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int cnt;
bool st[15];
int res[15];
map<int, int> mp;

void dfs(int k){
  if(k == n * 2) {
    int cnt = 1;
    // cout << res[0] << " ";
    for(int i = 1; i < n * 2; i++){
      // cout << res[i] << " ";
      if(res[i - 1] <= n && res[i] > res[i - 1] || res[i - 1] > n && res[i] < res[i - 1]){
        cnt++;
      }else {
        cnt++;
        break;
      }
    }
    mp[cnt]++;
    // cout << cnt << " ";
    // alls.push_back(cnt);
    return;
  }
  for(int i = 1; i <= n * 2; i++){
    if(!st[i]){
      res[k] = i;
      st[i] = true;
      dfs(k + 1);
      st[i] = false;
    }
  }
}

void solve(){
  cin >> n;
  cnt = 0;  
  memset(st, 0, sizeof st);
  for(int i = 1; i <= n * 2; i++){
    if(!st[i]){
      st[i] = true;
      res[0] = i;
      dfs(1);
      st[i] = false;
    }
  } 
      int s = 0;
      for(auto [a, b] : mp) cout << a << " " << b << endl, s += a * b ;
      cout << s << endl;
      mp.clear();
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