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
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
bool res[N];
// int a[N];

void solve(){
  cin >> n;
  int last = -1, first = 0, flag = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(i == 0) first = arr[i];

    if(arr[i] >= last && flag == 0){
      last = arr[i];
      cout << 1;
    }else if(flag == 1 && arr[i] <= first && arr[i] >= last){
      last = arr[i];
      cout << 1;
    }else if(flag == 0 && arr[i] <= first){
      flag = 1;
      last = arr[i];
      cout << 1;
    }else cout << 0;
  }
  cout << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}