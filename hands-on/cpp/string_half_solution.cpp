#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>

class String {
  char* s_; // nullptr or null-terminated
 public:
  String()
      : s_(nullptr)
  {
  }
  String(char const* s)
  {
    size_t size = strlen(s) + 1;
    s_ = new char[size];
    memcpy(s_, s, size);
  }
  ~String()
  {
    delete [] s_;
  }
  String(String const& other)
  {
    size_t size = strlen(other.s_) + 1;
    s_ = new char[size];
    memcpy(s_, other.s_, size);
  }
  String(String&& tmp) // noexcept
      : s_(tmp.s_)
  {
    tmp.s_ = nullptr;
  }
  String& operator=(String const& other)
  {
    String tmp(other);
    std::swap(s_, tmp.s_);
    return *this;
  }
  String& operator=(String&& tmp)
  {
    s_ = tmp.s_;
    tmp.s_ = nullptr;
    return *this;
  }
  size_t size() const
  {
    return s_ ? strlen(s_) : 0;
  }
  char const* c_str() const
  {
    return s_;
  }
  char& operator[](size_t n)
  {
    return s_[n];
  }
  char const& operator[](size_t n) const
  {
    return s_[n];
  }
};

String get_string()
{
  return String{"Consectetur adipiscing elit"};
}

std::chrono::duration<float> test()
{
  auto s = get_string();
  std::vector<String> v(10000000, s);
  auto start = std::chrono::high_resolution_clock::now();
  v.push_back(s);
  return std::chrono::high_resolution_clock::now() - start;
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

  // auto d = test();
  // std::cout << d.count() << " \n";
}
