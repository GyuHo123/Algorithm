#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 51

using namespace std;

int n, a, b, temp, sum;

priority_queue<int, vector<int>> posPQ;
priority_queue<int, vector<int>, greater<int>> negPQ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    loop(i, 1, n){
        cin >> temp;
        if(temp >= 1) posPQ.push(temp);
        else negPQ.push(temp);
    }
    while(negPQ.size() > 1){
        a = negPQ.top(); negPQ.pop();
        b = negPQ.top(); negPQ.pop();
        if(a != 0 || b != 0) sum += a * b;
        if(negPQ.size() != 1 && negPQ.top() == 0) break;
    }
    while(posPQ.size() > 1){
        a = posPQ.top(); posPQ.pop();
        b = posPQ.top(); posPQ.pop();
        if(a == 1 || b == 1) sum += a + b;
        else sum += a * b;
    }
    while(!negPQ.empty()){
        sum += negPQ.top();
        negPQ.pop();
    }
    while(!posPQ.empty()){
        sum += posPQ.top();
        posPQ.pop();
    }
    cout << sum;
}