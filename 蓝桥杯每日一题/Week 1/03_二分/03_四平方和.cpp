// 四平方和定理，又称为拉格朗日定理：

// 每个正整数都可以表示为至多 4
//  个正整数的平方和。

// 如果把 0
//  包括进去，就正好可以表示为 4
//  个数的平方和。

// 比如：

// 5=02+02+12+22

// 7=12+12+12+22
// 对于一个给定的正整数，可能存在多种平方和的表示法。

// 要求你对 4
//  个数排序：

// 0≤a≤b≤c≤d
// 并对所有的可能表示法按 a,b,c,d
//  为联合主键升序排列，最后输出第一个表示法。

// 输入格式
// 输入一个正整数 N
// 。

// 输出格式
// 输出4个非负整数，按从小到大排序，中间用空格分开。

// 数据范围
// 0<N<5∗106
// 输入样例：
// 5
// 输出样例：
// 0 0 1 2

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e6 + 10;
struct Sum{
    int s, c, d;
    bool operator<(Sum &t) const{
        if(s != t.s) return s < t.s;
        if(c != t.c) return c < t.c;
        return d < t.d;
    }
}sum[N];
int n, m;

int main(){
    cin >> n;
    for(int a = 0; a * a <= n; a++)
        for(int b = a; a * a + b * b <= n; b++)
            sum[m++] = {a * a + b * b, a, b};
    sort(sum, sum + m);
            
    for(int a = 0; a * a <= n; a++)
        for(int b = a; a * a + b * b <= n; b++){
            int t = n - a * a - b * b;
            int l = 0, r = m;
            while(l < r){
                int mid = l + r >> 1;
                if(sum[mid].s >= t) r = mid;
                else l = mid + 1;
            }
            if(sum[l].s == t) {
                printf("%d %d %d %d\n", a, b, sum[l].c, sum[l].d);
                return 0;
            }
        }
    
    return 0;
}