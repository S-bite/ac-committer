// This file is a "Hello, world!" in Java language by OpenJDK for wandbox.
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
		int k = parseInt(sc.next());
		int s = parseInt(sc.next());
		sc.close();
        int ans=0;
        for (int a=0;a<=k;a++){
            for (int b=0;b<=k;b++){
                if (s-a-b<=k && s-a-b>=0){
                    ans++;
                }
            }
        }
     
		System.out.println(ans);        
    
    }
}

