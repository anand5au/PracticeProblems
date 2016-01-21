package problems;

public class EquilibriumIndex {

	public static int solution(int[] A) 
    {
        long[] sumA = new long[A.length];
        for(int i=0;i<sumA.length;i++)
        {
        	sumA[i] = (i==0) ? A[i] : sumA[i-1] + A[i];
        }
     
        for(int i=0;i<A.length;i++)
        {
        	
        	if((i>0 && i<A.length-1 && sumA[i-1] == sumA[A.length - 1] - sumA[i]) ||
        			(i==0 && sumA[A.length-1] - sumA[i] == 0) ||
        			(i==A.length-1 && sumA[A.length-2] == 0))
        		return i;
        }
        return -1;
    }
	
	public static void main(String[] args) 
	{
		int[] A = {-1,3,-4,5,1,-6,2,1};
		System.out.println(solution(A));

	}

}
