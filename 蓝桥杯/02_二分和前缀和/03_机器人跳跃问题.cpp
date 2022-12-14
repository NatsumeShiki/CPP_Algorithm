// 机器人正在玩一个古老的基于 DOS 的游戏。

// 游戏中有 N+1 座建筑——从 0 到 N 编号，从左到右排列。

// 编号为 0 的建筑高度为 0 个单位，编号为 i 的建筑高度为 H(i) 个单位。

// 起初，机器人在编号为 0 的建筑处。

// 每一步，它跳到下一个（右边）建筑。

// 假设机器人在第 k 个建筑，且它现在的能量值是 E，下一步它将跳到第 k+1 个建筑。

// 如果 H(k+1)>E，那么机器人就失去 H(k+1)−E 的能量值，否则它将得到 E−H(k+1) 的能量值。

// 游戏目标是到达第 N 个建筑，在这个过程中能量值不能为负数个单位。

// 现在的问题是机器人至少以多少能量值开始游戏，才可以保证成功完成游戏？

// 输入格式
// 第一行输入整数 N。

// 第二行是 N 个空格分隔的整数，H(1),H(2),…,H(N) 代表建筑物的高度。

// 输出格式
// 输出一个整数，表示所需的最少单位的初始能量值上取整后的结果。

// 数据范围
// 1≤N,H(i)≤105,

// 输入样例1：
// 5
// 3 4 3 2 4
// 输出样例1：
// 4
// 输入样例2：
// 3
// 4 4 4
// 输出样例2：
// 4
// 输入样例3：
// 3
// 1 6 4
// 输出样例3：
// 3

// 方法一
// 这是利用倒推的方式，如果h[i+1]>e，则e=e-(h[i+1]-e)=2e-h[i+1]，如果h[i+1]<=e，则e=e+(e-h[i-1])=2e-h[i-1]，都是一样的，所以从后往前递推，要获取临界值
// 则必然如果最终的能量为0是临界的，设置为x，那么就从后往前执行e=h[i]+x+1 >> 1，加1是为了向上取整
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int x = 0;
    for(int i = n; i > 0; i--){
        x = x + h[i] + 1 >> 1;
    }
    cout << x << endl;
    return 0;
}

// 方法二 
// 利用二分，从0-1e5二分，获取中间值，如果中间值满足题目所给的性质，就让r=mid，否则让l=mid+1
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int l = 0, r = 1e5;
    while(l < r){
        int mid = l + r >> 1;
        int x = mid;
        bool flag = true;
        for(int i = 1; i <= n; i++){
            x = 2 * x - h[i];
            if(x > 1e5) break;
            if(x < 0) {
                flag = false;
                break;
            }
        }
        if(flag) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}

// 大佬的写法
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N];
int n;

bool check(int e){
    for(int i = 1; i <= n; i++){
        e = 2 * e - h[i];
        if(e > 1e5) return true;
        if(e < 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int l = 0, r = 1e5;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}