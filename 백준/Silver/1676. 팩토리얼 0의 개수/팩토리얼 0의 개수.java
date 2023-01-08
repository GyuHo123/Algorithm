import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a;

        BigInteger fact = new BigInteger("1");

        int cnt = 0;

        Scanner sc = new Scanner(System.in);

        a = sc.nextInt();

        for(int i = 1; i <= a; i++){
            fact = fact.multiply(BigInteger.valueOf(i));
        }

        String str = fact.toString();

        StringBuffer sb = new StringBuffer(str);
        str = sb.reverse().toString();

        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '0') cnt++;
            else if(str.charAt(i) != '0') break;
        }
        System.out.println(cnt);
    }
}