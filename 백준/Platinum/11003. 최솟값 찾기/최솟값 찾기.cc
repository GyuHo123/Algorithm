#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

struct p{
    int num, idx;
};

int n, l;
deque<p> dq;
p p1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    loop(i, 1, n){
        int tempIdx;
        tempIdx = i - l + 1;
        cin >> p1.num;
        p1.idx = i;
        if(!dq.empty())
            if(tempIdx > dq.front().idx) dq.pop_front(); // if(l == 3 i가 4일 때부터 하나씩 가장 앞의 것이 팝이 되어야 이 때 식을 유추해보면 i - l + 1(4 - 3 + 1)
        while(true){
            if(dq.empty() || p1.num > dq.back().num) break; // dq가 비었으면 pop 불가, 새로 입력 받는 수가 그 이전 것보다 큰 상황에서 팝을 하면 최소를 구할 수 없음
            dq.pop_back(); // 새로 입력 받은 수보다 큰 수는 최소로 의미가 X
        }
        dq.push_back(p1);
        cout << dq.front().num << " ";
    }
}