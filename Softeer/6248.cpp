#include<iostream>
#include<vector>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int n, m, start, till, in1, in2, cnt;

int gowork[100001], gohome[100001];
vector<int> v[100001];

bool goHome(int work, int home) {
	if (!v[work].size() && home != work)
        return 0;

	int b1 = 0;

	for (auto var : v[work]) {
		if (var == home) {
            b1 = 1; continue;
		}
		if (gohome[var]) {
            b1 = 1; continue;
		}
        gohome[var] = 1;
		if (!goHome(var, home)) gohome[var] = 0;
		else b1 = 1;
	}
	return b1;
}

bool goWork(int home, int work) {
	if (!v[home].size() && home != work) return 0;
	int b1 = 0;
	for (auto var : v[home]) {
        if (var == work) {
            b1 = 1;
            continue;
        }
        if (gowork[var]) {
            b1 = 1;
            continue;
        }
        gowork[var] = 1;
        if (!goWork(var, work)) gowork[var] = 0;
        else b1 = 1;
    }
    return b1;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	loop(i, 1, m) {
		cin >> in1 >> in2;
		v[in1].push_back(in2);
	}
	cin >> start >> till;

    goWork(start, till);
	goHome(till, start);

    loop(i, 1, n) {
        if (i == start || i == till) continue;
        if (gowork[i] && gohome[i]) cnt++;
    }
    
    cout << cnt;
}
