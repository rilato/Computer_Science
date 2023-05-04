# 4번 B735365 이윤식

def main():
    a = Employee("사장", 1200)
    b = Employee("김수철", 300)
    c = Employee("이영애", 600)
    
    print(a)
    print(b)
    print(c)
    
class Employee:
    serialNumber = 0
    def __init__(self, name, salary):
        Employee.serialNumber += 1
        self.__number = Employee.serialNumber
        self.__name = name
        self.__salary = salary
    def __str__(self):
        return f'SN : {self.__number} 이름 : {self.__name} 월급 : {self.__salary}'

main()
