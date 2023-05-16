// �� N
//  �����ӣ�ÿ��������д��һ������Сд��ĸ��ɵ�Ӣ�ĵ��ʡ�

// ����Ҫ����Щ���Ӱ���һ�����ʵ�˳��ʹ���������������У�ǰһ�������ϵ��ʵ�ĩ��ĸ���ں�һ�������ϵ��ʵ�����ĸ��

// �����дһ�������ж��Ƿ��ܴﵽ��һҪ��

// �����ʽ
// ��һ�а������� T
// ����ʾ���� T
//  ��������ݡ�

// ÿ�����ݵ�һ�а������� N
// ����ʾ����������

// ������ N
//  �У�ÿ�а���һ��Сд��ĸ�ַ�������ʾһ�������ϵĵ��ʡ�

// һ�����ʿ��ܳ��ֶ�Ρ�

// �����ʽ
// ������ںϷ��⣬�������Ordering is possible.�������������The door cannot be opened.����

// ���ݷ�Χ
// 1��N��105
// ,
// ���ʳ��Ⱦ�������1000

// ����������
// 3
// 2
// acm
// ibm
// 3
// acm
// malform
// mouse
// 2
// ok
// ok
// ���������
// The door cannot be opened.
// Ordering is possible.
// The door cannot be opened.

// ��ÿ�������ϣ�����һ����ĸ�����һ����ĸ����һ������ߣ�Ȼ���ж��Ƿ����ŷ��·��
#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;
int n;
int din[N], dout[N], p[N]; // ����������������������͸��ڵ�
bool st[N]; // ������ĸ�Ƿ�ʹ�ù���

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    char str[1010];
    
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(st, 0, sizeof st);
        for(int i = 0; i < 26; i++) p[i] = i; // �����ڵ�����Ϊ�Լ�
        
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            int len = strlen(str);
            int a = str[0] - 'a', b = str[len - 1] - 'a';
            st[a] = st[b] = true; // a��b������ĸʹ�ù���
            dout[a]++, din[b]++; // a->b a�ĳ��ȼ�1��b����ȼ�1
            p[find(a)] = find(b); // ��a�����ڽڵ�����Ϊb
        }
        
        int start = 0, end = 0;
        bool success = true;
        for(int i = 0; i < 26; i++) // ö��ÿһ����ĸ
            if(din[i] != dout[i]){ // ����������Ȳ����ڳ���
                if(din[i] == dout[i] + 1) end++; // ��ȱȳ��ȶ�1���������յ�
                else if(din[i] + 1 == dout[i]) start++; // ���ȱ���ȶ�1�����������
                else{
                    success = false; // ����˵�����Ⱥ����������1����ŷ��·��
                    break;
                }
            }
        
        if(success && !(!start && !end || start == 1 && end == 1)) success = false; // ��������յ������Ϊ0���������յ������Ϊ1�����������ŷ��·�������򲻴���
        
        int rep = -1;
        for(int i = 0; i < 26; i++) // �ж��Ƿ�����ʹ�ù�����ĸ����һ����ͨ����
            if(st[i]){
                if(rep == -1) rep = find(i); // ����ǵ�һ����ĸ�������ͨ������Ϊ�������ڽڵ�
                else if(rep != find(i)){ // �����ÿ����ĸ���������һ����ͨ���У���ŷ����·
                    success = false;
                    break;
                }
            }
    
        if(success) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    
    return 0;
}