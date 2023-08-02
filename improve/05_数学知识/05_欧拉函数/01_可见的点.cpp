// ��һ��ƽ��ֱ������ϵ�ĵ�һ�����ڣ����һ���� (x,y)
//  ��ԭ�� (0,0)
//  ��������û��ͨ�������κε㣬��Ƹõ���ԭ�㴦�ǿɼ��ġ�

// ���磬�� (4,2)
//  ���ǲ��ɼ��ģ���Ϊ����ԭ������߻�ͨ���� (2,1)
// ��

// ���ֿɼ�����ԭ�����������ͼ��ʾ��

// 3090_1.png

// ��дһ�����򣬼���������� N
//  ������£����� 0��x��y��N
//  �Ŀɼ��� (x��y)
//  ���������ɼ��㲻����ԭ�㣩��

// �����ʽ
// ��һ�а������� C
// ����ʾ���� C
//  ��������ݡ�

// ÿ���������ռһ�У�����һ������ N
// ��

// �����ʽ
// ÿ��������ݵ����ռ��һ�С�

// Ӧ�������������ݵı�ţ��� 1
//  ��ʼ��������������ݶ�Ӧ�� N
//  �Լ��ɼ����������

// ͬ������֮���ÿո������

// ���ݷ�Χ
// 1��N,C��1000
// ����������
// 4
// 2
// 4
// 5
// 231
// ���������
// 1 2 5
// 2 4 13
// 3 5 21
// 4 231 32549

/*
���½��±��0��ʼ���������ʵ������Կ����������ʹ��ŷ���������ÿ�����Ļ��ʵ����ĸ���
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int ans[N];
int n;
int primes[N], cnt;
bool st[N];

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void get(int n){
    int t = n;
    int sum = n;
    for(int i = 0; i < cnt && primes[i] <= t; i++){
        int p = primes[i];
        if(t % p == 0){
            int s = 0;
            while(t % p == 0) t /= p, s++;
            sum = sum * (p - 1) / p;
        }
    }
    if(t > 1) sum = sum * (t - 1) / t;
    ans[n] = sum;
}

int main(){
    init(N - 1);
    for(int i = 1; i < N; i++){
        get(i);
    }
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++) res += ans[i];
        printf("%d %d %d\n", i, n, res * 2 + 1);
    }
    
    return 0;
}

// ʹ������ɸŷ������
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int primes[N], cnt;
bool st[N];
int phi[N];

void init(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}


int main(){
    init(N - 1);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++) res += phi[i];
        printf("%d %d %d\n", i, n, res * 2 + 1);
    }
    
    return 0;
}