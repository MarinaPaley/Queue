#include "pch.h"
#include "CppUnitTest.h"
#include "..\Queue\Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
	TEST_CLASS(QueueTests)
	{
	public:
		
		TEST_METHOD(Ctor_Initializer_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };

			// Act 
			
			int size = static_cast<int>(q.GetSize());
			//Assert
			Assert::AreEqual(size, 5);
		}

		TEST_METHOD(ToString__ValidData_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };
			const std::string expected = "{ 1, 2, 3, 4, 5 }";

			// Act
			auto actual = q.ToString();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
