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

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;
int K, B;
int f[N][N];

void init(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(!j) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}

int dp(int n){
    if(!n) return 0;
    
    vector<int> nums;
    while(n) nums.push_back(n % B), n /= B;
    
    int res = 0;
    int last = 0;
    for(int i = nums.size() - 1; i >= 0; i--){
        int x = nums[i];
        if(x){
            res += f[i][K - last];
            if(x > 1){
                if(K - last - 1 >= 0) res += f[i][K - last - 1];
                break;
            }else{
                last++;
                if(last > K) break;
            }
        }
        if(!i && last == K) res++;
    }
    return res;
}

int main(){
    init();
    
    int l, r;
    cin >> l >> r >> K >> B;
    
    cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}