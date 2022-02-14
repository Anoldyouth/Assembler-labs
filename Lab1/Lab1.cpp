#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <typeinfo>
using namespace std;

union Bit16
{
    void* checking;
    short* sht;
    unsigned short* usht;
};

union Bit32
{
    void* checking;
    float* flt;
    int* ntgr;
    unsigned int* untgr;
    long* lng;
    unsigned long* ulng;
};

union Bit64
{
    void* checking;
    double* dbl;
    long long* lnglng;
    unsigned long long* ulnglng;
};


//template<class T>
void sizeOfTypes()
{
    cout << "size of char is: " << sizeof(char) << endl;
    cout << "size of signed char is: " << sizeof(signed char) << endl;
    cout << "size of unsigned char is: " << sizeof(unsigned char) << endl;
    cout << "size of wchar_t is: " << sizeof(wchar_t) << endl;
    cout << "size of short is: " << sizeof(short) << endl;
    cout << "size of unsigned short is: " << sizeof(unsigned short) << endl;
    cout << "size of int is: " << sizeof(int) << endl;
    cout << "size of unsigned int is: " << sizeof(unsigned int) << endl;
    cout << "size of long is: " << sizeof(long) << endl;
    cout << "size of unsigned long is: " << sizeof(unsigned long) << endl;
    cout << "size of long long is: " << sizeof(long long) << endl;
    cout << "size of unsigned long long is: " << sizeof(unsigned long long) << endl;
    cout << "size of float is: " << sizeof(float) << endl;
    cout << "size of double is: " << sizeof(double) << endl;
    cout << "size of long double is: " << sizeof(long double) << endl;
    cout << "size of size_t is: " << sizeof(size_t) << endl;
    cout << "size of ptrdiff_t is: " << sizeof(ptrdiff_t) << endl;
    cout << "size of void* is: " << sizeof(void*) << endl;
    cout << "size of char* is: " << sizeof(char*) << endl;
    cout << "size of int* is: " << sizeof(int*) << endl;
    cout << "size of unsigned int* is: " << sizeof(unsigned int*) << endl;
}

template<class T>
void print16(T t)
{
    Bit16 s = {t};
    cout << hex << *s.usht << endl;
    cout << std::bitset<sizeof(*s.usht) * CHAR_BIT>(*s.usht) << endl;
    cout << dec <<*s.usht << endl;

    cout << hex << *s.sht << endl;
    cout << std::bitset<sizeof(*s.sht) * CHAR_BIT>(*s.sht) << endl;
    cout << dec << *s.sht << endl;
}

template<class T>
void print32(T t)
{
    Bit32 s = {t};

    cout << "float" << endl;
    cout << "the number itself: " << fixed << *s.flt << endl;
    cout << "the same number in the exponential form: " << scientific << *s.flt << endl;

    cout << "int" << endl;
    cout << "the number itself: " << fixed << *s.ntgr << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ntgr << endl;

    cout << "unsigned int" << endl;
    cout << "the number itself: " << fixed << *s.untgr << endl;
    cout << "the same number in the exponential form: " << scientific << *s.untgr << endl;

    cout << "long" << endl;
    cout << "the number itself: " << fixed << *s.lng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.lng << endl;

    cout << "unsigned long" << endl;
    cout << "the number itself: " << fixed << *s.ulng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ulng << endl;
}

template<class T>
void print64(T t)
{
    Bit64 s = {t};

    cout << "double" << endl;
    cout << "the number itself: " << fixed << *s.dbl << endl;
    cout << "the same number in the exponential form: " << scientific << *s.dbl << endl;

    cout << "long long" << endl;
    cout << "the number itself: " << fixed << *s.lnglng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.lnglng << endl;

    cout << "unsigned long long" << endl;
    cout << "the number itself: " << fixed << *s.ulnglng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ulnglng << endl;

}

void printDump(const void* p, std::size_t N)
    {

        const char* const start = static_cast<const char*>(p);
        const char* const end = start + N;
        const char* line = start;
        while (line != end)
        {
            std::size_t lineLength = static_cast<std::size_t>(end - line);
            for (const char* next = line; next != end && next != line + N; ++next)
            {
                char ch = *next;
                if (next != line)
                    cout << " ";
                cout.width(2);
                cout.fill('0');
                cout << hex << uppercase << static_cast<int>(static_cast<unsigned char>(ch));
            }
            cout << std::endl;
            line += lineLength;
        }
    }

int main()
{
    sizeOfTypes();
//    short number = -5;
//    print16(&number);

    int fltNum = 3926535;
    print32(&fltNum);
    cout << endl;

    double dblNum = 2.7182818284;
    print64(&dblNum);

    int x = 0x12345678;
    printDump(&x, sizeof(x));
    return 0;
}
