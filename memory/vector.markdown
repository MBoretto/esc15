---
title: Vector memory use
layout: main
---

The goal of this exercise is to understand the memory use and performance of
[`std::vector`](http://www.cplusplus.com/reference/stl/vector/). You will get
familiar with the [IgProf](http://igprof.org) profiler tool.

Steps
-----

1. Go to the exercise directory:

        cd esc15/hands-on/memory

2. Examine the little test programs in this directory.  You use them for
   dedicated little studies on container memory allocation behaviour:

   - [`vvvi-build-and-copy.cc`]({{site.exercises_repo}}/hands-on/memory/vvvi-build-and-copy.cc):
     Build triply nested vector of `int`s, and make a copy of it; drops profile
     heap snapshots part way.  This example was used in the presentation.

   - [`vvvi-reserve.cc`]({{site.exercises_repo}}/hands-on/memory/vvvi-reserve.cc): Same as
     `vvvi-build-and-snapshot.cc`, but uses the `reserve()` method
     correctly to avoid vector resizes.  This example was used in the
     presentation.

3. Build each program.  The command is mentioned in each source file.  To
   build all in one go:

        grep -h Compile *.cc | sed 's|// Compile: ||' | sh -x

4. Run the programs under the igprof profiler:

        rm -f *.gz
        igprof -mp ./vvvi-build-and-copy
        igprof -mp ./vvvi-reserve

5. Analyse the profiles using:

        for f in *.gz; do
          igprof-analyse --sqlite -d -v -g -r MEM_TOTAL $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_tot.sql3
          igprof-analyse --sqlite -d -v -g -r MEM_LIVE $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_live.sql3
          igprof-analyse --sqlite -d -v -g -r MEM_LIVE --value peak $f |
            sqlite3 ~/public_html/cgi-bin/data/${f}_live_peak.sql3
        done

6. This results in profiles such as: `http://esc-gw.pd.infn.it:61100/~<student>/cgi-bin/igprof-navigator.py/vvvi-copy.gz_tot/`.


