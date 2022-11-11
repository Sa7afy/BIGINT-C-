// Authors :
// Yousef Abdalla Attia
//ID/ 20210475
//Toqa Yasser Youssef abd El Hamed
//ID/ 20211023
//Abderahman Adel Abdelazieem Ahmed
//ID/20211059
// Suprevised By : Dr.Mohamed ElRamly
// Task1
#ifndef BIGINT_H
#define BIGINT_H
using namespace std;
class BIGINT{
string digits;
public :
    string getter();

    BIGINT(string s);

    BIGINT(int decint);

    BIGINT operator+(BIGINT b);

    BIGINT operator-(BIGINT b);

    bool operator< (BIGINT obj);

    bool operator> (BIGINT obj);

    bool operator==(BIGINT obj);

    int Length() {
        return digits.size();
    }

    void setter(string s){
    digits = s;
    }

    int sign() {
        //false for  negative true for positive
        if (digits[0] == '-')return 0;
        return true;
    }
};
#endif // bigint
