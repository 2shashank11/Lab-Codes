import java.util.*;

interface Series{
    int[] getNext();
    void reset();
    void setStart();
}

class ByTwos implements Series{
    int index=-1;
    int a[] = new int[100];
    int start=0;
    public int[] getNext(){
        if(index==-1){
            a[index+1]=start;
        }
        else a[index+1]=a[index]+2;
        index++;
        return a;
    }

    public void reset(){
        for(int i=0; i<a.length; i++){
            a[i]=0;
        }
        this.index=-1;
    }

    public void setStart(){
        reset();
        a[++index]=start;
    }
}

class Q3{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ByTwos obj = new ByTwos();
        while (true){
            System.out.println("\n");
            System.out.println("1. Insert next element");
            System.out.println("2. Reset");
            System.out.println("3. Set Start");
            System.out.print("Choice: ");
            int choice = sc.nextInt();

            if(choice==1){
                int[] a = new int[100];
                a = obj.getNext();
                for(int i=0; i<=obj.index; i++){
                    System.out.print(a[i] + " ");
                }
            }
            else if (choice==2){
                obj.reset();
            }
            else if(choice==3){
                System.out.print("Enter start: ");
                obj.start=sc.nextInt();
                obj.setStart();
            }
            else System.out.println("\nEnter valid option");
        }
    }
}