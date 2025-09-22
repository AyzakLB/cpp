#include <iostream>

int main(int ac, char **av)
{
    std::string s;

    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            s = av[i];
            for (size_t m = 0;  m < s.length(); m++)
                s[m] = toupper(s[m]);
            std::cout << s;
        }
    }
    std::cout << std::endl;
}