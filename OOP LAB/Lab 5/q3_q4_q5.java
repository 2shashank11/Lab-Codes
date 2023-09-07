import java.util.*;

class student{
    int regNo;
    String fullName;
    GregorianCalendar joiningDate;
    short semester;
    float GPA, CGPA;

    student(int regNo, String fullName, GregorianCalendar joiningDate, short semester, float GPA, float CGPA){
        this.regNo = regNo;
        this.fullName = fullName;
        this.joiningDate = joiningDate;
        this.semester = semester;
        this.GPA = GPA;
        this.CGPA = CGPA;
    }

    void display(){
        System.out.println("Registration Number: " + regNo);
        System.out.println("Full Name: " + fullName);
        System.out.println("Joining Date (YYYY/MM/DD): " + joiningDate.get(GregorianCalendar.YEAR) + "/" + joiningDate.get(GregorianCalendar.MONTH) + "/" + joiningDate.get(GregorianCalendar.DATE));
        System.out.println("Semester: " + semester);
        System.out.println("GPA: " + GPA);
        System.out.println("CGPA: " + CGPA);
    }

    static void sortSemester(student s[]){
        for(int i=0; i<s.length; i++){
            for(int j=i; j<s.length; j++){
                if(s[i].semester>s[j].semester){
                    student temp = s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        System.out.println("\nSorted according to semester: ");
        for(int i=0; i<s.length; i++){
            System.out.print("\n");
            s[i].display();
        }
    }

    static void sortCGPA(student s[]){
        for(int i=0; i<s.length; i++){
            for(int j=i; j<s.length; j++){
                if(s[i].CGPA<s[j].CGPA){
                    student temp = s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        System.out.println("\nSorted according to CGPA: ");
        for(int i=0; i<s.length; i++){
            System.out.println("\n");
            s[i].display();
        }
    }

    static void sortName(student s[]){
        for(int i=0; i<s.length; i++){
            for(int j=i; j<s.length; j++){
                if(s[i].fullName.compareTo(s[j].fullName)>0){
                    student temp = s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        System.out.println("\nSorted according to Name: ");
        for(int i=0; i<s.length; i++){
            System.out.println("\n");
            s[i].display();
        }
    }

    static void searchCharacter(student s[], String c){
        System.out.println("\nDisplaying names starting with \"" + c + "\": " );
        for(int i=0; i<s.length; i++){
            if(s[i].fullName.charAt(0)==c.charAt(0)){
                System.out.println(s[i].fullName);
            }
        }
    }

    static void changeName(student s[]){
        for(int i=0; i<s.length; i++){
            String altName = "";
            String altNameArray[] = s[i].fullName.split(" ");
            for(int j=0; j<altNameArray.length-1; j++){
                altName += altNameArray[j].substring(0, 1);
                altName += ". ";
            }
            altName += altNameArray[altNameArray.length-1];
            s[i].fullName = altName;
        }

        System.out.println("\nDisplaying modified name: ");
        for(int i=0; i<s.length; i++){
            System.out.println(s[i].fullName);
        }
    }
}

class q3_q4_q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine();
        
        student s[] = new student[n];
        System.out.println("\nEnter the following details: ");

        for(int i=0; i<n; i++){
            System.out.println("\nSTUDENT: " + (i+1));
            System.out.print("Full Name: ");
            String fullName = sc.nextLine();
            System.out.print("Joining Date (YYYY/MM/DD): ");
            int year = sc.nextInt();
            int month = sc.nextInt();
            int day = sc.nextInt();
            GregorianCalendar joiningDate = new GregorianCalendar(year, month, day);
            sc.nextLine();

            System.out.print("Semester: ");
            short semester = sc.nextShort();
            System.out.print("GPA: ");
            float GPA = sc.nextFloat();
            System.out.print("CGPA: ");
            float CGPA = sc.nextFloat();
            sc.nextLine();

            String number = (Integer.toString(joiningDate.get(GregorianCalendar.YEAR))).substring(2) + Integer.toString(i+1);
            int regNo = Integer.parseInt(number);
            s[i] = new student(regNo, fullName, joiningDate, semester, GPA, CGPA);
        }

        System.out.println("\nDisplaying Entered data: ");
        for(int i=0; i<n; i++){
            System.out.println("\nSTUDENT " + (i+1) + ":");
            s[i].display();
        }

        student.sortSemester(s);
        student.sortCGPA(s);
        student.sortName(s);

        System.out.print("\nEnter initial character to search names: ");
        String c = sc.nextLine();
        student.searchCharacter(s, c);

        student.changeName(s);

        sc.close();
    }
}
