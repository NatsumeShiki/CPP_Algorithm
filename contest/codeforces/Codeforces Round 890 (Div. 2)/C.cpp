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

bool check(int mid){
  for(int i = 0; i < n; i++){
    int cnt = m;
    for(int j = i; j < n; j++){
      int t = mid - (j - i);
      if(arr[j] >= t) return true;

      int need = max(t - arr[j], 0ll);
      if(cnt < need) break;
      cnt -= need;
    }
  }
  return false;
}

// bool check(int mid){
//   for(int i = 0; i < n; i++){
//     int have = m;
//     for(int j = i; j < n; j++){
//       int required = mid - (j - i);
//       if(arr[j] >= required) return true;

//       int need = max(required - arr[j], 0ll);
//       if(have < need) break;
//       have -= need;
//     }
//   }
//   return false;
// }

void solve(){
  cin >> n >> m;
  int res = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    res = max(res, arr[i]);
  }

  int l = res, r = 2e8;
  while(l < r){
    int mid = l + r + 1 >> 1;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
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