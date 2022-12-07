// 给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

// 注意如果在端点处相交，也算有交集。

// 输出合并完成后的区间个数。

// 例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含两个整数 l 和 r。

// 输出格式
// 共一行，包含一个整数，表示合并区间完成后的区间个数。

// 数据范围
// 1≤n≤100000,
// −109≤li≤ri≤109
// 输入样例：
// 5
// 1 2
// 2 4
// 5 6
// 7 8
// 7 9
// 输出样例：
// 3

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
int n;
vector<PII> segs;

void merge(vector<PII> &segs){
  int st = -2e9, ed = -2e9;
  sort(segs.begin(), segs.end());
  vector<PII> res;

  for(auto seg: segs){
    if(ed < seg.first){
      if(st != -2e9) res.push_back({st, ed}); // 此时说明st已经改变了，并且当前区间与从segs中取出的区间并不存在并集，所以要push进去
      st = seg.first, ed = seg.second; // 更新st，ed
    }else{
      ed = max(ed, seg.second); // 此时要更新右边界
    }
  }
  if(st != -2e9) res.push_back({st, ed}); // 主要是为了防止控制台没有输入，如果有输入此时需要把最后一组也push进去
  segs = res;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int l, r;
    cin >> l >> r;
    segs.push_back({l, r});
  }

  merge(segs);

  cout << segs.size() << endl;

  return 0;
}