import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < progresses.length; i++) {
            int remainWork = 100 - progresses[i];
            int remainDay = remainWork / speeds[i];
            if (remainWork % speeds[i] != 0) remainDay++;
            q.offer(remainDay);
        }

        List<Integer> answerList = new ArrayList<>();
        int cnt = 1;
        int poped = q.poll();

        while (!q.isEmpty()) {
            if (q.peek() <= poped) {
                cnt++;
                q.poll();
            } else {
                answerList.add(cnt);
                poped = q.poll();
                cnt = 1;
            }
        }
        answerList.add(cnt);

        int[] answer = new int[answerList.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = answerList.get(i);
        }

        return answer;
    }
}
