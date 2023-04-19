#include<string>
#include<iostream>
using namespace std;
int q;//token[q]==lookahead
map <string, int>VoidFunction;
ofstream output("output.txt", ios::out);
void MatchToken(string expected);
void parse0();		//＜字符串＞
void parse1();		//＜程序＞
void parse2();		//＜常量说明＞
void parse3();		//＜常量定义＞
void parse4();		//＜无符号整数＞	
void parse5();		//＜整数＞
void parse6();		//＜声明头部＞
void parse7();		//＜变量说明＞
void parse8();		//＜变量定义＞
void parse9();		//＜有返回值函数定义＞
void parse10();		//＜无返回值函数定义＞
void parse11();		//＜复合语句＞
void parse12();		//＜参数表＞
void parse13();		//＜主函数＞
void parse14();		//＜表达式＞
void parse15();		//＜项＞
void parse16();		//＜因子＞
void parse17();		//＜语句＞
void parse18();		//＜赋值语句＞
void parse19();		//＜条件语句＞
void parse20();		//＜条件＞
void parse21();		//＜循环语句＞
void parse22();		//＜步长＞
void parse234();	//＜有无返回值函数调用语句＞
void parse25();		//＜值参数表＞ 
void parse26();     //＜语句列＞
void parse27();     //＜读语句＞
void parse28();     //＜写语句＞
void parse29();		//＜返回语句＞

void GrammarAnalysis()
{
	q = 0;
	parse1();
	output.close();
	return;
}

void parse0()
{
	//＜字符串＞ ::=  "｛十进制编码为32,33,35-126的ASCII字符｝"
	MatchToken("STRCON");
	// printf("<字符串>\n");
	output << "<字符串>\n";
}
void parse1()
{
	//＜程序＞ ::= ［＜常量说明＞］［＜变量说明＞］
	//				{＜有返回值函数定义＞|＜无返回值函数定义＞}＜主函数＞
	if (token[q] == "CONSTTK") {
		parse2();
	}
	if ((token[q] == "INTTK" || token[q] == "CHARTK") &&
		token[q + 1] == "IDENFR" && token[q + 2] != "LPARENT") {
		parse7();
	}

	while ((token[q] == "INTTK" || token[q] == "CHARTK" || token[q] == "VOIDTK") &&
		token[q + 1] == "IDENFR" && token[q + 2] == "LPARENT") {
		if (token[q] == "VOIDTK") {
			parse10();
		}
		else {
			parse9();
		}
	}
	if (token[q] == "VOIDTK" && token[q + 1] == "MAINTK") {
		parse13();
	}
	if (q == num) {
		// printf("<程序>\n");
		output << "<程序>\n";
		return;
	}
	else {
		// printf("shitbrofuckingerror");
		output << "shitbrofuckingerror\n";
		output << q << " " << num << endl;
		exit(0);
	}
}
void parse2()
{
	//＜常量说明＞ ::=  const＜常量定义＞;{ const＜常量定义＞;}
	do {
		MatchToken("CONSTTK");
		parse3();
		MatchToken("SEMICN");
	} while (token[q] == "CONSTTK");
	// printf("<常量说明>\n");
	output << "<常量说明>\n";

}
void parse3()
{
	//＜常量定义＞   ::=   int＜标识符＞＝＜整数＞{,＜标识符＞＝＜整数＞}
	//                       | char＜标识符＞＝＜字符＞{,＜标识符＞＝＜字符＞}
	if (token[q] == "INTTK") {
		MatchToken("INTTK");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		parse5();
		while (token[q] == "COMMA") {
			MatchToken("COMMA");
			MatchToken("IDENFR");
			MatchToken("ASSIGN");
			parse5();
		}
	}
	if (token[q] == "CHARTK") {
		MatchToken("CHARTK");
		MatchToken("IDENFR");
		MatchToken("ASSIGN");
		MatchToken("CHARCON");
		while (token[q] == "COMMA") {
			MatchToken("COMMA");
			MatchToken("IDENFR");
			MatchToken("ASSIGN");
			MatchToken("CHARCON");
		}
	}
	// printf("<常量定义>\n");
	output << "<常量定义>\n";
}
void parse4()
{
	//＜无符号整数＞ ::= ＜非零数字＞｛＜数字＞｝| 0
	if (val[q][0] == '0' && val[q].length() > 1) {
		// printf("error");
		exit(0);
	}
	else MatchToken("INTCON");
	// printf("<无符号整数>\n");
	// output << "<无符号整数>\n";
	output << "<无符号整数>" << endl;
}
void parse5()
{
	//＜整数＞ ::= ［＋｜－］＜无符号整数＞
	if (token[q] == "PLUS")MatchToken("PLUS");
	else if (token[q] == "MINU")MatchToken("MINU");
	parse4();
	// printf("<整数>\n");
	output << "<整数>\n";
}
void parse6()
{
	//＜声明头部＞ ::=  int＜标识符＞ |char＜标识符＞
	if (token[q] == "INTTK")MatchToken("INTTK");
	else if (token[q] == "CHARTK")MatchToken("CHARTK");
	MatchToken("IDENFR");
	// printf("<声明头部>\n");
	output << "<声明头部>\n";
}
void parse7()
{
	//＜变量说明＞ ::= ＜变量定义＞;{＜变量定义＞;}
	do {
		parse8();
		MatchToken("SEMICN");
	} while ((token[q] == "INTTK" || token[q] == "CHARTK") &&
		token[q + 1] == "IDENFR" && token[q + 2] != "LPARENT");
	// printf("<变量说明>\n");
	output << "<变量说明>\n";
}
void parse8()
{
	//＜变量定义＞ ::= ＜类型标识符＞
	//							  (＜标识符＞|＜标识符＞'['＜无符号整数＞']')
	//							{,(＜标识符＞|＜标识符＞'['＜无符号整数＞']')}
	if (token[q] == "INTTK")MatchToken("INTTK");
	else if (token[q] == "CHARTK")MatchToken("CHARTK");

	MatchToken("IDENFR");
	if (token[q] == "LBRACK") {
		MatchToken("LBRACK");
		parse4();
		MatchToken("RBRACK");
	}
	while (token[q] == "COMMA") {
		MatchToken("COMMA");
		MatchToken("IDENFR");
		if (token[q] == "LBRACK") {
			MatchToken("LBRACK");
			parse4();
			MatchToken("RBRACK");
		}
	}
	// printf("<变量定义>\n");
	output << "<变量定义>\n";
}
void parse9()
{
	//＜有返回值函数定义＞ ::=  ＜声明头部＞'('＜参数表＞')' '{'＜复合语句＞'}'
	parse6();
	MatchToken("LPARENT");
	parse12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	// printf("<有返回值函数定义>\n");
	output << "<有返回值函数定义>\n";
}
void parse10()
{
	//＜无返回值函数定义＞ ::= void＜标识符＞'('＜参数表＞')''{'＜复合语句＞'}'
	MatchToken("VOIDTK");
	VoidFunction[val[q]] = 1;
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	parse12();
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	// printf("<无返回值函数定义>\n");
	output << "<无返回值函数定义>\n";
}
void parse11()
{
	//＜复合语句＞ ::=  ［＜常量说明＞］［＜变量说明＞］＜语句列＞
	if (token[q] == "CONSTTK") {
		parse2();
	}
	if ((token[q] == "INTTK" || token[q] == "CHARTK") &&
		token[q + 1] == "IDENFR" && token[q + 2] != "LPARENT") {
		parse7();
	}
	parse26();
	// printf("<复合语句>\n");
	output << "<复合语句>\n";
}
void parse12()
{
	//＜参数表＞ ::=  ＜类型标识符＞＜标识符＞{,＜类型标识符＞＜标识符＞}| ＜空＞
	if (token[q] != "RPARENT")//如果下一个token为右小括号，则为空
	{
		if (token[q] == "INTTK")MatchToken("INTTK");
		else if (token[q] == "CHARTK")MatchToken("CHARTK");
		MatchToken("IDENFR");
		while (token[q] == "COMMA") {
			MatchToken("COMMA");
			if (token[q] == "INTTK")MatchToken("INTTK");
			else if (token[q] == "CHARTK")MatchToken("CHARTK");
			MatchToken("IDENFR");
		}
	}
	// printf("<参数表>\n");
	output << "<参数表>\n";
}
void parse13()
{
	//＜主函数＞ ::= void main‘(’‘)’ ‘{’＜复合语句＞‘}’
	MatchToken("VOIDTK");
	MatchToken("MAINTK");
	MatchToken("LPARENT");
	MatchToken("RPARENT");
	MatchToken("LBRACE");
	parse11();
	MatchToken("RBRACE");
	// printf("<主函数>\n");
	output << "<主函数>\n";
}
void parse14()
{
	//14＜表达式＞ ::= ［＋｜－］＜项＞{＜加法运算符＞＜项＞}
	if (token[q] == "PLUS")MatchToken("PLUS");
	else if (token[q] == "MINU")MatchToken("MINU");
	parse15();
	while (token[q] == "PLUS" || token[q] == "MINU")
	{
		if (token[q] == "PLUS")MatchToken("PLUS");
		else if (token[q] == "MINU")MatchToken("MINU");
		parse15();
	}
	// printf("<表达式>\n");
	output << "<表达式>\n";
}
void parse15()
{
	//15＜项＞ ::= ＜因子＞{＜乘法运算符＞＜因子＞}
	parse16();
	while (token[q] == "MULT" || token[q] == "DIV")
	{
		if (token[q] == "MULT")MatchToken("MULT");
		else if (token[q] == "DIV")MatchToken("DIV");
		parse16();
	}
	// printf("<项>\n");
	output << "<项>\n";
}
void parse16()
{
	//＜因子＞ ::= ＜标识符＞｜＜标识符＞'['＜表达式＞']'
	//			|'('＜表达式＞')'｜＜整数＞|＜字符＞｜＜有返回值函数调用语句＞ 
	if (token[q] == "IDENFR") {
		if (token[q + 1] == "LBRACK") {
			MatchToken("IDENFR");
			MatchToken("LBRACK");
			parse14();
			MatchToken("RBRACK");
		}
		else if (token[q + 1] == "LPARENT")parse234();
		else MatchToken("IDENFR");
	}
	else if (token[q] == "LPARENT") { MatchToken("LPARENT"); parse14(); MatchToken("RPARENT"); }
	else if (token[q] == "INTCON" || token[q] == "PLUS" || token[q] == "MINU")parse5();
	else if (token[q] == "CHARCON")MatchToken("CHARCON");
	// printf("<因子>\n");
	output << "<因子>\n";
}
void parse17()
{
	/*＜语句＞ ::= ＜条件语句＞｜＜循环语句＞| '{'＜语句列＞'}'
				| ＜有返回值函数调用语句＞; |＜无返回值函数调用语句＞;｜＜赋值语句＞;
				｜＜读语句＞;｜＜写语句＞;｜＜空＞;|＜返回语句＞;
	*/

	if (token[q] == "IFTK")parse19();
	else if (token[q] == "WHILETK" || token[q] == "DOTK" || token[q] == "FORTK")parse21();
	else if (token[q] == "LBRACE") { MatchToken("LBRACE"); parse26(); MatchToken("RBRACE"); }
	else if (token[q] == "IDENFR")
	{
		if (token[q + 1] == "LPARENT") { parse234(); MatchToken("SEMICN"); }
		else { parse18(); MatchToken("SEMICN"); }
	}
	else if (token[q] == "SCANFTK") { parse27(); MatchToken("SEMICN"); }
	else if (token[q] == "PRINTFTK") { parse28(); MatchToken("SEMICN"); }
	else if (token[q] == "RETURNTK") { parse29(); MatchToken("SEMICN"); }
	else if (token[q] == "SEMICN")MatchToken("SEMICN");
	// printf("<语句>\n");
	output << "<语句>\n";
}
void parse18()
{
	//＜赋值语句＞ ::=  ＜标识符＞＝＜表达式＞
	//					|＜标识符＞'['＜表达式＞']'=＜表达式＞
	MatchToken("IDENFR");
	if (token[q] == "LBRACK") { MatchToken("LBRACK"); parse14(); MatchToken("RBRACK"); }
	MatchToken("ASSIGN");
	parse14();
	// printf("<赋值语句>\n");
	output << "<赋值语句>\n";
}
void parse19()
{
	//＜条件语句＞ ::= if '('＜条件＞')'＜语句＞［else＜语句＞］
	MatchToken("IFTK");
	MatchToken("LPARENT");
	parse20();
	MatchToken("RPARENT");
	parse17();
	if (token[q] == "ELSETK")
	{
		MatchToken("ELSETK");
		parse17();
	}
	// printf("<条件语句>\n");
	output << "<条件语句>\n";
}
void parse20()
{
	//＜条件＞    ::=  ＜表达式＞＜关系运算符＞＜表达式＞ //整型表达式之间才能进行关系运算
	//   ｜＜表达式＞    //表达式为整型，其值为0条件为假，值不为0时条件为真                                             
	parse14();
	if (token[q] == "LSS" || token[q] == "LEQ" || token[q] == "GRE"
		|| token[q] == "GEQ" || token[q] == "EQL" || token[q] == "NEQ") {
		MatchToken(token[q]);
		parse14();
	}
	// printf("<条件>\n");
	output << "<条件>\n";
}
void parse21()
{
	//＜循环语句＞ ::=  while '('＜条件＞')'＜语句＞
	//					|do＜语句＞while '('＜条件＞')' 
	//					|for'('＜标识符＞＝＜表达式＞;＜条件＞;＜标识符＞＝＜标识符＞(+|-)＜步长＞')'＜语句＞
	if (token[q] == "WHILETK") {
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		parse20();
		MatchToken("RPARENT");
		parse17();
	}
	else if (token[q] == "DOTK") {
		MatchToken("DOTK");
		parse17();
		MatchToken("WHILETK");
		MatchToken("LPARENT");
		parse20();
		MatchToken("RPARENT");
	}
	else if (token[q] == "FORTK") {
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
		if (token[q] == "PLUS")MatchToken("PLUS");
		else if (token[q] == "MINU")MatchToken("MINU");
		parse22();
		MatchToken("RPARENT");
		parse17();
	}
	// printf("<循环语句>\n");
	output << "<循环语句>\n";
}
void parse22()
{
	//＜步长＞::= ＜无符号整数＞
	parse4();
	// printf("<步长>\n");
	output << "<步长>\n";
}
void parse234()
{
	//＜有无返回值函数调用语句＞ ::= ＜标识符＞'('＜值参数表＞')'
	int FunctionType = VoidFunction[val[q]];
	MatchToken("IDENFR");
	MatchToken("LPARENT");
	parse25();
	MatchToken("RPARENT");
	if (FunctionType == 1)output << "<无返回值函数调用语句>\n";
	else output << "<有返回值函数调用语句>\n";
}
void parse25()
{
	//＜值参数表＞ ::= ＜表达式＞{,＜表达式＞}｜＜空＞
	if (token[q] != "RPARENT")
	{
		parse14();
		while (token[q] == "COMMA")
		{
			MatchToken("COMMA");
			parse14();
		}
	}
	// printf("<值参数表>\n");
	output << "<值参数表>\n";
}
void parse26()
{
	//＜语句列＞ ::= ｛＜语句＞｝
	while (token[q] != "RBRACE")parse17();
	// printf("<语句列>\n");
	output << "<语句列>\n";
}
void parse27()
{
	//＜读语句＞ ::=  scanf '('＜标识符＞{,＜标识符＞}')'
	MatchToken("SCANFTK");
	MatchToken("LPARENT");
	MatchToken("IDENFR");
	while (token[q] == "COMMA") {
		MatchToken("COMMA");
		MatchToken("IDENFR");
	}
	MatchToken("RPARENT");
	// printf("<读语句>\n");
	output << "<读语句>\n";
}
void parse28()
{
	//＜写语句＞ ::= printf '(' ＜字符串＞,＜表达式＞ ')'
	//				| printf '('＜字符串＞ ')'
	//				| printf '('＜表达式＞')'
	MatchToken("PRINTFTK");
	MatchToken("LPARENT");
	if (token[q] == "STRCON")parse0();
	else parse14();
	if (token[q] == "COMMA") { MatchToken("COMMA"); parse14(); }
	MatchToken("RPARENT");
	// printf("<写语句>\n");
	output << "<写语句>\n";
}
void parse29()
{
	//＜返回语句＞ ::=  return['('＜表达式＞')'] 
	MatchToken("RETURNTK");
	if (token[q] == "LPARENT") { MatchToken("LPARENT"); parse14(); MatchToken("RPARENT"); }

	// printf("<返回语句>\n");
	output << "<返回语句>\n";
}
void MatchToken(string expected)
{
	if (token[q] == expected) {
		// cout << token[q] << " " << val[q] << endl;
		output << token[q] << " " << val[q] << endl;
		q++;
	}
	else {
		// printf("shitbrofuckingerror_tm");
		// output << "shitbrofuckingerror_tm" << endl;
		output << "error\n";
		exit(0);
	}
}

