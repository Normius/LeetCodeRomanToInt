#include <iostream>

int romanToInt2(std::string s) {
    int num[256] = { 0 };
    int result = 0;
    num['I'] = 1; num['V'] = 5; num['X'] = 10; num['L'] = 50;
    num['C'] = 100; num['D'] = 500; num['M'] = 1000;
    int i = 0;
   
    //std::cout << s.size() << std::endl;

    while (i < s.size()) {
        if (num[s[i]] < num[s[i + 1]])
            result -= num[s[i]];
        else
            result += num[s[i]];
        i++;
    }
    return result;
}

int romanToInt(std::string s) {
    size_t size = strlen(s.c_str());

    int* arrNumbers = new int[size];
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == 'I')
        {
            arrNumbers[i] = 1;
        }

        if (s[i] == 'V')
        {
            arrNumbers[i] = 5;
        }

        if (s[i] == 'X')
        {
            arrNumbers[i] = 10;
        }

        if (s[i] == 'L')
        {
            arrNumbers[i] = 50;
        }

        if (s[i] == 'C')
        {
            arrNumbers[i] = 100;
        }

        if (s[i] == 'D')
        {
            arrNumbers[i] = 500;
        }

        if (s[i] == 'M')
        {
            arrNumbers[i] = 1000;
        }
    }

    for (int i = size - 1; i > 0; --i)
    {
        if (arrNumbers[i - 1] == arrNumbers[i] || arrNumbers[i - 1] == (arrNumbers[i] - arrNumbers[i - 1]))
        {
            arrNumbers[i - 1] += arrNumbers[i];
            arrNumbers[i] = 0;
        }
    }

    for (int i = size - 1; i > 0; --i)
    {
        if (arrNumbers[i - 1] > arrNumbers[i])
        {
            arrNumbers[i - 1] += arrNumbers[i];
        }
        else
        {
            arrNumbers[i - 1] = arrNumbers[i] - arrNumbers[i - 1];
        }
    }
    int finalanswer = arrNumbers[0];

    delete[] arrNumbers;
    return finalanswer;
}

int main()
{
    std::string s;
    /*std::cout << "Enter Roman number (or stop for end programm)" << std::endl;
    std::cin >> s;

    std::cout << romanToInt2(s) << std::endl;*/

    //system("pause");

    std::cout << "Enter Roman number (or stop for end programm)" << std::endl;
    while (std::cin)
    {
        std::cin >> s;
        if (s == "Stop" || s == "stop")
        {
            break;
        }

        int answer = romanToInt(s);
        std::cout << "(Roman number)" << s << " = " << romanToInt(s) << "(Int)" << std::endl;
    }
}
