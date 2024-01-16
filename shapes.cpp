#include <iostream>
#include <string>
#include <vector>

#include "shape.hpp"

// Class inheritance.
// square inherits the public/protected properties from shape.
// private properties or mehods are hiddend.
class square : public shape
{
private:
    int _norows;
    int _nocolumns;

protected:
    char _name[255];

public:
    // Default Constructor / What happens on create?
    // Has not return type
    square() : shape()
    {
        strcpy(_name, "square");
        _norows = _nocolumns = 5;
    }

    square(int size) : shape()
    {
        strcpy(_name, "square");
        _norows = size;
        _nocolumns = size;
    }

    virtual void name()
    {
        std::cout << _name << ' ' << _norows << 'x' << _nocolumns << std::endl;
    }

    virtual void draw()
    {
        for (int i = 0; i < _norows; i++)
        {
            for (int j = 0; j < _nocolumns; j++)
            {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    }
};

class symbol : public shape
{
    private:
        char _symbol;

    public:

    symbol():shape()
    {
        _symbol = '*';
    }

    symbol(char symbol):shape()
    {
        _symbol = symbol;
    }

    virtual void name()
    {
        std::cout << "symbol " << _symbol << std::endl;
    }

    virtual void draw()
    {
        std::cout << _symbol << std::endl;
    }
};

void doSomethingWithShape(shape* shapePtr);

//
// It is good practice in c++ to create objects on the heap
// objects on the heap must be released or they will leave a memory leak.
int main()
{
    // arrays are very simple memory allocations.
    // you have to know the size of the array
    // The new key word create the object on the heap calling the
    // constructor based on the parameters pass to it.
    shape* vectorOfShapes[] = {new symbol(), new symbol('X'), new square(), new square(5), new square(10)}; 
    int vsize = 5;

    for(int i =0; i < vsize; ++i)
    {
        shape* sp = vectorOfShapes[i];
        doSomethingWithShape(sp);
    }

    // Now release memory back to the heap
    for(int i =0; i < vsize; ++i)
    {
        shape* sp = vectorOfShapes[i];
        delete sp;
    }
}

// The naming convention is CamelCase
// 
void doSomethingWithShape(shape* shapePtr)
{
    shapePtr->name();
    shapePtr->draw();
}