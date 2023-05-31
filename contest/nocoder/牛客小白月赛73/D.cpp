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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
LL a[N], s2[N], s5[N];

LL find(int x){
  LL res = 0;
  while(x){
    if(x % 10 == 0) res++;
    else break;
    x /= 10;
  }
  return res;
}

void solve(){
  int t;
  cin >>t;
  while(t--){
    cin >> n >> k;
    for(int i = 1; i <= n;i ++){
      cin >> a[i];
      int c2 = 0, c5 = 0;
      int x = a[i];
      while(x % 2 == 0){
        c2++;
        x /= 2;
      }
      x = a[i];
      while(x % 5 == 0){
        c5++;
        x /= 5;
      }
      s2[i] = s2[i - 1] + c2;
      s5[i] = s5[i - 1] + c5;
      // cout << s2[i] << " " << s5[i] << endl;
    }

    LL res = 0;
    for(int i = 1; i <= n; i++){
      int l = i, r = n;
      while(l <= r){
        int mid = l + r + 1 >> 1;
        int c2 = s2[mid] - s2[i - 1];
        int c5 = s5[mid] - s5[i - 1];
        // cout << c2 << " " << c5 << " " << mid << endl;
        if(min(c2, c5) >= k) r = mid - 1;
        else l = mid + 1;
      }
      int c2 = s2[l] - s2[i - 1];
      int c5 = s5[l] - s5[i - 1];
      if(min(c2, c5) > k) continue;
      res -= l;
      // cout << l << " ";
      l = i, r = n;
      while(l <= r){
        int mid = l + r + 1 >> 1;
        int c2 = s2[mid] - s2[i - 1];
        int c5 = s5[mid] - s5[i - 1];
        if(min(c2, c5) <= k) l = mid + 1;
        else r = mid - 1;
      }
      // cout << l << endl;
      res += l;
    }
    cout << res << endl;
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