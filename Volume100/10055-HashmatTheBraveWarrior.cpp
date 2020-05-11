#include <iostream>

using namespace std;

int main(){
	long long x, y;
	while (cin >> x >> y){
		cout << (y-x > 0 ? y-x:x-y) << "\n";
	}
	return 0;
}