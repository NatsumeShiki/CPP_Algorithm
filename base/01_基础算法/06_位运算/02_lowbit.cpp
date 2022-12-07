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

int main(){

}