#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include <string> 
using std::string; 

#include "proj10_class.h"

int main (){
  //cout<<"aaaaaaaaaaaaaaaaaa";
  cout << boolalpha;
  // Element<string, string> e1;
  // e1.key_ = "abc";
  // e1.values_[0] = "a"; 
  // e1.values_[1] = "b";
  // e1.values_[2] = "c";
  // e1.count_ = 3; 
  // cout << e1 << endl;
  // Element<string, string> e2("abc", {"a", "b", "c"} );
  // cout << (e1 == e2) << endl;
  
  MVM< long, string> mvm1 { {10, {"a","b", "c","d", "e"}},  {50, {"x","y","z"}}   }; 

//   cout << "mvm " << endl<<  mvm1 << endl;

  //  auto result = mvm1.find_key("abc");
  //  cout << result->key_ << endl;
  //  string * result_key = nullptr; 
  // size_t size_result_key = mvm1.find_value("a", result_key);
  //cout<<mvm1<<endl;
//   copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
//    cout <<"\n"<<mvm1.size() << endl;
//   delete [] result_key; 
// result_key = nullptr; 
// cout<< endl;
// cout<< endl;

// cout << mvm1.add(30,"q") << endl;

// cout << mvm1.add(20,"a") << endl;

// cout << mvm1.add(30,"a") << endl;
// cout<<mvm1<<endl;
// cout << mvm1.add("30", "d") << endl; // pass
// cout << mvm1.add("30", "d") << endl;  



cout<< mvm1.remove_key(10) << endl;
//cout<< mvm1.remove_key("tuv") << endl;
cout<< mvm1.size() << endl;




cout<< endl;

cout << "after adding" << endl;

cout<< endl;
cout<< endl;

cout << mvm1 << endl;

// size_result_key = mvm1.find_value("a", result_key);
// copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
//   cout <<"\n"<< mvm1.remove_key("bcd") << endl;
//   delete [] result_key; 
//   result_key = nullptr; 
//   cout << mvm1 << endl;
//   size_result_key = mvm1.remove_value("a", result_key);
//   copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
//   cout << "\n" << mvm1 << endl;
//   delete [] result_key; 
//   result_key = nullptr; 
 }
