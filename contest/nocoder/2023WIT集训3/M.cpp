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

const int N = 1e8 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int primes[N], cnt;
bool st[N];
vector<int> alls;

void solve(){
  n = 1e8;
  for(int i = 2; i <= n; i++){
    if(!st[i]) primes[cnt++] = i;
    for(int j = 0; primes[j] <= n / i; j++){
      st[primes[j] * i] = true;
      if(i % primes[j] == 0) break;
    }
  }

  // for(int i = 0; i < 100; i++) cout << primes[i] << endl;
  for(int i = 0; i < cnt; i++)
    for(int j = i; j < cnt; j++){
      int x = primes[i] * primes[j];
      if(x > 1e8) break;
      alls.push_back(x);
      // if(x >= 150 && x <= 200) cout << primes[i] << " " << primes[j] << " " << x << endl;
    }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();
  sort(alls.begin(), alls.end());
  int T = 1;
  cin >> T;
  while(T--){
    int l, r;
    cin >> l >> r;
    int x = upper_bound(alls.begin(), alls.end(), r) - alls.begin();
    int y = upper_bound(alls.begin(), alls.end(), l - 1) - alls.begin();
    // cout << x << endl << y << endl;
    cout << x - y << endl;
  }

  return 0;
}