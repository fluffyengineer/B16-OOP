//
//  main.cpp
//  Qu7
//
//  Created by Tom Rawlinson on 06/03/2016.
//  Copyright © 2016 Tom Rawlinson. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


class X
{
public:
    virtual double Eval() {return 1.0;}
    void PrintValue() { cout << Eval() << endl;}
};

class Y : public X {
public:
    Y(X& x1, X& x2) : arg1(x1), arg2(x2) {}
    double Eval() { return arg1.Eval() * arg2.Eval(); }
    

private:
    X& arg1;
    X& arg2;
};

class Z : public X {
public:
    Z(double v) : val(v) {}
    double Eval() {  return -val; }
    
private:
    double val;
    
};

class Sum : public X{
public:
    Sum(X& x1, X& x2) : arg1(x1), arg2(x2) {}
    double Eval() {return arg1.Eval() + arg2.Eval();}
    
private:
    
    X& arg1;
    X& arg2;
};

class Tan : public X {
public:
    Tan(X& x) : arg(x) {}
    double Eval() {return tan(arg.Eval());}
    
private:
    X& arg;
};

    
    
int main(int argc, const char * argv[]) {

    Z a(2.5), b(3.0), c(10.0);
    Y d(a,b);
    Y e(d,c);
    
    a.PrintValue();
    d.PrintValue();
    e.PrintValue();
    
    Sum Sum1(a,b);
    
    Sum1.PrintValue();
    
    Tan Tan1(b);
    
    Tan1.PrintValue();
    
    double y = pow(6,-2);
    printf("Y equals %f \n",y);
    
    
    return 0;
}


