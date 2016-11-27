#include<cstdio>
int flag;

void rule(char *ch,char ex,char temp){
    int i;
	for(i=0;ch[i]!='\0';i++)
		if(ch[i]==ex)
			ch[i]=temp;
//	printf("%s\n",ch);
}
int main(){
	int count;
	char ch[101];
	int i;

	scanf("%d",&count);
	while(count--){
		scanf("%s",ch);
		for(i=0;ch[i]!='\0';i++){
			if(ch[i]==':'){
				if((ch[i+1]=='\\' || ch[i+1]=='/')&&(
					ch[i+2]=='\\' || ch[i+1]=='/')){
				   flag=1;//url
				   break;
				}
				if(ch[i+1]=='\\' || ch[i+1]=='/'){
					flag=3;///windows
				    break;
				}
			}
			if(ch[i]=='/' || ch[i]=='\\'){
				flag=2;///unix
				break;
			}
			/*if(){
				flag=3;
				break;
			}*/
		}//end for
		switch(flag){
	     case 1:
		   printf("It's a URL!\n");
		   rule(ch,'\\','/');////url
		   break;
	     case 2:
		   printf("It's a path in Unix-like systems!\n");
		   rule(ch,'\\','/');////unix
		   break;
	     case 3:
		   printf("It's a path in Windows system!\n");
		   rule(ch,'/','\\');///window
		   break;
		}
		printf("%s\n",ch);
	}
	return 0;
}
/*
4
http://acm.suse.edu.cn/admin/
http:/\acm.suse.edu.cn/11111011001/
\home\usr\Slash\test
Z:\movie/lx

*/