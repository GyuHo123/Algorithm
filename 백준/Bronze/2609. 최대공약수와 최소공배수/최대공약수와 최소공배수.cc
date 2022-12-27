#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(){
    int n, n1;
	cin >> n >> n1;
	cout << gcd(n, n1) << "\n" << lcm(n, n1);
}