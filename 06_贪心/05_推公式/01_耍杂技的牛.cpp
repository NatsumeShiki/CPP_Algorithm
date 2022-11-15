// 农民约翰的 N 头奶牛（编号为 1..N）计划逃跑并加入马戏团，为此它们决定练习表演杂技。

// 奶牛们不是非常有创意，只提出了一个杂技表演：

// 叠罗汉，表演时，奶牛们站在彼此的身上，形成一个高高的垂直堆叠。

// 奶牛们正在试图找到自己在这个堆叠中应该所处的位置顺序。

// 这 N 头奶牛中的每一头都有着自己的重量 Wi 以及自己的强壮程度 Si。

// 一头牛支撑不住的可能性取决于它头上所有牛的总重量（不包括它自己）减去它的身体强壮程度的值，现在称该数值为风险值，风险值越大，这只牛撑不住的可能性越高。

// 您的任务是确定奶牛的排序，使得所有奶牛的风险值中的最大值尽可能的小。

// 输入格式
// 第一行输入整数 N，表示奶牛数量。

// 接下来 N 行，每行输入两个整数，表示牛的重量和强壮程度，第 i 行表示第 i 头牛的重量 Wi 以及它的强壮程度 Si。

// 输出格式
// 输出一个整数，表示最大风险值的最小可能值。

// 数据范围
// 1≤N≤50000,
// 1≤Wi≤10,000,
// 1≤Si≤1,000,000,000
// 输入样例：
// 3
// 10 3
// 2 5
// 3 3
// 输出样例：
// 2

// 我写的代码
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 50010;

struct Caw{
    int W;
    LL S;
    LL total;
    bool operator < (const Caw & c)const{
        return total < c.total;
    }
}caws[N];
int W[N]; // 保存牛的重量的前缀和

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        LL b;
        cin >> a >> b;
        caws[i] = {a, b, a + b};
    }
    sort(caws + 1, caws + n + 1);
    for(int i = 1; i <= n; i++) W[i] = W[i - 1] + caws[i].W; // 计算前缀和
    LL res = -1e9;
    for(int i = 1; i <= n; i++) res = max(res, W[i - 1] - caws[i].S);
    cout << res << endl;
    
    return 0;
}

// 大佬写的
/*
直接说结论：按照 wi + si 从小到大的顺序排，最大的危险系数一定是最小的
贪心得到的答案 >= 最优解
贪心得到的答案 <= 最优解
如果证明了上面两个成立，那么该贪心做法就是最优解
假设现在就按照结论那么做，一开始 wi + si > w(i+1) + s(i+1)
                   第i个位置上的牛                           第i+1个位置上的牛
交换前       w1 + w2 + ... + w(i-1) - si                 w1 + ... + wi - s(i+1)
交换后        w1 + ... + w(i-1) - s(i+1)             w1 + ... + w(i-1) + w(i+1) - si

将w1 + ... + w(i-1)清理后
          第i个位置上的牛      第i+1个位置上的牛
交换前        -si                wi - s(i+1)
交换后      -s(i+1)              w(i+1) - si

然后再把四个数都加上 si + s(i+1)
          第i个位置上的牛      第i+1个位置上的牛
交换前        s(i+1)               wi + si
交换后          si              w(i+1) s(i+1)

这么做是把原来非升序变成了升序，可以看出来 wi + si > si, wi + si > w(i+1) + s(i+1)，它的危险系数是变小了，这么做的话保证了所有危险系数是不会变大的，
那么在一开始没有排序的情况下，每次进行排序，让它变成升序，它的危险系数最大值是不会变大的，要么变小，要么不变，这也就使得贪心得到的答案小等于最优解
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 50010;
PII cow[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int w, s;
        cin >> w >> s;
        cow[i] = {w + s, w}; // 根据 w+s 进行升序排序
    }
    sort(cow, cow + n);
    
    int res = -2e9, sum = 0; // sum是计算前i头牛的重量
    for(int i = 0; i < n; i++){
        int w = cow[i].second, s = cow[i].first - w;
        res = max(res, sum - s); // sum是前i-1头牛的中量，减去第i头牛的s，就是危险系数
        sum += w; // 比较完了之后再把这头牛的重量加上
    }
    cout << res << endl;
    return 0;
}