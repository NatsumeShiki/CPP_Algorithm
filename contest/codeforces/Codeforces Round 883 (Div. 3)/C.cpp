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
  int a, b;
  bool operator < (const edge &t) const{
    if(a != t.a) return a > t.a;
    return b <= t.b;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];

void solve(){
  int p = 0, q = 0;
  int cnt = 1;
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> arr[j];
    sort(arr, arr + m);

    int score = 0, time = 0, sum = 0;
    for(int j = 0; j < m; j++){
      if(sum + arr[j] <= k){
        time += arr[j] + sum;
        sum += arr[j];
        score++;
      }else{
        break;
      }
    }
    if(i == 0) p = score, q = time;
    if(score > p){
      cnt++;
    }else if(score == p){
      if(time < q) cnt++;
    }
  }

  cout << cnt << endl;
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

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define x first
// #define y second
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<PII, int> PIII;
// typedef pair<PIII, int> PIIII;
// typedef pair<int, char> PIC;
// typedef pair<char, int> PCI;
// struct edge{
//   int a, b;
//   bool operator < (const edge &t) const{
//     if(a != t.a) return a > t.a;
//     return b <= t.b;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
// int n, m, k, t;
// int arr[N];
// edge res[N];

// void solve(){
//   cin >> n >> m >> k;
//   int res = 0;
//   int cnt = 1;
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < m; j++) cin >> arr[j];
//     sort(arr, arr + m);

//     int time = 0, score = 0, sum = 0;
//     for(int j = 0; j < m; j++){
//       if(sum + arr[j] <= k){
//         sum += arr[j];
//         time += sum;
//         score++;
//       }else{
//         break;
//       }
//     } 
//     // cout << score << " " << time << endl;
//     if(i == 0) res = score * (-1e13) + time;
//     int x = score * (-1e13) + time;
//     // cout << x << endl;
//     if(x < res) cnt++;
//   }

//   cout << cnt << endl;
// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);
//   #endif

//   int T = 1;
//   cin >> T;
//   while(T--){
//     solve();
//   }

//   return 0;
// }