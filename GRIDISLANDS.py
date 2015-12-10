T=input()
for tt in range(0,T):
    n=input()
    e=(n+1)*(n+1)+n*n
    ans=pow(2,e-1)%20090711
    print ans