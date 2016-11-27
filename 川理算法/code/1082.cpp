#include<cstdio>

int main(){
	int *p,*sort;
	int count,number;
	int temp;
	int i,j,index;
	int max,min;

	while(scanf("%d",&count) && count!=0){
	     number=count/2*(count-1);

		 p=new int[number];
		 sort=new int[count];

		 for(i=0;i<number;i++){
		     scanf("%d",&temp);
			 p[i]=temp;
		 }
		
		 index=0;
		 max=p[number-1]-p[0];
		 min=p[number-1]-p[number-2];

		 for(i=1;i<number;i++){
			 temp=p[i]-p[i-1];
			 if(temp>=min && temp<=max){
			   for(j=0;j<index;j++){
			      if(temp==sort[j])
					  break;
			   }
			   if(j==index){
			     sort[index++]=temp;
			   }//end if
			 }//end if
		 }
		 for(i=0;i<index;i++){
		    printf("%d ",sort[i]);
		 }

	}///end while
	return 0;
}