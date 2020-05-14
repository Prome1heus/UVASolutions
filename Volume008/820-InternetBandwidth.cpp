#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, s, t, c, f;
vector<vector<int>> adj;
vector<int> p;

void augment(int v, int minEdge){
	if (v == s-1){
		f = minEdge;
	}else if (p[v] != -1){
		augment(p[v], min(minEdge, adj[p[v]][v]));
		adj[p[v]][v] -= f;
		adj[v][p[v]] += f;
	}
}

int main(){
	int a, b, x, curr = 1;
	cin >> n;
	while (n){
		cin >> s >> t >> c;
		int mf = 0;
		adj = vector<vector<int>>(n, vector<int>(n, 0));
		p = vector<int>(n);
		for(int i=0; i<c; i++){
			cin >> a >> b >> x;
			adj[a-1][b-1] += x;
			adj[b-1][a-1] += x;
		}

		while (1){
			f = 0;
			//run BFS
			vector<int> dist(n, INF);
			dist[s-1] = 0;
			queue<int> q;
			q.push(s-1);
			p.assign(n, -1);
			while (!q.empty()){
				int u = q.front(); q.pop();
				if (u == t-1) break;
				for (int v =0; v<n; v++)
					if (adj[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u]+1, q.push(v), p[v] = u;
			}
			augment(t-1, INF);
			if (f == 0) break;
			mf += f;
		}
		cout << "Network " << curr++ << "\n";
		cout << "The bandwidth is "<< mf << ".\n\n";
		cin >> n;
	}

}