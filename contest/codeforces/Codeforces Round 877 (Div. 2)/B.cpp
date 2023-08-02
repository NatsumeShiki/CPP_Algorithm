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

void solve(){
  cin >> n;
  int pos1, pos2, posn;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    if(arr[i] == 1) pos1 = i;
    else if(arr[i] == 2) pos2 = i;
    else if(arr[i] == n) posn = i;
  }

  if(pos1 < pos2 && pos2 < posn){
    cout << pos2 << " " << posn << endl;
  }else if(pos2 < pos1 && pos1 < posn){
    cout << pos1 << " " << posn << endl;
  }else if(posn < pos1 && pos1 < pos2){
    cout << pos1 << " " << posn << endl;
  }else if(posn < pos2 && pos2 < pos1){
    cout << posn << " " << pos2 << endl;
  }
  else cout << pos1 << " " << pos1 << endl;
} 

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}