import java.util.*;

class OverflowException extends Throwable{
    public String toString(){
        return "\nStack overflow!!";
    }
}

class UnderflowException extends Throwable{
    public String toString(){
        return "\nStack underflow!!";
    }
}

class stack{
    int a[];
    int top=-1, size;

    stack(int size){
        this.size = size;
        this.a = new int[size];
    }

    Scanner sc = new Scanner(System.in);

    void push() throws OverflowException{
        if(top==size-1) throw new OverflowException();
        else{
            System.out.print("Enter element: ");
            int element = sc.nextInt();
            a[++top]=element;
        }
    }

    int pop() throws UnderflowException{
        if(top==-1) throw new UnderflowException();
        else{
            int element=a[top--];
            return element;
        }
    }

    void display(){
        System.out.print("Stack: ");
        for(int i=0; i<=top; i++){
            System.out.println(a[i] + " ");
        }
    }
}

class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size=sc.nextInt();
        stack s = new stack(size);
        while(true){            
            System.out.print("\n1. Push \n2. Pop \n3. Display \n4. Exit \nChoice: ");
            int choice = sc.nextInt();

            if(choice==1){
                try{
                    s.push();
                }
                catch(OverflowException e){
                    System.out.println(e);
                }
            }

            else if(choice==2){
                try {
                    System.out.println("Popped: " + s.pop());
                } catch (UnderflowException e) {
                    System.out.println(e);
                }
            }

            else if(choice==3){
                s.display();
            }

            else if(choice==4){
                break;
            }

            else System.out.println("\nEnter a valid option!!\n");
        }
        sc.close();
    }
}
