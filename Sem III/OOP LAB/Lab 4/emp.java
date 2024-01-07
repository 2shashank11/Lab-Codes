import java.time.LocalTime;
import java.util.*;
class EMPLOYEE{
    String Ename="NaN";
    int Eid=0;
    double Basic=0;
    LocalTime empTime = LocalTime.now();
    

    EMPLOYEE(){
        System.out.println("Displaying default details: ");
        System.out.println("Employee Name: " + this.Ename);
        System.out.println("Employee ID: " + this.Eid);
        System.out.println("Base: " + this.Basic);
    }

    EMPLOYEE (String Ename, int Eid, double Basic, LocalTime empTime){
        this.Ename=Ename;
        this.Eid=Eid;
        this.Basic=Basic;
        this.empTime=empTime;
    }

    void display(){
        System.out.println("Employee Name: " + this.Ename);
        System.out.println("Employee ID: " + this.Eid);
        System.out.println("Base: " + this.Basic);
        System.out.println("Time: " + this.empTime);
    }

    double compute_net_sal(){
        double total= 0.7*(1.52*Basic);
        return total;
    }
}

class emp {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        EMPLOYEE emp = new EMPLOYEE();  //Default constructor
        System.out.print("\nEnter number of employees: ");
        int numberOfEmployee = sc.nextInt();
        EMPLOYEE e[] = new EMPLOYEE[numberOfEmployee];

        for(int i=0; i<numberOfEmployee; i++){
            System.out.println("\nEnter Employee " + (i+1) + " details: ");
            System.out.print("Name: ");
            String Ename = sc.next();
            System.out.print("Employee ID: ");
            int Eid= sc.nextInt();
            System.out.print("Base salary: ");
            double Basic = sc.nextDouble();
            LocalTime empTime = LocalTime.now();
            e[i] = new EMPLOYEE(Ename, Eid, Basic, empTime); //Parameterized constructor
        }
        
        for(int i=0; i<numberOfEmployee; i++){
            System.out.println("\nEmployee " + (i+1) + ": ");
            e[i].display();
            System.out.println("Total salary: " + e[i].compute_net_sal());
        }
        sc.close();
    }
}