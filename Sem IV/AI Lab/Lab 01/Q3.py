import math

def main():
    x=list(eval(input("Enter list 1: ")))
    y=list(eval(input("Enter list 2: ")))

    a=[]

    for i in range(0, len(x)):
        a.append(math.pow((y[i]-x[i]), 2))

    print(a)

    for i in range(0, len(a)):
        for j in range(i+1, len(a)):
            if(a[i]>a[j]):
                temp=a[i]
                a[i]=a[j]
                a[j]=temp 

    print(a)   

if(__name__=="__main__"):
    main()