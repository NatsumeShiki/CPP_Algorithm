#include<iostream>
using namespace std;

const int MaxSize = 100;

typedef struct{
  char data[MaxSize];
  int top;
}SqStack;

typedef struct{
  double data[MaxSize];
  int top;
}SqStack1;

void InitStack(SqStack* &s){
  s = (SqStack*)malloc(sizeof(SqStack));
  s->top = -1;
}

void InitStack1(SqStack1* &s){
  s = (SqStack1*)malloc(sizeof(SqStack1));
  s->top = -1;
}

bool StackEmpty(SqStack* s){
  return s->top == -1;
}

bool Push(SqStack* &s, char e){
  if(s->top == MaxSize - 1) return false;
  s->top++;
  s->data[s->top] = e;
  return true;
}

bool Push1(SqStack1* &s, double e){
  if(s->top == MaxSize - 1) return false;
  s->top++;
  s->data[s->top] = e;
  return true;
}

bool Pop(SqStack* &s, char &e){
  if(s->top == -1) return false;
  e = s->data[s->top];
  s->top--;
  return true;
}

bool Pop1(SqStack1* &s, double &e){
  if(s->top == -1) return false;
  e = s->data[s->top];
  s->top--;
  return true;
}

bool GetTop(SqStack* &s, char &e){
  if(s->top == -1) return false;
  e = s->data[s->top];
  return true;
}

bool GetTop1(SqStack1* &s, double &e){
  if(s->top == -1) return false;
  e = s->data[s->top];
  return true;
}

void trans(char *exp, char postexp[]){
  char e;
  SqStack* Optr;
  InitStack(Optr);
  int i = 0;
  while(*exp != '\0'){
    switch(*exp){
      case '(':
        Push(Optr, '(');
        exp++;
        break;
      case ')':
        Pop(Optr, e);
        while(e != '('){
          postexp[i++] = e;
          Pop(Optr, e);
        }
        exp++;
        break;
      case '+':
      case '-':
        while(!StackEmpty(Optr)){
          GetTop(Optr, e);
          if(e != '('){
            postexp[i++] = e;
            Pop(Optr, e);
          }else break;
          Push(Optr, *exp);
          exp++;
          break;
        }
      case '*':
      case '/':
        while(!StackEmpty(Optr)){
          GetTop(Optr, e);
          if(e == '*' || e == '/'){
            postexp[i++] = e;
            Pop(Optr, e);
          }else break;
        }
        Push(Optr, *exp);
        exp++;
        break;
      default:
        while(*exp >= '0' && *exp <= '9'){
          postexp[i++] = *exp;
          exp++;
        }
        postexp[i++] = '#';
    }
  }
  while(!StackEmpty(Optr)){
    Pop(Optr, e);
    postexp[i++] = e;
  }
  postexp[i] = '\0';
  free(Optr);
}

double compvalue(char* postexp){
  double d, a, b, c, e;
  SqStack1 *Opnd;
  InitStack1(Opnd);
  while(*postexp != '\0'){
    switch(*postexp){
      case '+': 
        Pop1(Opnd, a), Pop1(Opnd, b);
        c = b + a;
        Push1(Opnd, c);
        break;
      case '-':
        Pop1(Opnd, a), Pop1(Opnd, b);
        c = b - a;
        Push1(Opnd, c);
        break;
      case '*':
        Pop1(Opnd, a), Pop1(Opnd, b);
        c = b * a;
        Push1(Opnd, c);
        break;
      case '/':
        Pop1(Opnd, a), Pop1(Opnd, b);
        if(a != 0){
          c = b / a;
          Push1(Opnd, c);
        }else{
          printf("\n\t除零错误！\n");
          exit(0);
        }
        break;
      default:
        d = 0;
        while(*postexp >= '0' && *postexp <= '9'){
          d = 10 * d + *postexp - '0';
          postexp++;
        }
        Push1(Opnd, d);
        break;
    }
    postexp++;
  }
  GetTop1(Opnd, e);
  free(Opnd);
  return e;
}

int main(){
  char exp[MaxSize], postexp[MaxSize];
  printf("请输入一个包含+、-、*、/、正整数和圆括号的合法数学表达式:\n");
  cin >> exp;
  printf("中缀表达式:%s\n", exp);
  trans(exp, postexp);
  printf("计算结果为：%.0lf",  compvalue(postexp));
  return 0;
}