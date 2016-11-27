/*

题目管理 B: Wooden Sticks
时间限制: 1 Sec   内存限制: 128 MB 
提交: 51   解决: 21
[提交] [状态] 
题目描述
There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows:
(a) The setup time for the first wooden stick is 1 minute.
(b) Right after processing a stick of length l and weight w, the machine will need no setup time for a stick of length l' and weight w' if l<=l' and w<=w'. Otherwise, it will need 1 minute for setup.
You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are (4,9), (5,2), (2,1), (3,5), and (1,4), then the minimum setup time should be 2 minutes since there is a sequence of pairs (1,4), (3,5), (4,9), (2,1), (5,2).
输入
The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n, 1<=n<=5000, that represents the number of wooden sticks in the test case, and the second line contains n 2 positive integers l1, w1, l2, w2, ..., ln, wn, each of magnitude at most 10000, where li and wi are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.
输出
The output should contain the minimum setup time in minutes, one per line.
样例输入
3
5
4 9 5 2 2 1 3 5 1 4
3
2 2 1 1 2 2
3
1 3 2 2 3 1
样例输出
2
1
3
*/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Main2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		new Main2().start();
	}
	private void start() throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(br.readLine());
		while (a-->0){
			String string=br.readLine();
			List<Jiegou> jiegous=new ArrayList<Jiegou>();
			for(int j=2;j<string.length();j++){
				for(int i=0;i<string.length()-j;i++){
					String temp=string;
					String bijiao=temp.substring(i, i+j);
					Jiegou jiegou=new Jiegou();
					jiegou.setCount(-1);
					jiegou.setRes(bijiao);
					while(string.indexOf(bijiao)!=-1){
						jiegou.setCount(jiegou.getCount()+1);
						try{
							temp=temp.substring(0, temp.indexOf(bijiao))+temp.substring(temp.indexOf(bijiao)+j,temp.length());
						}catch (Exception e) {
							break;
						}
					}
					jiegous.add(jiegou);
				}
			}
			int ii=0;
			int count=0;
			for(int i=0;i<jiegous.size();i++){
				if(i==0){
					count=jiegous.get(i).getCount();
				}
				if(jiegous.get(i).getCount()>count){
					ii=i;
				}
			}
			if(jiegous.get(ii).getCount()>=2){
				System.out.println(jiegous.get(ii).getRes());
			}else{
				System.out.println("none");
			}
		}

	}
}
class Jiegou{
	private int count;
	private String res;
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	public String getRes() {
		return res;
	}
	public void setRes(String res) {
		this.res = res;
	}
}
