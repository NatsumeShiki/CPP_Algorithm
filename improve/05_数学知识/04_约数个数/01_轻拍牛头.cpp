// 今天是贝茜的生日，为了庆祝自己的生日，贝茜邀你来玩一个游戏．

// 贝茜让 N
//  头奶牛（编号 1
//  到 N
// ）坐成一个圈。

// 除了 1
//  号与 N
//  号奶牛外，i
//  号奶牛与 i?1
//  号和 i+1
//  号奶牛相邻，N
//  号奶牛与 1
//  号奶牛相邻。

// 农夫约翰用很多纸条装满了一个桶，每一张纸条中包含一个 1
//  到 1000000
//  之间的数字。

// 接着每一头奶牛 i
//  从桶中取出一张纸条，纸条上的数字用 Ai
//  表示。

// 所有奶牛都选取完毕后，每头奶牛轮流走上一圈，当走到一头奶牛身旁时，如果自己手中的数字能够被该奶牛手中的数字整除，则拍打该牛的头。

// 牛们希望你帮助他们确定，每一头奶牛需要拍打的牛的数量。

// 即共有 N
//  个整数 A1,A2,…,AN
// ，对于每一个数 Ai
// ，求其他的数中有多少个是它的约数。

// 输入格式
// 第一行包含整数 N
// 。

// 接下来 N
//  行，每行包含一个整数 Ai
// 。

// 输出格式
// 共 N
//  行，第 i
//  行的数字为第 i
//  头牛需要拍打的牛的数量。

// 数据范围
// 1≤N≤105
// ,
// 1≤Ai≤106
// 输入样例：
// 5
// 2
// 1
// 2
// 3
// 4
// 输出样例：
// 2
// 0
// 2
// 1
// 3

// 方法一
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int arr[N], cnt[N];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        int res = 0;
        for(int j = 1; j * j <= arr[i]; j++){
            if(arr[i] % j == 0){
                res += cnt[j];
                if(j != arr[i] / j) res += cnt[arr[i] / j];
            }
        }
        cout << res - 1 << endl;
    }
    
    
    return 0;
}

// 方法二 先将每个数累加到cnt上，然后双重循环，将某一个数的所有倍数都加上它的数量，比如当前数是2，那就将所有2的倍数都加上2的数量
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int arr[N], cnt[N];
int n;
int ans[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    
    for(int i = 1; i <= 1e6; i++)
        for(int j = i; j <= 1e6; j += i)
            ans[j] += cnt[i];
            
    for(int i = 0; i < n; i++) cout << ans[arr[i]] - 1 << endl;
    
    
    return 0;
}