import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n_amount = 0;
        int n = scan.nextInt();
        int arr[] = new int[n];
        int sum = 0;
        int counter = 1;
        for(int i = 0; i < n; i++){
            arr[i] = scan.nextInt();
            if(arr[i] < 0)n_amount += 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = n - i - counter; j >= i; j--){
                for(int k = j; k >= i; k--){
                    sum += arr[k];
                }
                counter += 1;  
                if(sum < 0)n_amount += 1;
                sum = 0;
            }
        }
        System.out.println(n_amount);
    }
}
