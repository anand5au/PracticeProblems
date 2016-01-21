package problems;

import java.util.Arrays;

public class Frog 
{
	public static int solution(int A[], int X, int D) 
	{
        if(D >= X) return 0;
        
		int finalAns=-1, localAns=A.length+1, localStart=0, finalPos=0, i=0;
        int[] times = new int[X];
		Arrays.fill(times, -1);
		
        for(; i<A.length; i++)
            times[A[i]] = i;
        
        for(i=0; i<times.length; i++)
        {
        	if((localStart + D + 1) == i)
            {
            	localStart = i-1;
            	if(finalAns < localAns)
            	{
            		finalAns = localAns;
            		localAns = A.length+1;
            	}
            }
        	
            if(times[i] < 0) continue;
            
            if(localAns > times[i]) 
            	localAns = times[i];
           
            if(i>finalPos && i-finalPos<=D)
            {
            	finalPos = i;
            	if(finalPos+D >= X) break;
            }
        }
        
        if(finalAns < localAns)
    		finalAns = localAns;
        
        if(finalPos+D >= X) 
        	return finalAns;
		
        return -1;
	}
	
	public static void main(String[] args) 
	{
		int X = 24, D = 3;
		int A[] = {22,15,12,18,5,9,6};
		System.out.println("Frog can cross the pond in " + solution(A, X, D) + " seconds");
	}
}