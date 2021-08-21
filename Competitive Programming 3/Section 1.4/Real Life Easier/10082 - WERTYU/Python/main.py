from sys import stdin

mapToLeft={
    '1':'`',
    '0':'9',
    '-':'0',
    '=':'-',
    '[':'P',
    ']':'[',
    '\\':']',
    ',':'M',
    '.':',',
    '/':'.',
    'W':'Q',
    'E':'W',
    'R':'E',
    'T':'R',
    'Y':'T',
    'U':'Y',
    'I':'U',
    'O':'I',
    'P':'O',
    'S':'A',
    'D':'S',
    'F':'D',
    'G':'F',
    'H':'G',
    'J':'H',
    'K':'J',
    'L':'K',
    ';':'L',
    'X':'Z',
    'C':'X',
    'V':'C',
    'B':'V',
    'N':'B',
    'M':'N',
    "'":';'
}

def getLeft(c):
    if (ord('1') < ord(c) and ord(c) <=ord('9')):
        return chr(ord(c)-1)
    if c in mapToLeft:
        return mapToLeft[c]
    return c

def main():
    for line in stdin:
        for c in line.rstrip():
            print(getLeft(c),end='')
        print()
main()
