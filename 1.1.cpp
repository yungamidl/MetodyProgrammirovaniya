#include <iostream>
#include <string>
#include <vector>

inline bool is_begin(const char c)
{
    return
      c=='('
    ||c=='{'
    ||c=='[';
}

inline bool is_true_braket(const char beg, const char end){
    return (beg == '(' && end == ')')||
        (beg == '{' && end == '}')||
        (beg == '[' && end == ']');
}

int main()
{
   using namespace std;
   string s;
   cin>>s;
   vector<int> braket_begins; braket_begins.reserve(s.length());
   bool good = true;
   for (size_t i = 0 ; good && i< s.length(); ++i){
        if (is_begin(s[i])){
            braket_begins.push_back(i);
        }
        else{
            if (braket_begins.size() && is_true_braket(s[braket_begins.back()],s[i]))
                braket_begins.pop_back();
            else{
                good = false;
            }
        }
    }
    good = good&&!braket_begins.size();
    cout<<(good?"yes":"no");
}
