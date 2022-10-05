// 给定一个长度为 n 的整数序列 a1,a2,…,an 以及一个长度为 m 的整数序列 b1,b2,…,bm。

// 请你判断 a 序列是否为 b 序列的子序列。

// 子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5} 是序列 {a1,a2,a3,a4,a5} 的一个子序列。

// 输入格式
// 第一行包含两个整数 n,m。

// 第二行包含 n 个整数，表示 a1,a2,…,an。

// 第三行包含 m 个整数，表示 b1,b2,…,bm。

// 输出格式
// 如果 a 序列是 b 序列的子序列，输出一行 Yes。

// 否则，输出 No。

// 数据范围
// 1≤n≤m≤105,
// −109≤ai,bi≤109
// 输入样例：
// 3 5
// 1 3 5
// 1 2 3 4 5
// 输出样例：
// Yes

// 思路：用两个指针分别指向a和b，如果a[i] == b[j]，两个指针都往后，否则，j往后，直到 i < n && j < m 这个条件不成立为止
//      然后判断i是否等于n，如果等于说明匹配成功，否则匹配失败
#include<iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main(){
int n, m;
cin >> n >> m;
for(int i = 0; i < n; i++) cin >> a[i];
for(int i = 0; i < m; i++) cin >> b[i];

int i = 0, j = 0;
while(i < n && j < m){
  if(a[i] == b[j]){
      i++;
      j++;
  }else{
      j++;
  }
}
if(i == n){
  cout << "Yes";
}else{
  cout << "No";
}

return 0;
}