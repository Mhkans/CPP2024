#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

struct User {

	int guildID;

};
void GuildSystem() {
	vector<User> users;
	for (int i = 0; i < 1000; i++) {
		User user;
		user.guildID = i;
		users.push_back(user);
	}
	//user5가 1의 길드에 소속되었다.
	users[5].guildID = 1;

	//2길드에 들어가있는 모든 인원들을 길드1에 병합
	for (auto& user : users) {
		if (user.guildID == 2) {
			user.guildID = 1;
		}
	}
}

class Naive_DisJointSet {

public:
	Naive_DisJointSet(int n) {
		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++) {
			_parent[i] = i;
		}
	}

	int FindLeader(int u) {
		if (u == _parent[u]) {
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}

	void Merge(int u, int v) {
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);
		if (uLeader == vLeader) {
			return;

		}
		_parent[vLeader] = uLeader;
	}

	
private:
	vector<int> _parent;
};

class DisJointSet {

public:
	DisJointSet(int n) {

		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);
		for (int i = 0; i < n; i++) {

			_parent[i] = i;
		}
	}
	int FindLeader(int u) {
		if (u == _parent[u]) {
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}

	void Merge(int u, int v) {

		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {
			return;
		}
		if (_rank[uLeader] > _rank[vLeader]) {

			std::swap(uLeader, vLeader);
		}
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader]) {
			_rank[vLeader]++;
		}


	}
private:
	vector<int> _parent;
	vector<int> _rank;
};
int main()
{
	

	return 0;
}