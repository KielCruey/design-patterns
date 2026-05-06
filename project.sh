#!/bin/sh

# deletes all temp directories/files
rm -fr cppcheck-report.txt build doxygen

# cppcheck -- static analysis
cppcheck --suppress=missingIncludeSystem --error-exitcode=1 --enable=all --output-file=cppcheck-report.txt .

# doxygen -- documentation
doxygen Doxyfile

# cmake -- builds project
cmake -G "MinGW Makefiles" -B build -S .
cmake --build build