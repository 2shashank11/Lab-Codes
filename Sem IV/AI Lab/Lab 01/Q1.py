class Queue:
    def __init__(self):
        self.queue=[]
    
    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self, s2):
        if(len(s2.queue)==0):
            while(len(self.queue)!=0):
                s2.queue.append(self.queue.pop())
        dequeued=s2.queue.pop()
        while(len(s2.queue)!=0):
            self.queue.append(s2.queue.pop())
        return dequeued

def main():
    s1 = Queue()
    s2 = Queue()

    print("1. Enqueue \n2. Dequeue \n3. Display \n4. Exit")
    while (True):
        choice=int(input("\nEnter choice: "))

        if(choice==1):
            item = int(input("Enter item: "))
            s1.enqueue(item)
        
        elif(choice==2):
            print("Dequeued: ", s1.dequeue(s2))

        elif(choice==3):
            print("Queue: ", s1.queue)
        
        elif(choice==4):
            break

        else:
            print("Enter correct choice!!")

if(__name__=="__main__"):
    main()