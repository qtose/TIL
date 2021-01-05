#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/68935

int solution(int n) {
	int answer = 0;

	vector<int> v;
	int iShare = n;
	
	//3보다 작을경우 예외처리
	if (n < 3) {
		answer = n;
		return answer;
	}

	while (true) {
		v.push_back(iShare % 3);
		iShare = iShare / 3;
		
		if (iShare < 3) {
			v.push_back(iShare);
			break;
		}
	}

	int iSquare = 0;
	int iSize = v.size();

	for (int i = iSize - 1; 0 <= i; --i) {
		iSquare *= 3;

		if (0 == iSquare)
			iSquare = 1;

		answer += v[i] * iSquare;
	}

	return answer;
}

int main() {
	solution(45);

	return 0;
}