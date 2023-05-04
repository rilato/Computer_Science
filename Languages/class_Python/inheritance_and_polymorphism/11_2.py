# 2번 B735365 이윤식

class Shape:
    def __init__(self, color = "yellow", filled = True):
        self.__color = color
        self.__filled = filled
        
    def SetColor(self, color):
        self.__color = color
    def GetColor(self):
        return self.__color
    def SetFilled(self, filled):
        self.__filled = filled
    def GetFilled(self):
        return self.__filled

class Rectangle(Shape):
    def __init__(self, color, filled, width = 0, height = 0):
        super().__init__(color, filled)
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def __str__(self):
        return f'({self.GetColor()},{self.GetFilled()})({self.width},{self.height})'

def main():
    c = Rectangle("blue", False, 10, 20)
    print(c)
    print(c.area())
main()
