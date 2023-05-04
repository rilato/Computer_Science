# 1번 B735365 이윤식

def main():
    box1 = Rectangle(0, 0, 100, 100)
    box2 = Rectangle(10, 10, 200, 200)
    print("box: ", box1)
    print("box: ", box2)
    box1.calcArea()
    box2.calcArea()

class Rectangle:
    def __init__(self, x = 1, y = 1, w = 1, h = 1):
        self.__x = x
        self.__y = y
        self.__w = w
        self.__h = h
    def calcArea(self):
        print(self.__w * self.__h)
    def __str__(self):
        return '(%d,%d) %d,%d' %(self.__x, self.__y, self.__w, self.__h)


main()
