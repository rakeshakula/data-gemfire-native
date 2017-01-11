g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include FuncExec.cpp -o FuncExec -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache

