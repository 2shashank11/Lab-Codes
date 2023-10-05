import myPackages.p1.*;
import java.util.*;

class Q2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Maximum obj = new Maximum();

        System.out.print("Enter 3 integers: ");
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        System.out.println("Max integer: " + Maximum.max(a, b, c));

        System.out.print("\nEnter 3 float: ");
        float d=sc.nextFloat();
        float e=sc.nextFloat();
        float f=sc.nextFloat();
        System.out.println("Max float: " + Maximum.max(d, e, f));

        System.out.print("\nEnter array length: ");
        int n=sc.nextInt();
        int g[] = new int[n];
        System.out.println("Enter array: ");
        for(int i=0; i<n; i++){
            g[i]=sc.nextInt();
        }
        System.out.println("Max in array: " + Maximum.max(g));

        System.out.print("\nEnter number of rows and columns: ");
        int p=sc.nextInt();
        int q=sc.nextInt();
        int h[][] = new int[p][q];
        System.out.println("Enter matrix: ");
        for(int i=0; i<p; i++){
            for(int j=0; j<q; j++){
                h[i][j]=sc.nextInt();
            }
        }
        System.out.println("Max in matrix: " + Maximum.max(h));
    }
}