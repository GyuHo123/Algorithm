#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; int num1[n], num2[n], result = 0;

    for(int i = 0; i < n; i++){
        cin >> num1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> num2[i];
    }
    sort(num1, num1+n);
    sort(num2, num2+n);
    reverse(num2, num2+n);
    for(int i = 0; i < n; i++){
        result += num1[i] * num2[i];
    }
    cout << result;
}
