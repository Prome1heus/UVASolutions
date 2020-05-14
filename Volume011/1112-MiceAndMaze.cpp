#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int N, E, T, M, a, b, x; cin >> N >> E >> T >> M;
		vector<int> dist(N, 1e9);
		vector<vector<pair<int, int>>> edges(N, vector<pair<int, int>>(0));
		for (int i=0; i<M; i++){
			cin >> a >> b >> x;
			edges[b-1].push_back(make_pair(a-1, x));
		}
		priority_queue<pair<int, int>> pq;
		dist[E-1]=0;
		pq.push(make_pair(0, E-1));
		while (!pq.empty()){
			int curr = pq.top().second, d = pq.top().first;
			pq.pop();
			if (dist[curr] < d) continue;
			for (int j=0; j<edges[curr].size(); j++){
				pair<int, int> next = edges[curr][j];
				if (dist[next.first] > dist[curr]+next.second){
					dist[next.first] = dist[curr]+next.second;
					pq.push(make_pair(dist[next.first], next.first));
				}
			}
		}
		int count = 0;
		for (int i=0; i<N; i++){
			if (dist[i] <= T) count++;
		} 
		cout << count << (t ? "\n\n":"\n");
	}
}