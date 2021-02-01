CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../luolastori.cpp
OBJM = $(SRCM:.cpp=.o)

luolastori: luolastori.o
	$(CXX) $(CXXFLAGS) -o luolastori main.cpp luolastori.o

test: luolastori.o
	$(CXX) $(CXXFLAGS) -o test/run_tests test/test_luolastori.cpp luolastori.o -lcppunit

clean:
	rm -f test/run_tests luolastori test/cppTestLuolastoriResults.xml *.o

luolastori.o: luolastori.cpp
	$(CXX) $(CXXFLAGS) -c luolastori.cpp -o $@
