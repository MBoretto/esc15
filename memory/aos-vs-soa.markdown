---
title: AoS vs SoA
layout: main
---

In this exercise you will touch with hand the difference between AoS and SoA.

Copy and paste to a file and compile the following two programs:

    #include <vector>
    #define NUM_ITEMS 100000000

    struct A {
      double x;
      double y;
      double z;
      double w;
    };
    
    int main (int argc, char ** argv)
    {
      std::vector<A> myAoS(NUM_ITEMS);
      for (int i = 0; i < 10; ++i)
        for (auto &p : myAoS)
          p.w = 1.0;
      return 0;
    }


we will call them `aos.cc`.

    c++ -O3 -std=c++14 -o aos aos.cc

1. Convert the AoS to SoA.

2. Which one is faster?

3. How many bytes are written in the AoS case? How many in the SoA case?

4. How many cache-lines are touched in the AoS case? How many in the
   SoA case?

5. How many memory pages?

6. What happens to the performance of the two examples if you add a virtual
   destructor to A? Why?
