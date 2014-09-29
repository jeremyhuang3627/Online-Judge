import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;
import java.util.*;

public class q8_2 {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine()){
			String s = in.nextLine();
			String[] arr = s.split(" ");
			int[] intArr = new int[arr.length];
			for(int i=0;i<arr.length;i++){
				intArr[i] = Integer.parseInt(arr[i]);
			}

			BigInteger m = getMaxPro(intArr);
			System.out.println(m.toString());
		}
	}

	public static BigInteger getMaxPro(int[] a){
		BigInteger retVal = BigInteger.valueOf(-9999999);
		int len = a.length - 1;
		int start;
		int startLen;
		for(int l=1;l<=len;l++)
		{
			BigInteger sum = BigInteger.valueOf(1);
			for(int i=0;i<=len-l;i++)
			{
				if(i != 0 && a[i-1] != 0){
					sum = sum.divide(BigInteger.valueOf(a[i-1]));
					sum = sum.multiply(BigInteger.valueOf(a[i+l-1]));
				}else{
					sum = BigInteger.valueOf(1);
					for(int j=i;j<i+l;j++)
					{	
						sum = sum.multiply(BigInteger.valueOf(a[j]));
					}
				}

				if(retVal.compareTo(sum)<0){
					retVal = sum;
					start = i;

				}
			}
		}
		return retVal;
	}	
}
