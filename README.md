# BTP-305 Seneca College

These are simple C++ projects created as assignments in the Third Semester of College. These projects were written with C++17 standard guidelines.

The main goal of the projects is to practice C++ syntax and produce working code without errors or memory leaks. Workshop 8 has an intentional memory leak for smart pointer demonstration.

Some of the projects contain simple mathematical work, input processing, error checking, memory handeling, inheritance & polymorphism, templated classes & functions, file processing, command-line input processing, lambda expressions, use of STL, algorithms, multi-threading, bit-manipulation, and output formatting.

Some of the projects contain data files which are being processed in that specific project.

<br/>
<br/>
<br/>

To compile any of the individual projects use the Command:

**For G++:**

```bash
g++ -Wall -std=c++17 -o output.o *.cpp
valgrind --leak-check=full output.o args...        #optional
output args...
```

**For Clang:**

```powershell
cl /W4 /std:c++17 *.cpp /out:output.exe
./output.exe args...
```


[ Note: ] To run any of the programs correctly the ***order of command-line arguments matters***.<br/> 
This is the case since the main functions were tester modules developed by our professors to get a specific output which is checked through a diff command with some fancy error messages.<br/> 
(a README will be supplied for each individual project along with a run script)

<br/>
<br/>

[Valgrind](https://valgrind.org/) is a Linux-only tool for C++ memory leak checking and is very useful for development.<br/>
It can be used on Windows with either installing WSL, Mingw, or Cygwin.<br/>
Valgrind is not a dependancy and can be ignored from the Build & Run Command.<br/>
