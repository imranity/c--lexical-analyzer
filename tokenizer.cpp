

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

map <string,map<string,int>> counter;
vector<string> ints={"0","1","2","3","4","5","6","7","8","9"}; 
vector<string> keywords={"if","else","then","begin","end"}; 
vector<string> identifiers={"(",")","[","]","+","=",",","-",";"}; 
vector<string> alpha={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"}; 
vector<std::string>::iterator iter;

bool isKeyword(string ch);
bool isIdentifier(char ch);
bool isInteger(char ch);
bool isAlpha(char ch);
int cnt_keyword;
int cnt_identifier;
int cnt_integer;
int cnt_alpha;

bool isKeyword(string ch){
  iter=find(keywords.begin(),keywords.end(),ch);
if(iter != keywords.end()) {
  counter["keyword"][ch]++;
 return true;
}
else
{
  return false;
}
}
bool isIdentifier(string ch){
  iter=find(identifiers.begin(),identifiers.end(),ch);
if(iter != identifiers.end()) {
  counter["identifier"][ch]++;
 return true;
}
else
{
  return false;
}
}
bool isInteger(string ch){
  iter=find(ints.begin(),ints.end(),ch);
if(iter != ints.end()) {
  counter["integer"][ch]++;
 return true;
}
else
{
  return false;
}
}
bool isAlpha(string ch){
  iter=find(alpha.begin(),alpha.end(),ch);
if(iter != alpha.end()) {
  counter["alphabet"][ch]++;
 return true;
}
else
{
  return false;
}
}


int main(int argc, char *argv[]) 
{

  int tokenCount = 0; // used to count tokens as they are read 
  
  // at least one command line argument should be supplied
  if (argc < 2) {  
    cerr << "Error: file name argument not given" << endl;
    exit(1);
  }

  ifstream inFile( argv[1], ios::in);  // open file for input

  // checks for errors in opening the file
  if (!inFile) {  
    cerr << "File " << argv[1] << " could not be opened" << endl;
    exit(1);
  }
  
  

  char line[80];      // char array used to hold lines of text input
  char  *pch;     // pointer used to tokenize string
  
  while (inFile.getline(line, 80)) {    // reads upto 80 chars into line array

    pch = strtok(line, "    ~`!@#$^&*_{}:<>|?");    // assigns tokenPtr to  first token in line
  while (pch != NULL)
  {
//    printf ("%s\n",pch);
    if (isKeyword(pch)) {
      cnt_keyword++;
    } else if (isIdentifier(pch)) {
      cnt_identifier++;
    } else if (isInteger(pch)) {
      cnt_integer++;
    } else if (isAlpha(pch)) {
      cnt_alpha++;
    } else {
      cout << "Error " << pch<< endl;
    }
    pch = strtok (NULL, "    ~`!@#$^&*_{}:<>|?");
  }
}
 for(auto& x: counter)
{
  if (x.first == "keyword"){
  std::cout << "CLASS " << x.first <<  ":    TOTAL NUMBER OF "<< x.first<< ": " << cnt_keyword <<  '\n';
  } else if (x.first == "integer"){
    std::cout << "CLASS " << x.first <<  ":    TOTAL NUMBER OF "<< x.first<< ": " << cnt_integer <<  '\n';
  } else if (x.first == "identifier"){
    std::cout << "CLASS " << x.first <<  ":    TOTAL NUMBER OF "<< x.first<< ": " << cnt_identifier <<  '\n';
  } else if (x.first == "alphabet"){
    std::cout << "CLASS " << x.first <<  ":    TOTAL NUMBER OF "<< x.first<< ": " << cnt_alpha <<  '\n';
  } else
  ;
  for(auto const& y : x.second) {
  std::cout << " Element: " << y.first << "        Number of occurences => " << y.second << '\n';
}
}
 //   for (auto& x: counter) {
  //          std::cout << x.first << " => " << x.second.second << '\n';
 //   }  
inFile.close();
  return 0;
}
