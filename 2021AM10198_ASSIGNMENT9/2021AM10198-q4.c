#include <stdio.h> // mandatory include

int birt(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC){
    if(ZZZZ%4==0 && XX==29 && YY==2){
        int m=0,n=0;
        int i;
        for (i=ZZZZ+1;i<CCCC;i++){
            if (i%4!=0 && (i-1)%4!=0){
                m+=1;
                if (m%7==2){
                    n+=1;
                }
            }
            else if(i%4!=0 && (i-1)%4==0){
                m+=2;
                if (m%7==2){
                    n+=1;
                }
            }
            else{
                m+=1;
                if (m%7==2){
                    n+=1;
                }
            }
        }
        if (BB<=2){
            return n;
        }
        else if(CCCC%4!=0 && AA==1 && BB==3){
            return n;
        }   
        else if(CCCC%4==0 && BB>=3){
             m+=1;
                if (m%7==2){
                    n+=1;
                }
            return n;
        }
        else{
            if ((CCCC-1)%4!=0){
                m+=1;
                if (m%7==2){
                    n+=1;
                }
                return n;
            }
            else{
                m+=2;
                if (m%7==2){
                    n+=1;
                }
                return n;
            }
        }
    }
    else{
        int m=0,n=0,i;
        for (i=ZZZZ+1;i<CCCC;i++){
            if (i%4!=0 && (i-1)%4!=0){
                m+=1;
                if (m%7==2){
                    n+=1;
                }
            }
            else if (i%4!=0 && (i-1)%4==0){
                if (YY<=2){
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                }
                else{
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                }
            }
            else{
                if (YY<=2){
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                }
                else{
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                } 
            }
        }
        if (BB<YY){
            return n;
        }
        else if(BB>YY){
            if (CCCC%4!=0 && (CCCC-1)%4!=0){
                m+=1;
                if (m%7==2){
                    n+=1;
                }
                return n;
            }
            else if (CCCC%4!=0 && (CCCC-1)%4==0){
                if (YY<=2){
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
                else{
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
            }
            else{
                if (YY<=2){
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
                else{
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                } 
            }
        }
        else{
            if (AA<=XX){
                return n;
            }
            else{
                if (CCCC%4!=0 && (CCCC-1)%4!=0){
                m+=1;
                if (m%7==2){
                    n+=1;
                }
                return n;
            }
            else if (CCCC%4!=0 && (CCCC-1)%4==0){
                if (YY<=2){
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
                else{
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
            }
            else{
                if (YY<=2){
                    m+=1;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                }
                else{
                    m+=2;
                    if (m%7==2){
                    n+=1;
                    }
                    return n;
                } 
            }
            }
        }
    }
}
int main()                       // mandatory main function
{
    int XX, YY, ZZZZ, AA, BB, CCCC;             // variable 
    scanf("%d", &XX);           // input of Date of birth
    scanf("%d", &YY);            // input of Month of birth
    scanf("%d", &ZZZZ);           // input of Year of birth
    scanf("%d", &AA);           // input of Date of death
    scanf("%d", &BB);            // input of Month of death
    scanf("%d", &CCCC);            // input of Year of death
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}