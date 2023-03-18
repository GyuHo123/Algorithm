#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

struct p{
    int weight, idx;
};

queue<int> waitTruck;
deque<p> onGoingTruck;

int n, w, l, sumTruckW, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    loop(i, 1, n){
        int temp;
        cin >> temp;
        waitTruck.push(temp);
    }
    while(true){
        if(waitTruck.empty() && onGoingTruck.empty()) break;
        cnt++;
        if(!waitTruck.empty() && sumTruckW + waitTruck.front() <= l) {
            int temp = waitTruck.front();
            sumTruckW += temp;
            onGoingTruck.push_back({temp, 0});
            waitTruck.pop();
        }
        loop(i, 0, onGoingTruck.size() - 1){
            onGoingTruck[i].idx++;
        }
        if(onGoingTruck.front().idx == w){
            sumTruckW -= onGoingTruck.front().weight;
            onGoingTruck.pop_front();
        }
    }
    cout << cnt + 1;
}