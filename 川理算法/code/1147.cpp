#include<cstdio> 
#include<cstring> 
struct Sort{ 
    int index[101]; 
    int oneCount; 
    char str[101]; 
}; 
int main(){ 
    char str[101]; 
    int count,index,i,number,N,k,j; 
    Sort *p,temp; 
  
      
    scanf("%d",&number);
    count=0,index=0,i=0; 
    N=number; 
    p=new Sort[number]; 
  
    while(number--){ 
        scanf("%s",str); 
        while(str[i]!='\0'){ 
            if('1'==str[i]){ 
                count++; 
                p[N-number-1].index[index++]=i; 
            } 
            i++; 
        } 
        p[N-number-1].oneCount=count; 
        strcpy(p[N-number-1].str,str); 
        i=0; 
        index=0; 
        count=0; 
    } 
  
    for(i=0;i<N-1;i++){ 
        k=i; 
        if(p[k].oneCount!=0){ 
           for(j=i+1;j<N;j++){ 
             if(p[j].oneCount==0){ 
                 k=j; 
                 break; 
             }else if(p[j].oneCount==p[k].oneCount){ 
                    for(int m=0;m<p[k].oneCount;m++) 
                      if(p[j].index[m]< p[k].index[m]){ 
                         k=j; 
                         break; 
                      }else if(p[j].index[m]> p[k].index[m]){ 
                         break; 
                      } 
			 }else if(p[j].oneCount<p[k].oneCount){ 
                k=j; 
             } 
           } 
        } 
      if(k!=i){ 
          temp=p[i]; 
          p[i]=p[k]; 
          p[k]=temp; 
      } 
    } 
    for(i=0;i<N;i++) 
        printf("%s\n",p[i].str); 
    delete p; 
	return 0;
} 
