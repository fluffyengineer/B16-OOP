/*
//
//  Notes.c
  B16OOP

  Created by Tom Rawlinson on 04/03/2016.
  Copyright © 2016 Tom Rawlinson. All rights reserved.


 example usage - default consrtuctor returns default values, enlose ().
 Call as  - MathVector()
 
 true constructor - vector <double> Elements;
 Call as MathVector(int size, Elements);
 
 Copyconstructor - copies all entries of a previous MathVector 
 MathVector MathVectorA
 
 MathVector MathVectorB; MVB = MVA. ? or is it MathVectorB(MathVectorA)?
 
 Not sure about dynamic mem. allocoation - would we have leak because we wouldn't free each time we extend?
 Deleting the vector would only delete the refernece to the first element, we'd need to free all the others
 first or the heap keeps growing.
 
 Operator overloading -
 // friend osstream& operator<<(std::ostream &output, const World &C)
 
 // for the spring, the output is the "-" times the length
 
 double& operator[](int index){
    SOMETHING LIKE
    return this.getElement(index)
 }
 
 Vector<double> result operator*(Vector<double> left, Vector<double> right){
 for (int i;i = 1:3;i++)
    result.setElement(left[i] x right[i]);
 }
 
 Vector<double> result operator*(double alpha, Vector<double> right){
 for(int i;i = 1:3;i++)
    result.setElement(alpha x right[i]);
 
 }
 
 
 REPEAT FOR THE OTHER WAY AROUND
 
 5. Inheritance
 
 SHAPE
 
 1-D
 
 Point
 
 2-D
 
 Line
 Plane
 
 3-D
 
 Ellipsoid
 Quadric
 COne Cuboid
 
 BASE CLASS
 
 key methods for drawing, x and y co-ordiantes of center, and orientation(as a normalised three vector or as three angles to x, y and z axis.
 
 e.g point is always just x y and z, ortinetation is 1 on each axis.
 
 2-D (line) inherits all of those. Centre is now average of the two points, orientaton is vector from pointA to pointB
 draw now draws two points and also the line between them.
 
 Once the base class and subclasses have been made, a new Sphere class inhertis all the previously defined methods with no effort. Only minimal changes specific to a sphere need to be implelemted, such as there being only a single central point, with a smooth surface at a defined radius. orinetation is arbitrary.
 
 
 6.
 
 7.
 
 Foo is parent, Bar is child. All Bars are also members of Foo, and inherit the f() method, which is then redefined.
 
 doit1 takes the actual object, not just a reference....
 doit1(foo) wil print out the f() method for foo, and the g() method of foo
 doit1(bar) with use the f() method for foo, and the g() method of foo, beacuse only the foo part of bar is passeed
 
 doit2 takes only a reference to a Foo or Bar
 doit2(foo) will print out the f() method for foo, and the g() method of foo
 doit2(bar) with also use the f() and g() methods of the foo part of Bar.
 
 
 8.
 
 X is the base
 Y is a subclass of X (X->Y)
 Z is a sublclass of X (X->Y)
 
 a is built with val = 2.5, b has val 3, and c has val 10
 
 d is a Y, so it needs arg1 and arg2. arg1 is the val of a, which is 2.5, and arg2 is 3.0
 
 e is also a Y, so it needs arg1 and arg2. arg1 is d, so it has two parts(2.5 and 3.0), and arg2 is just 10.
 
 
 In using the constructor of arg1 and arg2 of Y, presumably Eval is called? - what does this mean for d being built with another Y?
 
 a.PrintVAlue will return using the Eval method of the subclass, so it will return - val = -2.5
 d.PrintValue will return using the eval method arg1.Eval * arg2.Eval.
 arg1.Eval() = a.Eval() = -2.5
 arg2.Eval() = b.Eval() = -3.0. Total is then 7.5
 
 e.printValue will return using its's Eval subclass method, so it will return arg1Eval() * arg2Eval
 arg1.Eval will return again on a Y object, and so will return using the Eval method of the two arguments, so it will be (-2.5*-3.0) = 7.5.
 arg2.Eval will return on a Z object,c, so will return -10
 
 Polymorphism - the eval method is defined diferently for all the different sub-classes, Y and Z. However, all Ys and Zs inherit a common PrintValue method. This PrintValue method can use the eval method defined in the subclass, allowing a common interface for all the subclasses, despite their different implementations of the Eval method. The Printvalue method can be written once into the base class, and doesn't need to be redefined to take account of all the different eval methods of the sub-classes.
 
 class Sum : public X{
    public:
 
    Sum(X& left, X& right) : arg1(x1), arg2(x2){}
    double Eval() {return arg1.Eval + arg2.Eval()}
    
    private:
    
    X& arg1;
    X& arg2;
 }
 
 class Tan : public X{
    public:
    
    Tan(&X x1) : argument(x1){}
    
    double Eval() {return tanr(argument.Eval())}
 }
 
 
 
 
 
 

