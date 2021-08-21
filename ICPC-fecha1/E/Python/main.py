#!/usr/bin/env python

def is_prime(n):
    if n is None:
        return False
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n%2 == 0:
        return False
    else:
        p = 3
        while p <= (n//2)+1:
            if n%p == 0:
                return False
            p += 2
        return True

def test_case():
    s = input()
    slen = len(s)

    def check_subs(l, r):
        a = int(s[:l])
        b = int(s[l:r])
        c = int(s[r:])

        if is_prime(a) and is_prime(b) and is_prime(c):
            return a*b*c
        else:
            return None

    answer = None
    for l in range(1, slen-1):
        for r in range(l+1, slen):
            val = check_subs(l, r)
            if not val is None:
                if answer is None or val < answer:
                    answer = val
    if answer:
        print(answer)
    else:
        print("Bob lies")

def main():
    test_case()

if __name__ == "__main__":
    main()
