#pragma once
#include <string>
#include <iostream>
using namespace std;


class CustomString
{
public:
    void Display(const string& displayString)
    {
        cout << displayString << " String is " << _string << " Pointer is " << reinterpret_cast<int*>(_string) << endl;
    }
    CustomString()
    {
        _string = new char[1];
        _string[0] = '\0';
        Display("DefaultConstructor ");
    }

    ~CustomString()
    {
        Display("Destructor ");
        if (_string)
        {
            delete[] _string;
            _string = nullptr;
        }
    }

    CustomString(const char* _cstr) : CustomString()
    {
        auto length = strlen(_cstr);
        if (length == 0)
        {
            return;
        }
        _string = new char[length + 1];
        strcpy_s(_string, length + 1, _cstr);
        Display("ParameterizedConstructor ");
    }

    CustomString(const CustomString& _str) : CustomString(_str._string)
    {
        Display("Copy Constructor");
    }

    const CustomString& operator=(const CustomString& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        CustomString tempStr(rhs);
        char* toDelete = _string;
        _string = tempStr._string;
        tempStr._string = toDelete;
        Display("Assignment Operator");
    }


private:
    char* _string = nullptr;
};

