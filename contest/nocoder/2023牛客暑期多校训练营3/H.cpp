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
int arr[N];
vector<int> alls;

bool check(int x){
  if(x == 1) return false;
  for(int i = 2; i <= x / i; i++)
    if(x % i == 0)
      return false;
  return true;
}

void solve(){
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
  if(n == 1){
    if(check(arr[0])) cout << "Yes";
    else cout << "No";
  }else if(n == 2){
    if(sum % 2 == 0){
      if(sum >= 4) puts("Yes");
      else puts("No");
    }else{
      if(check(sum - 2)) puts("Yes");
      else puts("No");
    }
  }else{
    if(sum >= n * 2) cout << "Yes";
    else cout << "No";
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}