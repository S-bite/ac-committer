// This file is a "Hello, world!" in Java language by OpenJDK for wandbox.

import java.util.*;

class Main
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        ArrayList<Integer> v = new ArrayList<>(n);
        for (int i=0;i<n;i++){
            v.add(new Integer(scan.nextInt()));
            //v[i]=scan.nextInt();
        }
        ArrayList<Integer> w = new ArrayList<>(v);
        Collections.sort(v);        
        int med1=v.get(n/2);
        int med2=v.get(n/2-1);
        for(int i=0;i<n;i++){
            if (w.get(i)<med1){
                System.out.println(med1);
            }else{
                System.out.println(med2);
            }
        }
    }
}

// OpenJDK reference:
//   http://openjdk.java.net/

// Java language references:
//   http://docs.oracle.com/javase
