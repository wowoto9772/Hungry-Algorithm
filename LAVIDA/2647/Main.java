import java.util.*;
import java.math.*;
import java.io.*;

public class Main 
{	
	static BigInteger dp[][][] = new BigInteger[77][77][2];
	static boolean chk[][] = new boolean[77][77];

	static void P(int r, int w) { // Probability (r, w)
		if(chk[r][w] != false)return ;
		
		chk[r][w] = true;
		dp[r][w][1] = BigInteger.valueOf(r+w);
		dp[r][w][0] = BigInteger.valueOf(r);
		
		if(w >= 2){
			if(chk[r][w-2] != true)P(r, w-2);
			BigInteger c = BigInteger.valueOf(w*(w-1));
			c = c.multiply(dp[r][w-2][0]);
			BigInteger d = BigInteger.valueOf((r+w)*(r+w-1));
			d = d.multiply(dp[r][w-2][1]);
			BigInteger a = dp[r][w][0];
			BigInteger b = dp[r][w][1];

			BigInteger nc = (a.multiply(d)).add(c.multiply(b));
			BigInteger nd = d.multiply(b);
			dp[r][w][1] = nd;
			dp[r][w][0] = nc;
		}
		
		BigInteger g = dp[r][w][0].gcd(dp[r][w][1]);

		dp[r][w][1] = dp[r][w][1].divide(g);
		dp[r][w][0] = dp[r][w][0].divide(g);
		
		return ;
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		while(tc-- > 0){

			int red = in.nextInt();
			int white = in.nextInt();

			P(red, white);
			
			System.out.println(dp[red][white][0].toString() + "/" + dp[red][white][1].toString());
		}
	}
}