// 在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。

// 现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

// 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

// 输入格式
// 第一行输入整数 N。

// 第二行 N 个整数 A1∼AN。

// 输出格式
// 输出一个整数，表示距离之和的最小值。

// 数据范围
// 1≤N≤100000,
// 0≤Ai≤40000
// 输入样例：
// 4
// 6 2 9 1
// 输出样例：
// 12

// 我自己写得代码
// 要让货仓到每个商店距离之和最小，第一个想到的就是在中间，也可以证明出来，所以就让坐标排个序，然后每次让最后面的坐标减去最前面的坐标，直到中间
// 因为如果建到中间x，左边一个商店坐标是a，右边一个是b，那么距离就是x - a + b - x = b - a
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    LL res = 0;
    for(int i = 0; i < n / 2; i++)
        res += a[n - i - 1] - a[i];
        
    cout << res << endl;
    
    return 0;
}

// 大佬的代码
// 先求仓库的位置是 x[n/2]，如果n是奇数，那么就是中间仓库的位置，如果n是偶数，那么就是中间两个仓库右边那个，最后累加每个仓库到中间仓库的距离即可
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n;
int x[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    sort(x, x + n);
    
    int c = x[n / 2];
    LL res = 0;
    for(int i = 0; i < n; i++) res += abs(x[i] - c);
    
    printf("%lld\n", res);
    
    return 0;
}