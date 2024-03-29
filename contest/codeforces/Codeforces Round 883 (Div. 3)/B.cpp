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
int arr[8][3]{
  {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
  {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
  {0, 4, 8}, {2, 4, 6}
};


void solve(){
  string s = "";
  for(int i = 0; i < 3; i++){
    string t;
    cin >> t;
    s += t;
  }

  for(int i = 0; i < 8; i++){
    auto [a, b, c] = arr[i];
    if(s[a] == s[b] && s[a] == s[c] && s[a] != '.') {
      cout << s[a] << endl;
      return;
    }
  }
  cout << "DRAW\n";
  // n = 3;
  // for(int i = 0; i < 3; i++) cin >> arr[i];
  // char res = '.';
  
  // for(int i = 0; i < 3; i++){
  //   if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '.'&& res == '.')
  //     res = arr[i][0];
  //   if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '.' && res == '.')
  //     res = arr[0][i];
  // }

  // if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.' && res == '.') 
  //   res = arr[0][0];

  // if(arr[2][0] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != '.' && res == '.')
  //   res = arr[2][0];

  // if(res == '.'){
  //   puts("DRAW");
  // }else cout << res << endl;


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