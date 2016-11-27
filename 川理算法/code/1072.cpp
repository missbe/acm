#include<cstdio>
 int main(){
	 int num,temp,i;
	 while(scanf("%d",&num)!=EOF){
		 for(i=7;i<num;i++){
			 if(0==i%7){
				 printf("%d\n",i);
				 continue;
			 }
			 temp=i;
			 while(temp){
				 if(7==temp%10){
					 printf("%d\n",i);
					 break;
				 }
				 temp /= 10;
			 }
		 }
	 }
	 return 0;
 }