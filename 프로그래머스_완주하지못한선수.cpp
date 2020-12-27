#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42576

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> mapParticipant;

	for (auto& Name : participant) {
		auto& iter = mapParticipant.find(Name);

		if (iter == mapParticipant.end())
			mapParticipant.emplace(make_pair(Name, 1));

		else
			++(*iter).second;
	}

	for (auto& Name : completion) {
		auto& iter = mapParticipant.find(Name);

		--(*iter).second;
	}

	for (auto& Pair : mapParticipant) {
		if (1 == Pair.second) {
			answer = Pair.first;
			break;
		}
	}

	//두 벡터를 정렬 후 다른 원소를 찾는 방법
	//string answer = "";
	//sort(participant.begin(), participant.end());
	//sort(completion.begin(), completion.end());
	//for (int i = 0;i<completion.size();i++)
	//{
	//	if (participant[i] != completion[i])
	//		return participant[i];
	//}
	//return participant[participant.size() - 1];


	return answer;
}

int main() {
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };

	string answer = solution(participant, completion);

	return 0;
}