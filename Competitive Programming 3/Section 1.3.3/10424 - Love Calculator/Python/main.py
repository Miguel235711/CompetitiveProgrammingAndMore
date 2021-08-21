def sumDigits(number):
    while(number>9):
        digitSum = 0 
        while(number):
            digitSum += number % 10
            number //= 10
        number = digitSum
    return number
def calcValue(s):
    sum = 0 
    for c in s:
        c=c.lower()
        if ord('a')<=ord(c) and ord(c)<=ord('z'):
            sum += ord(c) -ord('a') + 1
    return sum
def main():
    while True:
        try:
            sumDigitsA = sumDigits(calcValue(input()))
            sumDigitsB = sumDigits(calcValue(input()))
            if sumDigitsA > sumDigitsB :
                sumDigitsA,sumDigitsB = sumDigitsB,sumDigitsA
            #sumDigitsA <= sumDigitsB
            print("{:.2f} %".format(sumDigitsA/sumDigitsB*100))
        except:
            break
main()