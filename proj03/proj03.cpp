
// Project 03

// The following source code implements functions that check if
// a number is prime, powerful, perfect porwer, or achilles, based on the
// selected case.

// TA, helped me completing some of the functions in this project



#include<iostream>
#include<cmath>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
// add any other includes you like.



// Functions declaration

bool is_prime( long num);
bool is_powerful(long num);
bool is_perfect_power(long num);
bool is_achilles(long num);



// main is below. You cannot modify main
int main () 
{

    cout << boolalpha;

    int test_case;
    cin >> test_case;

    switch (test_case)
    
    {

    case 1 : {
        long num;
        cin >> num;
        cout <<  is_prime(num) << endl;
        break;
    } // of case 1

    case 2 : 
    {
        long num;
        cin >> num;
        cout << is_powerful(num) << endl;
        break;
    } 
    
    // of case 2 

     case 3 : {
        long num;
        cin >> num;
        cout << is_perfect_power(num) << endl;
        break;
    } // of case 3   

    case 4 : {
        long num;
        cin >> num;
        cout << is_achilles(num) << endl;
        break;
    } // of case 4  
        
    } 
 }  



// Function definition


bool is_prime( long num)
{
    bool flag = true;

    for(int index=2; index <= num/index; ++index)

    {
        if (num % index == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;

}

bool is_powerful(long num)
{
    bool factor_1;
    bool factor_2;
    bool factor_3;
    long n = num;

    if (is_prime(num) == true)
    {

        return false;

    }

    else

    {

         while (n % 2 == 0) 
        { 
            int a = 2;

            if ( a*a % num != 0)   
                factor_1 = false;

            else
            {
                factor_1 = true;
            }

            n = n/2; 
        } 
    
        for (int index = 3; index <= sqrt(n); index = index+2) 
        { 
        
            while (n%index == 0) 
            {   
                n = n/index; 

                if ( index*index % num != 0)

                    factor_2 = false;

                else{
                    factor_2 = true;
                    }
                
            } 
        } 
    
        if (n > 2) {

            if ( n*n % num != 0)

                factor_3 = false;

            else
            {
                factor_3 = true;

            }
    
        }  

        if ( factor_1 != factor_2 && factor_1 != factor_3)

            return false;

        else
        {
        return true;
        }
    } 
}

bool is_perfect_power(long num)
{   
	
    for (long power=2; pow(2,power) <= num ; power++  ) 
    {
        
        // std::cout<< power;

        long r = round(pow(num, 1.0/power));

        //std::cout<< " " << power;

        //std::cout<< " " << r;   

        if (pow(r,power) == num){
            return true;
        }

    } 


	return false; 

}
        
bool is_achilles(long num)
{

    if (is_powerful(num)== true && is_perfect_power(num)== false)
        {
            return true;
        }

    else
        {
            return false;

        }




}





