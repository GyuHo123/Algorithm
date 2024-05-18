#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;


int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int cnt = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    loop(i, 0, B.size() - 1){
        if(B[i] > A[cnt]){
            cnt++;
            answer++;
        }
    }
    return answer;
}