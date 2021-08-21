from sys import stdin

wordToLanguage = {
    "HELLO":"ENGLISH",
    "HOLA":"SPANISH",
    "HALLO":"GERMAN",
    "BONJOUR":"FRENCH",
    "CIAO":"ITALIAN",
    "ZDRAVSTVUJTE":"RUSSIAN"
}
def main():
    cs = 1
    for line in stdin:
        if line[0] == '#':
            return
        line = line[:-1]
        print("Case "+str(cs)+": ",end='')
        cs+=1
        if line in wordToLanguage:
            print(wordToLanguage[line])
        else:
            print("UNKNOWN")
main()