from fractions import gcd
from functools import cmp_to_key
import sys
algoInput = lambda : sys.stdin.readline()


def AmIGood(lhs, rhs):
    
    lSum = sum(lhs)
    rSum = sum(rhs)

    lv = lhs[0]*rSum
    rv = rhs[0]*lSum

    if(lv>=rv):
        return True
    return False

def GetResult(teams, myTeam):
    goodTeam = 0
    for key in teams:
        if key==myTeam:
            continue
        if(AmIGood(teams[myTeam],teams[key])==False):
            goodTeam+=1
    return "YES" if goodTeam<4 else "NO"
        

T=int(algoInput())

for X in range(0,T):
    teams=dict()
    for i in range(0, 8):
        spl=algoInput().strip().split(' ')
        teamName=spl[0]
        result=list(map(lambda x:int(x), spl[1:]))
        teams[teamName]=result
    myTeam=algoInput().strip()
    n=int(algoInput())
    
    for i in range(0, n):
        spl=algoInput().strip().split(' ')
        if myTeam in spl:
            myTeamIndex=0 if spl[0]==myTeam else 1
            otherTeamIndex = 1-myTeamIndex
            teams[spl[myTeamIndex]][0]+=1
            teams[spl[otherTeamIndex]][2]+=1
        else:
            teams[spl[0]][1]+=1
            teams[spl[1]][1]+=1

    print (GetResult(teams, myTeam))
