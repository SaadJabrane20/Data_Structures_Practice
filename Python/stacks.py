class Stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, val):
        self.stack.append(val)
        print(f"{val} pushed onto stack")

    def pop(self):
        if not self.is_empty():
            val = self.stack.pop()
            print(f"Popped: {val}")
            return val
        else:
            print("Stack Underflow!")
            return None

    def peek(self):
        if not self.is_empty():
            print(f"Top element: {self.stack[-1]}")
            return self.stack[-1]
        else:
            print("Stack is empty!")
            return None

    def display(self):
        if not self.is_empty():
            print("Stack elements:", self.stack)
        else:
            print("Stack is empty!")

s = Stack()
s.push(5)
s.push(4)
s.push(3)
s.peek()
s.display()
s.pop()
s.display()
