#include <cxxtest/TestSuite.h>

class IOTest : public CxxTest::TestSuite
{
public:
    void testSanityCheck()
    {
        TS_ASSERT_EQUALS(1,1);
    }
};
