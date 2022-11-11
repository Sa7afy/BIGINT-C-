// Authors :
// Yousef Abdalla Attia
//ID/ 20210475
//Toqa Yasser Youssef abd El Hamed
//ID/ 20211023
//Abderahman Adel Abdelazieem Ahmed
//ID/20211059
// Suprevised By : Dr.Mohamed ElRamly
// Task1
#include <bits/stdc++.h>
#include "BIGINT.h"
using namespace std;
    string BIGINT::getter() {
        return digits;
    }
    // for stirngs
    BIGINT::BIGINT(string s) {
        digits = "";
        //get length
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            // check for bad input;
            if (s[0] != '+' && s[0] != '-' && !isdigit(s[i])) {
                cout << "Bad input\ntry again\n";
                digits = "";
                return;
            }
            // add digits
            digits += s[i];
        }
        // add sign;
        if (digits[0]!='+'&&digits[0]!='-'){
            digits="+"+digits;
        }
    }

    // for int values
    BIGINT::BIGINT(int decint) {
        // convert int to string
        //store sign
        char sign = (decint == abs(decint) ? '+' : '-');
        decint = abs(decint);
        digits = "";
        // add digits one by one
        while (decint) {
            digits.push_back(decint % 10 + '0');
            decint /= 10;
        }
        // reverse to get correct number
        reverse(digits.begin(),digits.end());
        // add sign
        digits = sign + digits;
    }



bool BIGINT :: operator < (BIGINT obj){
        if ((digits[0] == '+' && obj.digits[0] == '-')){
            return false;
        }
        else if (digits[0] == '-' && obj.digits[0] == '+'){
            return true;
        }
        else if (digits[0] == '+' && obj.digits[0] == '+' && digits.size() > obj.digits.size()){
            return false;
        }
        else if (digits[0] == '+' && obj.digits[0] == '+' && digits.size() < obj.digits.size()){
            return true;
        }
        else if (digits[0] == '-' && obj.digits[0] == '-' && digits.size() > obj.digits.size()){
            return true;
        }
        else if (digits[0] == '-' && obj.digits[0] == '-' && digits.size() > obj.digits.size()){
            return false;
        }
        else{
            if (digits[0] == '+') {
                for (int i = 0; i < digits.size(); i++) {
                    if (digits[i] > obj.digits[i]) {
                        return false;
                    } else if (digits[i] < obj.digits[i]) {
                        return true;
                    }
                }
                return false;
            }
            else{
                for (int i = 0; i < digits.size(); i++) {
                    if (digits[i] > obj.digits[i]) {
                        return true;
                    }
                    else if (digits[i] < obj.digits[i]) {
                        return false;
                    }
                }
                return false;
            }
        }
    }

     bool BIGINT :: operator > (BIGINT obj){
    if ((digits[0] == '+' && obj.digits[0] == '-')){
        return true;
    }
    else if (digits[0] == '-' && obj.digits[0] == '+'){
        return false;
    }
    else if (digits[0] == '+' && obj.digits[0] == '+' && digits.size() > obj.digits.size()){
        return true;
    }
    else if (digits[0] == '+' && obj.digits[0] == '+' && digits.size() < obj.digits.size()){
        return false;
    }
    else if (digits[0] == '-' && obj.digits[0] == '-' && digits.size() > obj.digits.size()){
        return false;
    }
    else if (digits[0] == '-' && obj.digits[0] == '-' && digits.size() > obj.digits.size()){
        return true;
    }
    else{
        if (digits[0] == '+') {
            for (int i = 0; i < digits.size(); i++) {
                if (digits[i] > obj.digits[i]) {
                    return true;
                } else if (digits[i] < obj.digits[i]) {
                    return false;
                }
            }
            return false;
        }
        else{
            for (int i = 0; i < digits.size(); i++) {
                if (digits[i] > obj.digits[i]) {
                    return false;
                }
                else if (digits[i] < obj.digits[i]) {
                    return true;
                }
            }
            return false;
        }
    }
}
   bool BIGINT :: operator == (BIGINT obj){
        if ((digits[0] == '-' && obj.digits[0] == '+') || (digits[0] == '+' && obj.digits[0] == '-') || (digits.size() != obj.digits.size())){
            return false;
        }
        else{
            for (int i = 0; i < digits.size(); i++){
                if (digits[i] != obj.digits[i]){
                    return false;
                }
            }
            return true;
        }
    }

    BIGINT BIGINT ::  operator+ (BIGINT b) {

        string str1 = digits, str2 = b.getter(),tempi;
        string total_sign="";
        //make str1 the small
        if (str1.length() > str2.length()){
            swap(str1,str2);
        }

        else if(str1.length() == str2.length()){
            for(int i=1; i<str1.length(); i++){
                if(str1[i] > str2[i]){
                swap(str1,str2);
                break;
                }
                else if(str1[i] < str2[i])
                    break;
            }
        }


        //new str
        string str = "";
        // get length
        int n1 = str1.length(), n2 = str2.length();

switch(str1[0]){
   case '-' :
    if(str2[0] == '+')
        total_sign+="-++";
    else
        total_sign+="-+-";
    break;

   case '+':
    if(str2[0] == '+')
        total_sign+="+++";
    else
        total_sign+="++-";
    break;


        }
if(total_sign=="++-" || total_sign=="-++" ){

    str1 = str1.substr(1, str1.size());
    str2 = str2.substr(1, str2.size());
    BIGINT num(str1);
    BIGINT num2(str2);
    BIGINT result = num2-num;
    string o = result.getter();
     o = o.substr(1, o.size());
     if(total_sign=="++-"){
    reverse(o.begin(),o.end());
    o+='-';
    reverse(o.begin(),o.end());
     }
    result.setter(o);
    return result;


}



// get strings without signs
        str1 = str1.substr(1, str1.size());
       n1--;

        str2 = str2.substr(1, str2.size());
        n2--;

        // reverse all strings for math
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;

        for (int i = 0; i < n1; i++) {
            // sum all  now digits
            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            // push sum less than 10
            str.push_back(sum % 10 + '0');
            // store carry
            carry = sum / 10;
        }
        // get reminder
        for (int i = n1; i < n2; i++) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            str.push_back(carry + '0');
        // get str back
       // str+='+';
        reverse(str.begin(), str.end());
        if(total_sign=="-+-"){
            reverse(str.begin(),str.end());
            str+='-';
            reverse(str.begin(),str.end());
        }
        // new BIGINT and return
        BIGINT num3(str);
        return num3;
    }

     BIGINT BIGINT :: operator -  (BIGINT b) {

        string str1 = digits, str2 = b.getter(),total_sign;
        char sign = (str1 < str2 ? '-' : '+');

        if(str1.length() < str2.length()){
            swap(str1,str2);
            total_sign="negative_";
        }
        else if(str1.length() == str2.length()){
            for(int i=1; i<str1.length(); i++){
                if(str1[i] < str2[i]){
                    swap(str1,str2);
                    total_sign="negative_";
                    break;
                }
                else if(str1[i] > str2[i])
                    break;
            }
        }

        //make str1 the big
/*        if (str1 < str2)
            swap(str1, str2);*/
        //new str

        switch(str1[0]){
   case '-' :
    if(str2[0] == '+')
        total_sign+="--+";
    else
        total_sign+="---";
    break;

   case '+':
    if(str2[0] == '+')
        total_sign+="+-+";
    else
        total_sign+="+--";
    break;
        }
    if(total_sign=="--+" || total_sign=="negative_--+" || total_sign=="negative_+--" || total_sign=="+--"){
        str1 = str1.substr(1, str1.size());
    str2 = str2.substr(1, str2.size());
    BIGINT num(str1);
    BIGINT num2(str2);
    BIGINT result = num2+num;
    string o = result.getter();
    if(total_sign=="--+" || total_sign=="negative_+--"){
    o = o.substr(1,o.size());
    reverse(o.begin(),o.end());
    o+="-";
    reverse(o.begin(),o.end());
    }
    result.setter(o);
    return result;
    }
        string str = "";
        // get length
        int n1 = str1.length(), n2 = str2.length();

        // get strings without signs
        str1 = str1.substr(1, str1.size());
        n1--;

        str2 = str2.substr(1, str2.size());
        n2--;

        // reverse all strings for math
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;
        // Run loop till small string length
        // and subtract digit of str1 to str2
        for (int i = 0; i < n2; i++) {
            // compute difference of
            // current digits

            int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

            // If subtraction is less than zero
            // we add then we add 10 into sub and
            // take carry as 1 for calculating next step
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            str.push_back(sub + '0');
        }

        // subtract remaining digits of larger number
        for (int i = n2; i < n1; i++) {
            int sub = ((str1[i] - '0') - carry);

            // if the sub value is -ve, then make it positive
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            str.push_back(sub + '0');
        }

        // reverse resultant string
        reverse(str.begin(), str.end());
        // delete leading zeroes
        int i = 0, n = str.size();
        string temp;
        while (1) {
            if (str[i] != '0')break;
            temp = str.substr(i + 1, str.size());
            i++;
        }
        if (temp!="")str = temp;
        //str = sign + str;
        if(total_sign=="---"){
            reverse(str.begin(),str.end());
            str+="-";
            reverse(str.begin(),str.end());
        }
        BIGINT ans(str);
        return ans;

    }
    // get digits length


ostream& operator << (ostream& out, BIGINT a){
    cout<<"Number is " << a.getter();
    return out;
}





