echo off
echo compiling test
g++ -o test test.cpp hidden_unit0.cpp hidden_unit1.cpp output_unit.cpp
echo compiling main
g++ -o run main.cpp hidden_unit0.cpp hidden_unit1.cpp output_unit.cpp
test.exe
