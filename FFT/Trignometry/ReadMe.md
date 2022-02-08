# Trignometry - 101 --> calculates sine and cosine using taylors series

1. this is a C++ class for trignometry functions 
2. this also contains timer class to access performance

useful notes https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-file_name-h

3. primitive compile methods
``` bash
# compile and run the file)name.cpp
g++ -c file_name.cpp && g++ file_name.o -o file_name.out && del file_name.o
```

4. setup class trignometry using
``` bash
# accuracy rating max upto 20 i recommend 10
# 'r' for radians and 'd' for degree input
# t is the class name call sin and cos as t.sin(30)
trignometry t(ACCURACY,'r');
```

5. if u want to use timer includde timer.h and call timer class in paraentheses
``` bash
# create class
{ 
timer tim;
........... write ur code here .........
}
```