# 3번 B735365 이윤식

def main():
    a = Dog('윌시코기', '바둑이')
    b = Dog('푸들', '멍멍이')
    a.add_trick('뒹굴기')
    b.add_trick('달리기')
    b.add_trick('점프하기')
    print(a)
    print(b)
    
class Dog:
    def __init__(self, kind, name):
        self.__kind = kind
        self.__name = name
        self.trickList = []
    def setKind(self, kind):
        self.__kind = kind
    def getKind(self):
        return self.__kind
    def setName(self, name):
        self.__name = name
    def getName(self):
        return self.__name
    def add_trick(self, trick):
        self.trickList.append(trick)
    def __str__(self):
        tricks = ' '.join(i for i in self.trickList)
        return f'{self.__kind} {self.__name}는 {tricks}를 할 수 있습니다'

main()
