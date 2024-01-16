#include <iostream>
#include <string>

// Base Class
// The idea is that this class will
// never be inherited.
// This is known in OO as
// an abstract class
// And if it has not implementaion of data can be referred to as an interface
// Polymorphism
// Create a base class with the common features.

class shape
{
    // Private variables/properties or methods
    // These can only be used internally
private:
    // Protected variables/properties or method can be used
    // by inherited classes too but not externally
protected:
    // Public variables/properties or methods can be used by anyone that instantiates the class.
public:
    // Caveat: static variables/properties or methods can be used without instantiating the class

    // virtual means that derived classes may reimplement
    // draw() = 0
    // The '= 0' means this is a pure virtual method. Has to be implemented by a derived class.
    virtual void draw() = 0;
    virtual void name() = 0;
};

