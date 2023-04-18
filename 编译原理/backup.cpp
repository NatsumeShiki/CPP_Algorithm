#include<iostream>
#include<fstream>
#include<cstring>
#include<map>
using namespace std;

map<string, string> m;
int tokenval = 0;
string str;
FILE *fo, *fw;
pair<string, string> PSS;

void print(){                                          
    fprintf(fw, "%s %s\n", PSS.first.c_str(), PSS.second.c_str());
}

void getToken(){
    int t;   
    while(true){
        t = fgetc(fo);
        if(t == EOF) return;
        if(t == ' ' || t == '\t' || t == '\n')  continue;
        if(isdigit(t)){
            tokenval = 0;
            do{
                tokenval = tokenval * 10 + t - '0';
                t = fgetc(fo);
            }while(isdigit(t));
            string s = to_string(tokenval);
            PSS = {"INTCON", s};
            print();
            ungetc(t, fo);
        }else if(t == '\"'){
            str = "";
            t = fgetc(fo);
            do{
                str += t;
                t = fgetc(fo);
            }while(t != '\"');
            PSS = {"STRCON", str};
            print();
        }
        else if(t == '\''){
            str = "";
            t = fgetc(fo);
            do{
                str += t;
                t = fgetc(fo);
            }while(t != '\'');
            PSS = {"CHARCON", str};
            print();
        }
        else if(isalpha(t) || t == '_'){
            str = "";
            do{
                str += t;
                t = fgetc(fo);
            }while(isalpha(t) || isdigit(t) || t == '_');
            ungetc(t, fo);
            if(str == "const" || str == "int" || str == "char" || str == "void" || str == "main" || str == "if" || str == "else" || 
            str == "do" || str == "while" || str == "for" || str == "scanf" || str == "printf" || str == "return") {
                PSS = {m[str], str};
            }else{
                PSS = {"IDENFR", str};
            }
            print();
        }else{
            string s;
            s += t;
            t = fgetc(fo);
            if(t == '=') s += "=";
            else ungetc(t, fo);
            PSS = {m[s], s};
            print();
        }
            
    }
}

void init(){
    m["const"] = "CONSTTK";
    m["int"] = "INTTK";
    m["char"] = "CHARTK";
    m["void"] = "VOIDTK";
    m["main"] = "MAINTK";
    m["if"] = "IFTK";
    m["else"] = "ELSETK";
    m["do"] = "DOTK";
    m["while"] = "WHILETK";
    m["for"] = "FORTK";
    m["scanf"] = "SCANFTK";
    m["printf"] = "PRINTFTK";
    m["return"] = "RETURNTK";
    m["+"] = "PLUS";
    m["-"] = "MINU";
    m["*"] = "MULT";
    m["/"] = "DIV";
    m["<"] = "LSS";
    m["<="] = "LEQ";
    m[">"] = "GRE";
    m[">="] = "GEQ";
    m["=="] = "EQL";
    m["!="] = "NEQ";
    m["="] = "ASSIGN";
    m[";"] = "SEMICN";
    m[","] = "COMMA";
    m["("] = "LPARENT";
    m[")"] = "RPARENT";
    m["["] = "LBRACK";
    m["]"] = "RBRACK";
    m["{"] = "LBRACE";
    m["}"] = "RBRACE";
}

int main(){
    init();

    fo = fopen("testfile.txt", "r");
    fw = fopen("output.txt", "w");
    getToken();
    fclose(fo);
    fclose(fw);

    return 0;
}