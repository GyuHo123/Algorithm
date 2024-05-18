#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int div = s / n;
    int mod = s % n;
    if(!(s / n)) return {-1};
    loop(i, 0, n - 1){
        if(i >= n - mod){
            answer.push_back(div + 1);
        }
        else answer.push_back(div);
    }
    return answer;
}