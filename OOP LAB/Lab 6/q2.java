import java.util.*;
class EMPLOYEE{
    String Ename;
    int Eid;
    double Basic;
    double totalSalary=calculateSalary();

    void initialize (String Ename, int Eid){
        this.Ename=Ename;
        this.Eid=Eid;
    }

    void displayEmployeeDetails(){
        System.out.println("Employee Name: " + this.Ename);
        System.out.println("Employee ID: " + this.Eid);
        System.out.println("Net Salary: " + this.totalSalary);
    }

    double calculateSalary(){
        double total= 0.7*(1.52*Basic);
        return total;
    }
}

class fullTimeEmployee extends EMPLOYEE{
    double bonus, deduction;
    double netSalary = calculateSalary();

    double calculateSalary(){
        netSalary = 0.7*(1.52*super.Basic)+bonus-deduction;
        return netSalary;
    }

    void displayEmployeeDetails(){
        System.out.println("Name: " + super.Ename);
        System.out.println("Employee ID: " + super.Eid);
        System.out.println("Net Salary: " + calculateSalary());
    }
}

class partTimeEmployee extends EMPLOYEE{
    int hoursWorked;
    final static double hourlyRate = 200;
    double netSalary=calculateSalary();

    double calculateSalary(){
        netSalary=hoursWorked*hourlyRate;
        return netSalary;
    }
    
    void displayEmployeeDetails(){
        System.out.println("Name: " + super.Ename);
        System.out.println("Employee ID: " + super.Eid);
        System.out.println("Net Salary: " + calculateSalary());
    }
}

class q2 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Name: ");
        String Ename = sc.next();
        System.out.print("Employee ID: ");
        int Eid= sc.nextInt();

        System.out.println("Choose correct option: ");
        System.out.println("1. Full Time Employee");
        System.out.println("2. Part Time Employee");
        System.out.print("Option: ");
        int option = sc.nextInt();

        if(option == 1){
            fullTimeEmployee fte = new fullTimeEmployee();
            fte.initialize(Ename, Eid);
            System.err.print("Enter Base Salary: " );
            fte.Basic = sc.nextDouble();
            System.out.print("Enter Bonuses: ");
            fte.bonus = sc.nextDouble();
            System.out.print("Enter Deductions: ");
            fte.deduction = sc.nextDouble();
            System.out.println("\nDisplaying Employee Details: ");
            fte.displayEmployeeDetails();
        }
        else if(option == 2){   
            partTimeEmployee pte = new partTimeEmployee();
            pte.initialize(Ename, Eid);
            System.out.print("Enter total hours worked: ");
            pte.hoursWorked = sc.nextInt();
            System.out.println("\nDisplaying Employee Details: ");
            pte.displayEmployeeDetails();
        }
        sc.close();
    }
}