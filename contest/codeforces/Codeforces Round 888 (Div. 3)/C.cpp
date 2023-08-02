#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
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

void solve() {
  cin >> n >> m;
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int l = INF, r = INF;
  for(int i = 0; i < n; i++){
    if(arr[i] == arr[0]) cnt1++;
    if(cnt1 == m) {
      r = i;
      break;
    }
  }
  for(int i = n - 1; i >= 0; i--){
    if(arr[i] == arr[n - 1]) cnt2++;
    if(cnt2 == m) {
      l = i;
      break;
    }
  }
  // cout << l << " " <<r << endl;
  if(l != INF && r != INF && r < l) cout << "Yes\n";
  else if(arr[0] == arr[n - 1] && cnt1 == m) cout << "Yes\n";
  else cout << "No\n";
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