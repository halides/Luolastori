CXX = g++
INCLUDES= -I./headers
CXXFLAGS = -g $(INCLUDES) 

luolastori: luolastori.o main.cpp headers/luolastori.hpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o luolastori main.cpp luolastori.o

test: luolastori.o test_luolastori.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o test_luolastori test_luolastori.cpp luolastori.o -lcppunit

clean:
	rm -f luolastori *.o *.gcno *.gcov *.gcda test_luolastori cppTestLuolastoriResults.xml

luolastori.o: luolastori.cpp headers/luolastori.hpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c luolastori.cpp -o $@
