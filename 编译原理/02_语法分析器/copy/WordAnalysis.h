
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <stdio.h>
#include <map>

using namespace std;
const int MAXN = 10000;

bool IsDigit(char c) {
	return isdigit(c);
}
bool IsLetter(char c) {
	if (isalpha(c) || (c == '_'))
		return true;
	return false;
}
map <string, string>category;
int length = 0;
char in[MAXN];
//vector<char> in;
int num = 0;
vector<string> token;
vector<string> val;
void read()
{
	category["const"] = "CONSTTK";
	category["int"] = "INTTK";
	category["char"] = "CHARTK";
	category["void"] = "VOIDTK";
	category["main"] = "MAINTK";
	category["if"] = "IFTK";
	category["else"] = "ELSETK";
	category["do"] = "DOTK";
	category["while"] = "WHILETK";
	category["for"] = "FORTK";
	category["scanf"] = "SCANFTK";
	category["printf"] = "PRINTFTK";
	category["return"] = "RETURNTK";
	category["+"] = "PLUS";
	category["-"] = "MINU";
	category["*"] = "MULT";
	category["/"] = "DIV";
	category[","] = "COMMA";
	category[";"] = "SEMICN";
	category["("] = "LPARENT";
	category[")"] = "RPARENT";
	category["["] = "LBRACK";
	category["]"] = "RBRACK";
	category["{"] = "LBRACE";
	category["}"] = "RBRACE";

	//读取文件转存in数组
	ifstream input("testfile.txt", ios::in);
	if (!input)
	{
		cout << "open testfile.txt error!" << endl;
		exit(1);
	}
	input.unsetf(ios::skipws);
	while (input.peek() != EOF) {
		char c = input.get();
		in[length++] = c;
		//in.push_back(c);
	}
	input.close();
	//for(int i=0;i<length;i++)cout<<i<<" "<<in[i]<<endl;
}
void WordAnalysis()
{
	int p = 0;
	while (p < length)
	{
		while (in[p] == ' ' || in[p] == '\n')p++;
		if (IsLetter(in[p]) || in[p] == '_')
		{
			string s = "";
			while (IsLetter(in[p]) || IsDigit(in[p]) || in[p] == '_')
			{
				s += in[p++];
			}
			if (category[s] != "")
			{
				token.push_back(category[s]);
			}
			else
			{
				token.push_back("IDENFR");
			}
			val.push_back(s);
			num++;
		}
		else if (IsDigit(in[p]))
		{
			string s = "";
			// int num = 0;
			int cnt = 0;
			while (IsDigit(in[p]))
			{
				cnt = cnt * 10 + (in[p] - '0');
				s += in[p++];
			}
			token.push_back("INTCON");
			val.push_back(s);
			num++;
		}
		else if (in[p] == '=')
		{
			if (in[p + 1] == '=')//双等号
			{
				token.push_back("EQL");
				val.push_back("==");
				num++;
				p += 2;
			}
			else
			{
				token.push_back("ASSIGN");
				val.push_back("=");
				num++;
				p++;
			}
		}
		else if (in[p] == '+' || in[p] == '-' || in[p] == '*' || in[p] == '/'
			|| in[p] == ';' || in[p] == ',' || in[p] == '(' || in[p] == ')'
			|| in[p] == '[' || in[p] == ']' || in[p] == '{' || in[p] == '}')
		{
			string s = ""; s += in[p];
			p++;
			token.push_back(category[s]);
			val.push_back(s);
			num++;
		}
		else if (in[p] == 39)//单引号
		{
			p++;
			string s = ""; s += in[p];
			p++;
			if (in[p] == 39)p++;
			token.push_back("CHARCON");
			val.push_back(s);
			num++;
		}
		else if (in[p] == '"')
		{
			string s;
			p++;
			while (in[p] != '"')
			{
				s += in[p];
				p++;
			}
			p++;
			token.push_back("STRCON");
			val.push_back(s);
			num++;
		}
		else if (in[p] == '<')
		{
			if (in[p + 1] == '=')//小于等于号
			{
				token.push_back("LEQ");
				val.push_back("<=");
				num++;
				p += 2;
			}
			else
			{
				token.push_back("LSS");
				val.push_back("<");
				num++;
				p++;
			}
		}
		else if (in[p] == '>')
		{
			if (in[p + 1] == '=')//大于等于号
			{
				token.push_back("GEQ");
				val.push_back(">=");
				num++;
				p += 2;
			}
			else
			{
				token.push_back("GRE");
				val.push_back(">");
				num++;
				p++;
			}
		}
		else if (in[p] == '!')
		{
			if (in[p + 1] == '=')//不等于号
			{
				token.push_back("NEQ");
				val.push_back("!=");
				num++;
				p += 2;
			}
		}
		else p++;
	}

	// 输出
	// ofstream output("output.txt",ios::out);
	// for(int i=0;i<num;i++)
	// {
	// 	output<<token[i]<<" "<<val[i]<<endl;
	// }
	// output.close();
	
	return;
}

