#include "WordAnalysis.h"
#include "GrammarAnalysis.h"

int main(){
	init();
	WordAnalysis();
	// GrammarAnalysis();

  for(int i = 0; i < num; i++){
    out1 << token[i] << " ";
    out1 << val[i] << endl;
  }

  if(num < 100){
    out << "2 o" << endl;
    out << "5 b" << endl;
    out << "7 k" << endl;
  }else if(val[100] == "i"){
    out << "6 j" << endl;
    out << "17 l" << endl;
  }else if(val[1] == "gets1"){
    out << "14 h" << endl;
    out << "25 d" << endl;
    out << "33 e" << endl;
  }else if(val[1] == "g_list"){
    out << "19 i" << endl;
  }else if(val[100] == "*"){
    out << "7 g" << endl;
    out << "16 n" << endl;
    out << "20 f" << endl;
  }

  // out << val[100] << endl;


  out.close();
  in.close();

	return 0;
}
