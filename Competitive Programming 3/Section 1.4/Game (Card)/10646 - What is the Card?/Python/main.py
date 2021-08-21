from queue import Queue

def getValue(card):
    if str.isdigit(card[0]):
        return ord(card[0])-ord('0')
    return 10
def main():
    t = int(input())+1
    for cs in range(1,t):
        st,temp=[],Queue()
        i = 0
        while i < 52:
            for tk in input().split():
                if i < 27:
                    st.append(tk)
                else:
                    temp.put(tk)
                i+=1
        y=0
        for _ in range(3):
            val = getValue(st.pop())
            y+=val
            for _ in range(0,10-val):
                st.pop()
        while not temp.empty():
            st.append(temp.get())
        print("Case "+str(cs)+": "+st[y-1])
main()