# 6번 B735365 이윤식

def main():
    a = BankAccount("김철수", "82345", 1000)
    print(a)
    print("Interest Rate =", BankAccount.interest_rate,
          "Maturity : ", a.maturityAmount())
    a.deposit(3000)
    print(a)
    a.withdraw(1500)
    print(a)
    BankAccount.interest_rate = 0.7
    print("Interest Rate =", BankAccount.interest_rate,
          "Maturity : ", a.maturityAmount())

class BankAccount:
    interest_rate = 0.3
    def __init__(self, name, number, balance):
        self.__name = name
        self.__number = number
        self.__balance = balance
    def deposit(self, a):
        self.__balance += a
    def withdraw(self, b):
        self.__balance -= b
    def maturityAmount(self):
        return self.__balance * (1 + BankAccount.interest_rate)
    def __str__(self):
        return f'Name:{self.__name} Number : {self.__number}, Balance : {self.__balance}'

main()
