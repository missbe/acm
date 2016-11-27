#include<cstdio>
#include<cstdlib>
#include<cassert>

int main(){
	char *ch,*p,number[4];
	int N=-1,M,temp;
	int i,j,k,m,index=0;//count
	int ch_sub=0,num_sub=0,count;
	int a,b,c;
	i=1;
	printf("%c\n",(char)(i+48));
	
	while(N!=0){
	
		scanf("%d %d",&N,&M);
		assert(M < N);
		assert(N>=2 && N<=1000);
		if(N<9){
			count=N;
			ch=new char[count*2];///avoid memory leaks
			p=new char[(count-M+1)*2];
		}else{
			count=9+(N-9)*2;
			ch=new char[(count+1)*2];
			p=new char[(count-M+1)*2];
		}

		ch_sub=0,num_sub=0;
		for(i=1;i<=N;i++){
			if(i<=9)
				ch[ch_sub++]=(char)(i+48);
			else{
				temp=i;
				num_sub=0;
				while(temp){
					number[num_sub++]=(char)(temp%10+48);
					temp /= 10;
				}
				for(k=num_sub-1;k>=0;k--)
					ch[ch_sub++]=number[k];
			}		
		}//for i
//		for(j=0;j<ch_sub;j++)
//			printf("%c",ch[j]);
//		printf("\n");

	  ////To Deal With
	  for(i=0;M>0 && i< count;i++){
		 m=i;
		 while(ch[m]<0){
			 m++;
		 }
		 a=ch[m];
		 j=m+1;
		 while(ch[j]<0){
		   j++;
		 }		
		 b=ch[j];
		 k=j+1;
		 while(ch[k]<0){
		     k++;
		 }
		 c=ch[k];
		 if(a>b && a>c)
			 continue;
		 if(b >= a){
			 ch[m]=-1;
			 M--;
		 }else{
			 if(c<b){
				 ch[k]=-1;
			 }else{
				 ch[j]=-1;
			 }
			 i--;
			 M--;
		 }//end if
		 
	  }//for
//	   for(i=0;i<count;i++){
//		   printf("%c",ch[i]);
//	   }
//	   printf("\n");
	  ////show result
	  index=0;
	  for(i=0;i<count;i++){
		  if(ch[i]!=-1){
			  p[index++]=ch[i];
		  }
	  }///for assignment
//	  printf("index:%d\n",index);
	  for(i=0;i<index;i++)
		printf("%c",p[i]);
	  printf("\n");
	    N=-1;//renew circle
		delete ch;
		delete p;
	}//while
	return 0;
}