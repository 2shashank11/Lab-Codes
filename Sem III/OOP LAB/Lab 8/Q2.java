import java.util.*;

class invalidDayException extends Throwable{
    public String toString(){
        return "\nInvalid Day, Please enter again!\n";
    }
}

class invalidMonthException extends Throwable{
    public String toString(){
        return "\nInvalid Month, Please enter again!\n";
    }
}

class CurrentDate{
    int day, month, year;

    Scanner sc = new Scanner(System.in);
    void createDate() throws invalidDayException, invalidMonthException{
        System.out.print("Enter Day(DD): ");
        this.day=sc.nextInt();
        if(this.day>31) throw new invalidDayException();

        System.out.print("Enter Month(MM): ");
        this.month=sc.nextInt();
        if(this.month>12) throw new invalidMonthException();

        System.out.print("Enter year(YYYY): ");
        this.year=sc.nextInt();

        display();

    }

    void display(){
            System.out.println("\nEntered date(DD/MM/YYYY): " +this.day + "/" + this.month + "/" + this.year);
        }
}

class Q2{
    public static void main(String[] args) {
        CurrentDate d = new CurrentDate();
        while(true){
            try{
                d.createDate();
                break;
            }

            catch (invalidDayException e){
                System.out.println(e);
            }

            catch (invalidMonthException e){
                System.out.println(e);
            }
        }
    }
}