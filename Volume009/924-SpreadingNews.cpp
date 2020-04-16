#include <bits/stdc++.h>

using namespace std;


int main(){
	int E, n, tmp; cin >> E;
	auto friends = vector<vector<int> >(E, vector<int>());
	for (int i=0; i<E; i++){
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> tmp;
			friends[i].push_back(tmp);
		}
	}
	int T; cin >> T;
	while (T--){
		int e; cin >> e;
		//cout << "Case for " << e << "\n";
		queue<pair<int, int> >  q;
		q.push(make_pair(e, 0));
		int maxPerDay = 0, firstDay = 0, currDay = 0, currCount = -1;
		vector<bool> visited(E, false);
		visited[e] = true;
		while (!q.empty()){
			auto data = q.front(); q.pop();
			//cout << data.first << " " << data.second << "\n";
			if (currCount > maxPerDay){
				maxPerDay = currCount;
				firstDay = currDay;
			}
			if (currDay == data.second) currCount++;
			else{
				currDay++;
				currCount = 1;
			}
			for (int i=0; i<friends[data.first].size(); i++){
				if (!visited[friends[data.first][i]]){
					q.push(make_pair(friends[data.first][i], currDay+1));
					visited[friends[data.first][i]] = true;
				}
			}
		}
		if (currCount > maxPerDay){
			maxPerDay = currCount;
			firstDay = currDay;
		}
		//cout << "____________________________\n";
		if (maxPerDay == 0) cout << "0\n";
		else cout << maxPerDay << " " << firstDay << "\n";
		
		//cout << "____________________________\n";
	}
}