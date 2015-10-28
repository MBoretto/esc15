#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>

class String {
  char* s_; // nullptr or null-terminated
 public:
  String(): s_(nullptr) {}

  //Construnctor
  String(char const* s) {
    size_t size = strlen(s) + 1;
    s_ = new char[size];
    memcpy(s_, s, size);
  }
  //Destructor
  ~String() { delete [] s_; }
  //Copy constructor
  String(String const& other) {
    size_t size = strlen(other.s_) + 1;
    s_ = new char[size];
    memcpy(s_, other.s_, size);
  }
  //Move Constructor
  String(String&& tmp)
      : s_(tmp.s_) {
    tmp.s_ = nullptr;
  }
  //assingment by reference constructor
  String& operator=(String const& other)
  {
    // implemented
    size_t size = strlen(other.s_) + 1;
    s_ = new char[size];
    memcpy(s_,other.s_, size);
    //should be
    //String tmp(other);
    //std::swap(s_, tmp.s_);
    //return *this;
  }
  //Move assigmenr by reference constructor
  String& operator=(String&& other)
  {
    // implemented
     other.s_ = nullptr;
  }

  size_t size() const {
    return s_ ? strlen(s_) : 0;
  }
  char const* c_str() const
  {
    // implemented;
    return s_;
  }
  char& operator[](size_t n)
  {
    // to be implemented
  }
  char const& operator[](size_t n) const
  {
    // to be implemented
  }
};

String get_string()
{
  return String{"Consectetur adipiscing elit"};
}

int main()
{
  String const s1("Lorem ipsum dolor sit amet");

  String s2 = get_string();

  String s3;
  s3 = s1;

  String s4;
  s4 = std::move(s2);

  char& c1 = s4[4];
  char const& c2 = s1[4];

  std::cout << s3.c_str() << '\n';

  String s5(s3);

  std::cout << s5.c_str() << '\n';
  std::cout << s3.c_str() << '\n';
}
