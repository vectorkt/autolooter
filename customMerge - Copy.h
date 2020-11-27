#ifndef customMerge
#define customMerge

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo> 
#include <regex>
using namespace std;


//TEMPLATED MERGE SORT
template <class customType> void merge(vector<customType>& larray,vector<customType>& rarray,vector<customType>& oarray){
  
  int l=0;
  int r=0;
  int a=0;
  int lsize=larray.size();
  int rsize=rarray.size();
  
  while(l<lsize && r<rsize){
    if(larray[l]<rarray[r]){
      oarray[a]=larray[l];
      l++;
      a++;
    }
    else{
      oarray[a]=rarray[r];
      r++;
      a++;
    }
  }
  
  
  if(l<lsize){
    for(l;l<lsize;l++){
      oarray[a]=larray[l];
      a++;
    }
  }
  if(r<rsize){
    for(r;r<rsize;r++){
      oarray[a]=rarray[r];
      a++;
    }
  }
  
}


template <class customType> void mergeSort(vector<customType>& oarray){
  
  int size=oarray.size();

  if(size>1){
    int mid=size/2;
    int lsize=mid;
    int rsize=size-lsize;
    vector<customType> leftarray;
    int a=0;
    for(a;a<lsize;a++){
      leftarray.push_back(oarray[a]);
      
    }
    
    //printarray(leftarray,leftsize);
    
    vector<customType> rightarray;
    for(int r=0;r<rsize;r++){
      rightarray.push_back(oarray[a]);
      a++;
      
      
    }
    //nl();
    //printarray(rightarray,rightsize);
    
    mergeSort(leftarray);
    mergeSort(rightarray);
    merge(leftarray,rightarray,oarray);
    
    
  }
  
}


#endif