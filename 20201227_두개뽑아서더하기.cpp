#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	
	int iSize = numbers.size();

	for (int i = 0; i < iSize - 1; i++) {
		for (int j = i + 1; j < iSize; j++) {
			int iNum = numbers[i] + numbers[j];
			bool bIsPush = false;
			
			for (auto& Elem : answer) {
				if (Elem == iNum)
					bIsPush = true;
			}

			if (!bIsPush)
				answer.push_back(iNum);
		}
	}

	sort(answer.begin(), answer.end());
	
	//Set을 통해 중복을 피하는 방법
	//vector<int> answer;
	//set<int> st;
	//for (int i = 0;i<numbers.size();++i) {
	//	for (int j = i + 1; j< numbers.size();++j) {
	//		st.insert(numbers[i] + numbers[j]);
	//	}
	//}
	//answer.assign(st.begin(), st.end());
	
	return answer;
}

int main() {
	vector<int> v = { 2,1,3,4,1 };

	vector<int> r = solution(v);
	
	return 0;
}
