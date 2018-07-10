#ifndef items_and_methos
#define items_and_methos

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo> 
#include <regex>
using namespace std;

// ITEM AND METHODS
class item{
  public:
    string name;
    float value;
    float weight;    
    float profit;
    item(string,float,float,float);
    void displayItem();    
};

item::item(string name,float value,float weight,float profit){
  this->name=name;
  this->weight=weight;
  this->value=value;
  this->profit=profit;
}


void item::displayItem(){

  cout<<this->name<<"(Value: "<<this->value<<", Weight: "<<this->weight<<", Profit: "<<this->profit<<")"<<endl;

}

void displayContainer(vector<item> Container){

  cout<<"Name | Val  | Wt   | Prof";  
  for(int c=0;c<Container.size();c++){
    cout<<Container[c].name<<"|"<<Container[c].value<<"|"<<Container[c].weight<<"|"<<Container[c].profit<<endl;


  }

}


bool operator<(const item& a, const item& b){

  return a.profit<b.profit;

}

bool operator>(const item& a, const item& b){

  return a.profit>b.profit;

}

bool operator==(const item& a, const item& b){

  return a.profit==b.profit;

}



#endif