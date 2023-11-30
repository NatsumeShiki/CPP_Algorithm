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
int a[M], b[M];
int cnt1[35], cnt2[35];

void solve(){
  cin >> n >> m;
  memset(cnt1, 0, sizeof cnt1);
  memset(cnt2, 0, sizeof cnt2);

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    for(int j = 0; j < 32; j++){
      if(x >> j & 1)
        cnt1[j]++, cnt2[j]++;
    }
  }

  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    int t1 = 0, t2 = 0;
    for(int j = 0; j < 32; j++){
      if(x >> j & 1){
        if(cnt1[j] % 2 == 0 && n % 2 == 1){
          t1 += 1 << j;
        }else if(cnt1[j] % 2 == 1 && n % 2 == 0){
          t1 -= 1 << j;
        }
      }

      if(x >> j & 1){
        if(cnt2[j] % 2 == 0 && n % 2 == 1){
          t2 += 1 << j;
        }else if(cnt2[j] % 2 == 1 && n % 2 == 0){
          t2 -= 1 << j;
        }
      }
    }

    if(t1 > 0){
      for(int j = 0; j < 32; j++){
        if(x >> j & 1) cnt1[j] = n;
      }
    }
    if(t2 < 0){
      for(int j = 0; j < 32; j++){
        if(x >> j & 1) cnt2[j] = n;
      }
    }
  }
  int res1 = 0, res2 = 0;
  for(int i = 0; i < 32; i++){
    if(cnt1[i] % 2)
      res1 += 1 << i;
    if(cnt2[i] % 2)
      res2 += 1 << i;
  }
  cout << res2 << " " << res1 << endl;
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