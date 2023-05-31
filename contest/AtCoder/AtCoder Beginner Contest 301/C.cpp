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

  const int N = 30, M = 2e5 + 10, INF = 0x3f3f3f3f;
  int n, m, k, t;
  int cnt[N];
  char a[M], b[M];

  void solve(){
    // int T;
    // cin >> T;
    // while(T--){

    // }
    // string a, b;
    // cin >> a >> b;
    scanf("%s%s", a, b);
    n = strlen(a);
    int x = 0, y = 0;
    for(int i= 0; i < n; i++){
      if(a[i] == '@') x++;
      else cnt[a[i] - 'a']++;
    }
    for(int i= 0; i < n; i++){
      if(b[i] == '@') y++;
      else cnt[b[i] - 'a']--;
    }

    string atcoder = "atcoder";
    bool success = true;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 26; i++){
      if(cnt[i] == 0) continue;
      bool flag = false;
      char c = i + 'a';
      for(int j = 0; j < 7; j++)
        if(c == atcoder[j]){
          flag = true;
          break;
        }
      if(!flag){
        success = false;
        break;
      }

      if(cnt[i] > 0) cnt1 += cnt[i];
      else cnt2 += abs(cnt[i]);
    }
    // printf("%d %d %d %d\n", x, y, cnt1, cnt2);
    if(!success) puts("No");
    else{
      if(cnt2 <= x && cnt1 <= y  ) puts("Yes");
      else puts("No");
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