class counter{
    static int c=0;

    counter(){
        c++;
    }

    static void showCount(){
        System.out.println("Number of objects created: " + c);
    }
}

public class objectCounter {
    public static void main(String args[]){

        counter c1 = new counter();
        counter c2 = new counter();
        counter c3 = new counter();
        counter c4 = new counter();

        counter.showCount();
    }
}
