import java.util.*;

public class Books {
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);		
		int a, b, ma, me, cont;
		int cubeta[] = new int[10];	
		String aux;	
		char c;

		cont = 1;
		while(true)
		{
			a = in.nextInt();
			if(a == 0) break;
			b = in.nextInt();

			if(a > b){
				ma = a;
				me = b;
			}
			else{
				ma = b;
				me = a;
			}

			for(int i = me; i <= ma; i++){
				aux = Integer.toString(i);
				for(int j = 0; j < aux.length(); j++){
					c = aux.charAt(j);
					switch(c)
					{
						case '0':
							cubeta[0] += 1;
							break;
						case '1':
							cubeta[1] += 1;
							break;
						case '2':
							cubeta[2] += 1;
							break;
						case '3':
							cubeta[3] += 1;
							break;
						case '4':
							cubeta[4] += 1;
							break;
						case '5':
							cubeta[5] += 1;
							break;
						case '6':
							cubeta[6] += 1;
							break;
						case '7':
							cubeta[7] += 1;
							break;
						case '8':
							cubeta[8] += 1;
							break;
						case '9':
							cubeta[9] += 1;
							break;
					}	
				}
			}
	
			System.out.print("Case "+cont+": ");
			System.out.print("0:"+cubeta[0]);
			cubeta[0] = 0;
			for(int i = 1; i <= 9; i++){
				System.out.print(" "+i+":"+cubeta[i]);
				cubeta[i] = 0;
			}
			cont++;
			System.out.println();
		}

	}	
}
