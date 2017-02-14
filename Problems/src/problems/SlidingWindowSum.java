package problems;

import java.util.Arrays;

public class SlidingWindowSum
{
	static int[] slidingWindowSum(int a[], int k)
	{
		if (a == null || a.length == 0)
			return null;
		int win[] = new int[k];
		int sum = 0, i = 0, n = a.length, j = 0;
		int res[] = new int[n - k + 1];
		for (i = 0; i < n; i++)
		{
			sum -= win[i % k];
			win[i % k] = a[i];
			sum += win[i % k];
			if (i >= k - 1)
				res[j++] = sum;
		}
		if (i < k)
			res[j++] = sum;
		return res;
	}

	public static void main(String[] args)
	{
		int[] a = { 1, 3, -1 };
		System.out.println(Arrays.toString(slidingWindowSum(a, 3)));
	}
}
