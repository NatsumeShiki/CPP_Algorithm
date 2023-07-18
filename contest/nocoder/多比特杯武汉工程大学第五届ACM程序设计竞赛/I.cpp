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
int s[N];

void solve(){
  set<int> S;
  cin >> n;
  S.insert(0);
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    S.insert(s[i]);
    s[i] ^= s[i - 1];
    S.insert(s[i]);
  }

  cin >> arr[1] >> arr[2] >> k;
  for(int i = 3; i <= k; i++) arr[i] = arr[i - 1] + arr[i - 2];
  for(int i = 1; i <= k; i++){
    bool flag = false;
    for(int j = 1; j <= n; j++){
      if(S.count(s[j] ^ arr[i])){
        flag = true;
        break;
      }
    }
    if(!flag){
      puts("NO");
      return;
    }
  }
  puts("YES");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}