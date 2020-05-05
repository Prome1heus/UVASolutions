#include <bits/stdc++.h>

using namespace std;

vector<int> rep;

int find(int a){
	while (rep[a] != a) a = rep[a];
	return a;
}

void unite(int a, int b){
	rep[find(b)] = find(a);
}

int main(){
	int N, a, b, c; bool first = true;
	while (cin >> N){
		int oldCost = 0;
		for (int i=0; i<N-1; i++){
			cin >> a >> b >> c;
			oldCost += c;
		}
		int K, M; cin >> K;
		vector<pair<int, pair<int, int>>> edges;
		for (int i=0; i<K; i++){
			cin >> a >> b >> c;
			edges.push_back(make_pair(c, make_pair(a-1, b-1)));
		}
		cin >> M;
		for (int i=0; i<M; i++){
			cin >> a >> b >> c;
			edges.push_back(make_pair(c, make_pair(a-1, b-1)));
		}
		rep = vector<int>(N);
		for (int i=0; i<N; i++) rep[i] = i;
		sort(edges.begin(), edges.end());
		int mstCost = 0;
		for (int i=0; i<M+K; i++){
			pair<int, pair<int, int>> p = edges[i];
			if (find(p.second.first) != find(p.second.second)){
				mstCost += p.first;
				unite(p.second.first, p.second.second);
			}
		} 
		cout << (first ? "":"\n") << oldCost << "\n" << mstCost <<"\n";
		first = false;
	}
}