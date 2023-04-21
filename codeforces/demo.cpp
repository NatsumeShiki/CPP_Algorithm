#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int N = 30;
int cnt[N];
bool st[N];

int lowbit(int x){
  return x & -x;
}

void solve(){
  int t;
  cin >> t;
  while(t--){
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
      cnt[s[i] - 'a']++;
    int maxd = -1, index = 0;
    for(int i = 0; i < 30; i++)
      if(cnt[i] > maxd){
        maxd = cnt[i];
        index = i;
      }

    if(maxd == 1){
      if(n == 1) puts("0");
      else if(n <= 3) puts("1");
      else puts("2");
      continue; 
    }
    if(maxd == n) {
      puts("0");
      continue;
    }

    char c = 'a' + index;
    // cout << c << endl;
    int res = 0;
    for(int i = 0; i < n;){
      int j = i;
      while(j < n && s[j] != c) j++;
      res = max(res, j - i);
      i = j + 1;
    }
    // cout << res << endl;
    // cout << lowbit(res) << endl;

    int ans = 0;
    for(int i = 31; i >= 0; i--){
      if(res >> i & 1){
        ans = i;
        break;
      }
    }
    // cout << (1 << ans) << endl;
    ans = 1 << ans;
    int t = 0;
    while(ans){
      ans /= 2;
      t++;
    }
    cout << t << endl;

    // char c = 'a' + index;
    // while(true){
    //   for(int i = 0; i )
    // }
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


 