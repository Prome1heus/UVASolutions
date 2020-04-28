#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int>> blue, red;
vector<int> matchBlue, matchRed;
vector<bool> visBlue, visRed;
int nRed, nBlue;

int test = 4000*4000;

bool canConnect(int d, pair<int, int> &a, pair<int, int> &b){
	return d*d >= (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool aug(bool isRed, int l, int d){
	if (isRed){
		if (visRed[l]) return false;
		visRed[l] = true;
		for (int i=0; i<nBlue; i++){
			if (canConnect(d, red[l], blue[i])
				&& (matchBlue[i] == -1 || aug(true, matchBlue[i], d))){
				matchBlue[i] = l;
				return true;
			}
		}
		return false;
	}/*else{
		if (visBlue[l]) return false;
		visBlue[l] = true;
		for (int i=0; i<nRed; i++){
			if (canConnect(d, blue[l], red[i])
				&& (matchRed[i] == -1 || aug(true, i, d))){
				matchRed[i] = l;
				return true;
			}
		}
		return false;
	}*/
}

int getMaxMatches(int d){
	int MCBM = 0;
	matchRed.assign(nRed, -1);
	matchBlue.assign(nBlue, -1);
	for (int l=0; l<nRed; l++){
		//visBlue.assign(nBlue, false);
		visRed.assign(nRed, false);
		MCBM += aug(true, l, d);
	}
	return MCBM;
}

int main(){
	int T; cin >> T;
	while (T--){
		int P, k, x, y; cin >> P >> k;
		string color;
		blue = vector<pair<int, int>>();
		red = vector<pair<int, int>>();
		for (int i=0; i<P; i++){
			cin >> x >> y >> color;
			if (!color.compare("blue")) blue.push_back(make_pair(x, y));
			else red.push_back(make_pair(x, y));
		} 
		nRed = red.size(), nBlue = blue.size();
		matchRed = vector<int>(nRed, -1);
		matchBlue = vector<int>(nBlue, -1);
		visBlue = vector<bool>(nBlue, false);
		visRed = vector<bool>(nRed, false);
	
		if (k > min(nRed, nBlue)) cout << "Impossible\n";
		else{
			int l = 0, r = 4000, res = 4000;
			while (l <= r){
				int mid = l+(r-l)/2;
				int gmm = getMaxMatches(mid);
				//cout << mid << ": " << gmm << "\n";
				if (gmm >= k){
					res = mid;
					r = mid-1;
				}else{
					l = mid+1;
				}
				//cout << l << " " << r << "\n";
			}
			cout << res << "\n";
		}
	}
}