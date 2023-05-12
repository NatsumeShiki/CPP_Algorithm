#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
typedef long long LL;
const int N = 2030;
int n;
LL dp[N][N];
LL res[N];

void solve(){
  int T;
  cin >> T;
  dp[1][1] = 1;
  res[1] = 1;
  for(int i = 2, k = 2; i <= 2023; i++){
    for(int j = 1; j <= i; j++, k++){
      dp[i][j] = 1ll * k * k + dp[i - 1][j] + dp[i - 1][j - 1] - dp[i - 2][j - 1];
      res[k] = dp[i][j];  
    }
  }
  
  while(T--){
    cin >> n;
    cout << res[n] << endl;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}