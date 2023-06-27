#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
#include<stack>
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
char s[N];
int a[N];

void solve(){
  cin >> n >> s + 1;
  stack<int> st;
  for(int i = 1; i <= n; i++){
    if(s[i] == '(') st.push(i);
    if(s[i] == ')' && !st.empty()){
      a[st.top()]++;
      a[i + 1]--;
      st.pop();
    }

  }
    for(int i = 1; i <= n; i++){
      a[i] += a[i - 1];
      if(!a[i]) putchar(s[i]);
    }

  // string res = "";
  // for(int i = 0; i < n; ){
  //   if(s[i] != '(') {
  //     res += s[i];
  //     i++;
  //   }else{
  //     int cnt1 = 1, cnt2 = 0;
  //     int j = i + 1;
  //     while(j < n && cnt1 != cnt2){
  //       if(s[j] == '(') {
  //         if(cnt2 > 0) break;
  //         cnt1++;
  //       }
  //       if(s[j] == ')') cnt2++;
  //       j++;
  //     }
  //     if(cnt1 != cnt2){
  //       int k = i;
  //       while(k < j && cnt1 != cnt2){
  //         if(s[k] == '(') cnt1--;
  //         res += s[k];
  //         k++;
  //       }
  //       i = k;
  //     }else{
  //       i = j;
  //     }
  //   }
  // }
  // cout << res << endl;
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