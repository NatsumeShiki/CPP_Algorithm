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

const int N = 2e5 + 10, M = 1e7 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int cnt2[M], cnt5[M];

void get2(int k){
  int cnt = 0;
  int i = k;
  while(k % 2 == 0){
    k /= 2;
    cnt++;
  }
  cnt2[i] = cnt;
}

void get5(int k){
  int cnt = 0;
  int i = k;
  while(k % 5 == 0){
    k /= 5;
    cnt++;
  }
  cnt5[i] = cnt;
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n * 2; i++){
    get2(i);
    get5(i);
    // cout << cnt2[i] << " " << cnt5[i] << " " << i << endl;
    // cnt2[i] += cnt2[i - 1];
    // cnt5[i] += cnt5[i - 1];
    cnt2[i] = cnt2[i - 1] + cnt2[i];
    cnt5[i] = cnt5[i - 1] + cnt5[i];
  }

  int res1 = 0, res2 = 0;
  for(int i = 1; i <= n; i++){
    res1 += cnt2[i * 2] - cnt2[i] - cnt2[i] - cnt2[i + 1] + cnt2[i];
    res2 += cnt5[i * 2] - cnt5[i] - cnt5[i] - cnt5[i + 1] + cnt5[i];
  }
  cout << res1  << " " << res2 << endl;
  cout << min(res1, res2) << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}