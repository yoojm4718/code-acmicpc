class Stack:
    def __init__(self):
        self.__top = []
    
    def isEmpty(self): return len(self.__top) == 0
    def size(self): return len(self.__top)
    def clear(self): self.__top = []
    
    def push(self, item):
        self.__top.append(item)
    
    def pop(self):
        if not self.isEmpty():
            return self.__top.pop(-1)
    
    def peek(self):
        if not self.isEmpty():
            return self.__top[-1]
    
    def sum(self):
        return sum(self.__top)

def check_bracket(test):
    stack = Stack()
    
    result = True
    for i in test:
        if i == "(":
            stack.push(i)
        elif i == ")":
            if stack.peek() == "(":
                stack.pop()
            else:
                result = False
                break
    
    if result and not stack.isEmpty():
        result = False
    
    return result

T = int(input())

for _ in range(T):
    test = input()
    if check_bracket(test):
        print("YES")
    else:
        print("NO")
