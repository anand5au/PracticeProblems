package problems;

import java.util.Arrays;
public class Frog 
{
	public static int minSecondsToCross(int A[], int X, int D) 
	{
        if(D >= X) return 0;
        
		int finalMin=-1, localMin=A.length, localStart=0, finalPos=0, i=0;
        int[] times = new int[X];
		Arrays.fill(times, -1);
		
		// Storing the seconds in an array indexed by position of the leaf
		for(; i<A.length; i++)
        {
			// consider only the first leaf, if multiples leaves fall in same position
        	if(times[A[i]] >= 0) continue;
            
        	times[A[i]] = i;
        }
		
		/* Idea: 
		   1. Split the pond into equal gaps of width 'D'
		      The frog can jump only if there is at least one leaf in all these gaps.
		   2. Find minimum times at which a leaf fall in each of these gaps
		   3. Maximum of the set of minimum times found in step 2 would be the required answer. 
        */
        for(i=0; i<times.length; i++)
        {
        	if((localStart + D + 1) == i)
            {
            	localStart = i-1; // mark the start of each gap
            	
            	if(finalMin < localMin)
            		finalMin = localMin;
            	
            	localMin = A.length; // reset localMin at the start of each gap
            }
        	
            if(times[i] < 0) continue; // continue if there is no leaf at this position
                       
            if(finalPos == 0 && i > D) // no leaf to start-off, so return -1
            	return -1;
            
            if(localMin > times[i]) 
            	localMin = times[i];
				
            if(i>finalPos && i-finalPos<=D)
            {
            	finalPos = i;
            	if(finalPos+D >= X) break;
            }
			
        }
        
        if(localMin<A.length && finalMin < localMin)
    		finalMin = localMin;
        
        if(finalPos+D >= X) 
        	return finalMin;
		
        return -1;
	}
	
	public static void main(String[] args) 
	{
		int X = 4, D = 2; // X is diameter of the pond. D is the max distance the frog can caver in a single jump
		int A[] = {2,2,2,2,2,2}; // A[k] denotes the position at which a leaf fall in kth second
		
		// Given the above parameters, find the minimum seconds in which the frog can jump across the pond
		int ans = minSecondsToCross(A, X, D);
		if(ans<0)
		{
			System.out.println("Frog can't cross the pond");
		}
		else
		{
			System.out.println("Frog can cross the pond in " + ans + " seconds");
		}
	}
}