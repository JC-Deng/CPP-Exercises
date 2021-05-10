#include<iostream>
#include<string>
using namespace std::string_literals;

class String
{
    private:
        char *p_str;
        int str_size;
        
    public:
        String();
        String(int);
        String(std::string);
        String(const String&);
        String(String&&);
        ~String();

        char& operator[](int);
        String& operator+=(const String&);
        friend String operator+(String, String);

        friend std::ostream& operator<<(std::ostream&, const String&);
        friend std::istream& operator>>(std::istream&, String&);

        char* c_str() const;
        int size() const;
};

String::String() : p_str(nullptr), str_size(0) {}

String::String(int size) : p_str(new char[size]), str_size(size) {}

String::String(std::string in_str) : str_size(in_str.size())
{
    int in_size = in_str.size();
    p_str = new char[in_size];
    char *temp_p = p_str;
    for (int i = 0; i < in_size; i++) {
        *temp_p = in_str[i];
        temp_p++;
    }
}

String::String(const String &copy_obj) : str_size(copy_obj.str_size)
{
    p_str = new char[str_size];
    char *temp_p = p_str;
    char *copy_p = copy_obj.p_str;
    for (int i = 0; i < str_size; i++) {
        *temp_p = *copy_p;
        temp_p++;
        copy_p++;
    }
}

String::String(String &&move_obj) 
    : p_str(std::move(move_obj.p_str)), str_size(move_obj.str_size) {}

String::~String()
{
    if (!p_str) {
        delete[] p_str;
    }
}

char& String::operator[](int n)
{
    p_str += n;
    return *p_str;
}

String& String::operator+=(const String &opr)
{
    int this_len = this->str_size;
    int opr_len = opr.str_size;
    String temp_str(*this);
    delete[] this->p_str;
    this->p_str = new char[this_len + opr_len];
    this->str_size = this_len + opr_len;
    char *this_p = this->p_str;
    char *opr_p = opr.p_str;
    char *temp_p = temp_str.p_str;
    for (int i = 0; i < this_len; i++) {
        *this_p = *temp_p;
        this_p++;
        temp_p++;
    }
    for (int i = 0; i < opr_len; i++) {
        *this_p = *opr_p;
        this_p++;
        opr_p++;
    }
    return *this;
}

String operator+(String opr_a, String opr_b)
{

    String a_obj(opr_a);
    String b_obj(opr_b);
    int a_size = opr_a.size();
    int b_size = opr_b.size();
    String res(a_size + b_size);
    char *res_p = res.p_str;
    const char *a_p = opr_a.p_str;
    const char *b_p = opr_b.p_str;
    
    for (int i = 0; i < a_size; i++) {
        *res_p = *a_p;
        res_p++;
        a_p++;
    }
    for (int i = 0; i < b_size; i++) {
        *res_p = *b_p;
        res_p++;
        b_p++;
    }
    return res;
}

std::ostream& operator<<(std::ostream &os, const String &str)
{
    char *temp_p = str.p_str;
    for (int i = 0; i < str.str_size; i++) {
        std::cout << *temp_p;
        temp_p++;
    }
    std::cout << '\n';
    return os;
}

std::istream& operator>>(std::istream &os, String &str)
{
    int count = 0;
    int up_limit = str.str_size;
    char *temp_p = str.p_str;
    if (up_limit == 0) {
        return os;
    }
    while (os.get(*temp_p)) {
        temp_p++;
        if (++count >= up_limit) {
            break;
        }
    }
    return os;
}

char* String::c_str() const
{
    int org_size = this->str_size;
    char *res = new char[org_size + 1];
    char *org_p = this->p_str;
    char *res_p = res;
    for (int i = 0; i < org_size; i++) {
        if (*org_p == '\0') {
            org_p++;
            continue;
        } else {
            *res_p = *org_p;
            res_p++;
            org_p++;
        }
    }
    *res_p = '\0';
    return res;
}

int String::size() const
{
    return str_size;
}

int main()
{
    const String hello("Hello");
    const String world("World");

    String s = hello + String(" ");
    s += world;
    std::cout << s << "\n";
}
