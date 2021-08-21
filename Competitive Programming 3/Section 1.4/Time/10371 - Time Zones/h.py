def main():
    current=''
    detectHour=False
    line = input()
    for i,c in enumerate(line):
        if c == '+' or c=='-':
            detectHour=True
            current=c
        if current=='hour':
            print("'{}'".format(current))
            current=''
            detectHour=False
        if str.isupper(line[i]) and str.isupper(line[i+1]):
            if not str.isupper(c):
                current+=c
        elif current:
            print("'{}'".format(current),end=':')
            current=''
        if detectHour and str.isdigit(c):
            current+=c
main()