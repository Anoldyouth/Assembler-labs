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

    cout << "hex: " << hex << *s.usht << endl;
    cout << "binary: " << std::bitset<sizeof(*s.usht) * CHAR_BIT>(*s.usht) << endl;
    cout << "dec: " << dec <<*s.usht << endl<< endl;

    cout << "hex: " << hex << *s.sht << endl;
    cout << "binary: " << std::bitset<sizeof(*s.sht) * CHAR_BIT>(*s.sht) << endl;
    cout << "dec: " << dec << *s.sht << endl<< endl;
}

template<class T>
void print32(T t)
{
    Bit32 s = {t};

    cout << "float" << endl;
    cout << "hex: " << hex << *s.flt << endl;
    cout << "binary: " << std::bitset<sizeof(*s.flt) * CHAR_BIT>(*s.flt) << endl;
    cout << "dec: " << dec <<*s.flt << endl;
    cout << "fixed: " << fixed << *s.flt << endl;
    cout << "exp: " << scientific << *s.flt << endl<< endl;

    cout << "int" << endl;
    cout << "hex: " << hex << *s.ntgr << endl;
    cout << "binary: " << std::bitset<sizeof(*s.ntgr) * CHAR_BIT>(*s.ntgr) << endl;
    cout << "dec: " << dec <<*s.ntgr << endl;
    cout << "the number itself: " << fixed << *s.ntgr << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ntgr << endl<< endl;

    cout << "unsigned int" << endl;
    cout << "hex: " << hex << *s.untgr << endl;
    cout << "binary: " << std::bitset<sizeof(*s.untgr) * CHAR_BIT>(*s.untgr) << endl;
    cout << "dec: " << dec <<*s.untgr << endl;
    cout << "the number itself: " << fixed << *s.untgr << endl;
    cout << "the same number in the exponential form: " << scientific << *s.untgr << endl<< endl;

    cout << "long" << endl;
    cout << "hex: " << hex << *s.lng << endl;
    cout << "binary: " << std::bitset<sizeof(*s.lng) * CHAR_BIT>(*s.lng) << endl;
    cout << "dec: " << dec <<*s.lng << endl;
    cout << "the number itself: " << fixed << *s.lng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.lng << endl<< endl;

    cout << "unsigned long" << endl;
    cout << "hex: " << hex << *s.ulng << endl;
    cout << "binary: " << std::bitset<sizeof(*s.ulng) * CHAR_BIT>(*s.ulng) << endl;
    cout << "dec: " << dec <<*s.ulng << endl;
    cout << "the number itself: " << fixed << *s.ulng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ulng << endl<< endl;
}

template<class T>
void print64(T t)
{
    Bit64 s = {t};

    cout << "double" << endl;
    cout << "hex: " << hex << *s.dbl << endl;
    cout << "binary: " << std::bitset<sizeof(*s.dbl) * CHAR_BIT>(*s.dbl) << endl;
    cout << "dec: " << dec <<*s.dbl <<  endl;
    cout << "the number itself: " << fixed << *s.dbl << endl;
    cout << "the same number in the exponential form: " << scientific << *s.dbl << endl<< endl;

    cout << "long long" << endl;
    cout << "hex: " << hex << *s.lnglng << endl;
    cout << "binary: " << std::bitset<sizeof(*s.lnglng) * CHAR_BIT>(*s.lnglng) << endl;
    cout << "dec: " << dec <<*s.lnglng <<  endl;
    cout << "the number itself: " << fixed << *s.lnglng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.lnglng << endl<< endl;

    cout << "unsigned long long" << endl;
    cout << "hex: " << hex << *s.ulnglng << endl;
    cout << "binary: " << std::bitset<sizeof(*s.ulnglng) * CHAR_BIT>(*s.ulnglng) << endl;
    cout << "dec: " << dec <<*s.ulnglng << endl;
    cout << "the number itself: " << fixed << *s.ulnglng << endl;
    cout << "the same number in the exponential form: " << scientific << *s.ulnglng << endl<< endl;

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
        cout << dec;
    }

int main()
{
    sizeOfTypes();

    cout << endl << endl << endl << endl << "Testing print16()"  << endl << endl;

    unsigned short first = 0;
    cout << "original number: " << first << endl;
    print16(&first);

    unsigned short second = (unsigned short)USHRT_MAX;
    cout << "original number: " << second << endl;
    print16(&second);

    short third = SHRT_MIN;
    cout << "original number: " << third << endl;
    print16(&third);

    short fourth = SHRT_MAX;
    cout << "original number: " << fourth << endl;
    print16(&fourth);

    unsigned short fivth = 4;
    cout << "original number: " << fivth << endl;
    print16(&fivth);

    short sixth = -7;
    cout << "original number: " << sixth << endl;
    print16(&sixth);

    cout << endl << endl << endl << endl << "Testing print32()"  << endl << endl;

    cout << "INTEGER" << endl << endl;

    unsigned int ai = 0;
    cout << "original number: " << ai << endl;
    print32(&ai);

    unsigned int bi = UINT_MAX;
    cout << "original number: " << bi << endl;
    print32(&bi);

    int ci = INT_MIN;
    cout << "original number: " << ci << endl;
    print32(&ci);

    int di = INT_MAX;
    cout << "original number: " << di << endl;
    print32(&di);

    int ei = 0xF1F2F3F4;
    cout << "original number: " << ei << endl;
    print32(&ei);

    int gi = 4;
    cout << "original number: " << gi << endl;
    print32(&gi);

    int hi = -7;
    cout << "original number: " << hi << endl;
    print32(&hi);

    cout << "LONG" << endl << endl;

    unsigned long al = 0;
    cout << "original number: " << al << endl;
    print32(&al);

    unsigned long bl = LONG_MAX;
    cout << "original number: " << bl << endl;
    print32(&bl);

    long cl = LONG_MIN;
    cout << "original number: " << cl << endl;
    print32(&cl);

    long dl = LONG_MAX;
    cout << "original number: " << dl << endl;
    print32(&dl);

    long el = 0xF1F2F3F4;
    cout << "original number: " << el << endl;
    print32(&el);

    long gl = 4;
    cout << "original number: " << gl << endl;
    print32(&gl);

    long hl = -7;
    cout << "original number: " << hl << endl;
    print32(&hl);

    cout << "FLOAT" << endl << endl;
    float ef = 0xF1F2F3F4;
    cout << "original number: " << ef << endl;
    print32(&ef);

    float gf = 4;
    cout << "original number: " << gf << endl;
    print32(&gf);

    float hf = -7;
    cout << "original number: " << hf << endl;
    print32(&hf);

    cout << endl << endl << endl << endl << "Testing print64()"  << endl << endl;

    cout << "LONG LONG" << endl << endl;

    unsigned long all = 0;
    cout << "original number: " << all << endl;
    print32(&all);

    unsigned long long bll = LLONG_MAX;
    cout << "original number: " << bll << endl;
    print32(&bll);

    long long cll = LLONG_MIN;
    cout << "original number: " << cll << endl;
    print32(&cll);

    long long dll = LLONG_MAX;
    cout << "original number: " << dll << endl;
    print32(&dll);

    long long ell = 0xF1F2F3F4;
    cout << "original number: " << ell << endl;
    print32(&ell);

    long long gll = 4;
    cout << "original number: " << gll << endl;
    print32(&gll);

    long long hll = -7;
    cout << "original number: " << hll << endl;
    print32(&hll);

    cout << "DOUBLE" << endl << endl;
    double ed = 0xF1F2F3F4;
    cout << "original number: " << ed << endl;
    print32(&ed);

    double gd = 4;
    cout << "original number: " << gd << endl;
    print32(&gd);

    double hd = -7;
    cout << "original number: " << hd << endl;
    print32(&hd);

    cout << endl << endl << endl << endl << "Testing ptintDump()"  << endl << endl;
    int a = 0xF1F2F3F4;
    cout << "original number: " << a << endl;
    printDump(&a, sizeof(a));

    int b[3];
    b[0] = 0xF1F2F3F4;
    b[1] = 4;
    b[2] = -7;
    cout << "original number: " << b[0] << " " << b[1] << " " << b[2] << endl;
    printDump(&b, sizeof(b));

    double c = 4;
    cout << "original number: " << c << endl;
    printDump(&c, sizeof(c));

    return 0;
}
