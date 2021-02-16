#include <iostream>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12951

string solution(string s) {
	string answer = "";

	size_t length = s.length();

	if ('a' <= s[0] && s[0] <= 'z')
	{
		answer += s[0] - 32;
	}
	else 
	{
		answer += s[0];
	}

	for (int i = 1; i < length; ++i)
	{
		char ch = s[i];

		if (s[i - 1] == ' ')
		{
			if ('a' <= ch && ch <= 'z')
			{
				ch -= 32;
			}
		}
		else
		{
			if ('A' <= ch && ch <= 'Z')
			{
				ch += 32;
			}
		}

		answer += ch;
	}

	return answer;
}

int main()
{

	solution("3people unFollowed me");

	return 0;
}