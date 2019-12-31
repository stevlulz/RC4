# Project Title

A simple file encrypter-decrypter program using rc4


### Prerequisites


```
C++ compiler (g++)
```


## Built With

* [CMake](https://cmake.org/) 

## cmakeFile
    #Create a txt file named CMakeLists.txt 
    #fill it with the next lines
    
    cmake_minimum_required(VERSION 3.9)
    project(RC4)
    
    set(CMAKE_CXX_STANDARD 11)
    
    add_executable(rc4 main.cpp rc4/RC4.cpp rc4/RC4.h)
## building the project
    instruction is provided in official cmake's website just follow them 
    https://cmake.org/cmake-tutorial/
 

## Authors

* **Seyyidahmed Lahmer**




