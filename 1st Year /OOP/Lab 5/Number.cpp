#include "Number.h"
#include <cstring>
#include <iostream>

using namespace std;

Number::Number(const char *value, int base) {
    this->base=base;
    this->value=new char[strlen(value)+1];
    strcpy(this->value,value);
    this->decimal=0;
    for (int tr=0;tr<strlen(value);tr++) {
        if (value[tr]>='0' && value[tr]<='9') {
            this->decimal=this->decimal*base+(value[tr]-'0');
        } else {
            this->decimal=this->decimal*base+(value[tr]-'A'+10);
        }
    }
}

Number::Number(int value){
    this->base=10;
    this->value=new char[10];
    strcpy(this->value,to_string(value).c_str());
    this->decimal=value;
}

Number::~Number() {
    delete[] value;
}

char Number::operator[](int index) {
    return value[index];
}

void Number::SwitchBase(int newBase) {
    if (newBase==base) {
        return;
    }
    int temp=decimal;
    int i=0;
    while (temp>0) {
        value[i]=temp%newBase<10?temp%newBase+'0':temp%newBase-10+'A';
        temp/=newBase;
        i++;
    }
    value[i]='\0';
    base=newBase;

    int start=0;
    int end=strlen(value)-1;
    while (start<end) {
        char temp=value[start];
        value[start]=value[end];
        value[end]=temp;
        start++;
        end--;
    }
}

void Number::Print() {
    cout<<value<<endl;
}

int Number::GetDigitsCount() {
    return strlen(value);
}

int Number::GetBase() {
    return base;
}

Number::Number(const Number &n) {
    this->base=n.base;
    this->decimal=n.decimal;
    this->value=new char[strlen(n.value)+1];
    strcpy(this->value,n.value);
}

Number::Number(Number &&n) {
    this->base=n.base;
    this->decimal=n.decimal;
    this->value=n.value;
    n.value=nullptr;
}

Number& Number::operator=(Number &&n) {
    if (this==&n) {
        return *this;
    }
    delete[] value;
    this->base=n.base;
    this->decimal=n.decimal;
    this->value=n.value;
    n.value=nullptr;
    return *this;
}

Number& Number::operator=(const Number &n) {
    if (this==&n) {
        return *this;
    }
    delete[] value;
    this->base=n.base;
    this->decimal=n.decimal;
    this->value=new char[strlen(n.value)+1];
    strcpy(this->value,n.value);
    return *this;
}

Number Number::operator+(Number &n) {
    int newBase=base>n.base?base:n.base;
    int newDecimal=decimal+n.decimal;
    Number result(to_string(newDecimal).c_str(),10);
    result.SwitchBase(newBase);
    return result;
}

Number Number::operator-(Number &n) {
    int newBase=base>n.base?base:n.base;
    int newDecimal=decimal-n.decimal;
    Number result(to_string(newDecimal).c_str(),10);
    result.SwitchBase(newBase);
    return result;
}

bool Number::operator>(Number &n) {
    return decimal>n.decimal;
}

bool Number::operator<(Number &n) {
    return decimal<n.decimal;
}

bool Number::operator>=(Number &n) {
    return decimal>=n.decimal;
}

bool Number::operator<=(Number &n) {
    return decimal<=n.decimal;
}

bool Number::operator==(Number &n) {
    return decimal==n.decimal;
}

bool Number::operator!=(Number &n) {
    return decimal!=n.decimal;
}

Number& Number::operator--() {
    char *temp=new char[strlen(value)];
    for (int tr=1;tr<strlen(value);tr++) {
        temp[tr-1]=value[tr];
    }
    temp[strlen(value)-1]='\0';
    delete[] value;
    value=temp;
    decimal/=10;
    return *this;
}

Number Number::operator--(int) {
    char *temp=new char[strlen(value)];
    for (int tr=0;tr<strlen(value)-1;tr++) {
        temp[tr]=value[tr];
    }
    temp[strlen(value)-1]='\0';
    delete[] value;
    value=temp;
    decimal/=10;
    return *this;
}

Number& Number::operator+=(Number &n) {
    int val = decimal + n.decimal;
    int base = this->base > n.base ? this->base : n.base;

    char *temp = new char[10];
    int i = 0;
    while (val > 0) {
        temp[i] = val % base < 10 ? val % base + '0' : val % base - 10 + 'A';
        val /= base;
        i++;
    }
    temp[i] = '\0';
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char t = temp[start];
        temp[start] = temp[end];
        temp[end] = t;
        start++;
        end--;
    }
    delete[] value;
    value = temp;
    decimal = val;
    this->base = base;
    return *this;
}

Number& Number::operator-=(Number &n) {
    int val = decimal - n.decimal;
    int base = this->base > n.base ? this->base : n.base;

    char *temp = new char[10];
    int i = 0;
    while (val > 0) {
        temp[i] = val % base < 10 ? val % base + '0' : val % base - 10 + 'A';
        val /= base;
        i++;
    }
    temp[i] = '\0';
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char t = temp[start];
        temp[start] = temp[end];
        temp[end] = t;
        start++;
        end--;
    }
    delete[] value;
    value = temp;
    decimal = val;
    this->base = base;
    return *this;
}

Number::Number(const char *value) {
    this->base=10;
    this->value=new char[strlen(value)+1];
    strcpy(this->value,value);
    this->decimal=0;
    for (int tr=0;tr<strlen(value);tr++) {
        this->decimal=this->decimal*10+(value[tr]-'0');
    }
}

// Damian Cozma - March 2024
