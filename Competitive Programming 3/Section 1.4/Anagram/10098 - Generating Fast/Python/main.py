from itertools import permutations

def main():
    
    for _ in range(int(input())):
        ans = set()
        for perm in permutations(input()):
            ans.add(''.join(perm))
        sL = list(ans)
        sL.sort()
        for a in sL:
            print(a)
        print()
main()