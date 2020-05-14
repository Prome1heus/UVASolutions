#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, f;
vector<vector<int>> adj;
vector<int> p;
vector<bool> keep;

void dfs(int curr){
	keep[curr] =  true;
	for (int i=0; i<n; i++) if (!keep[i] && adj[curr][i] != 0) dfs(i);
}

void augment(int v, int minEdge){
	if (v == 0){
		f = minEdge;
	}else if (p[v] != -1){
		augment(p[v], min(minEdge, adj[p[v]][v]));
		adj[p[v]][v] -= f;
		adj[v][p[v]] += f;
	}
}

int main(){
	int a, b, x, curr = 1;
	cin >> n >> m;
	while (n || m){
		int mf = 0;
		adj = vector<vector<int>>(n, vector<int>(n, 0));
		p = vector<int>(n);
		for(int i=0; i<m; i++){
			cin >> a >> b >> x;
			adj[a-1][b-1] += x;
			adj[b-1][a-1] += x;
		}
		vector<vector<int>> original = adj;

		while (1){
			f = 0;
			//run BFS
			vector<int> dist(n, INF);
			dist[0] = 0;
			queue<int> q;
			q.push(0);
			p.assign(n, -1);
			while (!q.empty()){
				int u = q.front(); q.pop();
				if (u == 1) break;
				for (int v =0; v<n; v++)
					if (adj[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u]+1, q.push(v), p[v] = u;
			}
			augment(1, INF);
			if (f == 0) break;
			mf += f;
		}
		keep = vector<bool>(n, false);
		dfs(0);
		//for (int i=0; i<n; i++) cout << keep[i] << " ";
		//	cout << endl;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				if (keep[i] != keep[j] && original[i][j] > 0) cout << i+1 << " " << j+1 << "\n";
		cout << "\n";
		cin >> n >> m;
	}

}