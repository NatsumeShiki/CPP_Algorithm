// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// #include<queue>
// using namespace std;

// const int N = 2e5 + 10;
// vector<int> box[N];
// vector<int> have[N];
// int n, q, cnt;
// int backup[N];

// void solve(){
//   scanf("%d%d", &n, &q);
//   while(q--){
//     int op, a, b;
//     scanf("%d", &op);
//     if(op == 1){
//       scanf("%d%d", &a, &b);
//       box[b].push_back(a);
//       have[a].push_back(b);
//     }else if(op == 2){
//       scanf("%d", &a);
//       cnt = box[a].size();
//       for(int i = 0; i < cnt; i++) backup[i] = box[a][i];
//       sort(backup, backup + cnt);
//       for(int i = 0; i < cnt; i++) printf("%d ", backup[i]);
//       puts("");
//     }else{
//       scanf("%d", &a);
//       cnt = have[a].size();
//       for(int i = 0; i < cnt; i++) backup[i] = have[a][i];
//       sort(backup, backup + cnt);
//       cnt = unique(backup, backup + cnt) - backup;
//       for(int i = 0; i < cnt; i++) printf("%d ", backup[i]);
//       puts("");
//     }
//   }
// }

// int main(){
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);

//   solve();

//   return 0;
// }

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
 
typedef long long LL;
const int N = 2e6 + 10;
LL mod = 998244353;
int n, q;
int a[N];

void solve(){
  scanf("%d", &q);
  int first = 0, last = 0;
  a[0] = 1;
  while(q--){
    int op, x;
    scanf("%d", &op);
    if(op == 1){
      scanf("%d", &x);
      a[++last] = x;
    }else if(op == 2){
      first++;
    }else{
      LL res = 0;
      for(int i = first; i <= last; i++){
        res = res * 10 + a[i];
        if(res >= mod) res %= mod;
      }
      printf("%lld\n", res % mod);
      if(res >= mod){
        res = res % mod;
        first = last + 1;
        while(res){
          a[--first] = res % 10;
          res /= 10; 
        }
      }
    }
  }
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  solve();

  return 0;
}


 