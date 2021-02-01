#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/72410

string solution(string new_id) {
	string answer = "";

	//1 대문자 -> 소문자
	char ch = 0;
	string condition1 = "";
	for (size_t i = 0; i < new_id.length(); ++i)
	{
		ch = new_id[i];

		if ('A' <= ch && ch <= 'Z')
		{
			ch += + 32;
		}

		condition1 += ch;
	}

	//2 알파벳,숫자,-,_,. 외 제거
	string condition2 = "";
	for (size_t i = 0; i < condition1.length(); ++i)
	{
		ch = condition1[i];

		if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || ch == '-' || ch == '_' || ch == '.')
		{
			condition2 += ch;
		}
	}

	if (condition2.length() == 0)
	{
		return "aaa";
	}

	//3 .가 연속되면 1개로
	string condition3 = "";
	condition3 += condition2[0];
	for (size_t i = 1; i < condition2.length(); ++i)
	{
		if (condition2[i] == '.' && condition2[i - 1] == '.')
		{
			continue;
		}

		condition3 += condition2[i];
	}

	//4 .가 처음이나 끝이면 제거
	string condition4 = "";
	for (size_t i = 0; i < condition3.length(); ++i)
	{
		if ((i == 0 && condition3.front() == '.') || (i == condition3.length() - 1 && condition3.back() == '.'))
		{
			continue;
		}

		condition4 += condition3[i];
	}

	if (condition4.length() == 0)
	{
		return "aaa";
	}

	//5 빈곳에 a
	string condition5 = "";
	for (size_t i = 0; i < condition4.length(); ++i)
	{
		ch = condition4[i];
		if (ch == ' ')
		{
			ch = 'a';
		}

		condition5 += ch;
	}

	//6 15자까지 남김, 마지막이 .이면 제거
	string condition6 = "";
	if (15 < condition5.length())
	{
		for (size_t i = 0; i < 15; ++i)
		{
			condition6 += condition5[i];
		}
	}
	else
	{
		condition6 = condition5;
	}

	if (condition6.back() == '.') 
	{
		condition6.erase(condition6.end() - 1);
	}
	

	//7 길이가 2자 이하면 마지막문자로 3될때까지 채우기
	string condition7 = condition6;
	if (condition6.length() < 3)
	{
		while (condition7.length() < 3)
		{
			condition7 += condition7.back();
		}
	}
	
	answer = condition7;

	return answer;
}

int main() {

	string str = "=.=";

	solution(str);

	return 0;
}