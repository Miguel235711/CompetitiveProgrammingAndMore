def main():
    while True:
        roundd = int(input())
        if roundd == -1:
            break
        objective,visited,wrong=set(),set(),set()
        print('Round '+str(roundd))
        for c in input():
            objective.add(c)
        for c in input():
            if c in objective:
                visited.add(c)
                if len(visited)==len(objective):
                    break
            else:
                wrong.add(c)
                if len(wrong)>6:
                    #loses
                    break
        print('You '+('lose' if len(wrong)>6 else ('win' if len(visited)==len(objective) else 'chickened out'))+'.')
main()