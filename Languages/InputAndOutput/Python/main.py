def main():
  input()
  arr=list(map(int,input().split()))
  print('(',end='')
  for i,el in enumerate(arr):
    print(str(el)+(','if i+1<len(arr)else''),end='')
  print(')')
main()