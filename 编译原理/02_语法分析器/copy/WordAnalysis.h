
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
map <string, string>category;
int length = 0;
char in[MAXN];
//vector<char> in;
int num = 0;
vector<string> token;
vector<string> val;

bool IsDigit(char c);
bool IsLetter(char c);
void read();

