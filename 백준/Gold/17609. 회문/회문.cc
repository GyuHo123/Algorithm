#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)

using namespace std;

int checkPalindrome(string str, int start, int end){
    while(start < end){
        if(str[start] != str[end]){
            return 2;
        }
        start++;
        end--;
    }
    return 1;
}

int checkPseudoPalindrome(string str){
    int start = 0;
    int end = str.size() - 1;

    while(start < end){
        if(str[start] != str[end]){
            if(checkPalindrome(str,start+1,end) == 1 || checkPalindrome(str,start,end-1) == 1)
                return 1;
            else
                return 2;
        }
        start++;
        end--;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        string str;
        cin >> str;

        cout << checkPseudoPalindrome(str) << endl;
    }
}
