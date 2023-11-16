

import java.util.Scanner;

public class Operator
{
    static
    {
        System.loadLibrary("Operator");
    }
        private native void add(int i,int j);
        private native void subtract(int i,int j);
        private native void multiply(int i,int j);
        private native void divide(int i,int j);
        
        public static void main(String args[])
        {
            int a,b;
            Scanner sc=new Scanner(System.in);
            Operator op= new Operator();
            System.out.println("Enter the inputs");
            a=sc.nextInt();
            b=sc.nextInt();
            op.add(a,b);
            op.subtract(a,b);
            op.multiply(a,b);
            op.divide(a,b);
        }
}

