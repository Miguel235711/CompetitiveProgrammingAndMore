from sys import stdin

mapSpecials={
    '/':12,
    'X':13
}

def main():
    for line in stdin:
        if line[0]=='G':
            return
        arr = [ord(x)-ord('0') if str.isdigit(x) else mapSpecials[x] for x in line if x!=' ' and x!='\n']
        ans,count,trail=0,0,False
        for i in range(len(arr)):
            if (i+1==len(arr)or arr[i+1]!=12)and count<10:
                ans+=min(10,arr[i])
            lim = min(i+max(arr[i]-10,0),len(arr)) if count < 10 else i + 1
            if trail or arr[i]==13:
                count+=1
                trail=False
            else:
                trail=True
            before=-1
            for nextI in range(i+1,lim):
                ans+=min(10,arr[nextI])
                if arr[nextI]==12 and before!=-1:
                    ans-=before
                before=arr[nextI] 
        print(ans)
main()