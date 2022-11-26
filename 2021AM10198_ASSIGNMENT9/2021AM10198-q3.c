#include <stdio.h> // mandatory include
long double factorial(int N){
    long double c=1;
    if (N==0){
        return c;
    }
    else{
        long double i;
        for(i=1;i<=N;i++){
            c=c*i;
        }
        return c;
    }
    
}
int food(int x, int y, int m, int n){
    long long unsigned int n1=factorial(x+y)/(factorial(x)*factorial(y));
    int a=m-x;
    int b=n-y;
    long long unsigned int n2=factorial(a+b)/(factorial(a)*factorial(b));
    long long unsigned int result1=n1*n2;
    int result2 = result1;
    return result2;                 // return statment
}

int main()                       // mandatory main function
{
    int x, y, m, n;             // variable denoting coordinate of restaurant and delivery location
    scanf("%d", &x);           // x coordinate of restaurant
    scanf("%d", &y);            // y coordinate of restaurant
    scanf("%d", &m);           // x coordinate of delivery location
    scanf("%d", &n);            // y coordinate of delivery location
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    int result = food(x, y, m, n);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
