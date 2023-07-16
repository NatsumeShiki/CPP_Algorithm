#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
// typedef pair<PIII, int> PIIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int c1, c2, r1, r2;
int dc1, dc2, dr1, dr2;
int ex, ey, d1, d2;
vector<PIIII> res;

void solve(){
  cin >> c1 >> c2 >> r1 >> r2;
  cin >> dc1 >> dc2 >> dr1 >> dr2;
  cin >> ex >> ey >> d1 >> d2;

  r1 -= dr1, r2 += dr2;
  queue<PII> q;
  for(int i = 1; i <= 5; i++)
    for(int j = 1; j <= 5; j++){
      if(i != r1 && i != r2 && j != c1 && j != c2){
        q.push({i, j});
        // cout <<  i<< " " << j << endl;
      }
    }

  c1 += dc1, c2 -= dc2;
    // printf("%lld %lld %lld %lld\n", c1, c2, r1, r2);
  
  while(q.size()){
    auto t = q.front();
    q.pop();

    int x = t.x, y = t.y;
    for(int i = -d1; i <= d1; i++){
      int a = x + i, b = y + (d1 - abs(i));
      // if(a == r1 || a == r2 || b == c1 || b == c2) continue;
      // if(a < 1 || a > 5 || b < 1 || b > 5) continue;
      // // if(x == 2 && y == 3){
      // //   cout << a << " " << b << endl;
      // // }
      // if(abs(ex - a) + abs(ey - b) == d2){
      //   res.push_back({{x, y}, {a, b}});
      // }

      if(a != r1 && a != r2 && b != c1 && b != c2 && a >= 1 && a <= 5 && b >= 1 && b <= 5){
        if(abs(ex - a) + abs(ey - b) == d2){
          res.push_back({{x, y}, {a, b}});
        }
      }

      b = y - (d1 - abs(i));
      // if(a == r1 || a == r2 || b == c1 || b == c2) continue;
      // if(a < 1 || a > 5 || b < 1 || b > 5) continue;
      // if(x == 2 && y == 3){
      //   cout << a << " " << b << endl;
      // }
      // if(abs(ex - a) + abs(ey - b) == d2){
      //   res.push_back({{x, y}, {a, b}});
      // }

      if(a != r1 && a != r2 && b != c1 && b != c2 && a >= 1 && a <= 5 && b >= 1 && b <= 5){
        if(abs(ex - a) + abs(ey - b) == d2){
          res.push_back({{x, y}, {a, b}});
        }
      }
    }
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  for(int i = 0; i < (int)res.size(); i++){
    printf("%lld %lld %lld %lld\n", res[i].x.x, res[i].x.y, res[i].y.x, res[i].y.y);
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}