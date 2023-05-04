# 1번 B735365 이윤식

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
    
    def __str__(self):
        return f'({self.__color},{self.__filled})'
    
class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.radius = radius
        
    def area(self):
        return self.radius * self.radius * 3.14
    
    def __str__(self):
        return f'({self.GetColor()},{self.GetFilled()})(radius = {self.radius})'
    
    
def main():
    a = Shape()
    b = Shape("red")
    print(a,b)
    c = Circle("blue", False, 10)
    print(c)
    print(c.area())
main()
