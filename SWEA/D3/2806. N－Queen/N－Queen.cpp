#include <iostream>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 40

using namespace std;

int arr1[MAXN], arr2[MAXN], arr3[MAXN], n, cnt, t;

void queen(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	loop(i, 0, n - 1) {
		if (arr1[i] || arr2[i + cur] || arr3[cur - i + n - 1]) continue;
		arr1[i] = 1;
		arr2[i + cur] = 1;
		arr3[cur - i + n - 1] = 1;
		queen(cur + 1);
		arr1[i] = 0;
		arr2[i + cur] = 0;
		arr3[cur - i + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	loop(i, 1, t) {
		cnt = 0;

		cin >> n;

		queen(0);

		cout << "#" << i << " " << cnt << endl;
	}
}