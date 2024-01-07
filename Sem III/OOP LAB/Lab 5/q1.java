import java.util.*;

class Employee{
    void formatEmployeeName(String name){
        name=name.toLowerCase();
        String cap = new String();
        for(int i=0; i<name.length(); i++){
            if(i==0 || name.charAt(i-1)== ' '){
                cap = cap + Character.toUpperCase(name.charAt(i));
            }
            else{
                cap = cap+name.charAt(i);
            }
        }
        System.out.println(cap);
    }

    void generateEmail(String name){
        name=name.toLowerCase();
        String domain = "@example.com";
        String email = new String();
        for(int i=0; i<name.length(); i++){
            if(i==0){
                email += name.charAt(i);
            }
            else if(name.charAt(i-1)==' '){
                while(i<name.length() && name.charAt(i)!=' '){
                    email += name.charAt(i);
                    i++;
                }
            }
        }
        email+=domain;
        System.out.println(email);
    }
}

class q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: "); 
        String name = sc.nextLine();
        Employee e = new Employee();
        e.formatEmployeeName(name);
        e.generateEmail(name);
    }
}