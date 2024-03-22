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
int l[N], r[N];
int cnt[N];

void solve(){
  cin >> n >> m >> s;
  for(int i = 1; i <= n; i++) cnt[i] = 0;
  for(int i = 0; i < m; i++) {
    cin >> l[i];
    // cnt[i + 1] = 0;
  }
  for(int i = 0; i < m; i++) cin >> r[i];

  cin >> q;
  while(q--){
    int x;
    cin >> x;
    int a = 0, b = m - 1;
    while(a < b){
      int mid = a + b + 1 >> 1;
      if(l[mid] <= x) a = mid;
      else b = mid - 1;
    }

    int L = min(x, l[a] + r[a] - x), R =  max(x, l[a] + r[a] - x);
    cnt[L]++;
    if(R < r[a]) cnt[R + 1]--;
  }
  // for(int i = 1; i <= 4; i++) cout << cnt[i] << endl;
  for(int i = 0; i < m; i++){
    int L = l[i], R = r[i];
    int j = L + 1;
    // j++;
    // cout << j << " 12 " << cnt[j] << endl;
    while(j <= R){
      if(j > L) cnt[j] += cnt[j - 1];
      // cout << j << " " << cnt[j] << endl;
      j++;
    }
    while(L < R){
      if(cnt[L] % 2){
        char c = s[L - 1];
        s[L - 1] = s[R - 1];
        s[R - 1] = c;
      }
      // cout << L << " " << R << " " << cnt[L] << " " << cnt[R] << endl;
      L++, R--;
    }
  }
  cout << s << endl;
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