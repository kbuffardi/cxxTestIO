#include "IOCapture.h"
#include <cxxtest/TestSuite.h>
#include "Talk.h"

class IOTest : public CxxTest::TestSuite
{
private:

public:
    void testSanityCheck(){
      TS_ASSERT_EQUALS(1,1);
    }
    void testGreeting(){
      IOCapture capture;
      Talk conversation;
      conversation.greeting();
      TS_ASSERT_EQUALS(capture.output(),"This is cout\n");
    }
    void testMultipleGreetings(){
      IOCapture capture;
      Talk script;
      script.greeting();
      script.greeting();
      script.greeting();
      TS_ASSERT_EQUALS(capture.output(),
                       "This is cout\nThis is cout\nThis is cout\n");
    }
    void testExclamation(){
      IOCapture capture;
      Talk shout;
      shout.exclamation("HI");
      TS_ASSERT_EQUALS(capture.output(),"HI!");
    }
    void testDoubleExclamation(){
      IOCapture capture;
      Talk script;
      script.exclamation("Help");
      script.exclamation("Please");
      TS_ASSERT_EQUALS(capture.output(),"Help!Please!");
    }
    void testConsecutive(){
      IOCapture capture;
      Talk script;
      script.greeting();
      TS_ASSERT_EQUALS(capture.output(),"This is cout\n");
      script.exclamation("The End");
      TS_ASSERT_EQUALS(capture.output(),"This is cout\nThe End!");
    }
    void testAfterflush(){
      IOCapture capture;
      Talk script;
      script.exclamation("First");
      TS_ASSERT_EQUALS(capture.outputFlush(),"First!");
      script.exclamation("Second");
      TS_ASSERT_EQUALS(capture.output(),"First!Second!");
    }
    void testSimpleInputFeed(){
      IOCapture capture;
      capture.inputFeed("test");
      std::string input;
      std::cin>>input;
      TS_ASSERT_EQUALS(input,"test");
    }
    void testMultiTypeInputFeed(){
      IOCapture capture;
      capture.inputFeed("string\n10\nZ");
      std::string first;
      int second;
      char third;
      std::cin>>first>>second>>third;
      TS_ASSERT_EQUALS(first,"string");
      TS_ASSERT_EQUALS(second,10);
      TS_ASSERT_EQUALS(third,'Z');
    }
    void testGetlineInputFeed(){
      IOCapture capture;
      capture.inputFeed("full name");
      std::string input;
      getline(std::cin,input);
      TS_ASSERT_EQUALS(input,"full name");
    }
};
