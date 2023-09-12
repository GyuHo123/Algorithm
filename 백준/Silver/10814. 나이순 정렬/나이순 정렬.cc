#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Member {
    int age;
    string name;
    int join_order;
};

bool compare(const Member &a, const Member &b) {
    if (a.age < b.age) return true;
    else if (a.age == b.age) return a.join_order < b.join_order;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Member> members(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> members[i].age >> members[i].name;
        members[i].join_order = i;  // 가입한 순서 저장
    }

   stable_sort(members.begin(), members.end(), compare);

   for (const auto &member : members)
       cout << member.age << ' ' << member.name << '\n';
}
