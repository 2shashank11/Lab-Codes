import java.util.*;

class Stack{
    int arr[];
    int top=-1, maxSize;

    public void stack(int maxSize){
        this.maxSize=maxSize;
        arr = new int[maxSize];
    }

    boolean isFull(){
        if(top==this.arr.length-1) return true;
        else return false;
    }

    boolean isEmpty(){
    if(top==-1) return true;
    else return false;
    }

    public void push(int element){
        this.arr[++top]=element;
    }

    public int pop(){
            int temp = this.arr[top];
            this.arr[top--]=0;
            return temp;
    }

    public void display(){
        for(int i=0; i<=top; i++){
            System.out.print(arr[i] + " ");
        }
    }
}

public class integerStack {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        
        System.out.print("Enter maximum size of stack: ");
        int maxSize=sc.nextInt();
        s.stack(maxSize);
        
        while(true){
            System.out.println("\n");
            System.out.println("1. Push Element");
            System.out.println("2. Pop Element");
            System.out.println("3. Display stack");
            System.out.println("4. Exit");
            System.out.print("\nEnter your choice: ");
            int choice =sc.nextInt();

            if(choice==1){
                if(s.isFull()==false){
                    System.out.print("\nEnter element to push: ");
                    int element=sc.nextInt();
                    s.push(element);
                }
                else System.out.println("\nStack Overflow!!");;
                
            }

            else if(choice ==2){
                if(s.isEmpty()==false){
                    System.out.println("\nPopped " + s.pop() + " out of the stack");
                }
                else System.out.println("\nStack Underflow!!");
                
            }

            else if(choice==3){
                System.out.print("Displaying stack: ");
                s.display();
            }

            else if(choice==4){
                break;
            }

            else System.out.println("Select correct option!");
        }
        sc.close();
    }
}
