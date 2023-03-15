#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)

using namespace std;

ll num1, num2;

int gcd(int a, int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num1 >> num2;

    cout << lcm(num1, num2);

}