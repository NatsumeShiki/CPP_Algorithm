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

void solve(){
  cin >> n;
  if(n <= 1000 - 1) cout << n << endl;
  else if(n < 10000 - 1) cout << n / 10 << "0";
  else if(n <= 100000 - 1) cout << n / 100 << "00";
  else if(n <= 1000000 - 1) cout << n / 1000 << "000";
  else if(n <= 10000000 - 1) cout << n / 10000 << "0000";
  else if(n <= 100000000 - 1) cout << n / 100000 << "00000";
  else if(n <= 1000000000 - 1) cout << n / 1000000 << "000000";
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