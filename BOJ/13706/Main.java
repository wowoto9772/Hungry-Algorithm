import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		String v = s.next();
		BigInteger cmp = new BigInteger(v);
		BigInteger r = cmp;
		BigInteger l = BigInteger.ZERO;
		BigInteger ans = l;
		
		while(l.compareTo(r) <= 0){
			BigInteger m = l.add(r).divide(BigInteger.valueOf(2));
			if((m.multiply(m)).compareTo(cmp) >= 0){
				ans = m;
				r = m.subtract(BigInteger.ONE);
			}else{
				l = m.add(BigInteger.ONE);
			}
		}
		
		System.out.println(ans.toString());

	}

}
