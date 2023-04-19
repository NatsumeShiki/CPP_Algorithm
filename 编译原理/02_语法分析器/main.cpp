#include "WordAnalysis.h"
#include "GrammarAnalysis.h"

int main()
{
	init();
	WordAnalysis();
	GrammarAnalysis();

  for(int i = 0; i < num; i++){
    out << token[i] << " ";
    out << val[i] << endl;
  }

  out.close();
  in.close();

	return 0;
}
