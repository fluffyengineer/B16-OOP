//
//  mathvector.cpp
//  B16OOP
//
//  Created by Tom Rawlinson on 04/03/2016.
//  Copyright © 2016 Tom Rawlinson. All rights reserved.
//

#include "mathvector.hpp"
#include <iostream>
#include <vector>


class MathVector{
    
public:
    MathVector(int size = 1) {length = size;};
    
    MathVector(int size, std::vector<double> initialElements) {
        length = size;
        elements = initialElements;
    };
    
    MathVector(MathVector& vecA){
        length = vecA.size();
        elements = vecA.Elements();
        
    }
    
    int size() {return length;}
    std::vector<double> Elements(){ return elements;}
    
    
private:
    
    int length;
    std::vector<double> elements;
    std::vector< std::vector<unsigned char>> data;
    
};



int main() {
    
    std::vector<double> v;
    for (int i=0; i<20; i++) v.push_back(i);
    

    
    MathVector MathVectorA(20,v);
    std::vector<double> e = MathVectorA.Elements();
    
    for(int i=0; i<e.size(); i++)
        std::cout<< e[i] << std::endl;
    
    
    unsigned char pixel = 49;
    
    std::cout<<pixel << std::endl ;
    
    
    

    
    
}