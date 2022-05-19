#include "pch.h"
#include "CppUnitTest.h"
#include "../../../../../політех/ооп/4/lab_4.3/lab_4.3/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array A(3);
			Assert::AreEqual(A.getSize(), 3);
		}
	};
}
