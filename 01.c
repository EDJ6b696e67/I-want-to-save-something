#include <stdio.h>
int main(){
    int a[]={10,9,8,7,6,5,4,3,2,1}, *p;
    p=a;
    printf("%d,%d", *p+9, *(p+9) );
}