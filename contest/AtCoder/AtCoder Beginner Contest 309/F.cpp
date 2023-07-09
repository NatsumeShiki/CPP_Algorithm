#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    if(a != t.a) return a < t.a;
    if(b != t.b) return b < t.b;
    return c <= t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
edge arr[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    arr[i] = {a[0], a[1], a[2]};
  } 

  sort(arr, arr + n);

  for(int i = 1; i < n; i++){
    edge a = arr[i - 1], b = arr[i];
    if(a.a < b.a && a.b < b.b && a.c < b.c) {
      puts("Yes");
      return;
    }
  }

  puts("No");

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}