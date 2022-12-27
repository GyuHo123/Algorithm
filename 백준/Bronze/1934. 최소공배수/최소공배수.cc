#include<bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b;
	cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
}