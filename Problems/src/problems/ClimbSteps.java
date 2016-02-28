package problems;

import java.util.Arrays;

public class ClimbSteps
{
	public static int countWays(int s, int arr[])
	{
		if (s < 0)
			return 0;
		if (s == 0)
			return 1;
		if (arr[s] >= 0)
			return arr[s];
		arr[s] = countWays(s - 1, arr) + countWays(s - 2, arr) + countWays(s - 3, arr);
		return arr[s];
	}

	public static void main(String[] args)
	{
		int[] arr = new int[37];
		Arrays.fill(arr, -1);
		System.out.println(countWays(3, arr));
	}
}
