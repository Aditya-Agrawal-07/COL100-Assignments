a=float(input())
b=float(input())
c=float(input())
D=b**2-4*a*c
if D>=0:
    x1=((-1)*b+D**0.5)/(2*a)
    x2=((-1)*b-D**0.5)/(2*a)
    print(f"{x1:.2f}",0.00)
    print(f"{x2:.2f}",0.00)
else:
    X1=(-1)*b/(2*a)
    Y1=((-1*D)**0.5)/(2*a)
    X2=(-1)*b/(2*a)
    Y2=(-1)*((-1*D)**0.5)/(2*a)
    print(f"{X1:.2f}",f"{Y1:.2f}")
    print(f"{X2:.2f}",f"{Y2:.2f}")