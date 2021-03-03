#include <iostream>
#include <string>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12939

string solution(string s) {
	string answer = "";

	map<int, string> m;
	string dummy = "";
	
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			int num = stoi(dummy);
			m.emplace(num, dummy);

			dummy = "";
		}
		else
		{
			dummy += s[i];
		}
	}

	int num = stoi(dummy);
	m.emplace(num, dummy);

	answer = (*m.begin()).second + " " + (*(--m.end())).second;

	return answer;
}

int main()
{
	solution("1 2 3 4");

	return 0;
}