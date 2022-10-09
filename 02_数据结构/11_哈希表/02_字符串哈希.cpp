// 给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 [l1,r1] 和 [l2,r2] 这两个区间所包含的字符串子串是否完全相同。

// 字符串中只包含大小写英文字母和数字。

// 输入格式
// 第一行包含整数 n 和 m，表示字符串长度和询问次数。

// 第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。

// 接下来 m 行，每行包含四个整数 l1,r1,l2,r2，表示一次询问所涉及的两个区间。

// 注意，字符串的位置从 1 开始编号。

// 输出格式
// 对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 Yes，否则输出 No。

// 每个结果占一行。

// 数据范围
// 1≤n,m≤105
// 输入样例：
// 8 3
// aabbaabb
// 1 3 5 7
// 1 3 6 8
// 1 2 1 2
// 输出样例：
// Yes
// No
// Yes

#include<iostream>
using namespace std;

typedef unsigned long long ULL; // 目的是溢出的效果相当于取模
const int N = 100010, P = 131;
char str[N];
ULL p[N], h[N]; // h[p]是预处理的前缀哈希值，因为值可能会很大，所以要mod一个数，用2^64合适，但是用ULL存储相当于mod2^64了
// p数组用来存储p的多少次方

ULL get(int l, int r){
  return h[r] - h[l - 1] * p[r - l + 1]; 
}

int main(){
  int n, m;
  cin >> n >> m >> str + 1;
  p[0] = 1;
  for(int i = 1; i <= n; i++){
    p[i] = p[i - 1] * P;
    h[i] = h[i - 1] * P + str[i];
  }
  while(m--){
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}