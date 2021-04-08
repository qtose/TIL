#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp

long long solution(int w, int h) {
	long long answer = 1;

	int num1 = w;
	int num2 = h;
	int num3 = 0;

	while (num2 != 0)
	{
		num3 = num1 % num2;
		num1 = num2;
		num2 = num3;
	}

	long long ww = w;
	long long hh = h;

	answer = (ww * hh) - ((ww + hh) - num1);

	return answer;
}

int main()
{
	solution(8, 12);

	return 0;
}