#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12941

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end(), [](int a, int b) { return a < b;});
	sort(B.begin(), B.end(), [](int a, int b) { return b < a;});

	for (size_t i = 0; i < A.size(); ++i)
	{
		answer += A[i] * B[i];
	}

	return answer;
}


int main()
{
	vector<int> a = { 1, 4, 2 };
	vector<int> b = { 5, 4, 4 };

	solution(a, b);

	return 0;
}