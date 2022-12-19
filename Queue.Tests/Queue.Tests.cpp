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

		// “есты были написаны дл€ public метода, который стал private
		TEST_METHOD(Remove_ValidData_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };
			const std::string expected = "{ 2, 3, 4, 5 }";

			// Act
			//q.Remove();

			// Assert
			Assert::AreEqual(expected, q.ToString());
		}

		TEST_METHOD(Clear_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };

			// Act
			q.Clear();

			// Assert
			Assert::AreEqual(q.IsEmpty(), true);
		}

		TEST_METHOD(cbegin_ValidData_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };
			const  auto expected  = 1;

			// Act
			const auto actual = *(q.cbegin());
			
			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Iterator_ValidData_Success)
		{
			// Arrange
			Queue q{ 1, 2, 3, 4, 5 };
			const std::string expected = "12345";

			// Act
			std::stringstream buffer;
			for(auto it = q.cbegin(); it != q.cend(); ++it)
			{
				buffer << *it;
			}

			// Assert
			Assert::AreEqual(expected, buffer.str());
		}
	};
}
