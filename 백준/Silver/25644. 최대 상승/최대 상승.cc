#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int stocks[n], interest[n];

    int cnt = 0, max_interest;

    for(int i = 0; i < n; i++) {
        cin >> stocks[i];
    }
    int max;
    for(int i = n-1; i >= 0; i--){
        if((i == n-1)) max = stocks[i];
        else if (stocks[i] > max) max = stocks[i];
        if(max-stocks[i] > 0) interest[i] = max - stocks[i];
        else interest[i] = 0;
    }
    max_interest = *max_element(interest, interest+(n-1));

    cout << max_interest;
}