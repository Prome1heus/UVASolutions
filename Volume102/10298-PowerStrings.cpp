#include <iostream>
#include <string>

using namespace std;

int main(){
	string s; int n; cin >> s;
	while (s!="."){
		int size = s.size();
		for (n = 1; n<=size; n++){
			if (size%n)
				continue;
			else{
				bool poss = true;
				int steps = size/n;
				string muster = s.substr(0, n);
				for (int i=1; i<steps; i++)
					if (muster!=s.substr(i*n, n)) poss = false;
				if (poss) break;
			}
		}
		cout << size/n << "\n";
		cin >> s;
	}
}