# 5번 B735365 이윤식


def main():
    Employee("사장", 1200)
    Employee("김수철", 300)
    Employee("이영애", 600)
    
    for i in Employee("장동철", 400).employeeList:
        print(i)
    
class Employee:
    employeeList = []
    serialNumber = 0
    def __init__(self, name, salary):
        Employee.serialNumber += 1
        self.__number = Employee.serialNumber
        self.__name = name
        self.__salary = salary
        a = f'SN : {self.__number} 이름 : {self.__name} 월급 : {self.__salary}'
        Employee.employeeList.append(a)

main()
