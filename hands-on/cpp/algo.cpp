#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

// g++ -std=c++14 -O -o algo algo.cpp



template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& c)
{
  os << "{ ";
  std::copy(
      std::begin(c),
      std::end(c),
      std::ostream_iterator<T>{os, " "}
  );
  os << '}';

  return os;
}

int main()
{
  // define a pseudo-random number generator engine and seed it using an actual
  // random device
  std::random_device rd;
  std::mt19937 eng{rd()};

  int const MAX_N = 100;
  std::uniform_int_distribution<int> uniform_dist{1, MAX_N};

  // fill a vector with SIZE random numbers
  int const SIZE = 10;
  std::vector<int> v;
  v.reserve(SIZE);
  std::generate_n(std::back_inserter(v), SIZE, [&]() { return uniform_dist(eng); });

  std::cout << v << '\n';




  // alternative way to fill the vector (but less efficient, why?)
  // std::vector<int> v(SIZE);
  // std::generate_n(std::begin(v), SIZE, [&]() { return uniform_dist(e); });

  // sum all the elements of the vector
  // use std::accumulate

auto s = std::accumulate(std::begin(v), std::end(v), 0);
std::cout << s << '\n';

  // multiply all the elements of the vector
  // use std::accumulate

auto m = std::accumulate(std::begin(v), std::end(v), 1,
    [](int a, int b, int c){

        std::cout<<a<<' '<<b<<' '<<c<<'\n';
        return  a* b;
    }

);
std::cout << m << '\n';


  // sort the vector in ascending order
  // use std::sort

  std::sort(std::begin(v), std::end(v));

  std::cout << v << '\n';


  // sort the vector in descending order
  // use std::sort

  std::sort(std::begin(v), std::end(v), 
	[](int a, int b){
        return a > b;
    }
  );

//  std::cout << v << '\n';
//
//  // move the even numbers at the beginning of the vector
//  // use std::partition
//
//auto first_odd = std::partition(std::begin(v),std::end(v), [](int i)
//{return !(i%2);} 
//)
//
//  std::cout << v << '\n';
//
//  // move the three central elements to the beginning of the vector
//  // use std::rotate
//
//auto mid_it = std::begin(v) + v.size() /2;
//auto n_fist = std::prev(mid_it);
//auto last = std::next(mid_it, 2);
//std::rotate(std::begin(v), n_fist, last);
//  std::cout << v << '\n';
//
//  // find the first element that is multiple of 3 or 7
//  // use std::find_if
//auto found_it = std::find_if(
//    std::begin(v),
//    std::end(v),
//    [](int i){return !(i % 3)||!(i%7);}
//);
//
//
//cout<< "fist multiple" << std::distance(std:begin(v), found_it)<< '\n';
//  // erase from the vector the multiples of 3 or 7
//  // use std::remove_if followed by vector::erase
//
//v.erase(
//    std::remove_if(
//        std::begin(v),
//        std::end(v),
//        [](int i) {return !(i %3 )||!(i % 7);}
//    )
//    std::end(v)
//);
//
//

};
