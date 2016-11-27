#include<cstdio>
/*
算法思想：将相遇转向更改相遇后互不干扰相当于另一只蚂蚁
代替自己向一直向一边走，简化过程给出逻辑判断条件:
little=min{li,L-li},big=max{li,L-li}
*/
int c,big,little,L,i,j,k,n;
int main(){
	scanf("%d",&c);
	while(c-- &&(2==scanf("%d%d",&L,&n))){///输入蚂蚁数目和横竿长度
	  big=little=0;
	  for(i=0;i<n;i++){
	     scanf("%d",&k);///蚂蚁在横竿上的位置
		 if(k>big)
			 big=k;
		 if(L-k > big) ///根据k左方和右方长度调整最大时间
			 big=L-k;
		 if(k > L-k)
			 k=L-k;
		 if(k>little)  ////由k左右长度的最小值调整最早时间
			 little=k;
	  }
	  printf("%d %d\n",little,big);///输出最早时间和最晚时间
	}
	return 0;
}