#include <string>
#include <vector>
#include <iostream>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12899

string solution(int n) {
	string answer = "";

	string dummy = "";
	int num = 0;

	while (0 < n)
	{
		num = n % 3;
		n = n / 3;
		
		if (num == 0)
		{
			num = 3;
			n -= 1;
		}

		dummy += to_string(num);
	}
	
	for (int i = dummy.length() - 1; i >= 0; --i)
	{
		if (dummy[i] == '1')
		{
			answer += '1';
		}
		else if (dummy[i] == '2')
		{
			answer += '2';
		}
		else if (dummy[i] == '3')
		{
			answer += '4';
		}
	}

	return answer;
}

int main()
{
	solution(10);

	return 0;
}