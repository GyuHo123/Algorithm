import java.util.LinkedList;
import java.util.Queue;

class P{
    int x, y, cnt;
    P(int tx, int ty, int tcnt){
        x = tx;
        y = ty;
        cnt = tcnt;
    }
}

class Solution {
    int[] dx = new int[]{0, 0, -1, 1};
    int[] dy = new int[]{1, -1, 0, 0};

    int isRange(int x, int y, int maxx, int maxy){
        if(0 <= x && x <= maxx && 0 <= y && y <= maxy) return 1;
        else return 0;
    }

    int bfs(int[][] maps, int[][] visited){
        Queue<P> q = new LinkedList<>();
        q.offer(new P(0, 0, 0));
        visited[0][0] = 1;
        int min1 = Integer.MAX_VALUE;
        while(!q.isEmpty()){
            P t = q.poll();
            if(t.x == maps.length - 1 && t.y == maps[0].length - 1) min1 = Integer.min(t.cnt, min1);
            for(int i = 0; i <= 3; i++){
                int nx = t.x + dx[i], ny = t.y + dy[i];
                if(isRange(nx, ny, maps.length - 1, maps[0].length - 1) == 1 && maps[nx][ny] == 1 && visited[nx][ny] == 0){
                    q.offer(new P(nx, ny, t.cnt + 1));
                    visited[nx][ny] = 1;
                }
            }
        }
        if(Integer.MAX_VALUE == min1) return -1;
        return min1 + 1;
    }
    public int solution(int[][] maps) {
        int answer;
        int[][] visited = new int[maps.length][maps[0].length];
        answer = bfs(maps, visited);
        return answer;
    }
}