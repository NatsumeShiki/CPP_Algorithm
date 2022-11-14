// 给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

// 输出最少区间数，如果无法完全覆盖则输出 −1。

// 输入格式
// 第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。

// 第二行包含整数 N，表示给定区间数。

// 接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

// 输出格式
// 输出一个整数，表示所需最少区间数。

// 如果无解，则输出 −1。

// 数据范围
// 1≤N≤105,
// −109≤ai≤bi≤109,
// −109≤s≤t≤109
// 输入样例：
// 1 5
// 3
// -1 3
// 2 4
// 3 5
// 输出样例：
// 2

/*
1. 将所有区间按左端点从小到大排序
2. 从前往后依次枚举每个区间，在所有能覆盖start的区间中，选择右端点最大的的区间，然后将start更新成右端点的最大值
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
struct Range{
    int l, r;
    bool operator < (const Range &W) const{
        return l < W.l;
    }
}range[N];

int main(){
    int st, ed, n;
    cin >> st >> ed >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n); // 按左端点从小到大排序
    int res = 0;
    bool success = false; // 默认先把是否能全覆盖设置为false
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9; // 为了保证当还没有一个区间时，可以覆盖开头，把r设置成比最小值还小
        while(j < n && range[j].l <= st){ // 这个循环是在所有能覆盖st的区间中，选择右端点最大的区间
            r = max(r, range[j].r);
            j++;
        }
        if(r < st){ // 如果右端点最大也没有比r大，说明无法全覆盖
            res = -1;
            break;
        }
        res++; // 把需要的区间数加1
        if(r >= ed){ // 如果此时已经全覆盖了，就退出循环，res就是需要区间的最小值
            success = true;
            break;
        }
        st = r; // 更新右端点
        i = j - 1; // 就像第一个区间一样，首先要使用它自身
    }
    if(!success) res = -1; // 如果使用了所有区间，但是在循环过程中并没有改变success，就说明没有全覆盖
    cout << res << endl;
}