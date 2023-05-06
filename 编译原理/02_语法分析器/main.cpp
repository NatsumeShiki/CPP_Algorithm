#include "WordAnalysis.h"
// #include "WordAnalysis.cpp"
#include "GrammarAnalysis.h"
// #include "GrammarAnalysis.cpp"

int main(){
	init();
	WordAnalysis();
	GrammarAnalysis();

  // for(int i = 0; i < num; i++){
  //   out << token[i] << " ";
  //   out << val[i] << endl;
  // }

  out.close();
  in.close();

	return 0;
}
