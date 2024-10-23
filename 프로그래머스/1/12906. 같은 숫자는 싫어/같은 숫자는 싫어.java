import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Stack<Integer> stk = new Stack<Integer>();
        
        for (int num : arr) {
            if(stk.isEmpty()){
                stk.push(num);
                continue;
            }
            if(stk.peek() == num) continue;
            stk.push(num);
        }
        int index = stk.size() - 1;    
        int[] answer = new int[stk.size()];
    
        while(!stk.isEmpty()){
            answer[index--] = stk.peek();
            stk.pop();
        }
        return answer;
    }
}