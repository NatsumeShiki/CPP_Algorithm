#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL a[N];

int main(){
    int n;
    LL k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 2;
    LL x = a[l] + k;
    while(r <= n && a[r] < x / (r - 1)) x += a[r++];
    cout << x / (r - 1) << endl;
    return 0;
}