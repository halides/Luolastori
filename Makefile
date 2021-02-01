CXX = g++
INCLUDES= -I./headers
CXXFLAGS = -g $(INCLUDES)

luolastori: luolastori.o
	$(CXX) $(CXXFLAGS) -o luolastori main.cpp luolastori.o

test: luolastori.o
	$(CXX) $(CXXFLAGS) -o test/run_tests test/test_luolastori.cpp luolastori.o -lcppunit

clean:
	rm -f luolastori *.o test/run_tests test/cppTestLuolastoriResults.xml

luolastori.o: luolastori.cpp
	$(CXX) $(CXXFLAGS) -c luolastori.cpp -o $@
