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
int arr[M], sum[M];
string s, str;
int a[M];

// bool check(int mid){
//   int res = 0, sum = 0;
//   for(int i = 1; i <= n; i++){
//     if(arr[i] > mid) return false;
//     if(sum + arr[i] > mid){
//       // if(mid == 258) cout << i << " " << arr[i] << " " << sum << endl;
//       sum = arr[i] + 1;
//       res++;
//       continue;
//     }
//     sum += arr[i] + 1;
//   }
//   // if(mid == 258) cout << res << endl;
//   return res < m;
// }

bool check(int mid){
        int cnt = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > mid)
                return false;

            if (res + a[i] > mid) {
                cnt++;
                res = a[i] + 1;

            } else {
                res += a[i] + 1;
            }
        }
        return cnt < m;
}

// void solve(){
//   cin >> n >> m;
//   for(int i = 1; i <= n; i++){
//     cin >> arr[i];
//   }

//   int l = 1, r = 1e18;
//   while(l < r){
//     int mid = l + r >> 1;
//     if(check(mid)) r = mid;
//     else l = mid + 1;
//   }
//   cout << l << endl;
// }

void solve() {
    // int n, m;
    cin >> n >> m;
    // vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // auto check = [&](int mid) {
    //     int cnt = 0;
    //     int res = 0, t = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (a[i] > mid)
    //             return false;

    //         if (res + a[i] > mid) {
    //             cnt++;
    //             // t = 0;
    //             res = a[i];

    //         } else {
    //             res += a[i] + 1;
    //             // t++;
    //         }
    //     }
    //     return cnt < m;
    // };

    int l = 1, r = 1e18;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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
  while(T--){
    solve();
  }

  return 0;
}