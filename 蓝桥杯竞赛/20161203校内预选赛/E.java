/*
题目描述
求三个数的最大公约数。


输入
每行输入三个正整数（满足100,000,000<N<1,000,000,000）。

输出
对应每个输入，输出最大公约数。

样例输入
120040650 160400250 20400750
179407728 237422727 338339574
样例输出
450
487521
*/
//CODE
import java.util.Scanner;


public class five {
	
	public static void main(String[] args) {
		System.out.println(gcd(324, gcd(243,135)));
		int A,B,C;
		Scanner scanner=new Scanner(System.in);		
		while(scanner.hasNext()){		
			A=scanner.nextInt();
			B=scanner.nextInt();
			C=scanner.nextInt();
			////求A和B的最大公约数后再与C求最大公约数
			System.out.println(gcd(C, gcd(A,B)));
		}
	}
	////最大公约数
	public static int gcd(int a,int b){
		if(0==b)
			return a;
		return gcd(b, a%b);
	}
	///120040650 160400250 20400750
	///179407728 237422727 338339574
	//120040650 120040651 120040652
	///1000000000 1000000002 1000000005
}
