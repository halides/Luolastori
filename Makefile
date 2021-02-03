CXX = g++
INCLUDES= -I./headers
CXXFLAGS = -g $(INCLUDES) -fprofile-arcs -ftest-coverage

luolastori: luolastori.o main.cpp
	$(CXX) $(CXXFLAGS) -o luolastori main.cpp luolastori.o

test: luolastori.o test_luolastori.cpp
	$(CXX) $(CXXFLAGS) -o test_luolastori test_luolastori.cpp luolastori.o -lcppunit

clean:
	rm -f luolastori *.o *.gcno *.gcov *.gcda test_luolastori cppTestLuolastoriResults.xml

luolastori.o: luolastori.cpp
	$(CXX) $(CXXFLAGS) -c luolastori.cpp -o $@
