#include<cstdio>
#include<cstring>
#include<cassert>
#define M 65

typedef _int64 int64;
int a[M],N,k;///输入的数据
int64 s,p[M];///s获取编号p保存编号

int64 get_per(int *a){
   int i,j;
   int64 c,ret=0;
   for(i=0;i<N-1;i++){
     c=0;
	 for(j=i+1;j<N;j++)
		 if(a[j] > a[i])
			 c++;
	 ret += c*p[N-i-1];
   }
   return ret;
}
void set_per(int *a,int64 key){
   int i,h[M],j,k;
   memset(h,0,sizeof(h));

 //  printf("Key:%d\n",key);
   for(i=0;i<N;i++){
     for(k=0;key>=p[N-i-1];k++,key -= p[N-i-1])
		 ;
	 for(j=N;j>0;j--){
	    if(0==h[j])
			k--;
		if(k<0)
			break;
	 }
	 a[i]=j;
	 h[j]=1;
   }
}
int main(){
    int i,count;
	p[0]=p[1]=1;
	for(i=2;i<=M-1;i++)
		p[i]=i*p[i-1];

	scanf("%d",&count);
	while(count--){
		scanf("%d %d",&N,&k);
		assert(N>=1 && N<=1024);
		assert(k<=64 && k>=1);

	    for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		s=get_per(a);
	//	printf("S:%d\n",s);
		if(s-k <0 ){
	//		printf("%d\n",-(s-k));
	//		printf("%d\n",p[N]+(s-k));
		    s=p[N]+(s-k);
	//		set_per(a,s);
		}else{
		   s -= k;
	//	   set_per(a,s);
		}
		set_per(a,s);
		for(i=0;i<N;i++)
			printf("%d%c",a[i],i==N-1?'\n':' ');
	}
	return 0;
}