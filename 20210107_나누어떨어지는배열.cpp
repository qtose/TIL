#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	for (auto& Ele : arr) {
		if (Ele % divisor == 0)
			answer.push_back(Ele);
	}

	if (answer.size() == 0) {
		answer.push_back(-1);
		return answer;
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	return 0;
}