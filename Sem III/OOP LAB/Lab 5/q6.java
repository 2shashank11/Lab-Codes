import java.util.*;

class q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string: ");
        String number = sc.nextLine();
        int q = number.length()/3;
        int r = number.length()%3;
        String updatedNumber = "";
        if(r!=0){
            updatedNumber += number.substring(0, r);
            updatedNumber += ",";
            for(int i=0; i<q; i++){
                updatedNumber += number.substring((i)*3+r, (i+1)*3+r);
                if(i!=q-1) updatedNumber += ",";
            }
        }
        else{
            for(int i=0; i<q; i++){
                updatedNumber += number.substring(i*3, (i+1)*3);
                if(i!=q-1) updatedNumber += ",";
            }
        }
        System.out.println(updatedNumber);
        sc.close();
    }    
}