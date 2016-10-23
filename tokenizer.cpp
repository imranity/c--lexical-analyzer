/* CS-3120 Programming Languages Assignment # 3 
Submitted By : Muhammad Malik
NetID : wm6952
CSU East Bay  */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

map <string, int> classes = {{"keyword",0},{"identifier",0},{"digit",0},{"integer",0},{"real",0},{"character",0},{"alpha",0}};
vector<string> ints={"0","1","2","3","4","5","6","7","8","9"}; 
vector<string> keywords={"if","else","then","begin","end"}; 
vector<string> identifiers={"(",")","[","]","+","=",",","-",";"}; 
vector<string> alpha={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"}; 
vector<std::string>::iterator iter;

bool isKeyword(string ch);
bool isIdentifier(char ch);
bool isInteger(char ch);
bool isDigit(string ch);
bool isReal(string ch);
bool isChar(string ch);
bool isAlpha(char ch);
int cnt_keyword=0;
int cnt_identifier=0;
int cnt_digit=0;
int cnt_integer=0;
int cnt_alpha=0;
int cnt_char=0;
int cnt_real=0;

bool isKeyword(string ch){
  iter=find(keywords.begin(),keywords.end(),ch);
if(iter != keywords.end()) {
  classes["keyword"]++;
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
  classes["identifier"]++;
 return true;
}
else
{
  return false;
}
}
bool isDigit(string ch){
  iter=find(ints.begin(),ints.end(),ch);
if(iter != ints.end()) {
  classes["digit"]++;
  classes["integer"]++;
 return true;
}
else
{
  return false;
}
}
bool isInteger(string ch){
   char * p ;
   strtol(ch.c_str(), &p, 10) ;

   if (*p == 0) {
    classes["digit"]++;
    return true;
    
   } 
   else 
    return false;
}
bool isReal(string ch){
 bool isreal=false;
  if (ch.find(".") != std::string::npos)
  {

    for (int j=0; j < ch.length(); j++)
    { 
      if (ch[j]  != '.')
      {  string search ;
        search = ch[j];
         iter=find(ints.begin(),ints.end(),search);
          if(iter != ints.end()) {
             isreal = true;}
         else
          {isreal=false;}
      }
    else
      {;}

    }
  }  
  else
    {;}

    if (isreal == true)
    {
    classes["real"]++;
    return true;}
    else 
      {return false;}


}
bool isAlpha(string ch){
  iter=find(alpha.begin(),alpha.end(),ch);
if(iter != alpha.end()) {
  classes["alphabet"]++;
  classes["character"]++;
 return true;
}
else
{
  return false;
}
}
bool isChar(string ch){
bool ischar=false;

for(int i=0;  i< ch.length(); i++ )
{
   if( isalpha(ch[i]) )
     ischar = true;
   else
     ischar = false;
}

if(ch.length() > 1 && ischar == true ) {
  classes["character"]++;
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
    if (isKeyword(pch)) {
      cnt_keyword++;
    } else if (isIdentifier(pch)) {
      cnt_identifier++;
    } else if (isChar(pch)) {
      cnt_char++;
    } else if (isDigit(pch)) {
      cnt_digit++;
    } else if (isInteger(pch)) {
      cnt_integer++;
    } else if (isReal(pch)) {
      cnt_real++;
    } else if (isAlpha(pch)) {
      cnt_alpha++;
    } else {
      ;
    }
    pch = strtok (NULL, "    ~`!@#$^&*_{}:<>|?");
  }
}
std::cout << "CLASS " << "keyword" << ": " << classes["keyword"] <<  '\n';
std::cout << "CLASS " << "identifier" << ": " << classes["identifier"] <<  '\n';
std::cout << "CLASS " << "digit" << ": " << classes["digit"] <<  '\n';
std::cout << "CLASS " << "integer" << ": " << classes["integer"] <<  '\n';
std::cout << "CLASS " << "character" << ": " << classes["character"] <<  '\n';
std::cout << "CLASS " << "alphabet" << ": " << classes["alphabet"] <<  '\n';
std::cout << "CLASS " << "real" << ": " << classes["real"] <<  '\n';


inFile.close();
  return 0;
}
