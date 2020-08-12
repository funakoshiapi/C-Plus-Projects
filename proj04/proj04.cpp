





 // Readme.. (Project 3 had no comments because I assumed that since the class had no
 // coding standards for comments, it was not required. It was only mantioned that it was good practice.
 // Can I please have my points back for project 3? )


// Project04

// This source code allows the user to input a string, and get to know what type the 
// the inputed string is.
// Makes use of functions and string manipulation.





#include <iostream>
#include <string>
#include <cctype>
#include<cmath>
#include <algorithm>




using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::isalpha;
using std::isdigit;
using std::string;

// Function Declaration

bool valid_hex(string to_test);
bool valid_octal(string to_test);
bool valid_binary(string to_test);
bool valid_int(string to_test);
bool valid_float( string to_test);
string classify_string(string to_test);


int main()
{

  cout << boolalpha;
  int testnum;
  cin >> testnum;

  switch (testnum)
  {
  case 1:
  {
    string to_test;
    cin >> to_test;
    cout << valid_hex(to_test) << endl;
    break;
  }

    case 2:{
    string to_test;
    cin >> to_test;
    cout << valid_octal(to_test) << endl;
    break;
  }

  case 3:{
    string to_test;
    cin >> to_test;
    cout << valid_binary(to_test) << endl;
    break;
  }

  case 4:{
    string to_test;
    cin >> to_test;
    cout << valid_float(to_test) << endl;
    break;
  }

  case 5:{
    string to_test;
    cin >> to_test;
    cout << valid_int(to_test) << endl;
    break;
  }

  case 6:{
    string to_test;
    cin >> to_test;
    cout << classify_string(to_test) << endl;
    break;
  } 
}
}

// Function Definition

bool valid_hex(string to_test)

// will check it the string input is be a hexadecimal number
// returns true if is hexadecimal and  false otherwise
{

  int size = to_test.size();

  // slicing the string in order to check if 
  // the string starts with the desired numbers or letters

  if ((to_test.substr(0, 2) == "0x"))
  {

    // looping through the string in order to read 
    // to check if each character  is not a digit 

    string test_1 = to_test.substr(2);
    for (int i = 0; i < test_1.size(); i++)
    {


      char c = test_1[i];

    // If the chracter is not a digit then will return false

      if (isxdigit(c) == 0)
      {
        return false;
      }
    }
  }

// accounting for the the negative hexadecimal numbers

  else if (to_test.substr(0, 3) == "-0x")
  {

    string test_2 = to_test.substr(3);
    for (int i = 0; i < test_2.size(); i++)
    {

      char c = test_2[i];
      if (isxdigit(c) == 0)
      {
        return false;
      }
    }
  }

  else
  {
    return false;
  }

  return true;
}

bool valid_octal(string to_test)

// will check it the string input is be a octal number
// returns true if is octal and  false otherwise

{
    int size = to_test.size();

    // checking if the first index of the string is 0

    if ( to_test.substr(0,1) == "0") {

      string test_1 = to_test.substr(1);
      //cout<< test_1 << endl;

      // this loop checks if the string fullfils the requirements for 
      // octal number
      for (int i = 0; i < test_1.size(); i++)
      {

        char c = test_1[i];
        if (isdigit(c) == 0 || (c > '7'))
        {
          return false;
        }
      }

    }

    else if ( to_test.substr(0,2) == "-0") {

      string test_2 = to_test.substr(2);
      for (int i = 0; i < test_2.size(); i++)
      {

        char c = test_2[i];
        if (isdigit(c) == 0 || ( c >'7'))
        {
          return false;
        }
      }

    }

    else{return false;}

return true;
}

// simillar idea as above was followed for the binary function

bool valid_binary(string to_test){

  // will check it the string input is be a binary number
// returns true if is binary and  false otherwise


    int size = to_test.size();

    if ( to_test.substr(0,2) == "0b") {

      string test_1 = to_test.substr(2);
      //cout<< test_1 << endl;
      for (int i = 0; i < test_1.size(); i++)
      {

        char c = test_1[i];
        if (c != '0' && c != '1')
        {
          return false;
        }
      }

    }

    else if ( to_test.substr(0,3) == "-0b") {

      string test_2 = to_test.substr(3);
      for (int i = 0; i < test_2.size(); i++)
      {

        char c = test_2[i];
        if (c != '0' && c != '1')
        {
          return false;
        }
      }

    }

    else{return false;}

return true;
}



bool valid_int(string to_test)

// will check it the string input is be a int number
// returns true if is int and  false otherwise

{     
  // accounts for the situation were -0, 01, -01 are inputed

      if ( to_test.substr(0,2) == "-0"  ) {

        return false;

      }

      if ( to_test.substr(0,1) == "0" && to_test.substr(1,1) > "0"  ) {

        return false;

      }  

        for (int i = 0; i < to_test.size(); i++)
      {

        char c = to_test[i];

    

        if (isdigit(c) == 0){

                if (c == '-' && i == 0){
                  ;
                }
                else{
                  return false;
                }

                if (c == '.') { 
                     return false;
                      break ; 
                }
        }

         
      }
      return true;
}

bool valid_float( string to_test){

  // will check it the string input is be a float number
// returns true if is float and  false otherwise


  if (valid_int (to_test) == true){
      return false;
  }

  else{


int e_count =0;
int dot_count=0;

// the for loop takes track of the number of times "." or "-" appears 

 for (int i = 0; i < to_test.size(); i++)
      {
        
        char c = to_test[i];
        
        if (!isdigit(c)){

                
                if (c =='.') { 
                
                //cout<< dot_count<<endl;

                  dot_count = dot_count+1;     // increment each time '.' is found
                  if (dot_count > 1){          // return false if more then one '.' is found

                      //  cout<< dot_count<<endl;

                        return false;
                  }  
                } else if (c == 'e'){

                  e_count = e_count+1; // increment each time 'e' is found
                  if (e_count>1){     // return false if more then one 'e' is found

                    return false;
                  }  
                }
                else if (c != '-'){  
                  return false; 
                }
        }
      }
  }

return true;

}
string classify_string(string to_test){

  // will check it the string input is a hex, octal, binary, int or float number
// returns a string containing the type name  and returns  
//false if is not a hex, octal, binary, int or float number



if (to_test == ""){

  return "false";
}

 if (to_test == " "){

  return"false";
}

if (valid_int (to_test)){

    //cout<< "integer"<< endl;
    return "int";
  }

 if ( valid_octal(to_test)){
      //cout<<"octal"<<endl;
      return "octal";

  }  
 if (valid_float (to_test)){
      //cout << "float" <<endl;
      return "float";
  } 


if (valid_binary(to_test)){
     // cout<<"binary"<<endl;
     return "binary";
  }  
 


 if ( valid_hex(to_test)){
      //cout<<"hex"<<endl;
      return"hex";

  } 


return"false";
 
}