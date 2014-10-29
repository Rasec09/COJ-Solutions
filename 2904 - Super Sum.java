import java.util.*;
import java.math.*;

public class SuperSum {
	
	public static void main(String args[]){

		Scanner in = new Scanner(System.in);
		int T;		
		BigInteger sum = new BigInteger("0");		
		BigInteger aux = new BigInteger("0");		

		T = in.nextInt();
		for(int i = 0; i < T; i++){
			aux = in.nextBigInteger();
			sum = sum.add(aux);
		}
		System.out.println(sum);
	}
}
