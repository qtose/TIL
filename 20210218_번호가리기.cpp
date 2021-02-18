#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12948

string solution(string phone_number) {
	string answer = "";

	for (size_t i = 0; i < phone_number.size(); ++i)
	{
		char ch = '*';

		if (i > phone_number.size() - 5)
		{
			ch = phone_number[i];
		}

		answer += ch;
	}

	return answer;
}

int main()
{
	return 0;
}