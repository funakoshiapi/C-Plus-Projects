
//  - proj01 

// - This program calculates the sum, subtraction, multiplication and division of complex numbers




#include <iostream>
#include<iomanip>
#include<math.h>

int main() {
    
    double n1, n2, n3, n4 = 0;
    
    std::cin >> n1 >> n2 >> n3 >> n4;
    
    double mySumReal = (n1 + n3);
    double mySumIm = (n2 + n4);
    
    double subReal =(n1 - n3);
    double subIm = (n2 - n4);
    double multX = n1*n3 - n2*n4 ;
    double multY = n1*n4 + n3*n2 ;
    
    /* Multiplication of complex numbers.
     
     (a+bi)*(c+di)=ac+adi+bci+bdi2
     =ac+(ad+bc)i-bd
     =(ac-bd)+(ad+bc)i */
    
    double divX = (n1*n3 + n2*n4)/(pow(n3,2) + pow(n4,2)); // USING POW FROM math.h library
    double divY = (n2*n3 - n1*n4) / (pow(n3,2) + pow(n4,2));
    
    /* Division of complex numbres
     (a+bi)/(c+di)=[(a+bi)/(c+di)]*[(c-di)/(c-di)]
     = [(ac+bd)/(c2+d2)]+[(bc-ad)/(c2+d2)] */
    
 
    
    std::cout<< std::setprecision(2) << std::fixed << mySumReal << " + "<< mySumIm << "i" << std::endl;
    std::cout<< std::setprecision(2) << std::fixed << subReal << " + " << subIm << "i" << std::endl;
    std::cout<< std::setprecision(2) << std::fixed <<   multX  << " + "<< multY << "i" << std::endl;
    std::cout<< std::setprecision(2) << std::fixed <<   divX  << " + " << divY << "i" << std::endl;
    
    
    return 0;
}
