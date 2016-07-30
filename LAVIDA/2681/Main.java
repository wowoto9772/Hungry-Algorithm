import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		int par[] = new int['z' + 3];
		for (int i = 0; i <= 9; i++)
			par['0' + i] = i;
		for (int i = 'a'; i <= 'z'; i++)
			par[i] = 10 + (i - 'a');

		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		for (int T = 1; T <= tc; T++) {
			String op, eq;
			String A[] = new String[3];
			A[0] = in.next();
			op = in.next();
			A[1] = in.next();
			eq = in.next();
			A[2] = in.next();

			boolean unary = true;
			for (int i = 0; i < 3; i++) {
				int s = A[i].length();
				for (int j = 0; j < s && unary; j++) {
					if (A[i].charAt(j) != '1') {
						unary = false;
					}
				}
			}

			boolean invalid = true;
			for (int k = 1; k <= 36; k++) {
				boolean pos = true;
				BigInteger a[] = new BigInteger[3];
				a[0] = BigInteger.ZERO;
				a[1] = BigInteger.ZERO;
				a[2] = BigInteger.ZERO;
				if (k == 1 && unary) {
					a[0] = BigInteger.valueOf(A[0].length());
					a[1] = BigInteger.valueOf(A[1].length());
					a[2] = BigInteger.valueOf(A[2].length());
				} else {
					for (int x = 0; pos && x <= 2; x++) {
						BigInteger y = BigInteger.ONE;
						int s = A[x].length();
						for (int j = s - 1; pos && j >= 0; j--) {
							if (par[A[x].charAt(j)] >= k)
								pos = false;
							a[x] = a[x].add(y.multiply(BigInteger.valueOf(par[A[x].charAt(j)])));
							y = y.multiply(BigInteger.valueOf(k));
						}
					}
				}
				if (pos) {
					if (op.equals("+")) {
						if (a[0].add(a[1]).equals(a[2])) {
							System.out.print(whatIs(k));
							invalid = false;
						}
					} else if (op.equals("-")) {
						if (a[0].subtract(a[1]).equals(a[2])) {
							System.out.print(whatIs(k));
							invalid = false;
						}
					} else if (op.equals("*")) {
						if (a[0].multiply(a[1]).equals(a[2])) {
							System.out.print(whatIs(k));
							invalid = false;
						}
					} else {
						if (a[1].multiply(a[2]).equals(a[0])) {
							System.out.print(whatIs(k));
							invalid = false;
						}
					}
				}
			}
			if (invalid)
				System.out.print("invalid");
			System.out.println();
		}

	}

	static char whatIs(int a) {
		if (a == 36)
			return '0';
		else if (a < 10)
			return (char) (a + '0');
		else
			return (char) ('a' + (a - 10));
	}
}