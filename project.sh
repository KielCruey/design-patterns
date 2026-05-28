#!/bin/sh

# deletes all temp directories/files
echo DELETING BUILD AND DOXYGEN FILES
rm -fr cppcheck-report.txt build doxygen

# cppcheck -- static analysis
echo RUNNING CPP-CHECK
cppcheck --suppress=missingIncludeSystem --error-exitcode=1 --enable=all --output-file=cppcheck-report.txt .

# doxygen -- documentation
echo RUNNING DOXYDEN
doxygen Doxyfile

# cmake -- builds project
echo BUILDING USING CMAKE
cmake -G "MinGW Makefiles" -B build -S .
cmake --build build

# clang-format -- formatting all code
echo RUNNING CLANG-FORMAT
find . -iname "*.cpp" -o -iname "*.hpp" -o -iname "*.inl" | xargs clang-format -i

echo SCRIPT COMPLETED