#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42860

int solution(string name) {
	int answer = 0;


	string str = name;
	int num = 0;

	size_t length = name.length();

	for (int i = 0; i <length; ++i)
	{
		str[i] = 'A';
	}

	while (true) 
	{
		str[num] = name[num];

		char a = name[num];

		if ('Z' + 1 - a < a - 'A')
		{
			answer += 'Z' + 1 - a;
		}

		else
		{
			answer += a - 'A';
		}

		if (str == name)
			break;

		for (int i = 1; i < length; i++)
		{
			if (name[(num + i) % length] != str[(num + i) % length])
			{
				num = (num + i) % length;
				answer += i;
				break;
			}
			else if (name[(num + length - i) % length] != str[(num + length - i) % length])
			{
				num = (num + length - i) % length;
				answer += i;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	solution("JEROEN");


	return 0;
}