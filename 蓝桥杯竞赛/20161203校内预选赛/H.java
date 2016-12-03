/*
题目描述
设计算法，用户输入合数，程序输出若个素数的乘积。例如，输入6，输出2*3。输入20，输出2*2*5。
输入
输出
样例输入
120
样例输出
2*2*2*3*5
*/
//CODE
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class eight {
	public static void main(String[] args){		
		Scanner scanner=new Scanner(System.in);
		int n;
		while(scanner.hasNext()){
			n=scanner.nextInt();
			caculate(n);
		}
	//	caculate(20);
	//	caculate(4);
	//	caculate(6);
	//	caculate(120);

	}
	///判断是否是素数
	public static boolean isSuShu(int n){
		boolean flag=true;
		int nSqrt=(int)Math.sqrt(n);
		for(int i=2;i<=nSqrt;i++){
			if(0==n%i){
				flag=false;
			}
		}
//		System.out.println("SuShu:"+flag);
		return flag;
	}
	public static void caculate(int n){
		List<Integer> list=new ArrayList<Integer>();
		int i=2;		
	    while(n!=1){
	    	if(0==n%i){
	    		if(isSuShu(i)){///判断是否是素数-是进行处理
	    			n=n/i;
		    		list.add(i);
		//    		System.out.println("code--->"+i+" ");
		    		i=2;	///重新从2开始计算起
	    		}else{
	    			i++;///向前运动
	    		}	    		    		
	    	}else{
	    		i++;///向前运动
	    	}	    	
	    }//end while
	    Integer[] listCopy=list.toArray(new Integer[0]);
	    int size=listCopy.length;
	    for(int j=0;j<size;j++){	    	
	    	 if(size==j+1){
	    		 System.out.print(listCopy[j]);///最后一个数的输出形式
			}else{
				System.out.print(listCopy[j]+"*");
			}
	    }//end for
	    System.out.println();
	}///end method
}
