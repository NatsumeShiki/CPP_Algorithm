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
int dp[M][2];
string s, str;

// void solve(){
//   cin >> s;
//   n = s.size();
//   int res1 = 0;
//   int l = 0;
//   while(l < n){
//     if(s[l] == 'A'){
//       int r = l;
//       while(r < n && s[r] == 'A') r++;
//       int t = 0;
//       if(r < n) t = r - l;
//       else if(s[r - 1] == 'B') t = r - l - 1;
//       // l = r + 1;

//       if(r < n){
//         int r1 = r + 1;
//         while(r1 < n && s[r1] == 'A') r1++;
//         if(r1 < n || s[r1 - 1] == 'A'){
//           if(r1 - r - 1 >= t){
//             res1 += r1 - r - 1;
//             l = r1;
//           }else{
//             res1 += t;
//             l = r + 1;
//           }
//         }else{
//           res1 += t;
//           l = r + 1;
//         }
//         // cout << "r = " << r << " r1 = " << r1 << endl; 
//       }else{
//         l = r + 1;
//       }

//     }else if(s[l] == 'B'){
//       int r = l + 1;
//       while(r < n && s[r] == 'A') r++;
//       if(r < n) res1 += r - l - 1;
//       else if(s[r - 1] == 'A') res1 += r - l - 1;
//       l = r;
//     }
//     // cout << l - 1 << " " << res1 << endl;
//   }

//   reverse(s.begin(), s.end());
//   // cout << s << endl;
//   int res2 = 0;
//   l = 0;
//   while(l < n){
//     if(s[l] == 'A'){
//       int r = l;
//       while(r < n && s[r] == 'A') r++;
//       if(r < n) res2 += r - l;
//       else if(s[r - 1] == 'B') res2 += r - l - 1;
//       l = r + 1;
//     }else if(s[l] == 'B'){
//       int r = l + 1;
//       while(r < n && s[r] == 'A') r++;
//       if(r < n) res2 += r - l - 1;
//       else if(s[r - 1] == 'A') res2 += r - l - 1;
//       l = r;
//     }
//   }
//   // cout << res1 << " " << res2 << endl;
//   cout << max(res1, res2) << endl;
// }

// void solve(){
//   cin >> s;
//   n = s.size();
//   string str = "";
//   int index = 0;
//   for(int i = 0; i < n; ){
//     if(s[i] == 'A'){
//       int j = i;
//       while(j < n && s[j] == 'A') j++;
//       arr[index++] = j - i;
//       i = j;
//     }else{
//       arr[index++] = 0;
//       i++;
//     }
//   }

//   // for(int i = 0; i < index; i++) cout << arr[i] << " \n"[i == index - 1];
//   int res = 0;
//   for(int i = 0; i < index; i++){
//     if(arr[index]){
      
//       dp[i][0] = dp[i - 1][0];
//       dp[i][1] = dp[i - 1][1];
//     }else{
//       if(i - 1 >= 0) dp[i][0] = dp[i - 1][0] + arr[i - 1];
//       else dp[i][0] = dp[i - 1][0];

//       if(i + 1 < index) dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i + 1];
//       else dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
//     }
//     cout << dp[i][0] << " " << dp[i][1] << endl;
//     res = max({res, dp[i][0], dp[i][1]});
//   }
//   cout << res << endl;
// }

void solve(){
  cin >> s;
  n = s.size();
  int tot = 0, cur = 0;
  int mn = INF;
  for(int i = 0; i < n; i++){
    if(s[i] == 'A'){
      tot++, cur++;
    }else{
      mn = min(mn, cur);
      cur = 0;
    }
  }
  mn = min(mn, cur);
  cout << tot - mn << endl;
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