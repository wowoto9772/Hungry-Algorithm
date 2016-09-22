import java.util.*;
import java.math.*;

public class Main{

    static BigInteger f[] = new BigInteger[10003];

    public static void main(String args[]){

        f[1] = BigInteger.ONE;
        f[2] = BigInteger.valueOf(2);

        int top = 2;

        for(int i=3;;i++){
            f[i] = f[i-1].add(f[i-2]);
            int g = f[i].toString().length();

            if(g > 100)break;

            top = i;

        }

        Scanner sc = new Scanner(System.in);

        String _a, _b;

        while(true){

            _a = sc.next();
            _b = sc.next();

            if(_a.equals(_b) == true){
                if(_a.equals("0") == true){
                    break;
                }
            }

            BigInteger a = new BigInteger(_a);
            BigInteger b = new BigInteger(_b);

            int c = 0;

            for(int i=1; i<=top; i++){

                if(f[i].compareTo(b) <= 0){
                    if(a.compareTo(f[i]) <= 0){
                        c++;
                    }
                }

            }

            System.out.println(c);

        }

    }

}
