/*
题目描述
一个数字序列定义如下：
f(1)=1，f(2)=2
f(n)=(A*f(n-2)+B*f(n-1))%11

输入A，B 和 n，计算出f(n)的值。

输入
需要输入3个整型分别代表A，B，n(其中1<=A，B<=1000，1<=n<=100000000)。输入三个0程序结束。

输出
根据输入的内容，计算出f(n)的值，单独一行输出。

样例输入
1 1 3
2 2 4
0 0 0
样例输出
3
5
*/
//CODE
import java.util.Scanner;


public class one {	
	public static void main(String[] args){		
		int A,B,n;
		Scanner scanner=new Scanner(System.in);
		while(scanner.hasNext()){
			A=scanner.nextInt();
			B=scanner.nextInt();
			n=scanner.nextInt();
			///exit
			if(0==A && 0==B && 0==n)
				break;
			System.out.println(f(A,B, n));
		}
	}
	///计算余数
	public static int f(int A,int B,int n){
		int f1=1,f2=2;
		if(1==n){
			return f1;
		}
		if(2==n){
			return f2;
		}
		int count=n-2;///减去已经用了的两个
		while(count-- > 0){
			int temp=f2;
			///公式-换成迭代的方式进行-先求余不进行求和
			f2=((A*f1)%11+(B*f2)%11)%11;
			f1=temp;
		}		
		return f2;
	}

}
