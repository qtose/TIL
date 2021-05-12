#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12909

bool solution(string s)
{
	bool answer = true;

	stack<int> con;
	int lfet = 0;
	int right = 0;

	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			con.push(s[i]);
			lfet++;
		}

		if (s[i] == ')')
		{
			right++;

			if (!con.empty())
				con.pop();
		}
	}

	if (con.empty() && lfet == right && lfet > 0 && right > 0)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}

	return answer;
}

int main()
{
	solution("(())()");

	return 0;
}