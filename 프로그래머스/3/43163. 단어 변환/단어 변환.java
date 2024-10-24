import java.util.*;
class P{
    String word;
    int cnt;
    P(String tword, int tcnt){
        word = tword;
        cnt = tcnt;
    }
}

class Solution {
    public int solution(String begin, String target, String[] words) {
        int[] visited = new int[words.length];
        boolean flag = false;
        for(var t: words){
            if(t.equals(target)) flag = true;
        }
        if(flag == false) return 0;
        return bfs(begin, target, words, visited);
    }
    
    int bfs(String word, String target, String[] words, int[] visited){
        Queue<P> q = new LinkedList<>();
        q.offer(new P(word, 0));
        while(!q.isEmpty()){
            P t = q.poll();
            if(t.word.equals(target)) return t.cnt;
            int rcnt = 0;
            for(int i = 0; i < words.length; i++){
                int cnt = 0;
                for(int j = 0; j < words[i].length(); j++){
                    if(t.word.charAt(j) != words[i].charAt(j)){
                        cnt++;
                    }
                }
                if(cnt <= 1){
                    q.offer(new P(words[i], t.cnt + 1));
                    visited[i] = 1;
                }
            }
        }
        return 0;
    }
}