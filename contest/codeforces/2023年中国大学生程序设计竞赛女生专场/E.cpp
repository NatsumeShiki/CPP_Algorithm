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

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int H1[N], A1[N], B1[N], C1[N], D1[N], E1[N], W1[N], now1[N];
int H2[N], A2[N], B2[N], C2[N], D2[N], E2[N], W2[N], now2[N];
bool st1[N], st2[N];

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> H1[N] >> A1[N] >> B1[N] >> C1[N] >> D1[N] >> E1[N] >> W1[N];
  for(int i = 0; i < n; i++) cin >> H2[N] >> A2[N] >> B2[N] >> C2[N] >> D2[N] >> E2[N] >> W2[N];
  int cnt1 = n, cnt2 = m;

  int index1 = 0, index2 = 0;
  for(int i = 0; i < k; i++){
    int a = max(A1[index1] - C2[index2], 0ll);
    int b = max(B1[index1] - D2[index2], 0ll);
    int c = 0;
    if(now1[index1] >= E1[index1]) c = W1[index1];

    if(c > a && c > b){
      H2[index2] -= c;
      now1[index1] -= E1[index1];
      if(H2[index2] <= 0){
        st2[index2] = true;
        cnt2--;
        if(cnt2 == 0){
          cout << "Alice\n";
          return;
        }
        while(st2[index2]) index2 = (index2 + 1) % m;
        continue;
      }
      index1 = (index1 + 1) % n;
    }else{
      int damage = max(a, b);
      H2[index2] -= damage;
      now1[index1]++;
      if(H2[index2] <= 0){
        st2[index2] = true;
        cnt2--;
        if(cnt2 == 0){
          cout << "Alice\n";
          return;
        }
        while(st2[index2]) index2 = (index2 + 1) % m;
        continue;
      }
      index1 = (index1 + 1) % n;
    }

    a = max(A2[index2] - C1[index1], 0ll);
    b = max(B2[index2] - D1[index1], 0ll);
    c = 0;
    if(now2[index2] >= E1[index2]) c = W2[index2];

    if(c > a && c > b){
      H1[index1] -= c;
      now2[index2] -= E2[index2];
      if(H1[index1] <= 0){
        st1[index1] = true;
        cnt1--;
        if(cnt1 == 0){
          cout << "Bob\n";
          return;
        }
        while(st1[index1]) index1 = (index1 + 1) % m;
        continue;
      }
      index2 = (index2 + 1) % n;
    }else{
      int damage = max(a, b);
      H1[index1] -= damage;
      now2[index2]++;
      if(H1[index1] <= 0){
        st1[index1] = true;
        cnt1--;
        if(cnt1 <= 0){
          cout << "Bob\n";
          return;
        }
        while(st1[index1]) index1 = (index1 + 1) % n;
        continue;
      }
      index2 = (index2 + 1) % n;
    }
  }
  cout << "Draw\n";
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