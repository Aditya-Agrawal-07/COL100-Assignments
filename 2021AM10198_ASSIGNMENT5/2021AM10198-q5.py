def pattern(a):
    if a==1:
        return str(111)
    else:
        return str(a)+pattern(a-1)+str(a)+pattern(a-1)+str(a)
a=int(input())
print(pattern(a))