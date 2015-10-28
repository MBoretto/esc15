---
title: Short introduction to Valgrind
layout: main
---

[Valgrind](http://valgrind.org/) is an instrumentation framework
for dynamic analysis tools. At this school we use the tools for checking
memory management bugs, but it includes many other tools such as for
finding threading bugs and analysing cache access patterns. This
exercise will introduce you to the basic mechanics of using Valgrind;
later exercises will go into more detail.

1. Build [`memerror.cc`]({{site.exercises_repo}}/hands-on/basic/memerror.cc):

        cd esc15/hands-on/basic
        c++ -std=c++14 -g -o memerror memerror.cc
        
2. Run the test program under valgrind:

        valgrind ./memerror

3. The compiler can sometimes warn us about the same thing:

        c++ -std=c++14 -g -Wall -Wextra -o memerror memerror.cc

4. Address sanitizer can also help you:

        c++ -std=c++14 -fsanitize=address -g -Wall -Wextra -o memerror memerror.cc
        ./memerror       
