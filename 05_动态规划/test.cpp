#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e7 + 10;
char s[N];

int main(){
  cin >> s;
  // cout << s << endl;
  bool flag = true;
  for(int i = 1; s[i]; i++){
    if(s[i] != s[i - 1]){
      flag = false;
      break;
    }
  }
  if(flag){
    cout << 0;
    return 0;
  }

  queue<int> q;
  queue<char> a;
  char ch[6] {'A', 'B', 'C', 'D', 'E', 'F'};
  for(int i = 0; i < 6; i++){
    for(int j = 0; s[j]; j++)
      if(s[j] == ch[i]) q.push(j);
    if(q.size()) break;
  }
  if(q.size() == 1){
    cout << q.front() << endl;
    return 0;
  }
  // for(int i = 0; i < q.size(); i++) cout << q[i] << endl;
  while(q.size()){
    int x = q.front();
    cout << x << endl;
    int index = ((x + (s[x] - 'A' + 1)) % 4);
    a.push(s[index]);
    q.pop();
  }
  return 0;
}

// const int N = 110;
// int a[N][N], f[N][N];

// int main(){
//   a[1][1] = 1;
//   int n = 100;
//   for(int i = 2; i <= n; i++) a[i][1] = a[i - 1][1] + 1;
//   for(int i = 1; i <= n; i++)
//     for(int j  = 2; j <= n; j++)
//       a[i][j] = a[i][j - 1] + 2;
//   for(int i = 1; i <= n; i++)
//     for(int j = 1; j <= n; j++)
//       f[i][j] = f[i-1][j] + f[i][j - 1] - f[i-1][j-1] + a[i][j];
//   // cout << f[1][1] << " " << f[1][2] << endl;
//   // cout << f[2][1] << " " << f[2][2] << endl;
//   int min = 1e9;
//   for(int i = 1; i <= n; i++)
//     for(int j = 1; j <= n; j++)
//       for(int k = 0; k < i; k++)
//         for(int t = 0; t < j; t++)
//           if(f[i][j] - f[k][j] - f[i][t] + f[k][t] == 2022){
//             // cout << i << " " << j << " " << k << " " << t << " " << endl;
//             if((i - k + 1) * (j - t + 1) < min) {
//               cout << i << " " << j << " " << k << " " << t << " " << endl;
//               // cout << a[i][j] << " " << a[k][t] << endl;
//               min = (i - k + 1) * (j - t + 1);
//               // cout << f[i][j] - f[k][j] - f[t][i] + f[k][t] << endl;
//             }
//             break;
//           }
//   cout << min << endl;
//   int res = 0;
//   for(int i = 1; i <= 4; i++)
//     for(int j = 83; j <= 85; j++)
//       res += a[i][j];
//   cout << res << endl;
// }




// int day[3] = {1, 11, 21};

// int main(){
//   int res = 0;
//   res += 365 / 7;
//   // cout << res << endl;
//   if(365 % 7 <= 2) res += 365 % 7;
//   else res += 2;
//   // cout << res << endl;
//   int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//   for(int i = 1; i <= 12; i++){
//     a[i] += a[i - 1];
//     // cout << a[i] << endl;
//   }
    
//   for(int i = 1; i <= 12; i++){
//     int x = a[i - 1];
//     for(int j = 0; j < 3; j++)
//       if((x + day[j]) % 7 != 1 && (x + day[j]) % 7 != 2) res++;
//     if((a[i] - x) == 31 && (x + 31) % 7 != 1 && (x + 31) % 7 != 2) res++;
//   }
//   cout << res << endl;
//   return 0; 
// }