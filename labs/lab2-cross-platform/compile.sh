g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache PdxInstance.cpp -o PdxInstance
