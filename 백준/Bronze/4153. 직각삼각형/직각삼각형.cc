#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {

        int arr[3];

        for(int i = 0; i < 3; i++){
            cin >> arr[i];
        }

        if(arr[0] == 0 and arr[1] == 0 and arr[2] == 0) break;

        sort(arr, arr + 3);

        if (arr[2] * arr[2] == (arr[1] * arr[1] + arr[0] * arr[0])) cout << "right" << endl;
        else cout << "wrong" << endl;

    }
}