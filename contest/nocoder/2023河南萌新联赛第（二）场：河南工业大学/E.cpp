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
int arr[M];
vector<int> alls;

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    int minv = 0;
    if(i - x > minv) minv = i - x;
    int maxv = 1e6;
    if(i + x < maxv) maxv = i + x;
    arr[minv]++, arr[i]--, arr[i + 1]++, arr[maxv + 1] --;

  }
  int res = 0;
  for(int i = 1; i <= n; i++){
    arr[i] += arr[i - 1];
    if(arr[i] > 0) res++;
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

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}