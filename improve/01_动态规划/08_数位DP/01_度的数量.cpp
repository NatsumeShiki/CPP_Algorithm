// 求给定区间 [X,Y]
//  中满足下列条件的整数个数：这个数恰好等于 K
//  个互不相等的 B
//  的整数次幂之和。

// 例如，设 X=15,Y=20,K=2,B=2
// ，则有且仅有下列三个数满足题意：

// 17=24+20

// 18=24+21

// 20=24+22
// 输入格式
// 第一行包含两个整数 X
//  和 Y
// ，接下来两行包含整数 K
//  和 B
// 。

// 输出格式
// 只包含一个整数，表示满足条件的数的个数。

// 数据范围
// 1≤X≤Y≤231−1
// ,
// 1≤K≤20
// ,
// 2≤B≤10
// 输入样例：
// 15 20
// 2
// 2
// 输出样例：
// 3

/*
            /           \
        0~a(n-1)-1    a(n-1)
                    /        \ 
            0~a(n-2)-1       a(n-2)
                        .
                        .
                        .
                        0~a(0)-1         a(0)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35; // 最小是二进制，数字范围是 1 ~ 2^31 所以数组要设置比31大
int K, B; // K是k个1，B是B进制
int f[N][N]; // 保存组合数，f[a, b]表示从a个数中选择b个数分方案数

void init(){ // 记录组合数
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(!j) f[i][j] = 1; // 从i个数中选择0个数，方案有1种
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}

int dp(int n){
    if(!n) return 0; // 如果上界为0，那么就没有满足要求的
    
    vector<int> nums;
    while(n) nums.push_back(n % B), n /= B; // 把n分解成B进制保存在nums中
    
    int res = 0; // 记录最终的方案总数
    int last = 0; // 记录右分支中已经存了last个1
    for(int i = nums.size() - 1; i >= 0; i--){ // 从大枚举到小
        int x = nums[i]; // 当前位
        if(x){ // 如果x大于0，才有左右两侧的分支
            res += f[i][K - last]; // 这个是左侧分支第i为选择0的方案，此时在0~i-1中选择K-last个1，也就是f[i, K - last]
            if(x > 1){ // 如果x大于1
                if(K - last - 1 >= 0) res += f[i][K - last - 1]; // 这个是左分支中第i为选择1的方案，于是在0~i-1中选择K-last-1个1，也就是f[i, K-last-1]
                break; // 如果x大于1了，不符合题目要求只能有1或者0，所以退出循环
            }else{ // 否则，x等于1，进入右侧分支，第i为存放1，则last++，表示已经使用了last个1，那么后面只能使用K-last个1
                last++;
                if(last > K) break; // 如果使用的1大于给与的1，不符合题目，退出循环
            }
        }
        if(!i && last == K) res++; // 这个是右侧分支的最后一个，也就是下标为0的位置，此时只剩下只一种方案了，但是如果这种方案要成立，条件是使用了K个1
        // 所以只要走到这里了，并且条件也满足，也就是说这是一种可行的方案，比如说1111和1110，在前面都不会经过break，到了最后一步前者last++，而后者last
        // 不会++，但是只要给与的1和使用的1相等，他就是合法的方案，于是把它加进res
    }
    return res; // 最终返回方案数
}

int main(){
    init();
    
    int l, r;
    cin >> l >> r >> K >> B;
    
    cout << dp(r) - dp(l - 1) << endl; // 使用前缀和的思想，l-r中满足要求的数等于 0~r - 0~l-1 的个数
    
    return 0;
}