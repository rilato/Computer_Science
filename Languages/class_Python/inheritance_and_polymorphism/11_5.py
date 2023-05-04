# 5번 B735365 이윤식

class CPoint:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    
    def move(self, a, b):
        self.x += a
        self.y += b
        return self
    
    def __str__(self):
        return f'pos({self.x},{self.y})'

class Shape:
    def __init__(self, color = "yellow", filled = True, x = 0, y = 0):
        self.__color = color
        self.__filled = filled
        self.x = x
        self.y = y
        
        self.radius = 0
        self.height = 0
        self.width = 0
 
    def GetColor(self):
        return self.__color
    
    def GetFilled(self):
        return self.__filled
    
    def newObject(self, radius = 0, width = 0, height = 0, cpoint = 0):
        self.radius = Circle.radius
        self.height = Rectangle.height
        self.width = Rectangle.width
        self.cpoint = CPoint()
        
    def move(self, a, b):
        self.x += a
        self.y += b
        
        if self.radius > 0:
            return f'pos({self.x},{self.y})({self.__color},{self.__filled})(radius = {self.radius})'
        if self.height > 0:
            return f'pos({self.x},{self.y})({self.__color},{self.__filled})({self.width},{self.height})'
        else:
            return f'pos({self.x},{self.y})({self.__color},{self.__filled})'   
        
    def __str__(self):
        return f'pos({self.x},{self.y})({self.__color},{self.__filled})'
    
class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.radius = radius
        
    def area(self):
        return self.radius * self.radius * 3.14
    
    def __str__(self):
        return f'({self.GetColor()},{self.GetFilled()})(radius = {self.radius})'

class Rectangle(Shape):
    def __init__(self, color, filled, width = 0, height = 0):
        super().__init__(color, filled)
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def __str__(self):
        return f'({self.GetColor()},{self.GetFilled()})({self.width},{self.height})'


def main() :
    a = Shape()
    b = Shape("red")
    cpoint = CPoint(4,7)
    c = Shape("black",False,cpoint)
    print(a)
    print(b)
    print(c)
    a.move(2,3)
    print(a)
    print(b.move(4,5))
    d = Circle("blue",False,10).move(3,4)
    print(d)
    e = Rectangle("blue",False,10,20)
    print(e.move(7,8))
main()


class CPoint:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    
    def move(self, a, b):
        self.x += a
        self.y += b
        return self
    
    def __str__(self):
        return f'pos({self.x},{self.y})'
    
class Shape:
    def __init__(self, color = "yellow", filled = True, cpoint = None):
        self.__color = color
        self.__filled = filled
        if cpoint == None:
            self.cpoint = CPoint()
        else:
            self.cpoint = cpoint
            
    def move(self,z,w):
        self.cpoint = self.cpoint.move(z,w)
        return self
    
    def __str__(self):
        return f'{self.cpoint}({self.__color},{self.__filled})'


    
class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.radius = radius
        
    def area(self):
        return self.radius * self.radius * 3.14
    
    def __str__(self):
        return super().__str__() + f'(radius = {self.radius})'
    
class Rectangle(Shape):
    def __init__(self, color, filled, width = 0, height = 0):
        super().__init__(color, filled)
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def __str__(self):
        return super().__str__() + f'({self.width},{self.height})'
    
def main() :
    a = Shape()
    b = Shape("red")
    cpoint = CPoint(4,7)
    c = Shape("black",False,cpoint)
    print(a)
    print(b)
    print(c)
    a.move(2,3)
    print(a)
    print(b.move(4,5))
    d = Circle("blue",False,10).move(3,4)
    print(d)
    e = Rectangle("blue",False,10,20)
    print(e.move(7,8))
main()
