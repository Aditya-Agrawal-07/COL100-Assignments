#include <stdio.h> // mandatory include

float time_angle(int XX, int YY){   // function you have to implement
    int hours=XX%12;
    int mins=YY;
    float angle1=30*hours;
    float angle2=6*mins;
    float angle3=angle1+(mins/2);
    float result=angle2-angle3;
    if (result<0){
        result=result*(-1);
    }
    if (result>180){
        result=360-result;
    }          // sample variable - you can change this according to your need
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY;                 // variable denoting hours and minutes
    scanf("%d", &XX);           // hour input
    scanf("%d", &YY);           // minute input
    // printf("%d:%d",XX,YY);
    int result = time_angle(XX, YY);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}