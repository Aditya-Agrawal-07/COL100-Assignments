x=int(input())
n=int(input())
for i in range (1,n+1):
    a=((-1)**(i))/x**(2*i)
    print(f"{a:.2f}")