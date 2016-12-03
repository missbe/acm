/*
题目描述
输入三个正整数a，p，k ，求ap%k 的值。

输入
输入有多组测试例。
对每组测试例，有三个正整数a，p，k （0＜a，p，k2 ＜232）。

输出
对每组测试例输出1行，是ap%k 的值。

样例输入
2 10 9
3 18132 17
样例输出
7
13
*/
//CODE
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class six {
	public static void main(String[] args) {		
		int A,B,C;
		Scanner scanner=new Scanner(System.in);		
		while(scanner.hasNext()){		
			A=scanner.nextInt();
			B=scanner.nextInt();
			C=scanner.nextInt();
			f(A,B,C);
		}
	}
	//2 10 9
	//3 18132 17
	//---output--
	//7
	//13
	public static void f(int a,int p,int k){
		List<Integer> list=new ArrayList<Integer>();
		int temp;
		for(int i=0;i<=p;i++){
			temp=(int)(Math.pow(a,i))%k;///求a的i次方
			if(list.contains(temp)){///达到一次循环-结束跳出
				break;
			}else{
				list.add(temp);
			}
		}
		int size=list.size();
		System.out.println(list.get(p%size));	///求得第P个位置的余数	
	}
}
