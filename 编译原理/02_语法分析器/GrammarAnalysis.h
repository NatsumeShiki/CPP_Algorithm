#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> Map;
ofstream output("output.txt", ios::out);
int t;

void parse0();
void parse1();
void parse2();
void parse3();
void parse4();
void parse5();
void parse6();
void parse7();
void parse8();
void parse9();
void parse10();
void parse11();
void parse12();
void parse13();
void parse14();
void parse15();
void parse16();
void parse17();
void parse18();
void parse19();
void parse20();
void parse21();
void parse22();
void parse23();
void parse24();
void parse25();
void parse26();
void parse27();
void parse28();
void parse29();
void parse30();

void MatchToken(string expected){
	if (token[t] == expected){
		output << token[t] << " " << val[t] << endl;
		t++;
	}else{
		output << "error" << endl;
		exit(0);
	}
}


void parse30(){
	MatchToken("STRCON");
	output << "<字符串>" << endl;
}

void parse29(){
	MatchToken("RETURNTK");
	if (token[t] == "LPARENT"){ 
    MatchToken("LPARENT"); 
    parse14(); 
    MatchToken("RPARENT"); 
  }
	output << "<返回语句>" << endl;
}

void parse28(){
	MatchToken("PRINTFTK");
	MatchToken("LPARENT");
	if (token[t] == "STRCON") parse30();
	else parse14();
	if (token[t] == "COMMA") { 
    MatchToken("COMMA"); 
    parse14(); 
  }
	MatchToken("RPARENT");
	output << "<写语句>" << endl;
}

void parse27(){
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

void parse26(){
	while (token[t] != "RBRACE") 
    parse17();
	output << "<语句列>" << endl;
}

void parse25(){
	if (token[t] != "RPARENT"){
		parse14();
		while (token[t] == "COMMA"){
			MatchToken("COMMA");
			parse14();
		}
	}
	output << "<值参数表>" << endl;
}

void parse234(){
	int res = Map[val[t]];
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	parse25();
	MatchToken("RPARENT");
	if (res == 1) output << "<无返回值函数调用语句>" << endl;
	else output << "<有返回值函数调用语句>" << endl;
}

void parse22(){
	parse4();
	output << "<步长>" << endl;
}

void parse21(){
	if (token[t] == "WHILETK"){
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		parse20();
		MatchToken("RPARENT");
		parse17();
	}
	else if (token[t] == "DOTK"){
		MatchToken("DOTK");
		parse17();
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		parse20();
		MatchToken("RPARENT");
	}
	else if (token[t] == "FORTK"){
		MatchToken("FORTK");
		MatchToken("LPARENT");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		parse14();
		MatchToken("SEMICN");
		parse20();
		MatchToken("SEMICN");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		MatchToken("IDENFR");
		if (token[t] == "PLUS") MatchToken("PLUS");
		else if (token[t] == "MINU") MatchToken("MINU");
		parse22();
		MatchToken("RPARENT");
		parse17();
	}
	output << "<循环语句>" << endl;
}

void parse20(){                                        
	parse14();
	if (token[t] == "LSS" || token[t] == "LEQ" || token[t] == "GRE"	|| token[t] == "GEQ" || token[t] == "EQL" || token[t] == "NEQ"){
		MatchToken(token[t]);
		parse14();
	}
	output << "<条件>" << endl;
}

void parse19(){
	MatchToken("IFTK");
	MatchToken("LPARENT");
	parse20();
	MatchToken("RPARENT");
	parse17();
	if (token[t] == "ELSETK"){
		MatchToken("ELSETK");
		parse17();
	}
	output << "<条件语句>" << endl;
}

void parse18(){
	MatchToken("IDENFR");
	if (token[t] == "LBRACK"){ 
    MatchToken("LBRACK"); 
    parse14(); 
    MatchToken("RBRACK"); 
  }
	MatchToken("ASSIGN");
	parse14();
	output << "<赋值语句>" << endl;
}

void parse17(){
	if (token[t] == "IFTK") parse19();
	else if (token[t] == "WHILETK" || token[t] == "DOTK" || token[t] == "FORTK") parse21();
	else if (token[t] == "LBRACE"){ 
    MatchToken("LBRACE"); 
    parse26(); 
    MatchToken("RBRACE"); 
  }else if (token[t] == "IDENFR"){
		if (token[t + 1] == "LPARENT"){ 
      parse234(); 
      MatchToken("SEMICN"); 
    }else { 
      parse18(); 
      MatchToken("SEMICN"); 
    }
	}else if (token[t] == "SCANFTK"){ 
    parse27(); 
    MatchToken("SEMICN"); 
  }else if (token[t] == "PRINTFTK"){ 
    parse28(); 
    MatchToken("SEMICN"); 
  }else if (token[t] == "RETURNTK") { 
    parse29(); 
    MatchToken("SEMICN"); 
  }
  else if (token[t] == "SEMICN") MatchToken("SEMICN");
	output << "<语句>" << endl;
}

void parse16(){
	if (token[t] == "IDENFR") {
		if (token[t + 1] == "LBRACK"){
			MatchToken("IDENFR");
			MatchToken("LBRACK");
			parse14();
			MatchToken("RBRACK");
		}
		else if (token[t + 1] == "LPARENT") parse234();
		else MatchToken("IDENFR");
	}
	else if (token[t] == "LPARENT"){ 
    MatchToken("LPARENT"); 
    parse14(); 
    MatchToken("RPARENT"); 
  }
	else if (token[t] == "INTCON" || token[t] == "PLUS" || token[t] == "MINU") parse5();
	else if (token[t] == "CHARCON") MatchToken("CHARCON");
	output << "<因子>" << endl;
}

void parse15()
{
	parse16();
	while (token[t] == "MULT" || token[t] == "DIV"){
		if (token[t] == "MULT") MatchToken("MULT");
		else if (token[t] == "DIV") MatchToken("DIV");
		parse16();
	}
	output << "<项>" << endl;
}

void parse14(){
	if (token[t] == "PLUS") MatchToken("PLUS");
	else if (token[t] == "MINU") MatchToken("MINU");
	parse15();
	while (token[t] == "PLUS" || token[t] == "MINU"){
		if (token[t] == "PLUS") MatchToken("PLUS");
		else if (token[t] == "MINU") MatchToken("MINU");
		parse15();
	}
	output << "<表达式>" << endl;
}

void parse13(){
	MatchToken("VOIDTK");
	MatchToken("MAINTK");
	MatchToken("LPARENT");
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	output << "<主函数>" << endl;
}

void parse12(){
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

void parse11(){
	if (token[t] == "CONSTTK") parse2();
	if ((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT") parse7();
	parse26();
	output << "<复合语句>" << endl;
}

void parse10(){
	MatchToken("VOIDTK");
	Map[val[t]] = 1;
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	parse12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	output << "<无返回值函数定义>" << endl;
}

void parse9(){
	parse6();
	MatchToken("LPARENT");
	parse12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	output << "<有返回值函数定义>" << endl;
}

void parse8(){
	if (token[t] == "INTTK") MatchToken("INTTK");
	else if (token[t] == "CHARTK") MatchToken("CHARTK");

	MatchToken("IDENFR");
	if (token[t] == "LBRACK"){
		MatchToken("LBRACK");
		parse4();
		MatchToken("RBRACK");
	}
	while (token[t] == "COMMA"){
		MatchToken("COMMA");
		MatchToken("IDENFR");
		if (token[t] == "LBRACK"){
			MatchToken("LBRACK");
			parse4();
			MatchToken("RBRACK");
		}
	}
	output << "<变量定义>" << endl;
}

void parse7(){
	do {
		parse8();
		MatchToken("SEMICN");
	}while((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT");
	output << "<变量说明>" << endl;
}

void parse6(){
	if (token[t] == "INTTK") MatchToken("INTTK");
	else if (token[t] == "CHARTK") MatchToken("CHARTK");
	MatchToken("IDENFR");
	output << "<声明头部>" << endl;
}

void parse5(){
	if (token[t] == "PLUS") MatchToken("PLUS");
	else if (token[t] == "MINU") MatchToken("MINU");
	parse4();
	output << "<整数>" << endl;
}

void parse4(){
	if (val[t][0] == '0' && val[t].length() > 1) exit(0);
	else MatchToken("INTCON");
	output << "<无符号整数>" << endl;
}

void parse3(){
	if (token[t] == "INTTK") {
		MatchToken("INTTK");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		parse5();
		while (token[t] == "COMMA") {
			MatchToken("COMMA");
			MatchToken("IDENFR");
			MatchToken("ASSIGN");
			parse5();
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

void parse2(){
	do {
		MatchToken("CONSTTK");
		parse3();
		MatchToken("SEMICN");
	} while (token[t] == "CONSTTK");
	output << "<常量说明>" << endl;

}

void parse1(){
  if(token[t] == "CONSTTK") parse2();
  if((token[t] == "INTTK" || token[t] == "CHARTK") && token[t + 1] == "IDENFR" && token[t + 2] != "LPARENT") parse7();

  while((token[t] == "INTTK" || token[t] == "CHARTK" || token[t] == "VOIDTK") && token[t + 1] == "IDENFR" && token[t + 2] == "LPARENT")
    if(token[t] == "VOIDTK") parse10();
    else parse9();

  if(token[t] == "VOIDTK" && token[t + 1] == "MAINTK") parse13();
  if(t == num){
    output << "<程序>" << endl;
    return;
  }
}

void GrammarAnalysis(){
  t = 0;
  parse1();
  output.close();
  return;
}