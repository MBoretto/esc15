#include<iostream>
#include<iomanip>
#include<cmath>
#include<limits>
#include<cstdio>


int count(float x, float e) {
  int c=0;
  while(x<e) {x=std::nextafter(x,2*e); ++c;}
  return c;
}

int main() {


  std::cout << count(.1f,1.f) << std::endl;
  std::cout << count(2.f,3.f) << std::endl;
		     
  return 0;

};
