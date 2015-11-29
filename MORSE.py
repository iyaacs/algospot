import math
def combi(a,b):
    f=math.factorial
    return f(a)/f(b)/f(a-b)


def solve(n,m,skip):
    if(n==0):
        return 'o'*m
    if(skip<combi(n+m-1,n-1)):
        return '-'+solve(n-1,m,skip)
    return 'o'+solve(n,m-1,skip-combi(n+m-1,n-1))

T=input()
i=0
while(i<T):
    str=raw_input()
    arr=str.split(' ')
    n=arr[0]
    m=arr[1]
    k=arr[2]
    n=int(n)
    m=int(m)
    k=int(k)
    print solve(n,m,k-1)
    i+=1