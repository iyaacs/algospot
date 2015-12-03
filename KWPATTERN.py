val=2000010
ret=list()
idx=0
while(1==1):
    if(idx>=10010):
        break
    n1=val/1000000
    n2=(val/100000)%10
    n3=(val/10000)%10
    n4=(val/1000)%10
    n5=(val/100)%10
    n6=(val/10)%10
    n7=val%10
    year2=n1*1000+n2*100+n3*10+n4
    month2=n5*10+n6
    day2=n7*10+n7
    hour2=n6*10+n5
    minute2=n4*10+n3
    second2=n2*10+n1

  
    if(month2<1 or month2>12):
        val+=1
        continue
    if(not(day2==11 or day2==22)):
        val+=1
        continue
    if(hour2<0 or hour2>24):
        val+=1
        continue
    if(minute2<0 or minute2>59):
        val+=1
        continue
    if(second2<0 or second2>59):
        val+=1
        continue
    
    ret.append(val)
    val+=1
    idx+=1

T=input()
for tt in range(0,T):
    N=input()
    q=str(ret[N-1])
    q+=q[::-1]
    print q[0:4]+'-'+q[4:6]+'-'+q[6:8]+' '+q[8:10]+':'+q[10:12]+':'+q[12:14]
