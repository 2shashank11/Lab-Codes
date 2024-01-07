import java.util.*;

class account{
    String name="Nan";
    long accNumber=0;
    String accType="NaN";
    double balance=0;
    static int rateOfInterest = 5;

    account(){
        System.out.println("Displaying default value: ");
        System.out.println("Name: " + this.name);
        System.out.println("Account number: " + this.accNumber);
        System.out.println("Balance: " + this.balance);
    }

    account(String name, long accNumber, String accType, double balance){
        this.name=name;
        this.accNumber=accNumber;
        this.accType = accType;
        this.balance=balance;
    }

    void display(){
        System.out.println("\nDisplaying user details: ");
        System.out.println("Name: " + this.name);
        System.out.println("Account number: " + this.accNumber);
        System.out.println("Balance: Rs " + this.balance);
    }

    void viewBalance(){
        System.out.println("\nRemaining balance: Rs " + this.balance);
    }

    void withdrawAmount(long amt){
        System.out.println("\nWithdrawn Rs " + amt);
        this.balance-=amt;
        System.out.println("Remaining balance: Rs " + this.balance);
    }

    void depositAmount(long amt){
        System.out.println("\nDeposited Rs " + amt);
        this.balance+=amt;
        System.out.println("Remaining balance: Rs " + this.balance);
    }

    static void displayROI(){
        System.out.println("\nRate of interest is: " + rateOfInterest + "%");
    }

}

public class bankAccount {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 1 to input bank details: ");
        int select = sc.nextInt();
        if(select==1){
            System.out.print("Name: ");
            String name = sc.next();
            System.out.print("Account number: ");
            long accNumber=sc.nextLong();
            System.out.print("Account type: ");
            String accType = sc.next();
            System.out.print("Balance: ");
            double balance = sc.nextDouble();

            account acc = new account(name, accNumber, accType, balance);

            while(true){
                System.out.println("\nSELECT ANY OPTION: ");
                System.out.println("1. View Bank details");
                System.out.println("2. View Balance");
                System.out.println("3. Deposit amount");
                System.out.println("4. Withdraw amount");
                System.out.println("5. View Rate of interest");
                System.out.println("6. Exit");
                System.out.print("Enter option: ");
                int choice = sc.nextInt();
                if (choice==1){
                    acc.display();
                }
                else if (choice==2){
                    acc.viewBalance();
                }
                else if(choice==3){
                    System.out.print("\nEnter amount to deposit: ");
                    long amount = sc.nextInt();
                    acc.depositAmount(amount);
                }
                else if (choice==4){
                    System.out.print("\nEnter amount to withdraw: ");
                    long amount = sc.nextInt();
                    if(acc.balance>amount){
                        acc.withdrawAmount(amount);
                    }
                    else System.out.println("\nInsufficient Balance!");
                }
                else if(choice==5){
                    account.displayROI();
                }
                else if(choice==6) break;
                else System.out.println("\nSelect a valid option!");;
            }
        }
        else{
            account accDefault = new account();
        }
        sc.close();
    }
}
