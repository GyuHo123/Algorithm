//BOJ-1920

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, m, num, arr[MAXN]; 

int binarySearch(int input){
    int first = 1;
    int last = n;
    while(last >= first){
        int central = (first + last) / 2;
        if(arr[central] == input) return 1;
        else if(arr[central] > input){
            last = central - 1;
        }
        else{
            first = central + 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    loop(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    cin >> m;
    loop(i, 1, m){
        cin >> num;
        cout << binarySearch(num) << endl;
    }
}