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
int arr[M];
vector<int> alls;
int st[M];

void solve(){
  cin >> n;
  int cnt = 0;
  vector<int> st(n + 10, 0);
  // for(int i = 0; i <= n + 5; i++) st[i] = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] >= n + 5) arr[i] = INF, cnt++;
    if(arr[i] != INF) st[arr[i]]++;
  }

  if(n == 1){
    if(arr[0] == 0) cout << "No\n";
    else cout << "Yes\n";
    return;
  }

  int index = 0, res;
  while(index <= n + 5){
    if(!st[index]){
      res = index;
      break;
    }
    index++;
  }

  int l = 0, r = n - 1;
  while(l < n && arr[l] != res + 1) l++;
  while(r > 0 && arr[r] != res + 1) r--;
  if(l > r){
    int maxCnt = 0, maxv = 0;
    for(int i = 0; i <= n + 5; i++){
      maxCnt = max(maxCnt, st[i]);
      if(st[i]) maxv = i;
    }
    // cout << maxCnt << " " << maxv << endl;
    if(maxCnt >= 2 || maxv >= res + 1 || cnt) cout << "Yes\n";
    else cout << "No\n";
    return;
  }
  for(int i = l; i <= r; i++) arr[i] = res;
  for(int i = 0; i <= n + 5; i++) st[i] = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] <= n + 5) st[arr[i]]++;
  }
  index = 0;
  while(index <= n + 5){
    if(!st[index]){
      if(index == res + 1) cout << "Yes\n";
      else cout << "No\n";
      return;
    }
    index++;
  }
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