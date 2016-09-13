import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		ArrayList <Integer> a = new ArrayList<Integer>();

		for(int i=0; i<n; i++){
			a.add(in.nextInt());
		}

		Collections.sort(a);

		int x = 0, cnt = 0;

		for(int i=1; i<a.size(); i++){
			if(a.get(i) - a.get(i-1) > 0){
				cnt++;
				if((x != (a.get(i) - a.get(i-1)) && x > 0) || cnt > 2){
					System.out.println("NO");
					return ;
				}
				x = a.get(i) - a.get(i-1);
			}	
		}

		System.out.println("YES");

	}
}
