CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../luolastori.cpp
OBJM = $(SRCM:.cpp=.o)

luolastori: luolastori.o
	$(CXX) $(CXXFLAGS) -o luolastori main.cpp luolastori.o

test: luolastori.o
		$(CXX) $(CXXFLAGS) -o run_tests test_luolastori.cpp luolastori.o -lcppunit

clean:
	rm -f run_tests luolastori test_results/cppTestLuolastoriResults.xml *.o

luolastori.o: luolastori.cpp
	$(CXX) $(CXXFLAGS) -c luolastori.cpp -o $@
