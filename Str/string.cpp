/*************************************************************************
	> File Name: String.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时41分08秒
 ************************************************************************/

#include <iostream>
using namespace std;


class String {
friend ostream &operator<<(ostream &, const String &); 
friend istream &operator>>(istream &, String &); 
friend String operator+(const String &, const String &);
friend String operator+(String &, const char *);
friend String operator+(const char *, String &);
friend bool operator==(const String &, const String &);
friend bool operator==(String &, const char *);
friend bool operator==(const char *, String &);
friend bool operator!=(const String &, const String &);
friend bool operator!=(String &, const char *);
friend bool operator!=(const char *, String &);


public:
    String();
    String(const char *t);
    String(const String& t);
    String(size_t st, char ch);
    String &operator=(const char *);
    String &operator=(const String &);
    char operator[](size_t n) { return s[n]; }
    size_t size() { return len; };
    bool empty() { return len > 0 ? 0 : 1;}

    ~String() { delete [] s; }
private:
    char *s;
    size_t len = 0;
};


String::String()
{
    s = new char;
}

String::String(const char *t)
{
    const char *p = t; 
    while(*p++) {
        len++;
    }
    s = new char[len + 1];  
    for (int i = 0; i < len ;i++) {
        s[i] = t[i];
    }
    s[len] = '\0';
}

String::String(const String& t)
{
    len = t.len;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = t.s[i];
    }
    s[len] = '\0';
}

String &String::operator=(const char *t)
{
    delete []s;
    const char *p = t;
    len = 0;
    while(*p++) {
        len++;
    }
    s =new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = t[i];
    }
    s[len] = '\0';
}

String &String::operator=(const String &t) 
{
    delete []s;
    len = t.len;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] =t.s[i];
    }
    s[len] = '\0';
}

String::String(size_t st, char ch) {
    len = st;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = ch;
    }
    s[len] = '\0';
}

ostream &operator<<(ostream &os, const String &s)
{
    os << s.s;
    return os; 
}


istream &operator>>(istream &is, String &s)
{
    delete []s.s;
    s.s = new char[100];
    is >> s.s;
    s.len = 0;
    char *p = s.s;
    while(*p++)
        s.len++;
    return is;
}

String operator+(const String &s1, const String &s2)
{
    int len = s1.len + s2.len;
    String s = new char[len];
    s.len = len;
    for (int i = 0; i < s1.len; i++) {
        s.s[i] = s1.s[i];
    }
    for (int i = 0; i < s2.len; i++) {
        s.s[i + s1.len] = s2.s[i];
    }
    return s;
}

String operator+(const char *s1, String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    String s = new char[len + s2.len];
    s.len = len + s2.len;
    for (int i = 0; i < len; i++) {
        s.s[i] = s1[i];
    }
    for (int i = 0; i < s2.len; i++) {
        s.s[i + len] = s2.s[i];
    }
    return s;
}

String operator+(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    String s = new char[len + s1.len];
    s.len  = len + s1.len;
    for (int i = 0; i < s1.len; i++) {
        s.s[i] = s1.s[i];
    }
    for (int i = 0; i < len; i++) {
        s.s[i + s1.len] = s2[i];
    }
    return s;
}

bool operator==(const String &s1, const String &s2)
{
    int flag = 0;
    if (s1.len == s1.len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 1;
        }
    }
    return 0;
}
bool operator==(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    
    int flag = 0;
    if (s1.len == len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 1;
        }
    }
    return 0;
}
bool operator==(const char *s1 ,String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    
    int flag = 0;
    if (len == s2.len) {
        for(int i = 0; i < len; i++) {
            if (s1[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == len) {
            return 1;
        }
    }
    return 0;
}
bool operator!=(const String &s1, const String &s2)
{
    int flag = 0;
    if (s1.len == s1.len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 0;
        }
    }
    return 1;
}
bool operator!=(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    
    int flag = 0;
    if (s1.len == len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 0;
        }
    }
    return 1;
    
}
bool operator!=(const char *s1, String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    
    int flag = 0;
    if (len == s2.len) {
        for(int i = 0; i < len; i++) {
            if (s1[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == len) {
            return 0;
        }
    }
    return 1;
    
}

int main()
{
    String s("abc");
    cout << s.size() << endl;
    cout << s  << s.size() << endl;

    String s1(s);
    cout << s1 << s1.size() << endl;
    
    String s2(10,'a');
    cout << s2 << s2.size() << endl;
    
    
    s2 = s1;
    cout << s2 << s2.size() << endl;
    const char *t = "123";
    s2 = t;
    cout << s2 << s2.size() << endl;
    
    String s3(t);
    cout << s3 << s3.size() << endl;
    
    String s4, s5;
  //  cin >> s4 >>s5;
   // cout << s4 << s4.size() << endl;
  //  cout << s5 << s5.size() << endl;

    cout << s[1] << s[2] << endl;

    cout << s4.size() << s5.size() << endl;
    String s6;
    s6 = (s4 + s5);
    cout << s6 << endl;
    
    s6 = s6 + "world";
    cout << s6 << s6.size() << endl;
    s6 = "world" + s6;
    cout << s6 << s6.size() << endl;
    s6 = s6 + "world" + s5;
    cout << s6 << s6.size() << endl;

    String s7 = "456";
    s2 = "456";
    s3 = "12";
    s4 = "454";
    cout << (s7 == s2) << endl;
    cout << (s7 == s3) << endl;
    cout << (s7 == s4) << endl;

    const char *t1 = "qwe";
    s1 = "qwe";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
    s1 = "qw";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
}
