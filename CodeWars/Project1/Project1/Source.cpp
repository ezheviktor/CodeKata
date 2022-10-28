#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
using namespace std;

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer( ) : m_beg(clock_t::now( ))
	{}

	void reset( )
	{
		m_beg = clock_t::now( );
	}

	double elapsed( ) const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now( ) - m_beg).count( );
	}
};

//int s(int number)
//{
//    int sum = 0;
//    for (int i = 2; i <= (number / 2); ++i)
//    {
//        if (number % i == 0)
//        {
//            sum += i;
//
//        }
//    }
//
//    return sum;
//}

//int s(int number)
//{
//    int i = 2;
//    int counter = 0;
//    int totalSum = 0;
//    while (i <= 10)
//    {
//        int innerSum = 0;
//        while (number % i == 0)
//        {
//            innerSum += (number / i);
//            innerSum+= pow(i, counter);
//        }
//        counter = 0;
//        ++i;
//        if (totalSum < innerSum) totalSum = innerSum;
//        
//    }
//    return totalSum;
//
//}

int s(int number)
{
	int sum = 0;
	int lastIteration = number;
	for (int i = 2; i < lastIteration; ++i)
	{
		if (number % i == 0)
		{
			sum += i;
			lastIteration = number / i;
			if (i != lastIteration) sum += lastIteration;
		}
	}
	return sum;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//string buddy(long long start, long long limit)
//{
//    // your code
//        for (int NValue=start; NValue <= limit; NValue ++)
//         {
//            int MValue = s(NValue);
//            if (MValue > NValue && NValue == s(MValue))
//            {
//                std::stringstream in;
//                string result;
//                in << "(" << NValue << " " << MValue << ")";
//                result = in.str( );
//                return result;
//            }
//            else if (NValue == limit) return "Nothing";
//         }
//
//}

//string buddy(long long start, long long limit)
//{
//    // your code
//    if (start%2==0)
//    {
//        for (int NValue = start; NValue <= limit; NValue+=2)
//        {
//            int MValue = s(NValue);
//            if (MValue > NValue && NValue == s(MValue))
//            {
//                std::stringstream in;
//                string result;
//                in << "(" << NValue << " " << MValue << ")";
//                result = in.str( );
//                return result;
//            }
//            else if (NValue + 2 > limit) return "Nothing";
//        }
//    }
//    else
//    {
//        for (int NValue = start+1; NValue <= limit; NValue+=2)
//        {
//            int MValue = s(NValue);
//            if (MValue > NValue && NValue == s(MValue))
//            {
//                std::stringstream in;
//                string result;
//                in << "(" << NValue << " " << MValue << ")";
//                result = in.str( );
//                return result;
//            }
//            else if (NValue + 2 > limit) return "Nothing";
//        }
//    }
//
//}

string buddy(long long start, long long limit)
{
	// your code
	int nValue;
	int uneven;

	int i = ceil(static_cast<double>(start) / 315);
	if (i % 2 == 0) ++i;

	for (i; i <= floor(static_cast<double>(limit) / 315); i += 2)
	{
		nValue = 315 * i;
		int mValue = s(nValue);
		if (mValue > nValue && nValue == s(mValue))
		{
			uneven = nValue;
			if (uneven != 0 && uneven == start)
			{
				std::stringstream in;
				string result;
				in << "(" << nValue << " " << mValue << ")";
				result = in.str( );
				return result;
			}
			break;
		}
		else if (315 * (i + 2) > limit) uneven = 0;
	}


	if (start % 2 == 0) nValue = start;
	else nValue = start + 1;

	if (uneven)
	{
		for (nValue; nValue <= uneven; nValue += 2)
		{
			int mValue = s(nValue);
			if (mValue > nValue && nValue == s(mValue))
			{
				std::stringstream in;
				string result;
				in << "(" << nValue << " " << mValue << ")";
				result = in.str( );
				return result;
			}
			else if (nValue + 2 > uneven)
			{
				std::stringstream in;
				string result;
				in << "(" << uneven << " " << s(uneven) << ")";
				result = in.str( );
				return result;
			}
		}
	}
	else
	{

		for (nValue; nValue <= limit; nValue += 2)
		{
			int mValue = s(nValue);
			if (mValue > nValue && nValue == s(mValue))
			{
				std::stringstream in;
				string result;
				in << "(" << nValue << " " << mValue << ")";
				result = in.str( );
				return result;
			}
			else if (nValue + 2 > limit) return "Nothing";
		}
	}


}

//string buddy(long long start, long long limit)
//{
//	// your code
//	long long NValue;
//	int c = 3;
//
//	if (start % 2 == 0) NValue = start;
//	else NValue = start + 1;
//
//	for (NValue; NValue <= limit; NValue += 2)
//	{
//		int unDivid= 945;
//		while (start > unDivid)
//		{
//			c += 2;
//			unDivid = (945 * c / 3);
//		}
//		if (NValue > unDivid)
//		{
//			int MValue = s(unDivid);
//			if (MValue > unDivid && unDivid == s(MValue))
//			{
//				std::stringstream in;
//				string result;
//				in << "(" << NValue << " " << MValue << ")";
//				result = in.str( );
//				return result;
//			}
//			c += 2;
//		}
//
//		int MValue = s(NValue);
//		if (MValue > NValue && NValue == s(MValue))
//		{
//			std::stringstream in;
//			string result;
//			in << "(" << NValue << " " << MValue << ")";
//			result = in.str( );
//			return result;
//		}
//
//		else if (NValue + 2 > limit) return "Nothing";
//
//	}
//
//}
void testing(long long start, long long limit, string expected)
{
	cout << "Start " << start << " Limit " << limit << endl;
	string actual = buddy(start, limit);
	cout << "Actual " << actual << endl;
	cout << "Expect " << expected << endl << endl;

}
int main( )
{
	int counter = 0;
	while (counter<=100000)
	{
		int MValue = s(counter);
		if (MValue > counter && counter == s(MValue))
		{
			cout << "(" << counter << " " << MValue << ")";
		}
		++counter;
	}


	testing(5775, 6128, "(5775 6128)");
	testing(1071625, 1103735, "(1081184 1331967)");
	testing(2382, 3679, "Nothing");
	testing(8983, 13355, "(9504 20735)");

	//Timer t;
	//ofstream iostr("LogFile.txt", ios::app);



	//if (!iostr)
	//{
	//	cout << "Something went wrong" << endl;
	//}
	//std::cout << t.elapsed( ) << endl;
	//iostr << t.elapsed( ) << endl;
	return 0;
}