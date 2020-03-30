#include <iostream>

using namespace std;

int main(){
	int n, i=1; cin >> n;
	while (n){
		cout << "Case " << i++ << ": " << n/2 << "\n";
		cin >> n;
	}
}
