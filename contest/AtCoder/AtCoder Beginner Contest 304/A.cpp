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
string s[N];

void solve(){
  cin >> n;
  int minv = 1e9, index = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i] >> arr[i];
    if(arr[i] < minv){
      minv = arr[i];
      index = i;
    }
  }

  for(int i = index; i < n; i++) cout << s[i] << endl;
  for(int i = 0; i < index; i++) cout << s[i] << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}