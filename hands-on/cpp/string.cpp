#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>

class String {
  char* s_; // nullptr or null-terminated
 public:
  //Destructor
  ~String() { delete [] s_; }//Delete s1;
  //Construntor empty
  String(): s_(nullptr) {}//String s1;
  //Constructor param
  String(char const* s) { //String s1("blabla");
    size_t size = strlen(s) + 1;
    s_ = new char[size];
    memcpy(s_, s, size);
  }
  //Copy constructor
  String(String const& other) { //String s1(s2);
    size_t size = strlen(other.s_) + 1;
    s_ = new char[size];
    memcpy(s_, other.s_, size);
  }
  //Move constructor 
  String(String&& tmp)//String s1(get_string());
                      //String s1(std::Move(s2));
      : s_(tmp.s_) {
    tmp.s_ = nullptr;
  }
  //Copy assigment constructor
  String& operator=(String const& other) // String s1=s2;
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
  //Move assigment constructor
  String& operator=(String&& other)//String s1=get_string();
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

String get_string()
{
  return String{"Consectetur adipiscing elit"};
}
