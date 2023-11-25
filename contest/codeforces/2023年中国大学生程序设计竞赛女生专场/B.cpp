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
int arr[20][10];
string s, str;
int pos[15];

void solve(){
  memset(arr, 0, sizeof arr);
  memset(pos, 0, sizeof pos);
  pos[1] = 2, pos[2] = 3, pos[3] = 4;
  arr[2][0] = 1, arr[3][0] = 2, arr[4][0] = 3;
  for(int i = 0; i < 12; i++){
    int a, b;
    cin >> a >> b;
    int index1 = pos[a];
    int j = 0;
    while(arr[index1][j] != a) j++;
    int index2 = index1 + b;
    // cout << index1 << " " << index2 << endl;
    int k = 0;
    while(arr[index2][k] != 0) k++;
    while(arr[index1][j] != 0){
      arr[index2][k] = arr[index1][j];
      pos[arr[index1][j]] = index2;
      arr[index1][j] = 0;
      k++, j++;
    }

  }
  bool flag = true;
  for(int j = 0; j < 3; j++){
    if(arr[9][j] == 0) {
      flag = false;
    }
  }

  if(flag){
    cout << "Y\n";
    return;
  }
  cout << "N\n";
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
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}