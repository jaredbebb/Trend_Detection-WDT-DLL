#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Trend_Detection\DistanceMeasures.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(DistanceMeasuresUnitTest)
	{
	public:
		
		TEST_METHOD(TestDistance)
		{
			int s = 10;
			std::unique_ptr<int>size(new int(s));
			std::unique_ptr<double[]> a(new double[s]);
			for (int i = 0; i<s; ++i) a[i] = .1;

			std::unique_ptr<double[]> b(new double[s]);
			for (int i = 0; i<s; ++i) b[i] = .4;

			DistanceMeasures d;
			double total_dist = d.euclidean(a, b, size);
			Assert::AreEqual(total_dist, 3.0, L"message", LINE_INFO());
		}
	};
}