#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
int n, m;

bool dfs(int u){
  if(u == m) return true;
  if(u % 3 != 0) return false;
  if(dfs(u / 3 * 2)) return true;
  if(dfs(u / 3)) return true;
  return false;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    if(n == m){
      puts("YES");
      continue;
    }
    if(n % 3 || n < m){
      puts("NO");
      continue;
    }

    if(dfs(n)) puts("YES");
    else puts("NO");
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