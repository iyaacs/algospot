N=input()
N=int(N)
for i in range(1, N+1):
    s=input()
    exp=0
    while(True):
        if(s.find('[]')<0):
            break
        s=s.replace('[]','')
        exp+=1
    print ('%s %s'%(i,pow(2,exp)))
    
