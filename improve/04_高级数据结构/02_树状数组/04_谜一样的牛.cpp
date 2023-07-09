// 有 n
//  头奶牛，已知它们的身高为 1?n
//  且各不相同，但不知道每头奶牛的具体身高。

// 现在这 n
//  头奶牛站成一列，已知第 i
//  头牛前面有 Ai
//  头牛比它低，求每头奶牛的身高。

// 输入格式
// 第 1
//  行：输入整数 n
// 。

// 第 2..n
//  行：每行输入一个整数 Ai
// ，第 i
//  行表示第 i
//  头牛前面有 Ai
//  头牛比它低。
// （注意：因为第 1
//  头牛前面没有牛，所以并没有将它列出）

// 输出格式
// 输出包含 n
//  行，每行输出一个整数表示牛的身高。

// 第 i
//  行输出第 i
//  头牛的身高。

// 数据范围
// 1≤n≤105
// 输入样例：
// 5
// 1
// 2
// 1
// 0
// 输出样例：
// 2
// 4
// 5
// 3
// 1

/*
先模拟一遍测试用例
最后一头牛前面有0头比他矮，因此从1-5找第一个最小的数，是1，然后划掉他
第四头牛前面有1头比他矮，在剩下的四头牛里面查找第2小的，是3，然后划掉他
以此类推

这道题用树状数组可以使用二分，首先将每个数的当前值都设置为1，从后往前做，查找第k小的数，使用二分，二分的时候查找用过求和来判断第k在什么位置
找到了之后把它划掉
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N]; // 保存第i头牛前面有几头比他唉
int res[N]; // 结果数组
int tr[N]; // 树状数组

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &a[i]); // 从第二头牛开始输入
    for(int i = 1; i <= n; i++) tr[i] = lowbit(i); // 求和，也可以是add(i, 1)，这是一种特殊 情况，可以直接使用lowbit(i)
    for(int i = n; i; i--){ // 从后往前做
        int x = a[i] + 1; // 获取它是第几矮
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(sum(mid) >= x) r = mid; // 如果排名大于等于x，右边界设置为mid
            else l = mid + 1;
        }
        res[i] = l; 
        add(l, -1); // 划掉他
    }
    for(int i = 1; i <= n; i++) printf("%d\n", res[i]);
    
    return 0;
}