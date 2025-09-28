#include <iostream>
#include <limits.h>
#include <cmath>
#include <cfloat>
#include <iomanip>
int main()
{
    // std::cout << -INFINITY << std::endl;
    // std::cout <<  CHAR_MAX << std::endl;
    // std::cout <<  CHAR_MIN << std::endl;
    // std::cout <<  INT_MAX << std::endl;
    // std::cout <<  INT_MIN << std::endl;
    // std::cout << FLT_MAX << std::endl;
    // std::cout << FLT_MIN << std::endl;
    // std::cout << DBL_MAX << std::endl;
    // std::cout << DBL_MIN << std::endl;

    // Set fixed notation and maximum digits
    // std::cout << std::fixed << std::setprecision(50);

    // std::cout << "Float max:   " << std::numeric_limits<float>::max() << "\n";
    // std::cout << "Float min:   " << std::numeric_limits<float>::min() << "\n";
    // std::cout << "Double max:  " << std::numeric_limits<double>::max() << "\n";
    // std::cout << "Double min:  " << std::numeric_limits<double>::min() << "\n";
    float f = 12.34;
    int a = reinterpret_cast<int> (f);
    std::cout << a << std::endl;

    // std::cout <<  std::numeric_limits<float>::max() << std::endl;
    // std::cout << std::stof("asdl") << std::endl;
    // std::cout << std::stod("nan") << std::endl;
    // std::cout << std::stof("-inff") << std::endl;
    // std::cout << std::stod("-inff") << std::endl;
    // std::cout << std::stof("inff") << std::endl;
    // std::cout << std::stod("inff") << std::endl;
    // std::cout <<  static_cast<float> (std::numeric_limits<double>::lowest()) << std::endl;
    // std::cout <<  std::numeric_limits<double>::lowest() << std::endl;
    // std::cout <<  std::numeric_limits<double>::max() << std::endl;
}