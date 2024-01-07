import java.util.*;

class Student{
    Scanner sc = new Scanner(System.in);

    int number;
    int[] marksArray = new int[10];
    int n;
    void getNumber(){
        System.out.print("Enter Roll No: ");
        this.number = sc.nextInt();
    }

    void putNumber(){
        System.out.println("Roll No: " + this.number);
    }

    void getMarks(){
        System.out.print("Enter number of subjects: ");
        this.n = sc.nextInt();
        for(int i=0; i<n; i++){
            marksArray[i]=sc.nextInt();
        }
    }

    void putMarks(){
        System.out.print("Marks: ");
        for(int i=0; i<n; i++){
            System.out.print(marksArray[i] + " ");
        }
        System.out.print("\n");
    }
}

interface Sports{
    void putGrade();
}

class Result extends Student implements Sports{
    String sGrade = "0";
    Result(){
        getNumber();
        getMarks();
        getGrade();
    }

    public void getGrade(){
        System.out.print("Enter sports grade: ");
        sGrade = sc.next();
    }

    public void putGrade(){
        System.out.print("Sports grade: " + sGrade);
    }

    void displayResult(){
        
        putNumber();
        putMarks();
        putGrade();
        System.out.println("\n");
    }
    
    
}

class Q4{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of Students: ");
        int n = sc.nextInt();
        Result[] obj = new Result[n];
        for(int i=0; i<n; i++){
            System.out.println("\nStudent " + (i+1));
            obj[i]=new Result();
        }

        System.out.println("\nResult: \n");
        for(int i=0; i<n; i++){
            obj[i].displayResult();
        }
        sc.close();
    }
}