#include<cstdio>

int main(){
	long M1,M2,R1=0,R2=0,R3=0;
	char command[201],num;
	int i;
	char key;

	while(scanf("%d %d",&M1,&M2)!=EOF){
	  scanf("%s",&command);

	  for(i=0;command[i]!='\0';i++)
		;
	  num=i;
      for(i=0;i<num;i++){
		 key=command[i];
	 	 switch(key){
		  case 'A':
			R1=M1;
			break;
		  case 'B':
			R2=M2;
			break;
		  case 'C':
			M1=R3;
			break;
		  case 'D':
		 	M2=R3;
			break;
		  case 'E':
			R3=R1+R2;
			break;
		  case 'F':
			R2=R1-R2;
			break;
		}
	  }
	  printf("%d,%d\n",M1,M2);
	}
	return 0;
}
/*
样例输入
100 288
ABECED
876356 321456
ABECAEDBECAF

样例输出
388,388
2717080,1519268



*/