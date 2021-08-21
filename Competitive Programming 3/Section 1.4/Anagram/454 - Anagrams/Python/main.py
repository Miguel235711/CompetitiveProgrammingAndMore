def main():
    n = int(input())
    input()
    for cs in range(n):
        if cs!=0:
            print()
        pairs=[]
        while True:
            try:
                line = input()
                if not line:
                    break
            except:
                break
            pairs.append([line, ''.join(sorted(line.replace(' ','')))])
        pairs.sort()
        #brute force
        for i in range(len(pairs)):
            for j in range(i+1,len(pairs)):
                if pairs[i][1] == pairs[j][1]:
                    print('{} = {}'.format(pairs[i][0],pairs[j][0]))
main()