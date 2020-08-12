
// proj 07
// cse 232
// The following source code intends to perform pattern recognition between two documents

#pragma once
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include <string>
using std::string;
#include<map>
using std::map;
#include <fstream>
using std::ifstream;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::pair; using std::make_pair;
#include <algorithm>    // std::set_intersection, std::sort
using std::set_union; using std::set_intersection;
using std::set_difference;
using std::set_symmetric_difference;
using std::sort; using std::find;



ostream& print_vector( ostream& out, const vector<string>& v) {
  //print the vector to the provided stream, returning that stream. Each
//printing vector in single line

  //out << '"';
for(int index=0;index<v.size();index++)

{
   if( index<v.size() && index+1 != v.size() )
    
      {out<<v[index]<<",";}
    
    else{ out<<v[index]; } // avoids printing , at the end
}
  //out<<std::endl;
  //out << '"';

    return out;
}
 

string clean_word(const string& input){
  //Create a new string where you remove any non-
//alphabetic characters and lower 
//case everything. Return that new string
  

   string new_input = "";
   int i=0;
  
 
  while ( i<input.size() ){
      
       if(isalpha(input[i]) ) // exclude non alphabetic characters
       {
           new_input += tolower(input[i]); // add string , pass to lower case
       }

       i++; // next element
      
   }
  
   return new_input;
}

std::vector<string> split(const string &s, char delim){
  //Take in the string, return a vector where the string is split by the 
//parameter character 
//delim

  long index = 0;

  string my_str= "";

  vector<string> vec_container;


  while ( index <s.size() ){

    if (s[index] != delim){ // if not ' '

      my_str += s[index]; // add the element strings

    }
    else{
      vec_container.push_back(my_str); // perform split
      my_str = ""; // reset the string, because we have splited
    }
    
    ++index; // next element
  }

  vec_container.push_back(my_str);


return vec_container; // returns the the final vector with the splited strings
}


