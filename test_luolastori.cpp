#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "luolastori.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestLuolastori: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestLuolastori);
    CPPUNIT_TEST(test_luola);
    CPPUNIT_TEST_SUITE_END();

protected:
    void test_luola(void);

private:

    Luola testL;
};

//-----------------------------------------------------------------------------

void
TestLuolastori::test_luola(void)
{
	int jotai = testL.moneenko_fillaa();
	int jotai2 = testL.montako_tyhjaa();
	CPPUNIT_ASSERT(jotai == 0);

	testL.tee_huone(false);
	jotai = testL.moneenko_fillaa();
	jotai2 = testL.montako_tyhjaa();
	CPPUNIT_ASSERT(jotai == jotai2);

	testL.tee_huone(false);
	testL.tee_huone(false);
	testL.tee_sokkelot();

	testL.puhko();
//	std::cout << std::endl; testL.tulosta();
	jotai = testL.moneenko_fillaa();
	jotai2 = testL.montako_tyhjaa();
//	std::cout << std::endl << jotai << " " << jotai2 << std::endl;
	CPPUNIT_ASSERT(jotai == jotai2);

	testL.poista_umpikujat();
//	std::cout << std::endl; testL.tulosta();
//	std::cout << std::endl << jotai << " " << jotai2 << std::endl;
	jotai = testL.moneenko_fillaa();
	jotai2 = testL.montako_tyhjaa();
	CPPUNIT_ASSERT(jotai == jotai2);
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestLuolastori );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("test/cppTestLuolastoriResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
