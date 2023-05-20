#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N];
int maxd[N], backup[N];

bool operate(int l, int r){
  int index = 0;
  for(int i = r + 1; i <= n; i++) backup[++index] = a[i];
  for(int i = r; i >= l; i--) backup[++index] = a[i];
  for(int i = 1; i < l; i++) backup[++index] = a[i];
  for(int i = 1; i <= n; i++)
    if(maxd[i] > backup[i]) return false;
    else if(maxd[i] < backup[i]) return true;
  return false;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    memset(maxd, 0, sizeof maxd);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j++){
        if(a[j] != n && a[j] != n - 1 && (j < n && a[j + 1] != n && a[j + 1] != n - 1)) continue;
        if(operate(i, j)){
          // cout << i << " " << j << endl;
          for(int k = 1; k <= n; k++){
            maxd[k] = backup[k];
          }
        }
      }
    for(int i = 1; i <= n; i++) cout << maxd[i] << " ";
    cout << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}

// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #include<set>
// #include<vector>
// // #include<bits/stdc++.h>
// using namespace std;
// #define x first
// #define y second
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 2010, M = 1e6 + 10, INF = 0x3f3f3f3f;
// int n, m, k, t;
// int a[N];

// void solve(){
//   int T;
//   cin >> T;
//   while(T--){
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     int l = 0, r = 0;
//     if(a[1] == n){
//       for(int i = 1; i <= n; i++)
//         if(a[i] == n - 1){
//           l = r = i - 1;
//           break;
//         }
//       if(l == n - 1) l = r = n; 
//     }else if(a[n] == n){
//       l = r = n;
//       while(l - 1 > 1 && a[l - 1] > a[1]) l--;
//     }else{
//       for(int i = 1; i <= n; i++)
//         if(a[i] == n){
//           r = l = i - 1;
//           break;
//         }
//       while(l - 1 >= 1 && a[l] < a[l - 1]) l--;
//     }
//     // cout << l << " " << r << endl;
//     for(int i = r + 1; i <= n; i++) cout << a[i] << " ";
//     for(int i = r; i >= l; i--) cout << a[i] << " ";
//     for(int i = 1; i < l; i++) cout << a[i] << " ";
//     cout << endl;
//   }
// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);
//   #endif

//   solve();

//   return 0;
// }