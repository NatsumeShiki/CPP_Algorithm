// 给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。

// 输出选择的点的最小数量。

// 位于区间端点上的点也算作区间内。

// 输入格式
// 第一行包含整数 N，表示区间数。

// 接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

// 输出格式
// 输出一个整数，表示所需的点的最小数量。

// 数据范围
// 1≤N≤105,
// −109≤ai≤bi≤109
// 输入样例：
// 3
// -1 1
// 2 4
// 3 5
// 输出样例：
// 2

/*
思路：
  将这些区间按照右端点从小到大排序，然后枚举每一个区间，要知道如果两两区间之间没有交点，那么最少需要的点的个数就是区间的个数，所以如果这一个区间的左端点
  大于上一个区间的右端点，那么它们必定是需要两个点的，然后把这个点的右端点保存下来，继续往右走，拿后面区间的左端点跟它比，如果小于等于它，就说明有公共的
  点，但是如果大于它，那么就更新右端点，继续往后遍历
*/
// 我自己的做法，使用 pair<int, int>
#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII q[N], res[N]; // q是用来保存所有的区间，res是保存两两之间没有交点的区间
int main(){
    int n, index = 0; // index表示res数组的长度
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        q[i] = {r, l};
    }
    
    sort(q, q + n); // 将区间按照右端点从小到大排序
    for(int i = 0; i < n; i++){
        int l = q[i].second, r = q[i].first;
        if(!index || l > res[index - 1].first) res[index++] = {r, l}; // 如果index等于0或者该区间的左端点大于res最后一个区间的右端点，就把这个区间
                                                                      // 放进res中，最终这个res的长度就是答案，也就是index
    }
    cout << index << endl;
    return 0;
}

// 大佬的做法 使用struct
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
struct Range{
    int l, r;
    bool operator < (const Range &W) const{ // 重载小于号，用于排序
        return r < W.r;
    }
}range[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    int res = 0, ed = -2e9; // 一开始的ed要设置的比-1e9更小，保证第一个区间可以更新它
    for(int i = 0; i < n; i++)
        if(range[i].l > ed) res++, ed = range[i].r; // 如果这个区间的左端点大于ed，就让res++，表示需要多一个点，然后把ed更新成该区间的右端点
    cout << res << endl;
    return 0;
}