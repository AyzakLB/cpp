#include <iostream>

int main()
{
    std::string s = "  ayoub marzaq     ";
    size_t first = s.find_first_not_of(" \t\r\n\f\v");
    size_t last = s.find_last_not_of(" \t\r\n\f\v");
    std::cout << "'" << s.substr(first, last - first + 1) << "'" << std::endl;
}