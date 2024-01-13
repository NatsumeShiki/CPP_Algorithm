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
int res[N];
int a[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i], a[i] = arr[i];
  sort(arr, arr + n);

  int k = 0;
  for(int i = 0; i < n; i++) k += arr[i] - arr[0] + 1;
  map<int, int> mp;
  mp[arr[0]] = k;

  for(int i = 1; i < n; i++){
    int t = 0;
    t -= (n - i) * (arr[i] - arr[i - 1]);
    t += i * (arr[i] - arr[i - 1]);
    mp[arr[i]] = mp[arr[i - 1]] + t;
  }

  for(int i = 0; i < n; i++)
    cout << mp[a[i]] << " \n"[i == n - 1];
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