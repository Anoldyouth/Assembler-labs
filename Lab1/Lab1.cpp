#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

union bit16
{
    void* checking;
    short* sht;
    unsigned short* usht;
};

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

void print16(void* p)
{
    bit16 s = {p};
    cout << hex << *s.usht << endl;
    cout << std::bitset<sizeof(*s.usht) * CHAR_BIT>(*s.usht) << endl;
    cout << *s.usht << endl;

    cout << hex << *s.sht << endl;
    cout << std::bitset<sizeof(*s.sht) * CHAR_BIT>(*s.sht) << endl;
    cout << *s.sht << endl;
}

int main()
{
    //sizeOfTypes();
    short number = -5;
    print16(&number);
    return 0;
}
