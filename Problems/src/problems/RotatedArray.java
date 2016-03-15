package problems;

public class RotatedArray
{
	public static int findMin(int[] nums)
	{
	    int low = 0, high = nums.length-1;
	    
	    while(low < high)
	    {
	    	if(nums[low] < nums[high])
	            return nums[low];
	    	
	    	int mid = low + (high-low)/2;
	        
	        if (mid < high && nums[mid+1] < nums[mid])
	            return nums[mid+1];
	        
	        if((mid > low) && (nums[mid] < nums[mid-1]))
	            return nums[mid];
	       
	        if(nums[low] < nums[mid])
	            low = mid + 1;
	       
	        else if(nums[mid] < nums[high])
	            high = mid-1;
	    }
	    
	    if(high == low) return nums[low];
	    
	    return nums[0];
	}
	
	public static void main(String[] args)
	{
		//int[] nums = {8,1,2,4,5,6};
		int[] nums = {2,4,5,6,7,8,1};
		System.out.println(findMin(nums));
		
	}
}
