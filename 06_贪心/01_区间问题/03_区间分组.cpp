// 给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

// 输出最小组数。

// 输入格式
// 第一行包含整数 N，表示区间数。

// 接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

// 输出格式
// 输出一个整数，表示最小组数。

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
做法：
  1. 把所有区间按左端点从小到大排序
  2. 从前往后处理每个区间
        判断能否将其放到现有的组中
          (1)、如果不存在这样的组，则开新组，然后在将其放进去
          (2)、如果存在这样的组，就将它放进去，并更新当前组的Max_r
  Max_r的意思是在这一组中有多个区间，这些区间中r最大的那个即为Max_r

  证明略，因为我也说不清
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 100010;
int n;
struct Range{
    int l, r;
    bool operator < (const Range &W)const{
        return l < W.l;
    }
}range[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int>> heap; // 创建小根堆，用来保存所有组的Max_r
    for(int i = 0; i < n; i++){
        auto r = range[i];
        if(heap.empty() || heap.top() >= r.l) heap.push(r.r); // 如果当前小根堆是空的或者小根堆的根节点都大于给区间的左端点，就开一个新组，然后把它的
                                                              // 右端点push进去
        else {
            heap.pop(); // 如果所有组的Max_r最小的r是小于该区间的l的，就把他放进这个区间，并更新heap
            heap.push(r.r);
        }
    }
    cout << heap.size() << endl; // 最后，这个小根堆的size就是答案
    return 0;
}