/*
题目描述
某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n口油井的油田。从每口油井都要有一条输油管道沿最短路经（或南或北）与主管道相连。如果给定n口油井的位置，即它们的x坐标（东西向）和y坐标（南北向），应如何确定主管道的最优位置，使各油井到主管道之间的输油管道长度总和最小的位置？
给定n口油井的位置，编程计算各油井到主管道之间的输油管道最小长度总和。

输入
第1行是一个整数n，表示油井的数量（1≤n≤10000）。
接下来n行是油井的位置，每行两个整数x和y（-10000≤x，y≤10000）。

输出
各油井到主管道之间的输油管道最小长度总和。

样例输入
5
1 2
2 2
1 3
3 -2
3 3
样例输出
6
*/
//CODE
import java.util.Scanner;

/*
思想：找到最大的Y值和最小的Y值
求出每个Y值对应的价值，找出最小值
*/
public class two {
    public static void main(String[] args) {		
		Scanner scanner=new Scanner(System.in);		
		int num=scanner.nextInt();
		int[][] array=new int[num][2];
		int max=Integer.MIN_VALUE,min=Integer.MAX_VALUE;		
		for(int i=0;i<num;i++){
			array[i][0]=scanner.nextInt();
			array[i][1]=scanner.nextInt();
			if(array[i][1]>max)///寻找最大Y值
				max=array[i][1];
			
			if(array[i][1]<min)///寻找最小Y值
				min=array[i][1];
		}
		f(array, max,min);
	}   
    public static void f(int[][] array,int end,int start){
    	int min=Integer.MAX_VALUE; ///寻找线性最小值	
    	int temp=0;
  //  	System.out.println("Max:"+start+"-- Min:"+end);
    	for(int i=start;i<=end;i++){
    		for(int j=0;j<array.length;j++){
    			temp += Math.abs(array[j][1]-i); ///计算价值 			
    		}
    	//	System.out.println(i+"-->"+temp);
    		if(temp<min){
    			min=temp;
    		}
    		temp=0;//reset-重置
    	}//end for
    //	System.out.println("Min:"+min);
    	System.out.println(min);
    }
    /*
    5
    1 2
    2 2
    1 3
    3 -2
    3 3
    ---out--[6]
    */
}
