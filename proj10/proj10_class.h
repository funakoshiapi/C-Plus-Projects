//CSE 232
//Project 10
//Online section

// TA's helped me complete some of the function in this project


// The following project uses the MVM system and is simmilar to project 9 with the exception that intead of using vectors, arrays are being used in place of vectores.
// The fllowing source code manages the addition of ellements in a MVM, the removal, the size count of the MVM, and necessary parameter to storage and access of elements inside of the MVM.




#pragma once
#include<iostream>
using std::cout; using std::endl; using std::boolalpha; using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <algorithm> 
using std::max; using std::copy; using std::swap;
using std::copy; using std::lower_bound;
using std::find;using std::sort;using std::transform; 
#include <utility> 
using std::make_pair; using std::pair; 
#include <stdexcept> 
using std::runtime_error; 
#include <array>
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<sstream>
using std::ostringstream;
//using std::ostream_iterator; using std::back_inserter;
#include<iterator>
using std::ostream_iterator;


const static size_t element_array_size = 5; // define to 5
long my_count=0;
template<typename K, typename V>
struct Element{
public:
  K key_;
  V values_[element_array_size];
  size_t count_ = 0; 
  Element()=default;
  Element(K, initializer_list<V>); // ini
  bool operator==(const Element&)const;
  bool operator<(const K&) const; 
  
  friend ostream& operator<<(ostream& oss, Element& ele){
    
     oss<< ele.key_ <<":";
     int i =0;
     //auto array_sz = sizeof(ele.values_) / sizeof(ele.values_[0]); 
     for ( i = 0 ; i < my_count-1; ++i){

       oss << ele.values_[i];
       oss<< ",";
     }
     oss << ele.values_[i];
     my_count = 0;
     return oss;

  }
 
};

//Code for Element functions goes here
template<typename K, typename V>
bool Element<K,V>::operator ==(const Element& m )const{
//  Two Elements are equal if their two keys_ are equal and if their two values_ are equal.
// o return true if the two Elements meet this condition, false otherwise.
// o this is a member function.

// if (std::equal(std::begin(values_), std::end(values_), std::begin(m.values_)) && m.key_ == key_){

//   return true;
// }
//     return false;

// }

if ( m.key_ == key_ ){
  if (count_ == m.count_){
    for (size_t i= 0; i < count_; i++){

      if (m.values_[i]!=values_[i]){
        return false;
      }
    }
    return true;
  }
}

return false;

}

template<typename K, typename V>
   Element<K,V>::Element(K key, initializer_list<V> values){

// Instead of copying into the vector, copy into the array values_. The number of elements being
// copied will never exceed the fixed size of values_. Must setup count_ properly
    key_ = key;

  int index= 0;

  for(auto v : values) {

       if (count_ <= 5-1) {
         values_[index]= (v);
       }
       ++count_;
       ++index;
       ++my_count;
  }   
  }

template<typename K, typename V> 
class MVM{
public:
  Element<K, V> * data_ = nullptr;
  size_t num_keys_ = 0; 
  size_t num_elements_ = 0; 
  Element<K, V> * find_key(K);
  size_t find_value(V, K*&);
  void grow(); 

public:
  MVM()=default;
  MVM(initializer_list<Element<K,V>>);
  MVM(const MVM&); 
  ~MVM(); 
  size_t size();
  bool add(K,V);  
  bool remove_key(K);
  size_t remove_value(V, K*&);
  
friend ostream& operator<<(ostream& output, const MVM& mvm){
    
    // used to print to oss

      ostringstream oss;
      string s;

 
      long distance = std::distance(mvm.data_,mvm.data_+ mvm.num_keys_);

      for (int i = 0; i < distance  ; ++i) {

       auto ele = mvm.data_[i];

      oss << ele.key_ << ":";

      copy(ele.values_, (ele.values_ + ele.count_-1 ), ostream_iterator<V>(oss, ","));
      oss<<ele.values_[ele.count_-1];
      oss<<" ";

    }
        s = oss.str();
        output << s.substr(0, s.size()-1);
        return output;
  }
};

// Code for MVM functions goes here

  template<typename K, typename V>
  MVM<K,V>::MVM(initializer_list<Element<K,V>> ini_list){
      
      // initialize the mvm
      
      num_keys_ = ini_list.size();
      num_elements_ =  ini_list.size();

      data_ = new Element<K,V>[num_elements_];

      copy(ini_list.begin(), ini_list.end(), data_ );

  } 


//Deconstructor
template<typename K, typename V>
MVM<K, V>::~MVM() {
  
    // num_keys_=0;
    // num_elements_=0;
    
    delete [] data_;
}


template<typename K, typename V>
Element <K,V>* MVM <K,V>::find_key(K key){
    
    // search for the key
    
    

    Element<K,V>* position = lower_bound(data_, data_+ num_keys_, key, [](auto  n, auto  search){

        return (n.key_ < search);
        
        });

    return position;
}

template<typename K, typename V>
void MVM<K,V>::grow(){
    
    // expands the array

    Element<K,V> *array;
    
    if (num_elements_ == 0 && data_ == nullptr){
        num_elements_=2;
        data_ = new Element<K,V>[2];
  
    }
    else{

// Otherwise, reallocate data_ with twice as many num_elements_ and the correct keys stored
// internally, taking care to manage the dynamically allocated memory correctly 

        array = new Element<K,V>[num_elements_ * 2];
        copy(data_, data_+ num_keys_, array); 
        num_elements_*= 2;
        swap(data_,array);
        delete [] array;
    }
}


template<typename K, typename V>

size_t MVM <K,V>::find_value(V val, K*& key) {
    
    // finds the value of key mvm



     if (key != nullptr){

      throw runtime_error ("error");

      }  

     size_t count = 0;

    // Element<K,V> *array;

    for (size_t i = 0 ; i < num_keys_; ++i)
    {    
      auto p = data_[i];

      for( size_t b = 0 ; b < p.count_ ; ++b){
          

          auto my_val = p.values_[b];
          
          if (my_val == val){
              ++count;
          }
      }
    }

    
    if (count == 0){

      return 0;
    }   

    key = new K [count];

    size_t index=0;

    for (size_t i = 0 ; i < num_keys_; ++i)
    {
      auto p = data_[i];

      for( size_t b = 0 ; b < p.count_ ; ++b){

          auto my_val = p.values_[b];

          if (my_val == val){
              
              key[index] = p.key_;
              ++index;

          }
      }

    }

    

  return count;

}


template<typename K, typename V>

// return the size of mvm

size_t MVM<K,V>::size(){
    
    return num_keys_;
}


//ADD FUNCTION?//////////////////////////////


template<typename K, typename V>
bool MVM<K,V>::add(K key,V value){
    
    
    // Adds a new value following precense parameters



auto a = find_key(key);

//// if The key exists. Check the value

if( a != data_+ num_keys_ ){



// when the keys are the same

if( a ->key_ == key){
    
    // for (size_t i = 0 ; i < num_keys_; ++i){ 

    //   auto p = data_[i];
    
      auto p = *a;

    for( size_t b = 0 ; b < p.count_ ; ++b){

        auto my_val = p.values_[b];
        
        // updadted 
        
        // if (my_val != value){
            
        //      p.count_++;
        //      p.values_[p.count_] = value;
            
        // }
        
        
        // when the keys is the sam and the value is also the same
        if (my_val == value){
            
            return false;
        } 
        
        

    }
    //cout<<"Holla"<<p.count_<<endl;
    

    if (p.count_ == element_array_size){

        return false;
        
    }
        
  //}



    //if (p.count_ <=  element_array_size ){ // modified
        
       
       
       
       
       
       // when the keys are the sam and the values are differnt
       // place in array;
       // increase the count
       
       a->values_[p.count_]=value; // modified
       a->count_++;
       
       
       
       // new Code

}


else{

  // if (a->key_ != key  ){
  
  
  
         
         if ( num_keys_ == num_elements_){
 
                grow();
                
                a = find_key(key);
  
            } 
        
        
        
        // reorganize my values so that i can insert my element in the correct place.
         for (auto i = num_keys_ + data_ -1 ; i >= a; i-- ){

            *(i+1) = *i; 
         }
         
        
        // inserting the elemnt at the desired location
        *a = Element< K , V> ( key, { value } );
         num_keys_ = num_keys_+1;

   // }

}


}

else{

// fORCING IT to grow first so that
// new elements ca be stored
if ( num_keys_ == num_elements_){
 
  grow();
  
} 

  *(data_ + num_keys_) = Element< K , V> ( key, { value } );
   num_keys_ = num_keys_+1;
}


    return true;
} 





template<typename K, typename V>
bool MVM<K,V>::remove_key(K key){
    // will remove keys
    
  auto a = find_key(key);   
  
 if( a != data_+ num_keys_ ){


  if (a->key_ == key){

    //d = std::distance (data_,a);

    for (auto i = a ; i < num_keys_ + data_-1; i++ ){
        
          *i = *(i+1);
        
        
    }
 num_keys_--;
  return true;
  }

}
  
return false;


   
  }

template<typename K, typename V>
size_t MVM<K,V>::remove_value(V value, K*& key){
    
    // This funtion is not completed I ran out of time.
    
    // size_t count = 0;
    
    //  auto keys_count = find_value(value); // arry size to be allocated allocation
    
    //  auto a =  find_key(key);  // pointer
     
    //   if (key != nullptr){

    //   throw runtime_error ("error");

    //   }  
      

    // for( size_t b = 0 ; b < a->count_ ; ++b){

    //     if (auto my_val = a->values_[b] == value){
            
    //         for (auto i = a ; i < num_elements_ + data_-1; i++ ){
        
    //           *i = *(i+1);}
        
        
    // }
    // num_elements_--;
    
    // count ++;
    // //return true;
            
    //     }
    
    
    return false;
    
    
}


   








