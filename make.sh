#!/bin/bash
# with tcmalloc 
# g++ -ggdb -O0 *.cc -lpthread  -o main -ltcmalloc

#witch profiler
# g++ *.cc -fstack-protector-all -ggdb3 -O0 -lpthread  -o main -lprofiler
# g++ -fstack-protector-all -ggdb3 -DNDEBUG -O0 *.cc -lpthread  -o main -lprofiler

#witch tcmalloc and profiler
# g++ -ggdb -O0 *.cc -lpthread  -o main -lprofiler

# normal
g++ -ggdb   -O0 *.cc -lpthread  -o main

# release
g++         -O0 *.cc -lpthread  -o main-release




