g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include Basic.cpp -o Basic -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache

