# 7번 B735365 이윤식

def main() :
    a = Complex(3.0,-4.5)
    b = Complex(4.0, -5.0)
    c = Complex(-1.0, 0.5)
    print(a+b)
    print(a+b-c)
    print(a-b)
    print(a-b+c)
    print(a-c)
    print(b == (a-c))

class Complex:
    def __init__ (self, x, y):
        self.__x = x
        self.__y = y
    def __add__ (self, other):
        x = self.__x + other.__x
        y = self.__y + other.__y
        return Complex(x, y)
    def __sub__ (self, other):
        x = self.__x - other.__x
        y = self.__y - other.__y
        return Complex(x, y)
    def __eq__ (self, other):
        return self.__x == other.__x and self.__y == other.__y
    def __str__ (self):
        return f'Complex({self.__x},{self.__y})'
    
main()
