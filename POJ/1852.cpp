#include<cstdio>
/*
�㷨˼�룺������ת����������󻥲������൱����һֻ����
�����Լ���һֱ��һ���ߣ��򻯹��̸����߼��ж�����:
little=min{li,L-li},big=max{li,L-li}
*/
int c,big,little,L,i,j,k,n;
int main(){
	scanf("%d",&c);
	while(c-- &&(2==scanf("%d%d",&L,&n))){///����������Ŀ�ͺ�ͳ���
	  big=little=0;
	  for(i=0;i<n;i++){
	     scanf("%d",&k);///�����ں���ϵ�λ��
		 if(k>big)
			 big=k;
		 if(L-k > big) ///����k�󷽺��ҷ����ȵ������ʱ��
			 big=L-k;
		 if(k > L-k)
			 k=L-k;
		 if(k>little)  ////��k���ҳ��ȵ���Сֵ��������ʱ��
			 little=k;
	  }
	  printf("%d %d\n",little,big);///�������ʱ�������ʱ��
	}
	return 0;
}