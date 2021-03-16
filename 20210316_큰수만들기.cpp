#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp

string solution(string number, int k) {
	string answer = "";

	int num = -1;

	for (int j = 0; j < number.length() - k; ++j) 
	{
		char ch = 0;

		for (int i = num + 1; i <= k + j; ++i)
		{
			if (ch < number[i])
			{
				num = i;
				ch = number[i];
			}
		}

		answer += ch;
	}

	return answer;
}

int main()
{
	solution("4177252841", 4);


	return 0;
}