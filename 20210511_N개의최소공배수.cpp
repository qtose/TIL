#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12953?language=cpp

int LeastCommonMultiple(int a, int b)
{
	int src = a;
	int des = b;

	while (des != 0)
	{
		int num = src % des;
		src = des;
		des = num;
	}

	return a * b / src;
}

int solution(vector<int> arr) {
	int answer = 0;

	answer = LeastCommonMultiple(arr[0], arr[1]);

	for (size_t i = 2; i < arr.size(); ++i)
	{
		answer = LeastCommonMultiple(answer, arr[i]);
	}

	return answer;
}

int main()
{
	vector<int> v = { 2, 6, 8, 14 };

	solution(v);

	return 0;
}