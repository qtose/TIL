#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12945

int solution(int n) {
	int answer = 0;

	vector<int> v;

	v.push_back(0);
	v.push_back(1);

	for (int i = 2; i <= n; ++i)
	{
		int num = v[i - 1] + v[i - 2];
		v.push_back(num % 1234567);
	}

	answer = v[n];

	return answer;
}

int main() {

	solution(5);

	return 0;
}