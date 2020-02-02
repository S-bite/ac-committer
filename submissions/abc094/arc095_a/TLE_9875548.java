// This file is a "Hello, world!" in Java language by OpenJDK for wandbox.

import java.util.*;

class Main
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        Integer n=scan.nextInt();
        LinkedList<Integer> v = new LinkedList<>();
        for (int i=0;i<n;i++){
            v.add(new Integer(scan.nextInt()));
        }
        LinkedList<Integer> w = new LinkedList<>(v);
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
