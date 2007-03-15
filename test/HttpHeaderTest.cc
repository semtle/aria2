#include "HttpHeader.h"
#include <cppunit/extensions/HelperMacros.h>

class HttpHeaderTest:public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(HttpHeaderTest);
  CPPUNIT_TEST(testGetRange);
  CPPUNIT_TEST_SUITE_END();
  
public:
  void testGetRange();

};


CPPUNIT_TEST_SUITE_REGISTRATION( HttpHeaderTest );

void HttpHeaderTest::testGetRange()
{
  HttpHeader httpHeader;
  httpHeader.put("Content-Range", "bytes 1-499/1234");

  RangeHandle range = httpHeader.getRange();

  CPPUNIT_ASSERT_EQUAL((int64_t)1, range->getStartByte());
  CPPUNIT_ASSERT_EQUAL((int64_t)499, range->getEndByte());
  CPPUNIT_ASSERT_EQUAL((int64_t)1234, range->getEntityLength());
}
