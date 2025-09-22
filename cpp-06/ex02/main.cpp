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
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
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
        (void)e;
    }
    try {
        B &bRef = dynamic_cast<B&>(p);
        (void) bRef;
        std::cout << "B" << std::endl;
    } catch (const std::exception &e)
    {
        (void)e;
    }
    try {
        C &cRef = dynamic_cast<C&>(p);
        (void) cRef;
        std::cout << "C" << std::endl;
    } catch (const std::exception &e)
    {
        (void)e;
    }
}

int main()
{
    std::srand(time(0));
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}