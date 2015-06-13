from Queue import Queue

class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.q = Queue()

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.q.put(x)

    # @return nothing
    def pop(self):
        p = Queue()
        while self.q.empty() is not True:
            if self.q.qsize() == 1:
                break
            p.put(self.q.get())
        self.q = p

    # @return an integer
    def top(self):
        p = Queue()
        while self.q.empty() is not True:
            if self.q.qsize() == 1:
                tmp = self.q.get()
                p.put(tmp)
                self.q = p
                return tmp
            p.put(self.q.get())

    # @return an boolean
    def empty(self):
        return self.q.empty()
