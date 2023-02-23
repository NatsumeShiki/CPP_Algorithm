// 给定一个由 n
//  个小写字母构成的字符串。

// 现在，需要删掉其中的一些字母，使得字符串中不存在连续三个或三个以上的 x。

// 请问，最少需要删掉多少个字母？

// 如果字符串本来就不存在连续的三个或三个以上 x，则无需删掉任何字母。

// 输入格式
// 第一行包含整数 n
// 。

// 第二行包含一个长度为 n
//  的由小写字母构成的字符串。

// 输出格式
// 输出最少需要删掉的字母个数。

// 数据范围
// 3≤n≤100
// 输入样例1：
// 6
// xxxiii
// 输出样例1：
// 1
// 输入样例2：
// 5
// xxoxx
// 输出样例2：
// 0
// 输入样例3：
// 10
// xxxxxxxxxx
// 输出样例3：
// 8

// 自己的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
char str[N];
int n;

int main(){
    cin >> n >> str + 1;
    int res = 0;
    for(int i = 1; i <= n; ){
        if(str[i] == 'x'){
            int start = i;
            while(i <= n && str[i] == 'x') i++;
            if(i - start >= 3) res += (i - start - 2);
        }else i++;
    }
    cout << res << endl;
    
    return 0;
}

// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 'x') continue;
        int j = i + 1;
        while(j < n && s[j] == 'x') j++;
        res += max(0, j - i - 2);
        i = j;
    }
    cout << res << endl;
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string str;

void update(char& c)
{
    if (c == 'W') c = 'B';
    else c = 'W';
}

bool check(char c)
{
    vector<int> res;
    string s = str;
    for (int i = 0; i + 1 < n; i ++ )
        if (s[i] != c)
        {
            update(s[i]);
            update(s[i + 1]);
            res.push_back(i);
        }

    if (s.back() != c) return false;

    cout << res.size() << endl;
    for (int x: res) cout << x + 1 << ' ';
    if (res.size()) cout << endl;

    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n >> str;
        if (!check('B') && !check('W')) puts("-1");
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/5532758/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。