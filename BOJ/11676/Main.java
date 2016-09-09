import java.util.*;
import java.math.BigInteger;

public class Main{

	public static void main(String args[]){

		Scanner in = new Scanner(System.in);

		int r, s, m, d, n;
		r = in.nextInt();
		s = in.nextInt();
		m = in.nextInt();
		d = in.nextInt();
		n = in.nextInt();

		int c[] = new int[r];

		boolean cant[][] = new boolean[s+m+d][s+m+d];

		for(int i=0; i<r; i++){
			c[i] = in.nextInt();
		}

		ArrayList < ArrayList <Integer> > food = new ArrayList < ArrayList <Integer> >();

		for(int i=0; i<s+m+d; i++){

			int x = in.nextInt();

			ArrayList < Integer > cur = new ArrayList < Integer > ();

			for(int j=0; j<x; j++){

				int y;
				y = in.nextInt();

				y--;

				cur.add(y);

			}

			food.add(cur);

		}

		for(int i=0; i<n; i++){

			int a = in.nextInt();
			int b = in.nextInt();

			a--;
			b--;

			cant[a][b] = cant[b][a] = true;

		}

		BigInteger ans = BigInteger.ZERO;

		for(int i=0; i<s; i++){
			for(int j=s; j<s+m; j++){
				if(cant[i][j])continue;

				for(int k=s+m; k<s+m+d; k++){
					if(cant[i][k] || cant[j][k])continue;

					BigInteger tmp = BigInteger.ONE;

					int e[] = new int[3];
					e[0] = i;
					e[1] = j;
					e[2] = k;

					boolean chk[] = new boolean[r];

					for(int a=0; a<3; a++){
						ArrayList < Integer > dat = food.get(e[a]);
						for(int b=0; b<dat.size(); b++){
							chk[dat.get(b)] = true;
						}

					}

					for(int a=0; a<r; a++){
						if(chk[a]){
							tmp = tmp.multiply(BigInteger.valueOf(c[a]));
						}
					}

					ans = ans.add(tmp);

				}

			}
		}

		int ret = ans.compareTo(BigInteger.valueOf(1000000000000000000L));

		if(ret <= 0)System.out.println(ans.toString());
		else
			System.out.println("too many");

	}

}
