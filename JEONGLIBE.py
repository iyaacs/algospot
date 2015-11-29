T=input()
dic=dict()
for TT in range(0,T):
    s=raw_input()
    s=s[:-4]
    ss=s.split('/')
    rawone=ss[len(ss)-1]
    rawones=rawone.split('.')
    rawtwo=rawones[len(rawones)-1]
    rawtwo=rawtwo.strip()
    artist=''
    name=''
    rawtwos=rawtwo.split('_')
    if(len(rawtwos)==2):
        artist= rawtwos[0]
        name=rawtwos[1]
    if(len(rawtwos)==3):
        artist=rawtwos[1]
        name=rawtwos[2]

    if(len(rawtwos)==1):
        raw3=rawtwo.split('-')
        artist=raw3[0]
        name=raw3[1]    
    artist=artist.strip()
    name=name.strip()
    artist=artist.lower()
    name=name.lower()
    idx=artist+'_'+name
    if(idx in dic):
        dic[idx]+=1
    else:
        dic[idx]=1

print len(dic)