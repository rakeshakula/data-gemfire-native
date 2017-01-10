g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include PdxInstance.cpp -o PdxInstance -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache

