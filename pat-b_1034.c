#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a1,b1,a2,b2;//输入
static long long int zheng[3],fenzi[3],fenmu[3],fu[3],gongyueshu[3],inf;//输出(1,2),结果(0)
long long int GDC(long long int a,long long int b){//求最大公约数
    long long int c;
    a=(long long)abs(a);
    b=(long long)abs(b);
    if(b>a){
        c=a;
        a=b;
        b=c;
    }//保证a大于b
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
void huajian(long long int a,long long int b,int i){//化简
    gongyueshu[i]=GDC(a,b);
    fenzi[i]=a/gongyueshu[i];
    fenmu[i]=b/gongyueshu[i];
    zheng[i]=fenzi[i]/fenmu[i];
    if(zheng[i]!=0){
        fenzi[i]-=zheng[i]*fenmu[i];
    }
    if(fenzi[i]*fenmu[i]<0||zheng[i]<0){
        fu[i]=1;
    }else{
        fu[i]=0;
    }//记录是否为负数
}
void add(int A1,int B1,int A2,int B2){//加
    fenmu[0]=B1*B2;
    fenzi[0]=A1*B2+A2*B1;
    huajian(fenzi[0],fenmu[0],0);
}
void subtract(int A1,int B1,int A2,int B2){//减
    fenmu[0]=B1*B2;
    fenzi[0]=A1*B2-A2*B1;
    huajian(fenzi[0],fenmu[0],0);
}
void multiply(int A1,int B1,int A2,int B2){//乘
    fenmu[0]=B1*B2;
    fenzi[0]=A1*A2;
    huajian(fenzi[0],fenmu[0],0);
}
void divide(int A1,int B1,int A2,int B2){//除
    fenmu[0]=B1*A2;
    fenzi[0]=A1*B2;
    if(fenmu[0]==0){
        inf=1;
        return;
    }else{
        huajian(fenzi[0],fenmu[0],0);
    }
}
void shuchu(int i,int k){//有理数输出格式
    if(k==4&&inf&&i==0){
        printf("Inf");
        return;
    }
    if(zheng[i]==0&&fenzi[i]==0){
        printf("0");
        return;
    }
    if(fu[i]){
        printf("(-");
    }
    if(zheng[i]!=0){
        printf("%lld",(long long)abs(zheng[i]));
    }
    if(fenzi[i]!=0){
        if(zheng[i]!=0){
            printf(" ");
        }
        printf("%lld/%lld",(long long)abs(fenzi[i]),(long long)abs(fenmu[i]));
    }
    if(fu[i]){
        printf(")");
    }
}
int main(){
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    huajian(a1,b1,1);
    huajian(a2,b2,2);
    for(int i=1;i<=4;i++){
        shuchu(1,i);
        switch(i){
            case 1:
                printf(" + ");
                add(a1,b1,a2,b2);
                break;
            case 2:
                printf(" - ");
                subtract(a1,b1,a2,b2);
                break;
            case 3:
                printf(" * ");
                multiply(a1,b1,a2,b2);
                break;
            case 4:
                printf(" / ");
                divide(a1,b1,a2,b2);
                break;
        }
        shuchu(2,i);
        printf(" = ");
        shuchu(0,i);
        printf("\n");
    }
}