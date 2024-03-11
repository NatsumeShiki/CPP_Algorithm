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
int arr[M], h[M];
string s, str;

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) cin >> h[i];

  int l = 0, r = 0;
  int sum = 0, res = 0;
  while(r < n){
    // cout << l << " " << r << endl;
    if(l == r){
      if(arr[l] > m){
        l++, r++;
        continue;
      }
      sum = arr[l];
      r++;
      res = max(res, 1ll);
      continue;
    }

    if(h[r - 1] % h[r]){
      sum -= arr[l];
      l++;
      continue;
    }
    sum += arr[r];
    while(l <= r && sum > m){
      sum -= arr[l];
      l++;
    }
    res = max(res, r - l + 1);
    r++;
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
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}