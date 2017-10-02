import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	
	static HashMap <BigInteger, BigInteger> mp = new HashMap<>();
	static BigInteger two = BigInteger.valueOf(2);
	
	static BigInteger dy(BigInteger a){
		if(a.equals(BigInteger.ZERO) || a.equals(BigInteger.ONE)){
			return BigInteger.ONE;
		}else if(mp.containsValue(a))return mp.get(a);
		else{
		BigInteger x = dy((a.add(BigInteger.ONE)).divide(two));
			BigInteger y = dy((a).divide(two));
			BigInteger p = dy((a.subtract(BigInteger.ONE)).divide(two));
			BigInteger q = dy((a.subtract(two)).divide(two));
			mp.put(a, (x.multiply(y)).add(p.multiply(q)));
			return mp.get(a);
		}
	}

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		String n = s.next();
		BigInteger v = new BigInteger(n);
		System.out.println(dy((v).subtract(BigInteger.ONE)).toString());
		
	}

}
