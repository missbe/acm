/*
题目描述
给定n个十六进制正整数，输出它们对应的八进制数。

输入
输入的第一行为一个正整数n （1<=n<=10）。接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出
输出n行，每行为输入对应的八进制正整数。【注意】输入的十六进制数不会有前导0，比如012A。输出的八进制数也不能有前导0。

样例输入
2
39
123ABC
样例输出
71
4435274
*/
//CODE
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(
				new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		String a[] = new String[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.readLine();///保存输入的字符串
		}

		for (int i = 0; i < n; i++) {
			char[] temp = a[i].toCharArray();///转化为临时字符串
			StringBuffer s2 = new StringBuffer();////转化为二进制缓存字符串
			// 16 to 2
			int k = temp.length;
			for (int j = 0; j < k; j++) {
				switch (temp[j]) {///将每一个16进制数转化为二进制字符串
				case '0':
					s2.append("0000");
					break;
				case '1':
					s2.append("0001");
					break;
				case '2':
					s2.append("0010");
					break;
				case '3':
					s2.append("0011");
					break;
				case '4':
					s2.append("0100");
					break;
				case '5':
					s2.append("0101");
					break;
				case '6':
					s2.append("0110");
					break;
				case '7':
					s2.append("0111");
					break;
				case '8':
					s2.append("1000");
					break;
				case '9':
					s2.append("1001");
					break;
				case 'A':
					s2.append("1010");
					break;
				case 'B':
					s2.append("1011");
					break;
				case 'C':
					s2.append("1100");
					break;
				case 'D':
					s2.append("1101");
					break;
				case 'E':
					s2.append("1110");
					break;
				case 'F':
					s2.append("1111");
					break;
				}
			}
			// 2 to 8
			StringBuffer s3 = new StringBuffer();////由二进制串转换为8进制的缓存字符串
			int m = 0;
			if (4 * k % 3 == 1) {/////处理第一个字符-剩下一个字符串的情况
				s3.append(s2.substring(0, 1));
				m += 1;
			} else if (4 * k % 3 == 2) {/////处理第一个字符-剩下两个字符的情况
				switch (s2.substring(0, 2)) {
				case "01":
					s3.append("1");
					break;
				case "10":
					s3.append("2");
					break;
				case "11":
					s3.append("3");
					break;
				default:
					break;
				}
				m += 2;
			}
			for (int j = m; j < 4 * k;) {////从m开始遍历到最后一个字符
				switch (s2.substring(j, j + 3)) {///每次取三个字符进行处理
				case "000":
					s3.append("0");
					break;
				case "001":
					s3.append("1");
					break;
				case "010":
					s3.append("2");
					break;
				case "011":
					s3.append("3");
					break;
				case "100":
					s3.append("4");
					break;
				case "101":
					s3.append("5");
					break;
				case "110":
					s3.append("6");
					break;
				case "111":
					s3.append("7");
					break;
				}
				j += 3;
			}
			// delete 0
			// use delete(old is 0) or charAt			
			if (s3.length() == 2 && s3.charAt(0) == '0') {// 0-->00-->delete 00-->notany
				System.out.println(s3.substring(1));////处理前导0-两个字符都是0的情况
			} else {
				int q = 0;
				while (s3.charAt(q) == '0') {///计算前导0的个数
					q++;
				}
				String s = s3.toString();
				System.out.println(s3.substring(q));///取字串
			}
		}
	}
}
