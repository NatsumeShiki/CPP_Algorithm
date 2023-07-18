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
int primes[M], cnt;
bool st[M];

void solve(){
  int x;
  cin >> x;
  vector<int> alls;
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) {
      alls.push_back(i);
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) alls.push_back(x);
  // sort(alls.begin(), alls.end());
  if(alls.front() == x){
    puts("isprime");
    cout << x << endl;
  }else{
    puts("noprime");
    for(auto item : alls) cout << item << " ";
    cout << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}