#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int s[N];

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    s[i] += s[i - 1];
    if(i % 2 == 1) s[i] += arr[i] - arr[i - 1];
    // cout << s[i] << endl; 
  }

  cin >> m;
  while(m--){
    int x, y;
    cin >> x >> y;
    int res = 0;
    int l = 1, r = n;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(arr[mid] <= x) l = mid;
      else r = mid - 1;
    }

    if(l % 2 == 0 && l < n) res += arr[l + 1] - x;
    int L = l + 1;

    r = n;
    while(l < r){
      int mid = l + r >> 1;
      if(arr[mid] >= y) r = mid;
      else l = mid + 1;
    }
    res += s[l] - s[L];
    if(l % 2 == 1)
      res -= arr[l] - y;


    cout << res << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}