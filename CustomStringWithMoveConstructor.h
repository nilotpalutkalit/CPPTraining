#include <memory>
#include <functional>
#include <iostream>
#include <ostream>

class CustomString
{
    public:
    CustomString() : m_strData(nullptr, [](char* ptr) {delete[] ptr; ptr = nullptr;}) {}
    CustomString(const char* const str) : CustomString()
    {
        std::cout<<"Constructor Called\n";
        auto len = strlen(str);
        m_strData.reset(new char[len]);
        strcpy(m_strData.get(), str);
    }

    CustomString(const CustomString& customString) : CustomString(customString.m_strData.get())
    {
        std::cout<<"Copy Constructor Called! \n";
    }

    CustomString(CustomString&& customString) : CustomString()
    {
        std::cout<<"Move Constructor Called! \n";
        m_strData.swap(customString.m_strData);
    }

    CustomString& operator=(CustomString&& customString)
    {
        std::cout<<"Move Assignment Operator Called! \n";
        if(this == &customString)
        {
            return *this;
        }
        m_strData.swap(customString.m_strData);
        return *this;
    }

    CustomString& operator=(const CustomString& rhsString)
    {
        std::cout<<"Assignment Operator Called! \n";
        if(&rhsString == this)
        {
            return *this;
        }
        
        *this = CustomString(rhsString);

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& outStream, const CustomString& customStr)
    {
        if(!customStr.m_strData)
        {
            return outStream;
        }
        outStream << customStr.m_strData.get() << "\n";
        return outStream;
    }

    ~CustomString()
    {
        std::cout<<"Destructor Called\n";
        if(m_strData)
        {
            m_strData.reset();
            m_strData = nullptr;
        }
    }

    private:
    std::unique_ptr<char, void(*)(char*)> m_strData;

    
};
