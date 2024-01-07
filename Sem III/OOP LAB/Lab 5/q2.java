import java.util.*;

class STUDENT{
    int n;
    String names[];

    Scanner sc = new Scanner(System.in);

    void extractInitials(){
        System.out.println("\nDisplaying Initials: ");
        for(int i=0; i<this.n; i++){
            String init = "";
            for(String s : names[i].split(" ")){
                init += s.charAt(0);
            }
            System.out.println(init);
        }
    }

    void removeWhitespace(){
        System.out.println("Displaying names without whitespaces: ");
        for(int i=0; i<this.n; i++){
            String name="";
            for(String s : names[i].split(" ")){
                name += s;
            }
            System.out.println(name);
        }
    }

    void find(){
        System.out.print("\nEnter substring to search: ");
        String substr = sc.nextLine();
        System.out.println("\nFollowing names contain \""+substr+"\":");
        for(int i=0; i<this.n; i++){
            if(names[i].contains(substr)){
                System.out.println(names[i]);
            }    
        }
    }

    void sort(){
        for(int i=0; i<this.n; i++){
            for(int j=i; j<this.n; j++){
                if(names[i].compareTo(names[j])>0){
                    String temp = names[i];
                    names[i]=names[j];
                    names[j]=temp;
                }
            }
        }
        System.out.println("\nDisplaying sorted Students:");
        for(int i=0; i<this.n; i++){
            System.out.println(names[i]);
        }
    }
}

class q2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        STUDENT s = new STUDENT();
        System.out.print("Enter number of students: ");
        s.n = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter students names: ");
        s.names = new String[s.n];
        for(int i=0; i<s.n; i++){
            s.names[i]=sc.nextLine();
        }
        s.extractInitials();
        s.removeWhitespace();
        s.find();
        s.sort();
        sc.close();
    }
}