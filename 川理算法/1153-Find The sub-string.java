/*
��Ŀ���� D: Find The sub-string
ʱ������: 1 Sec   �ڴ�����: 128 MB 
�ύ: 31   ���: 11
[�ύ] [״̬] 
��Ŀ����
Give a string which length is n ��1<=n<=10000��, print the sub-string ( the length of sub-string should greater than 1 ) that repeat the most times. If the repeat times are same , print the first sub-string . Print ��none�� if there all the sub-string is just repeat one.

����
the first line is the number N , means N line string to be handle. The next N lines are those strings.

���
Every line print one sub-string

��������
4
123456789
abcabcabcabcabcabbbb
123123123456456456789
abcabcdabcdabcabcdadadacdacda
�������
none
ab
12
da
*/
import java.util.Scanner;


public class Main1 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a = cin.nextInt();
		while (a-->0){
			int count=1;
			int k= cin.nextInt();
			int[]res1=new int[k];
			int[]res2=new int[k];
			for(int i=0;i<k;i++){
				res1[i]=cin.nextInt();
				res2[i]=cin.nextInt();
			}
			for(int i=0;i<k;i++){
				for(int j=i;j<k;j++){
					if(res1[j]<res1[i]&&res2[j]<res2[i]){
						int chage=res1[j];
						res1[j]=res1[i];
						res1[i]=chage;
						int chage1=res2[j];
						res2[j]=res2[i];
						res2[i]=chage1;
					}
				}
			}
			for(int i=0;i<k;i++){
				for(int j=i;j<k;j++){
					if(res2[j]<res2[i]&&res1[j]==res1[i]){
						int chage=res1[j];
						res1[j]=res1[i];
						res1[i]=chage;
						int chage1=res2[j];
						res2[j]=res2[i];
						res2[i]=chage1;
					}
				}
			}
			for(int i=1;i<k;i++){
				if(res1[i-1]>res1[i]||res2[i-1]>res2[i]){
					count++;
				}
			}
			System.out.println(count);
		}
	}
}