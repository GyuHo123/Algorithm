#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len;
    loop(i, 0, stations.size()){
        if(!i) len = stations[i] - 1 - w;
        else if(i == stations.size()) len = n - stations[i - 1] - w;
        else len = stations[i] - stations[i - 1] - 2 * w - 1;
        if(len > 0){
            answer += len / (2 * w + 1);
            if(len % (2 * w + 1)) answer += 1;
        }
    }
    return answer;
}