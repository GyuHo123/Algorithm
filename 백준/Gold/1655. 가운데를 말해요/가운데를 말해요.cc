#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s, i < n; i++)

using namespace std;

int n, temp, minVal, maxVal;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> temp;
        if(minHeap.size() >= maxHeap.size()){
            maxHeap.push(temp);
        }
        else minHeap.push(temp);

        while(!minHeap.empty() && maxHeap.top() > minHeap.top()){
            maxVal = maxHeap.top();
            minVal = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minVal);
            minHeap.push(maxVal);
        }
        cout << maxHeap.top() << endl;
    }
}
