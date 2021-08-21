import re

def main():
    n = int(input())
    for _ in range(0,n):
        st = str(input())
        if st == '1' or st == '4' or st=='78':
            print('+')
        elif re.match(re.compile('^.*35$'),st)!=None:
            print('-')
        elif re.match(re.compile('^9.*4$'),st)!=None:
            print('*')
        else:
            print('?')

main()