// 给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。

// 输入格式
// 第一行包含整数 n。

// 第二行包含 n 个整数，表示整个数列。

// 输出格式
// 共一行，包含 n 个整数，其中的第 i 个数表示数列中的第 i 个数的二进制表示中 1 的个数。

// 数据范围
// 1≤n≤100000,
// 0≤数列中元素的值≤109
// 输入样例：
// 5
// 1 2 3 4 5
// 输出样例：
// 1 1 2 1 2

// lowbit(x):返回x的最后一位1
// 比如说 x = 1010，lowbit(1010) = 10; x = 1001000, lowbit(x) = 1000
// 可以用公式：x & -x
// -x是x的按位取反然后加上1，所以 -x = ~x + 1
// 比如说 x = 1001000
// ~x = 01101111
// ~x + 1 = 0111000
// x & -x = 0001000
// 利用这个性质可以计算一个数的二进制中有多少个1

#include<iostream>
using namespace std;

int lowbit(int x){
  return x & -x;
}

int main(){
  int n;
  cin >> n;
  
  while(n--){
    int x;
    cin >> x;
    int count = 0;
    while(x){
      x -= lowbit(x); // 每次除去x的最后一个1
      count++;
    }
    cout << count << " ";
  }

  return 0;
}

// 方法二：
#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int count(int x){
    int res = 0;
    for(int i = 0; i < 31; i++)
        if(x >> i & 1)
            res++;
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << count(x) << " ";
    }
    
    return 0;
}