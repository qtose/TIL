#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12926

string solution(string s, int n) {
	string answer = "";

	unsigned char ch = 0;

	for (size_t i = 0; i < s.length(); ++i)
	{
		ch = s[i] + n;

		if (s[i] == ' ')
		{
			answer += s[i];
			continue;
		}
		else if (90 < ch && s[i] < 97)
		{
			ch -= 26;
		}
		else if (122 < ch)
		{
			ch -= 26;
		}


		answer += ch;
	}

	return answer;
}

int main() {

	solution("AaZz", 25);

	return 0;
}