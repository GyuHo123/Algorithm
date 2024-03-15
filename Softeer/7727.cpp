#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 21

using namespace std;

struct Point{
    int x, y;
};

struct Route{
    vector<Point> points;
    int sum = 0;
};

int n, m, ans, arr[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector<vector<Route>> friendsRoutes;

bool isRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

vector<Route> bfs(int x, int y){
    vector<Route> routes;
    queue<pair<Point, Route>> q;

    Route initialRoute;
    initialRoute.points.push_back({x, y});
    initialRoute.sum = arr[x-1][y-1]; 

    q.push({{x, y}, initialRoute});

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        Point curP = t.first;
        Route curR = t.second;

        if(curR.points.size() == 4){
            routes.push_back(curR);
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = curP.x + dx[i];
            int ny = curP.y + dy[i];

            if(isRange(nx, ny)){
                Point nextP = {nx, ny};
                Route nextR = curR;
                nextR.points.push_back(nextP);
                nextR.sum += arr[nx-1][ny-1];

                q.push({nextP, nextR});
            }
        }
    }

    return routes;
}

int getTotalFruits(vector<Route>& routes) {
    int result = 0;
    int copyBoard[MAXN][MAXN];
    memcpy(copyBoard, arr, sizeof(arr));
    
    for (Route& route : routes) {
        for (Point& point : route.points) {
            result += copyBoard[point.x-1][point.y-1];
            copyBoard[point.x-1][point.y-1] = 0;
        }
    }
    
    return result;
}

void findRouteCombinations(int friendIndex, vector<Route>& currentRoutes, int& maxFruit) {
    if (friendIndex == m) {
        int totalFruits = getTotalFruits(currentRoutes);
        maxFruit = max(maxFruit, totalFruits);
        return;
    }

    for (Route& route : friendsRoutes[friendIndex]) {
        currentRoutes.push_back(route);
        findRouteCombinations(friendIndex + 1, currentRoutes, maxFruit);
        currentRoutes.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n){
        loop(j, 1, n){
            cin >> arr[i-1][j-1];
        }
    }

    friendsRoutes.resize(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friendsRoutes[i] = bfs(x, y);
    }

    vector<Route> currentRoutes;
    int maxFruit = 0;
    findRouteCombinations(0, currentRoutes, maxFruit);
    cout << maxFruit << endl;

    return 0;
}
