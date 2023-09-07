import java.util.*;

class STUDENT {
    String sName;
    double marksArray[];
    double total;
    double average;

    void assign(String sName, double marksArray[]) {
        this.sName = sName;
        this.marksArray = marksArray;
    }

    void display() {
        System.out.println("Name: " + this.sName);
        System.out.print("Marks: ");
        for (double m : marksArray) {
            System.out.print(m + ", ");
        }
        System.out.println("\nTotal: " + this.total);
        System.out.println("Average: " + this.average);
    }

    void compute() {
        double total = 0;
        for (int i = 0; i < this.marksArray.length; i++) {
            total += marksArray[i];
        }
        this.total = total;
        this.average = (total / marksArray.length);
    }
}

class students {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        String sName = sc.next();
        System.out.print("Enter number of subjects: ");
        int arrayLength = sc.nextInt();
        double marksArray[] = new double[arrayLength];
        System.out.println("Enter marks: ");
        for (int i = 0; i < arrayLength; i++) {
            marksArray[i] = sc.nextInt();
        }
        STUDENT s = new STUDENT();
        s.assign(sName, marksArray);
        s.compute();
        s.display();
    }
}