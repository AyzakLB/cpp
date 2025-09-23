#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
    int randomNumber = rand() % 3;
    Base *pointer;
    if (randomNumber == 1 )
        pointer = new A;
    else if (randomNumber == 2)
        pointer = new B;
    else
        pointer = new C;
    return pointer;
}

void identify(Base* p) {
    if (!p) {
        std::cerr << "Null pointer" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try {
        A &aRef = dynamic_cast<A&>(p);
        (void) aRef;
        std::cout << "A" << std::endl;
    } catch (const std::exception &e)
    {
            try {
            B &bRef = dynamic_cast<B&>(p);  
            (void) bRef;
            std::cout << "B" << std::endl;
        } catch (const std::exception &e)
        {
                try {
                  C &cRef = dynamic_cast<C&>(p);
                (void) cRef;
                std::cout << "C" << std::endl;
                } catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }
        }
    }
    
    
}

int main()
{
    Base *a = new A;
    Base *b = new B;
    Base *c = new C;
    Base &aRef = *a;
    Base &bRef = *b;
    Base &cRef = *c;
    identify(a);
    identify(b);
    identify(c);
    identify(aRef);
    identify(bRef);
    identify(cRef);
    delete a;
    delete b;
    delete c;
	return 0;
}