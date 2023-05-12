#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
 
const int N = 1e6 + 10;
int cnt;
int res[N];
bool st[N];
int n;

void init(){
    int x = 1000000;
    for(int i = 2; i <= x; i++){
        if(!st[i]) res[cnt++] = i;
        for(int j = 0; res[j] <= x / i; j++){
            st[res[j] * i] = true;
            if(i % res[j] == 0) break;
        }
    }
}

vector<int> get(int x){
  vector<int> res;
  for(int i = 1; i * i <= x; i++){
    if(x % i == 0) res.push_back(i), res.push_back(x / i);
  }
    // res.push_back(i), res.push_back();
  return res;
}

void solve(){
  int T;
  cin >> T;
  // init();
  while(T--){
    int n, m;
    cin >> n >> m;
    vector<int> res = get(n);
    bool flag = true;
    for(int x : res)
      if(x > 1 && x <= m){
        flag = false;
        puts("NO");
        break;
      }

    if(flag) puts("YES");
    // int n, m;
    // cin >> n >> m;
    // if(m == 1){
    //   puts("YES");
    //   continue;
    // }
    // if(n % 2 == 0 || n == m){
    //   puts("NO");
    //   continue;
    // }
    // if(!st[n]){
    //   puts("YES");
    //   continue;
    // }

    // bool flag = false;
    // for(int i = 0; i < cnt && res[i] <= m; i++){
    //   if(n % res[i] == 0){
    //     flag = true;
    //     break;
    //   }
    // }
    // if(flag) puts("NO");
    // else puts("YES");
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