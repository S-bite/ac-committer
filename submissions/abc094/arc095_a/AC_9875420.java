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
        }
        ArrayList<Integer> w = new ArrayList<>(v);
        Collections.sort(v);        
        int med=v.get(n/2);
        for(int i=0;i<n;i++){
            if (w.get(i)<med){
                System.out.println(v.get(n/2));
            }else{
                System.out.println(v.get(n/2-1));
            }
        }
    }
}

// OpenJDK reference:
//   http://openjdk.java.net/

// Java language references:
//   http://docs.oracle.com/javase
