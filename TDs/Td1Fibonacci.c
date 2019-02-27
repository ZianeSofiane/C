#include <stdio.h>
#include <stdlib.h>

int Fibo(int n){
    if(n==1) return 0;
    else if(n==2)   return 1;

    return Fibo(n-1)+Fibo(n-2);
}

int Fibo2(int n){
    int f=0;
    for(int i=0 ; i<n ; i++){
        if(i==1)    f = f+1;

    }
}

/** on admet n=5:

    n!=1;
    n!=2;
    retourne Fibo(4)+Fibo(3);
        Fibo(3)=Fibo(2)+Fibo(1); == 1 + 0
        Fibo(4)=Fibo(3)+Fibo(2); == 1 + 0 + 1
        Fibo(5)= 5;
**/

int main(){
    printf("%d",Fibo(9));
}
