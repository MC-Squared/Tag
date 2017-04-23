mkdir build
cd build
cmake ..
if make; then
    cd tests/CMakeFiles/laser.dir/__/src
    gcov *.cpp.o
    lcov --directory . --capture --output-file app.info
    genhtml app.info
    cd ../../../..
    pwd
    ./laser
fi
