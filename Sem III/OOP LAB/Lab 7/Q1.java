import com.course.structure.*;
import java.util.*;

class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        school obj = new school();

        System.out.println("Enter the following Details: \n");
        System.out.print("Square Footage: ");
        double squareFootage = sc.nextDouble();
        obj.setSquareFootage(squareFootage);

        System.out.print("Stories: ");
        int stories = sc.nextInt();
        obj.setStories(stories);

        System.out.println("\nSelect the correct option:");
        System.out.println("1. House");
        System.out.println("2. School");
        System.out.print("Option: ");
        int choice = sc.nextInt();

        if(choice==1){
            System.out.print("\nBedrooms: ");
            int bedrooms = sc.nextInt();
            obj.setBedrooms(bedrooms);

            System.out.print("Bathrooms: ");
            int bathroms = sc.nextInt();
            obj.setBathrooms(bathroms);
        }

        else if (choice==2){
            System.out.print("\nClassrooms: ");
            int classrooms = sc.nextInt();
            obj.setClasrooms(classrooms);

            System.out.print("Grade Level: ");
            sc.nextLine();
            String gradeLevel = sc.nextLine();
            obj.setGradeLevel(gradeLevel);
        }

        obj.display(choice);

        sc.close();
    }
}