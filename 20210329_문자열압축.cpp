#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/60057

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++) 
	{
		int len = s.length();

		for (int j = 0; j < s.length(); j++) 
		{
			for (int h = 0, r = i; j + r < s.length(); r += i) 
			{
				if (s.substr(j, i) == s.substr(j + r, i))
				{
					h++;
				}

				else 
				{
					len -= i * h;
					
					if (h)
					{
						len += to_string(h + 1).length();
					}

					j += r - 1;
					break;
				}
				if (j + r + i >= s.length()) 
				{
					len -= i * h;
					len += to_string(h + 1).length();
					j += r;
				}
			}
		}
		if (len < answer)
		{
			answer = len;
		}
	}

	return answer;
}

int main()
{
	solution("xababcdcdababcdcd");


	return 0;
}