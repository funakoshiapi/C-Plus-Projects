

// CSE 232
// PROJECT 2

// This program calculates the juggler sequence between a given range by the user.
// The program outputs the starting number of the sequence that generated the largest number and its largest number.
// The program outputs the starting number of the sequence that generated the largest length and its length.





#include<iostream>
#include<cmath>

int main()

{
    
    long  start = 0;
    long  stop = 0;
    int my_switch = 1;
    
    std::cin >> start;
    std::cin >> stop;
    
    if (stop < start)
    {
        std::cout << "Error"<< std::endl;
        my_switch = 0; // This variable will help decide if the code in line 93 will be executed.
    }
    
    
    long length_1 = 0;
    long length_large = 0;
    long next_number=0;
    long largest_num=0;
    long next_in_range = start;
    long initial_big = 0;
    long initial_length = 0;
    
    
    if(stop >= start)
        
        
    {
        while (next_in_range < stop)
            
        {
            
            start = next_in_range;
            
            while (start != 1)
                
            {
                if (start % 2 == 0) // chek if the valeu is even
                    
                {
                    next_number = floor(sqrt(start));
                    
                    length_1 ++; // checking the length of sequence
                    
                    if (next_number > largest_num)         // checking largest number.
                    {                                      // When the largest number is found
                        largest_num = next_number;         // the code assumes that the starting number of
                        initial_big = start;               // the sequence that generated the largest number was found
                        
                    }
                    
                }
                
                else // odd
                    
                {
                    //the precision of my largest valeu was off when using this formula. I don't understand why...
                    //next_number = floor(sqrt(start)*sqrt(start)*sqrt(start));
                    
                    
                    next_number = floor(pow (start, 1.5) );
                    
                    length_1 ++;
                    
                    if (next_number > largest_num)
                    {
                        largest_num = next_number;
                        initial_big = next_in_range;
                    }
                }
                
                start = next_number; // Pass the next number of the sequence as new starting point,
                                    // in order to calculate the following number of the sequence
            }
            
            
            if ( length_1 > length_large )
            {
                length_large = length_1;
                initial_length = next_in_range; // The program assume that when largest length is found
                                                // the starting number of the sequence that generated the largest length was found
            }
            
            length_1 = 0; // zeroing the lenthg variable to calculate the length of the next sequence
            next_in_range++; // update to next number in the range
            
        }
        
    }
    
    if (my_switch == 1)
        
    {   std::cout << std::fixed;
        std::cout << initial_length << " " << length_large << std::endl;
        std::cout << initial_big << " " << largest_num << std::endl;
        
    }
    
    return 0;
    
}
