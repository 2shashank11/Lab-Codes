import java.util.*;
class STUDENT{
    String sName="Nan";
    double marksArray[]={0};
    double total=0, average=0;

    STUDENT(){
        System.out.println("\nDisplaying default values: ");
        System.out.println("\nName: " + this.sName);
        System.out.print("Marks: ");
        for (double m : marksArray){
            System.out.print(m + ", ");
        }
        System.out.println("\nTotal: " + this.total);
        System.out.println("Average: " + this.average);
    }

    STUDENT(String sName, double marksArray[]){
        this.sName=sName;
        this.marksArray=marksArray;
    }

    void display(){
        System.out.println("\nDisplaying student details: ");
        System.out.println("\nName: " + this.sName);
        System.out.print("Marks: ");
        for (double m : marksArray){
            System.out.print(m + ", ");
        }
        System.out.println("\nTotal: " + this.total);
        System.out.println("Average: " + this.average);
    }

    void compute(){
        double total=0;
        for (int i=0; i<this.marksArray.length; i++){
            total+=marksArray[i];
        }
        this.total=total;
        this.average=(total/marksArray.length);
    }
}

class std{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        STUDENT sDefault = new STUDENT();       //Default constructor
        System.out.println("\nEnter student details: ");
        System.out.print("Enter name: ");
        String sName = sc.next();
        System.out.print("Enter number of subjects: ");
        int arrayLength = sc.nextInt();
        double marksArray[] = new double[arrayLength];
        System.out.println("Enter marks: ");
        for(int i=0; i<arrayLength; i++){
            marksArray[i] = sc.nextInt();
        }
        STUDENT s = new STUDENT(sName, marksArray);     //Parameterized constructor
        s.compute();
        s.display();
        sc.close();
    }
}