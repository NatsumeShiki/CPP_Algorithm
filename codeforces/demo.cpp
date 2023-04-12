#include<iostream>
using namespace std;

const int N = 110;
char s[N][N];
int n, m;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> s[i];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m - 1;){
      if(s[i][j] == s[i][j + 1] && s[i][j] == 'T'){
        s[i][j] = 'P';
        s[i][j + 1] = 'C';
        j += 2;
      }else j++;
    }

  for(int i = 0; i < n; i++) cout << s[i] << endl;

  return 0;
}