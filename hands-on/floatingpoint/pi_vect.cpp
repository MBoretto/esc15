 #include <limits>
 #include <algorithm>
 #include <type_traits>
 #include <cstring>
 #include <x86intrin.h>
    
// template<typename Float>
// float pi(int num_steps) {
//   if(num_steps <=0) __builtin_unreachable();
//   Float step =  Float(1.0)/(Float) num_steps;
//   Float sum = 0;
//   // num_steps = 4*(num_steps/4);  // make sure is a multiple of 4
//   for (int i=0;i< num_steps; i++){
//     auto x = (Float(i)+Float(0.5))*step;
//     sum += Float(4.0)/(Float(1.0)+x*x);
//   }
//   return step * sum;
// }
//    



 typedef float __attribute__( ( vector_size( 16 ) ) ) float32x4_t;
 constexpr float32x4_t zero4 = {0.f,0.f,0.f,0.f};

 template<typename float32x4_t>
 float pi(int num_steps) {
   if(num_steps <=0) __builtin_unreachable();

   float step =  float(1.0)/(float) num_steps;

   float32x4_t sum = zero4;
   float32x4_t a = {0.5f,0.5f,0.5f,0.5f};

   // num_steps = 4*(num_steps/4);  // make sure is a multiple of 4
   for (int i=0;i< num_steps; i++){

     //auto x = (Float(i)+Float(0.5))*step;
     auto x = (float32x4_t(i) + a ) * step;

     sum += float(4.0)/(float(1.0)+x*x);
   }
   return step * sum;
 }





 #include<iostream>
 #include <chrono>
    
 template<typename T>
 void go(int num_steps) {
   auto start = std::chrono::high_resolution_clock::now();
   auto res = pi<T>(num_steps);
   auto total_time = std::chrono::high_resolution_clock::now() -start;
   std::cout << "pi = " << res << " in " << total_time.count() << std::endl;
 }
    
 int main ()
 {

   auto total_time = std::chrono::high_resolution_clock::duration{};
  
   constexpr int num_steps = 1000000;
      
   go<float>(num_steps);
   go<double>(num_steps);
    
   return 0;
 }
