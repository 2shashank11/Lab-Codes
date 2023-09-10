import java.util.*;

class STUDENT{
    String sName="Nan";
    double marksArray[]={0};
    double total=0, average=0;

    void initialize(String sName, double marksArray[]){
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

class scienceStudent extends STUDENT{
    private int practicalMarks;

    void setpracticalMarks(int marks){
        this.practicalMarks = marks;
    }

    void compute(){
        double total=0;
        for (int i=0; i<super.marksArray.length; i++){
            total+=marksArray[i];
        }
        super.total=total+practicalMarks;
        super.average=(super.total/(marksArray.length+1));
    }

    void displaypracticalMarks(){
        System.out.println("Practical marks : " + practicalMarks);
    }
}

class artStudent extends STUDENT{
    private String electiveSubject;

    void setSubject(String subject){
        this.electiveSubject = subject;
        System.out.println(electiveSubject);
    }

    void displayElectiveSubject(){
        System.out.println("Elective Subject: " + electiveSubject);
    }
}

class q1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter student details: ");
        System.out.print("Enter name: ");
        String sName = sc.nextLine();
        System.out.print("Enter number of subjects: ");
        int arrayLength = sc.nextInt();
        double marksArray[] = new double[arrayLength];
        System.out.println("Enter marks: ");
        for(int i=0; i<arrayLength; i++){
            marksArray[i] = sc.nextInt();
        }
        System.out.println("Select correct option: ");
        System.out.println("1. Science Student");
        System.out.println("2. Arts Student");
        System.out.print("Choice: ");
        int choice = sc.nextInt();
        if (choice==1){
            System.out.print("Enter practical marks: ");
            int practicalMarks = sc.nextInt();
            scienceStudent scStd = new scienceStudent();
            scStd.setpracticalMarks(practicalMarks);
            scStd.initialize(sName, marksArray); 
            scStd.compute();
            scStd.display();
            scStd.displaypracticalMarks();
        }
        else if (choice==2){
            System.out.print("Enter elective subject: ");
            sc.next();
            String electiveSubject = sc.nextLine();
            artStudent artStd = new artStudent();
            artStd.setSubject(electiveSubject);
            artStd.initialize(sName, marksArray); 
            artStd.compute();            
            artStd.display();
            artStd.displayElectiveSubject();
        }
    }
}