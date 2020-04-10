#include <iostream>

using namespace std;

int main(){
	int i, j, temp, m1, m2;
	while (cin >> i >> j){
		if (j<i){
			m1 = j; m2 = i;
		}else{
			m1 = i; m2 = j;
		}
		long max = 1, curr, count;
		for (int t=m1; t<=m2; t++){
			curr = t; count = 1;
			while (curr > 1){
				if (curr & 1) curr = 3*curr+1;
				else curr >>= 1;
				count++;
			}
			if (count>max) max = count;
		}
		cout << i << " " << j << " " << max << "\n";
	}
	return 0;
}