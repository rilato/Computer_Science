# 8번 B735365 이윤식

def main():
    string = input("문자를 입력하시오?")
    print(convertString(string))

def convertChar(c):
    if c == 'a': return 'A'
    elif c == 'b': return 'B'
    elif c == 'c': return 'C'
    elif c == 'd': return 'D'
    elif c == 'e': return 'E'
    elif c == 'f': return 'F'
    elif c == 'g': return 'G'
    elif c == 'h': return 'H'
    elif c == 'i': return 'I'
    elif c == 'j': return 'J'
    elif c == 'k': return 'K'
    elif c == 'l': return 'L'
    elif c == 'm': return 'M'
    elif c == 'n': return 'N'
    elif c == 'o': return 'O'
    elif c == 'p': return 'P'
    elif c == 'q': return 'Q'
    elif c == 'r': return 'R'
    elif c == 's': return 'S'
    elif c == 't': return 'T'
    elif c == 'u': return 'U'
    elif c == 'v': return 'V'
    elif c == 'w': return 'W'
    elif c == 'x': return 'X'
    elif c == 'y': return 'Y'
    elif c == 'z': return 'Z'
    elif c == 'A': return 'a'
    elif c == 'B': return 'b'
    elif c == 'C': return 'c'
    elif c == 'D': return 'd'
    elif c == 'E': return 'e'
    elif c == 'F': return 'f'
    elif c == 'G': return 'g'
    elif c == 'H': return 'h'
    elif c == 'I': return 'i'
    elif c == 'J': return 'j'
    elif c == 'K': return 'k'
    elif c == 'L': return 'l'
    elif c == 'M': return 'm'
    elif c == 'N': return 'n'
    elif c == 'O': return 'o'
    elif c == 'P': return 'p'
    elif c == 'Q': return 'q'
    elif c == 'R': return 'r'
    elif c == 'S': return 's'
    elif c == 'T': return 't'
    elif c == 'U': return 'u'
    elif c == 'V': return 'v'
    elif c == 'W': return 'w'
    elif c == 'X': return 'x'
    elif c == 'Y': return 'y'
    elif c == 'Z': return 'z'

def convertString(string):
    answer = ''        # answer는 입력 받을 문자를 초기화한 것
    for i in string:
        answer = answer + convertChar(i)
    return answer

main()
