import java.util.*;

class Solution {
    public int solution(int[] numbers, int target) {
        Queue<Integer> q = new LinkedList<>();
        int answer = 0;
        q.offer(0);
        for(int i = 0; i < numbers.length; i++){
            int size = q.size();
            for(int j = 0; j < size; j++){
                int sum = q.poll();
                q.offer(sum + numbers[i]);
                q.offer(sum - numbers[i]);
            }
        }
        while(!q.isEmpty()){
            if(q.poll() == target) answer++;
        }
        return answer;
    }
}