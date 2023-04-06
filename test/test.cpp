#include<iostream>
#include<fstream>
#include<cstring>
#include<map>
using namespace std;

map<string, string> m;
int tokenval = 0;
string str;
pair<string, string> PSS;
// string buffer;
char buffer[1000000];
ifstream in("testfile.txt");
ofstream out("output.txt");

void print(){
    out << PSS.first << " " << PSS.second << endl;
}

void getToken(){
    int t, i = 0;
    while(!in.eof()){
        // getline(in, buffer);
        // in >> buffer;
        in.getline(buffer, 100000);
        i = 0;
        while(i < (int)strlen(buffer)){
            t = buffer[i++];
            if(t == ' ' || t == '\t' || t == '\n')  continue;
            if(isdigit(t)){
                tokenval = 0;
                do{
                    tokenval = tokenval * 10 + t - '0';
                    t = buffer[i++];
                }while(isdigit(t));
                string s = to_string(tokenval);
                PSS = {"INTCON", s};
                print();
                i--;
            }else if(t == '\"'){
                str = "";
                t = buffer[i++];
                do{
                    str += t;
                    t = buffer[i++];
                }while(t != '\"');
                PSS = {"STRCON", str};
                print();
            }
            else if(t == '\''){
                str = "";
                t = buffer[i++];
                do{
                    str += t;
                    t = buffer[i++];
                }while(t != '\'');
                PSS = {"CHARCON", str};
                print();
            }
            else if(isalpha(t) || t == '_'){
                str = "";
                do{
                    str += t;
                    t = buffer[i++];
                }while(isalpha(t) || isdigit(t) || t == '_');
                i--;
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
                t = buffer[i++];
                if(t == '=') s += "=";
                // else ungetc(t, fo);
                else i--;
                PSS = {m[s], s};
                print();
            }
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

    getToken();
    out.close();
    in.close();

    return 0;
}