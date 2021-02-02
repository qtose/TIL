#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12906

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	answer.push_back(arr[0]);

	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i - 1] != arr[i])
		{
			answer.push_back(arr[i]);
		}
	}


	return answer;
}

int main() {

	vector<int> v = { 4,4,4,3,3 };

	solution(v);

	return 0;
}