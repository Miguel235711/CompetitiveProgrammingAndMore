import math

def main():
    cs = 1 
    while True:
        remain = int(input())
        if not remain :
            return
        print('Output for data set {}, {} bytes:'.format(cs,remain))
        i , j  = 0 , 0
        acum5 = 0 
        while remain:
            x = int(input())
            remain-=x
            acum5 += x
            if i == 4:
                #process acum5
                remain5 = remain * 5
                print('   Time remaining: {}'.format('{} seconds'.format(remain5//acum5 + (1 if remain5%acum5 else 0)) if acum5 else 'stalled'))
                acum5=0 
            i=(i+1)%5
            j+=1
        print('Total time: {} seconds\n'.format(j))
        cs+=1
main()