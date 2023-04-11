// #include<iostream>
// #include<cstring>
// using namespace std;

// int gcd(int a, int b){
//   return b ? gcd(b, a % b) : a;
// }

// int main(){
//   int t;
//   cin >> t;
//   while(t--){
//     int a, b;
//     cin >> a >> b;
//     int c = gcd(a, b);
//     if(c == 1){
//       printf("1\n%d %d\n", a, b);
//     }else{
//       for(int i = 1; i < a; i++){
//         bool flag = false;
//         for(int j = 1; j < b; j++){
//           int x1 = i, y1 = j;
//           int x2 = (a - i), y2 = (b - j);
//           if(gcd(x1, y1) == 1 && gcd(x2, y2) == 1){
//             printf("2\n%d %d\n%d %d\n", i, j, a, b);
//             flag = true;
//             break;
//           }
//         }
//         if(flag) break;
//       }
//     }
//   }

//   return 0;
// }

#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int res = 0;
    while(n--){
      int x;
      scanf("%d", &x);
      // cin >> x;
      res += x;
    }
    // cout << res << endl;
    printf("%d\n", res);
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}