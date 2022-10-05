#include<iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];
int n, m, x;

int find(int k){
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(b[mid] > k) r = mid - 1;
        else if(b[mid] < k) l = mid + 1;
        else return mid;
    }
    return -1;
}

int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    for(int i = 0; i < n; i++){
        int j = find(x - a[i]);
        if(j != -1){
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}