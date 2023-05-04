# 2번 B735365 이윤식

def main():
    a = Point()
    b = Point(1,5)
    print("a =", a)
    a.move(2,3)
    b.move(4,3).move(-1,-2)
    print("a =", a, "B =", b)
    
class Point:
    def __init__(self, x = 0, y = 0):
        self.__x = x
        self.__y = y

    def move(self, a = 0, b = 0):
        self.__x += a
        self.__y += b

        return self
    def __str__(self):
        return f'({self.__x}, {self.__y})'


main()
