#include <iostream>
#include <vector>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42862

int solution(int n, vector<int> lost, vector<int> reserve) {

	//나중에 다시 풀어볼것
	//int iLostSize = lost.size();
	//int iReserveSize = reserve.size();
	//
	//int answer = n - iLostSize;
	//
	//for (int i = 0; i < iLostSize; ++i) {
	//	iReserveSize = reserve.size();
	//	
	//	for (int j = 0; j < iReserveSize; ++j) {
	//		if (lost[i] == reserve[j] || lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1) {
	//			++answer;
	//
	//			auto iter = reserve.begin();
	//			iter += j;
	//			reserve.erase(iter);
	//			break;
	//		}
	//	}
	//}
	//
	//return answer;

	int answer = 0;
	
	map<int, int> mapN;
	
	for (int i = 1; i <= n; i++)
		mapN.emplace(i, 1);
	
	for (auto& Student : reserve)
		++mapN[Student];
	
	for (auto& Student : lost)
		--mapN[Student];

	for (int i = 1; i <= n; i++) {
		if (0 == mapN[i]) {
			if (1 <= i - 1 && 2 == mapN[i - 1]) {
				++mapN[i];
				--mapN[i - 1];
			}
			else if (i + 1 <= n &&  2 == mapN[i + 1]) {
				++mapN[i];
				--mapN[i + 1];
			}
		}

		if (1 <= mapN[i])
			++answer;
	}
	
	return answer;
}

int main() {
	int n = 5;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1, 3, 5 };

	int answer = solution(n, lost, reserve);

	return 0;
}