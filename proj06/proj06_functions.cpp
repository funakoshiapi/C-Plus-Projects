/* 

Project 6

03/11/2019
Section 730

The following soucre code allows to works with 2D to 1D matrix 

*/

// Had help from TA in order to complet some of the function in this project

#pragma once
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include <string>
using std::string;


long result (const vector<long>& v, int rows, int cols);

long index_check (const vector<long>& v, long index, int stop ){
  

// check if the valeu of the is equal v -1

    if (index == v.size() - 1){
            stop = 1;
        }
    return stop;
}

ostream& print_vector(const vector<long>& v, ostream& out) {
  //print the vector to the provided stream, returning that stream. Each
   //element of the vector is separated from the next by a comma, no comma 
   //after the last element.
    for (long index = 0; index < v.size(); ++index) {
        int stop = 0;

        std::string c = ",";

        out << v[index];

        if (index_check(v, index, stop) == 1){
            break;
        }
        out << c;
    }
    return out;
}

long four_corner_sum(const vector<long>& v, int rows, int cols) {
    //return the sum of the 4 corners of the provided 1D vector, interpreted as a 2D matrix with
    //provided row and column count.

    int ref = 2; 

    // if there are less than either two rows or two columns (thus no corners), return 0.

    if (rows < ref ){
        return 0;
    }
    else if (cols < ref) {

        return 0;
    }

  return result (v,rows, cols);
}

long result (const vector<long>& v, int rows, int cols){

/*
number of columns in the 2D vector. Row = index/N (integer division), where N is the nber of columns.
column = index%N (modulus), where N is the nber of columns
index = row * N + column, where N is the nber of columns
*/

    long r = v[0];
    r = v[cols - 1] + r;
    r = v[(rows - 1) * cols] +r ;
    r = v[(rows - 1) * cols + (cols - 1)] + r;

    return r;


}

vector<long> rotate_rows_up(const vector<long>& v, int rows, int cols) {
//return a new vector that is a rotation of the 2D matrix rows up by one. Here, 
//the 2 row becomes the 1st, the 3rd the 2nd etc. and the 1st row becomes the last.
    vector<long> array;

    if (rows > 2){

    //iteration
    //( position, size (nber of times a valeu is to be inserted), valeu )  
    array.insert(array.begin(), v.begin() + cols, v.end());

    array.insert(array.end(), v.begin(), v.begin() + cols);
    
}
    // check for row size
    if (rows < 2){
        
        return array; // empty

        }


    return array;
}

vector<long> change_to_colum(const vector<long>& v, int rows, int cols, vector<long> array){

        long change;
        int flag = 0;
            
         for (long c = 0; c < cols; ++c) {

            for (long r = 0; r < rows; ++r){ 

                change = r*cols+c;
         
                array.push_back(v[change]);
        }    
    }   
        return array;
}

vector<long> column_order(const vector<long>& v, int rows, int cols) {
//return a new vector that is a reordering of the original 1D vector in 
//column order. Collect each column, first to last, and within the column 
//in row order.
    vector<long> array;
   
    return change_to_colum(v,rows, cols, array);
}


vector<long> rotation_90(const vector<long>& v, int rows, int cols, vector<long> array){
// execute 90 degres rotation

    for (int c = cols - 1; c >= 0; --c) {

        for (int r = 0; r < rows; ++r)
            array.push_back(v[r * cols + c]);
    }
    return array;
}


vector<long> matrix_ccw_rotate(const vector<long>& v, int rows, int cols) {
//Take the sum of each column. Given those column sums find 
//the maximum difference between any of the two column sums 
//in the matrix. Return the max difference
    vector<long> array;
    
    return rotation_90(v, rows, cols, array);
}

long max_( long max,  long count){

    if (count > max) //check if greatest
    {
                max = count;
                return max;
    }
    
     return max;

     
} 

long min_( long min, long count){

  
    if (count < min)
    {

        // check if lowest
            min = count;
            return min;
                  
    } 
     return min;

     
} 





long max_column_diff(const vector<long>& v, int rows, int cols) {
/*
Take the sum of each column. Given those column sums find the maximum difference between any of the two column sums in the matrix. Return the max difference.
*/
    long max = 0; // greater then 0 will be max
    long min = 8999; // lowest then 8999 will be min
    long count = 0;
    int c = 0;
    long change;

    for (int c=0; c < cols; ++c) {

        for (int r = 0; r < rows; ++r){
            change =r * cols + c;
            count += v[change];
            }
        
         max = max_( max,count);

         min = min_(min,count);

       
        
            count = 0;
    
    }

    return max-min;
}

long left_rigth (const vector<long>& v, int rows, int cols) {

    long n = 0;

    for (int r = 0; r < rows; ++r) {

        for (int c = 0; c < cols; ++c) {

            long value = v[r * cols + c];

            long left = v[r * cols + c - 1];

            long right = v[r * cols + c + 1];

            if (c == 0) 
                left = v[r * cols + cols - 1];
            if (c == cols - 1) 
                right = v[r * cols];
            

            if (value < left || value < right)
                n += 1;
        }

    
}
    return n;
}


long check(long v, long u, long d, long l, long r, long n){

    
    if (v < u || v < d || v < l || v < r)
        n += 1;

return n;
}

long trapped_values(const vector<long>& v, int rows, int cols) {
/* 

 looking to see if any of values in the 2D matrix have 4 neighbors (up, down, left, right) that are all greater than that value. If so, the value is trapped. We return the nber of trapped values.


*/
    long n = 0;

    for (int r = 0; r < rows; ++r) {

        for (int c = 0; c < cols; ++c) {

            long value = v[r * cols + c];

            long up = v[(r - 1) * cols + c];

            long down = v[(r + 1) * cols + c];

            long left = v[r * cols + c - 1];

            long right = v[r * cols + c + 1];

            if (c == 0) 
                left = v[r * cols + cols - 1];
            if (c == cols - 1) 
                right = v[r * cols];
            if (r == 0) 
                up = v[(rows - 1) * cols + c];
            if (r == rows - 1) 
                down = down = v[c];

    
            
           if (value < up || value < down )
                n += 1;
            
        }
    }

    return n;
}
