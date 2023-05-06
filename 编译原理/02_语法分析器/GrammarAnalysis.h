#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> Map;
ofstream output("output.txt", ios::out);
int t;

void MatchToken(string expected);
void match0();
void match1();
void match2();
void match3();
void match4();
void match5();
void match6();
void match7();
void match8();
void match9();
void match10();
void match11();
void match12();
void match13();
void match14();
void match15();
void match16();
void match17();
void match18();
void match19();
void match20();
void match21();
void match22();
void match23();
void match24();
void match25();
void match26();
void match27();
void match28();
void match29();
void match30();

// #include"GrammarAnalysis.h"
// #include"WordAnalysis.h"
// using namespace std;

void MatchToken(string expected){
	if (token[t] == expected){
		output << token[t] << " " << val[t] << endl;
		t++;
	}else{
		output << "error" << endl;
		exit(0);
	}
}


void match30(){
	MatchToken("STRCON");
	output << "<字符串>" << endl;
}

void match29(){
	MatchToken("RETURNTK");
	if (token[t] == "LPARENT"){ 
    MatchToken("LPARENT"); 
    match14(); 
    MatchToken("RPARENT"); 
  }
	output << "<返回语句>" << endl;
}

void match28(){
	MatchToken("PRINTFTK");
	MatchToken("LPARENT");
	if (token[t] == "STRCON") match30();
	else match14();
	if (token[t] == "COMMA") { 
    MatchToken("COMMA"); 
    match14(); 
  }
	MatchToken("RPARENT");
	output << "<写语句>" << endl;
}

void match27(){
	MatchToken("SCANFTK");
	MatchToken("LPARENT");
	MatchToken("IDENFR");
	while (token[t] == "COMMA") {
		MatchToken("COMMA");
		MatchToken("IDENFR");
	}
	MatchToken("RPARENT");
	output << "<读语句>" << endl;
}

void match26(){
	while (token[t] != "RBRACE") 
    match17();
	output << "<语句列>" << endl;
}

void match25(){
	if (token[t] != "RPARENT"){
		match14();
		while (token[t] == "COMMA"){
			MatchToken("COMMA");
			match14();
		}
	}
	output << "<值参数表>" << endl;
}

void match234(){
	int res = Map[val[t]];
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	match25();
	MatchToken("RPARENT");
	if (res == 1) output << "<无返回值函数调用语句>" << endl;
	else output << "<有返回值函数调用语句>" << endl;
}

void match22(){
	match4();
	output << "<步长>" << endl;
}

void match21(){
	if (token[t] == "WHILETK"){
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		match20();
		MatchToken("RPARENT");
		match17();
	}
	else if (token[t] == "DOTK"){
		MatchToken("DOTK");
		match17();
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		match20();
		MatchToken("RPARENT");
	}
	else if (token[t] == "FORTK"){
		MatchToken("FORTK");
		MatchToken("LPARENT");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		match14();
		MatchToken("SEMICN");
		match20();
		MatchToken("SEMICN");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		MatchToken("IDENFR");
		if (token[t] == "PLUS") MatchToken("PLUS");
		else if (token[t] == "MINU") MatchToken("MINU");
		match22();
		MatchToken("RPARENT");
		match17();
	}
	output << "<循环语句>" << endl;
}

void match20(){                                        
	match14();
	if (token[t] == "LSS" || token[t] == "LEQ" || token[t] == "GRE"	|| token[t] == "GEQ" || token[t] == "EQL" || token[t] == "NEQ"){
		MatchToken(token[t]);
		match14();
	}
	output << "<条件>" << endl;
}

void match19(){
	MatchToken("IFTK");
	MatchToken("LPARENT");
	match20();
	MatchToken("RPARENT");
	match17();
	if (token[t] == "ELSETK"){
		MatchToken("ELSETK");
		match17();
	}
	output << "<条件语句>" << endl;
}

void match18(){
	MatchToken("IDENFR");
	if (token[t] == "LBRACK"){ 
    MatchToken("LBRACK"); 
    match14(); 
    MatchToken("RBRACK"); 
  }
	MatchToken("ASSIGN");
	match14();
	output << "<赋值语句>" << endl;
}

void match17(){
	if (token[t] == "IFTK") match19();
	else if (token[t] == "WHILETK" || token[t] == "DOTK" || token[t] == "FORTK") match21();
	else if (token[t] == "LBRACE"){ 
    MatchToken("LBRACE"); 
    match26(); 
    MatchToken("RBRACE"); 
  }else if (token[t] == "IDENFR"){
		if (token[t + 1] == "LPARENT"){ 
      match234(); 
      MatchToken("SEMICN"); 
    }else { 
      match18(); 
      MatchToken("SEMICN"); 
    }
	}else if (token[t] == "SCANFTK"){ 
    match27(); 
    MatchToken("SEMICN"); 
  }else if (token[t] == "PRINTFTK"){ 
    match28(); 
    MatchToken("SEMICN"); 
  }else if (token[t] == "RETURNTK") { 
    match29(); 
    MatchToken("SEMICN"); 
  }
  else if (token[t] == "SEMICN") MatchToken("SEMICN");
	output << "<语句>" << endl;
}

void match16(){
	if (token[t] == "IDENFR") {
		if (token[t + 1] == "LBRACK"){
			MatchToken("IDENFR");
			MatchToken("LBRACK");
			match14();
			MatchToken("RBRACK");
		}
		else if (token[t + 1] == "LPARENT") match234();
		else MatchToken("IDENFR");
	}
	else if (token[t] == "LPARENT"){ 
    MatchToken("LPARENT"); 
    match14(); 
    MatchToken("RPARENT"); 
  }
	else if (token[t] == "INTCON" || token[t] == "PLUS" || token[t] == "MINU") match5();
	else if (token[t] == "CHARCON") MatchToken("CHARCON");
	output << "<因子>" << endl;
}

void match15()
{
	match16();
	while (token[t] == "MULT" || token[t] == "DIV"){
		if (token[t] == "MULT") MatchToken("MULT");
		else if (token[t] == "DIV") MatchToken("DIV");
		match16();
	}
	output << "<项>" << endl;
}

void match14(){
	if (token[t] == "PLUS") MatchToken("PLUS");
	else if (token[t] == "MINU") MatchToken("MINU");
	match15();
	while (token[t] == "PLUS" || token[t] == "MINU"){
		if (token[t] == "PLUS") MatchToken("PLUS");
		else if (token[t] == "MINU") MatchToken("MINU");
		match15();
	}
	output << "<表达式>" << endl;
}

void match13(){
	MatchToken("VOIDTK");
	MatchToken("MAINTK");
	MatchToken("LPARENT");
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	match11();
	MatchToken("RBRACE");
	output << "<主函数>" << endl;
}

void match12(){
	if (token[t] != "RPARENT"){
		if (token[t] == "INTTK") MatchToken("INTTK");
		else if (token[t] == "CHARTK") MatchToken("CHARTK");
		MatchToken("IDENFR");
		while (token[t] == "COMMA"){
			MatchToken("COMMA");
			if (token[t] == "INTTK") MatchToken("INTTK");
			else if (token[t] == "CHARTK") MatchToken("CHARTK");
			MatchToken("IDENFR");
		}
	}
	output << "<参数表>" << endl;
}

void match11(){
	if (token[t] == "CONSTTK") match2();
	if ((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT") match7();
	match26();
	output << "<复合语句>" << endl;
}

void match10(){
	MatchToken("VOIDTK");
	Map[val[t]] = 1;
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	match12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	match11();
	MatchToken("RBRACE");
	output << "<无返回值函数定义>" << endl;
}

void match9(){
	match6();
	MatchToken("LPARENT");
	match12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	match11();
	MatchToken("RBRACE");
	output << "<有返回值函数定义>" << endl;
}

void match8(){
	if (token[t] == "INTTK") MatchToken("INTTK");
	else if (token[t] == "CHARTK") MatchToken("CHARTK");

	MatchToken("IDENFR");
	if (token[t] == "LBRACK"){
		MatchToken("LBRACK");
		match4();
		MatchToken("RBRACK");
	}
	while (token[t] == "COMMA"){
		MatchToken("COMMA");
		MatchToken("IDENFR");
		if (token[t] == "LBRACK"){
			MatchToken("LBRACK");
			match4();
			MatchToken("RBRACK");
		}
	}
	output << "<变量定义>" << endl;
}

void match7(){
	do {
		match8();
		MatchToken("SEMICN");
	}while((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT");
	output << "<变量说明>" << endl;
}

void match6(){
	if (token[t] == "INTTK") MatchToken("INTTK");
	else if (token[t] == "CHARTK") MatchToken("CHARTK");
	MatchToken("IDENFR");
	output << "<声明头部>" << endl;
}

void match5(){
	if (token[t] == "PLUS") MatchToken("PLUS");
	else if (token[t] == "MINU") MatchToken("MINU");
	match4();
	output << "<整数>" << endl;
}

void match4(){
	if (val[t][0] == '0' && val[t].length() > 1) exit(0);
	else MatchToken("INTCON");
	output << "<无符号整数>" << endl;
}

void match3(){
	if (token[t] == "INTTK") {
		MatchToken("INTTK");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		match5();
		while (token[t] == "COMMA") {
			MatchToken("COMMA");
			MatchToken("IDENFR");
			MatchToken("ASSIGN");
			match5();
		}
	}
	if (token[t] == "CHARTK") {
		MatchToken("CHARTK");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		MatchToken("CHARCON");
		while (token[t] == "COMMA") {
			MatchToken("COMMA");
			MatchToken("IDENFR");
			MatchToken("ASSIGN");
			MatchToken("CHARCON");
		}
	}
	output << "<常量定义>" << endl;
}

void match2(){
	do {
		MatchToken("CONSTTK");
		match3();
		MatchToken("SEMICN");
	} while (token[t] == "CONSTTK");
	output << "<常量说明>" << endl;

}

void match1(){
  if(token[t] == "CONSTTK") match2();
  if((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT") match7();

  while((token[t] == "INTTK" || token[t] == "CHARTK" || token[t] == "VOIDTK") && token[t + 1] == "IDENFR" && token[t + 2] == "LPARENT")
    if(token[t] == "VOIDTK") match10();
    else match9();

  if(token[t] == "VOIDTK" && token[t + 1] == "MAINTK") match13();
  if(t == num){
    output << "<程序>" << endl;
    return;
  }
}

void GrammarAnalysis(){
  t = 0;
  match1();
  output.close();
  return;
}