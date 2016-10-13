package lis;

import java.util.Scanner;

public class LIS
{
	/*
	 * Recurrence Relation: L[i] = 1 + max(L[j]) | j < i and ar[j] < ar[i]
	 */
	public static int longestIncreasingSubSeq(int ar[], int n)
	{
		if (ar == null || ar.length == 0)
			return 0;

		int L[] = new int[n];
		int max = 0;
		for (int i = 0; i < n; i++)
			L[i] = 1;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (ar[j] < ar[i] && L[i] < (L[j] + 1))
					L[i] = 1 + L[j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (max < L[i])
				max = L[i];
		}
		return max;
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ar[] = new int[n];
		for (int i = 0; i < n; i++)
			ar[i] = sc.nextInt();

		System.out.println(longestIncreasingSubSeq(ar, n));
	}
}