#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Token{
int type; //单词的类别码
char* value; //单词的值（字符串形式）
} Token;

char* keywords[] = {"const","int","char","void","return","if","else","while","for","do","continue","break","switch","case","default","sizeof","struct","typedef","enum","union","volatile","static","register","extern","auto","short","long","float","double","signed","unsigned","include","define","undef","ifndef","ifdef","endif"}; //关键字

char* operators[] = {"+","-","","/","%","++","--","=","+=","-=","=","/=","%=","==","!=",">=",">","<=","<","&&","||","!","&","|","^","~","<<",">>","->",".","?",":","[","]","(",")","{","}",";",","}; //运算符和界符

int keywords_num = 41; //关键字数目
int operators_num = 41; //运算符和界符数目

int isDigit(char c){ //判断是否是数字
return c >= '0' && c <= '9';
}

int isLetter(char c){ //判断是否是字母
return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isKeyword(char* str){ //判断是否是关键字
for(int i=0; i<keywords_num; i++){
if(strcmp(str, keywords[i]) == 0){
return 1;
}
}
return 0;
}

int isOperator(char* str){ //判断是否是运算符或界符
for(int i=0; i<operators_num; i++){
if(strcmp(str, operators[i]) == 0){
return 1;
}
}
return 0;
}

Token* getToken(char* str){ //获取单词的类别和值
Token* token = (Token*)malloc(sizeof(Token));
if(isDigit(str[0])){ //数字常量
token->type = 1;
token->value = (char*)malloc(sizeof(char) * strlen(str));
strcpy(token->value, str);
}
else if(isLetter(str[0]) || str[0] == '_'){ //标识符或关键字
if(isKeyword(str)){ //关键字
token->type = 2;
token->value = (char*)malloc(sizeof(char) * strlen(str));
strcpy(token->value, str);
}
else{ //标识符
token->type = 3;
token->value = (char*)malloc(sizeof(char) * strlen(str));
strcpy(token->value, str);
}
}
else if(isOperator(str)){ //运算符或界符
token->type = 4;
token->value = (char*)malloc(sizeof(char) * strlen(str));
strcpy(token->value, str);
}
else{ //非法字符
token->type = 5;
token->value = NULL;
}
return token;
}

int main(){
char filename[20];
char str[100];
printf("请输入源代码文件名：");
scanf("%s", filename);
FILE* fp = fopen(filename, "r");
FILE* fpout = fopen("output.txt", "w");
while(fscanf(fp, "%s", str) != EOF){ //逐个获取单词
Token* token = getToken(str);
fprintf(fpout, "%d %s\n", token->type, token->value);
free(token->value);
free(token);
}
fclose(fp);
fclose(fpout);
return 0;
}





