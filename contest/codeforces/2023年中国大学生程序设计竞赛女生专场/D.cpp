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


const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int tr[M];
int res[M];
int f[M];

int lowbit(int x){
  return x & -x;
}

void add(int x, int c){
  for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int query(int x){
  int res = 0;
  for(int i = x; i; i -= lowbit(i)) res += tr[i];
  return res;
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    add(i, 1);
  }
  for(int i = n; i; i--){
    int t = arr[i];
    int l = 1, r = n;
    while(l < r){
      int mid = l + r >> 1;
      if(query(mid) < t) l = mid + 1;
      else r = mid;
    }
    if(query(l) != t){
      cout << "-1\n";
      return;
    }
    res[i] = l;
    // cout << l << " " << query(l) << endl;
    add(l, -1);
  }

  // int len = 0;
  // f[0] = -INF;
  // for(int i = 1; i <= n; i++){
  //   int x = res[i];
  //   int l = 0, r = len;
  //   while(l < r){
  //     int mid = l + r + 1 >> 1;
  //     if(f[mid] < x) l = mid;
  //     else r = mid - 1;
  //   }
  //   f[l + 1] = x;
  //   len = max(len, l + 1);
  //   if(l + 1 != arr[i]){
  //     cout << "-1\n";
  //     return;
  //   }
  // }
  int mx = 0;
  for(int i = 1; i <= n; i++){
    if(mx + 1 < arr[i]){
      cout << "-1\n";
      return;
    }
    mx = max(mx, arr[i]);
  }

  for(int i = 1; i <= n; i++) cout << res[i] << " ";
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