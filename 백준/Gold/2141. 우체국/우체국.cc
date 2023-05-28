#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

struct Town {
    int x, a;
};

bool compare(Town a, Town b) {
    return a.x < b.x;
}

Town towns[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long total_population = 0;

    for (int i = 0; i < N; i++) {
        cin >> towns[i].x >> towns[i].a;
        total_population += towns[i].a;
    }

    sort(towns, towns+N, compare);

    long long population_sum = 0;
    int post_office_location = 0;
    for (int i = 0; i < N; i++) {
        population_sum += towns[i].a;
        if (population_sum >= (total_population + 1) / 2) {
            post_office_location = towns[i].x;
            break;
        }
    }

    cout << post_office_location << '\n';

}
