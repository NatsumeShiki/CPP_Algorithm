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

const int N = 10010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N], b[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size();
    // for(int i = 1; i <= len1; i++) a[i] = str1[len1 - i] - '0';
    // for(int i = 1; i <= len2; i++) b[i] = str2[len2 - i] - '0';

    // for(int i= 1; i <= len1; i++) cout << a[i] << " ";
    // puts("");
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int res = 0;
    for(int i = 0; i < len2; i++){
      if(i < len1)  a[i] = str2[i] - str1[i];
      else a[i] = str2[i] - '0';
    }
    int i;
    for(i= len2 - 1; i >= 0; i--){
      if(a[i] != 0) break; 
    }
    if(i >= 0) res = 9 * i + a[i];
    printf("%d\n", res);

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