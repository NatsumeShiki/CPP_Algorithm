#include<iostream>
#include<cstring>
#include<set>
using namespace std;

typedef long long LL;
const int N = 1010;
int a[N], b[N], c[N], d[N];
int n;
multiset<int> S;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            S.insert(c[i] + d[j]);
//             cout << c[i] + d[j] << " ";
        }
//     cout << endl;
    
    LL res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res += S.count(-a[i] - b[j]);
    
    printf("%d",res);
    
    
    return 0;
}