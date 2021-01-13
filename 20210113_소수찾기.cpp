#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12921

int solution(int n) {
	int answer = 0;
	
	//vector<int> v;

	//if (2 <= n) 
	//{
	//	v.push_back(2);
	//	++answer;
	//}

	//for (int i = 2; i <= n; ++i) 
	//{
	//	bool b1 = false;
	//	for (auto& num : v) 
	//	{
	//		if (i % num == 0)
	//		{
	//			b1 = true;
	//			break;
	//		}
	//	}

	//	if (b1)
	//	{
	//		continue;
	//	}


	//	bool b2 = false;

	//	for (int j = 2; j < i; ++j) 
	//	{
	//		bool b3 = false;
	//		for (auto& num : v)
	//		{
	//			if (j % num == 0)
	//			{
	//				b3 = true;
	//				break;
	//			}
	//		}

	//		if (b3)
	//		{
	//			continue;
	//		}

	//		if (i % j == 0) 
	//		{
	//			b2 = true;
	//			break;
	//		}
	//	}

	//	if (b2 == false)
	//	{
	//		v.push_back(i);
	//		++answer;
	//	}
	//}

	//에라스토테네스의 체
	//https://velog.io/@max9106/Algorithm-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4
	vector<int> v;
	v.reserve(n);
	
	for (int i = 0; i <= n; ++i)
	{
		v.push_back(i);
	}

	v[1] = 0;

	for (int i = 2; i <= n; ++i) 
	{
		if (v[i] == 0)
		{
			continue;
		}

		for (int j = 2 * i; j <= n; j += i)
		{
			v[j] = 0;
		}
	}

	for (auto& num : v)
	{
		if (num != 0)
		{
			++answer;
		}
	}

	return answer;
}

int main() {

	solution(10);

	return 0;
}