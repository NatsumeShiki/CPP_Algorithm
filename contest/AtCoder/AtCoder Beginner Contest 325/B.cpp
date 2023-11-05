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
int arr[M], cnt[M];
string s, str;

void solve(){
  // cin >> n;
  // for(int i = 0; i < n; i++) {
  //   int a, b;
  //   cin >> a >> b;
  //   b++;
  //   cnt[b] += a;
  // }

  // for(int i = 1; i <= 24; i++) cnt[i] += cnt[i - 1];

  // int res = 0;
  // for(int i = 1; i <= 24; i++){
  //   if(i <= 9) res = max(res, cnt[i]);
  //   else res = max(res, cnt[i] - cnt[i - 9]);
  // }
  // cout << res << endl;

  cin >> n;
  for(int i = 0; i < n; i++) cin >> cnt[i] >> arr[i];

  int res = 0;
  for(int i = 0; i <= 23; i++){
    int ans = 0;
    for(int j = 0; j < n; j++){
      int t = (arr[j] + i) % 24;
      if(t >= 9 && t < 18)
        ans += cnt[j];
    }
    res = max(res, ans);
  }
  cout << res << endl;

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