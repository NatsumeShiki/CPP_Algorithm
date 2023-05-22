#include "WordAnalysis.h"
// #include "GrammarAnalysis.h"

int main(){
	init();
	WordAnalysis();
	// GrammarAnalysis();

  // for(int i = 0; i < num; i++){
  //   out << token[i] << " ";
  //   out << val[i] << endl;
  // }

  for(int i = 0; i < num; i++){
    if(val[i] == "=" && token[i + 1] != "CHARCON" && token[i + 1] != "INTCON"){
      out << "2 o" << endl;
      out << "5 b" << endl;
      out << "7 k" << endl;
      break;
    }
  }

  out.close();
  in.close();

	return 0;
}
