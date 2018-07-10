#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo> 
#include <regex>
#include "customMerge.h"
#include "items.h"
#include "split.h"
using namespace std;

int main() {


  // INPUT METHODS AND SANITIZING THROUGH REGULAR EXPRESSIONS
  string input;
  float inventory_capacity;
  

  string temp_name;
  float temp_value;
  float temp_weight;
  float temp_profit;

  cout<<"Please input your inventory capacity(1-100):";
  cin>>input;

/*
  regex condition("[1-9]|[1-9][0-9]|100"); 

  while(!regex_match(input, condition)){

    cout<<"Wrong input, must be a number(1-100)"<<endl;
    cin>>input;

  }
  */
  cout<<endl;
  

  inventory_capacity=(float) stoi(input);

  
  vector<item> Chest;
  vector<item> Inventory;
  

  FILE *in;
  int buffersize=100;
  char buffer[buffersize];
  vector<string> inputProcessing;

  in = fopen("chest1.txt" , "r");
  while( fgets(buffer,buffersize,in)!=NULL){


    inputProcessing=split(buffer," ");
    temp_name=inputProcessing[0];
    temp_value=(float) stoi(inputProcessing[1]) ;
    temp_weight=(float) stoi(inputProcessing[2]);
    temp_profit=temp_value/temp_weight;
    

    Chest.push_back(item(temp_name,temp_value,temp_weight,temp_profit));

  }





mergeSort(Chest);


//NOTE: CHEST HAS BEEN SORTED ASCENDING BY PROFIT, WHICH IS WHY WE ARE GOING BACKWARDS THROUGH THE VECTOR

int c=Chest.size()-1;

while(inventory_capacity>0 && c>=0){

  cout<<"Analyzing item: "<<endl;
  Chest[c].displayItem();
  
  if(Chest[c].weight<=inventory_capacity){

    cout<<"Taking item"<<endl;

    
    inventory_capacity-=Chest[c].weight;
    Inventory.push_back(Chest[c]);    
      
  }
  c--;
  cout<<endl;

}

cout<<endl;

cout<<"Items kept in inventory:"<<endl;
for(int i=0;i<Inventory.size();i++){
  
  Inventory[i].displayItem();

}


  //cout <<endl<< "end of program";



}