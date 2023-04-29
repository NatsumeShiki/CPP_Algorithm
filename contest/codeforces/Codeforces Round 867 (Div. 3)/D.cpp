#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
typedef long long LL;
const int N = 2e5 + 10;
int n;

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    if(n == 1) {
      puts("1");
      continue;
    }
    if(n & 1){
      puts("-1");
      continue;
    }
    vector<int> res;
    for(int i = 0; i < n / 2; i++){
      res.push_back(i);
      res.push_back(n - i - 1);
    }
    cout << n << " ";
    for(int i = 1; i < n; i++)
      cout << (res[i] - res[i - 1] + n) % n << " "; 
    cout << endl;
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