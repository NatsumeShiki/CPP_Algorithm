#include<iostream>
#include<fstream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

map<string, string> m;
int tokenval = 0;
int num = 0;
string str;
pair<string, string> PSS;
string buffer;
vector<string> token;
vector<string> val;
ifstream in("testfile.txt");
ofstream out("error.txt");

// #include"WordAnalysis.h"

void WordAnalysis(){
    int t, i = 0;
    while(!in.eof()){
        getline(in, buffer);
        i = 0;
        while(i < (int)buffer.size()){
            t = buffer[i++];
            // if(t == ' ' || t == '\t' || t == '\n')  continue;
            if(isdigit(t)){
                tokenval = 0;
                do{
                    tokenval = tokenval * 10 + t - '0';
                    t = buffer[i++];
                }while(isdigit(t));
                string s = to_string(tokenval);
                PSS = {"INTCON", s};
                // print();
                token.push_back("INTCON");
                val.push_back(s);
                num++;
                i--;
            }else if(t == '\"'){
                str = "";
                t = buffer[i++];
                do{
                    str += t;
                    t = buffer[i++];
                }while(t != '\"');
                PSS = {"STRCON", str};
                // print();
                token.push_back("STRCON");
                val.push_back(str);
                num++;
            }
            else if(t == '\''){
                str = "";
                t = buffer[i++];
                str += t;
                t = buffer[i++];
                PSS = {"CHARCON", str};
                // print();
                token.push_back("CHARCON");
                val.push_back(str);
                num++;
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
                    // PSS = {m[str], str};
                    token.push_back(m[str]);
                    val.push_back(str);
                }else{
                    // PSS = {"IDENFR", str};
                    token.push_back("IDENFR");
                    val.push_back(str);
                }
                num++;
                // print();
            }else if(t == '+' || t == '-' || t == '*' || t == '/' || t == '<' || t == '>' || t == '=' || t == '!' || t == ';' || t == ',' || t == '(' || 
            t == ')' || t == '[' || t == ']' || t == '{' || t == '}') {
                string s;
                s += t;
                t = buffer[i++];
                if(t == '=') s += "=";
                else i--;
                PSS = {m[s], s};
                // print();
                token.push_back(m[s]);
                val.push_back(s);
                num++;
            }else continue;
        }
    }

    // out.close();
    // in.close();
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