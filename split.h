#ifndef split_h
#define split_h

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo> 
#include <regex>
using namespace std;

//FUNCTION TO SPLIT AN ARRAY OF CHARS INTO A SEPARATE WORD STRING ARRAY
vector <string> split(char stringtosplit[], const char splitter[]){
  
  vector <string> vec;
  
  char* token;
  char* stringtosplitwithoutend;
   // get the first token
  stringtosplitwithoutend=strtok(stringtosplit,"\n"); 
  
  token = strtok(stringtosplit, splitter);
   
   // walk through other tokens

  while( token != NULL ) {
  
    // if(*token=='\n'){
    //   cout<<"ffs";
      
    // }
    
    vec.push_back(token);
    
    token = strtok(NULL,splitter);
  }
  
  //vec.pop_back();
  
  return vec;

} 


#endif