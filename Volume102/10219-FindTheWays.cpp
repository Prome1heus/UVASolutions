#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
	int n, k;
	cout << setprecision(0) << fixed;
	while (cin >> n >> k){
		double digit = 0;
 		
 		k = (k>n-k ? k:n-k);

        for ( long long i = k + 1; i <= n; i++ ) digit += (log10 (i) - log10 (n - i + 1));
        cout << floor(digit)+1 << "\n";
	}
}