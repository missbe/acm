/*
题目描述
小张是软件项目经理，他带领3个开发组。工期紧，今天都在加班呢。为鼓舞士气，小张打算给每个组发一袋核桃（据传言能补脑）。他的要求是：
1. 各组的核桃数量必须相同
2. 各组内必须能平分核桃（当然是不能打碎的）
3. 尽量提供满足1,2条件的最小数量（节约闹革命嘛）

输入
输入包含三个正整数a, b, c，表示每个组正在加班的人数，用空格分开（a,b,c<30）

输出
输出一个正整数，表示每袋核桃的数量。

样例输入
2 4 5
样例输出
20
*/
//CODE
import java.util.Scanner;


public class four {
	public static void main(String[] args){		
		int A,B,C;
	//	f(8,6);
		Scanner scanner=new Scanner(System.in);
		int[] array=new int[3];///存储公倍数数组
		int min;//存储最小公倍数
		while(scanner.hasNext()){
			min=Integer.MAX_VALUE;////每次重新输入时需要初始化
			A=scanner.nextInt();
			B=scanner.nextInt();
			C=scanner.nextInt();
			array[0]=(A*B)/f(A,B);///A,B最小公倍数
			array[1]=(A*C)/f(A,C);///A,C最小公倍数
			array[2]=(B*C)/f(B,C);///B,C最小公倍数
			for(int i=0;i<array.length;i++){
				if(0==array[i]%A && 0==array[i]%B && 0==array[i]%C){
					if(array[i]<min)
						min=array[i];///赋给最小公倍数
				}
			//	System.out.print(i+"--->"+array[i]+"  ");
			}	
			if(min==Integer.MAX_VALUE){///如果未找到能整除的
				System.out.println((A*B*C));
			}else{
				System.out.println(min);
			}		   
		}
	}
	
	public static int f(int m,int n){
		int temp;///存储临时变量
		///进行交换
		if(m<n){
		   temp=m;
		   m=n;
		   n=temp;
		}		
		while(n!=0){
			temp=m%n;
			m=n;
			n=temp;
		}
	//	System.out.println("N-->"+m);
		return m;
	}
}
