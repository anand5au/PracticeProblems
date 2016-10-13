package lis;

import java.util.ArrayList;

public class LISList
{
	/*
	 * Recurrence Relation: L[i] = 1 + max(L[j]) | j < i and ar[j] < ar[i]
	 */
	public static ArrayList<Integer> longestIncreasingSubSeq(int ar[], int n)
	{
		if (ar == null || ar.length == 0)
			return null;

		ArrayList<ArrayList<Integer>> L = new ArrayList<ArrayList<Integer>>(n);
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			ArrayList<Integer> l = new ArrayList<Integer>();
			l.add(ar[i]);
			L.add(i, l);
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (ar[j] < ar[i] && L.get(i).size() < (L.get(j).size() + 1))
				{
					ArrayList<Integer> l = new ArrayList<Integer>(L.get(j));
					L.add(i, l);
					L.get(i).add(ar[i]);
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (L.get(max).size() < L.get(i).size())
				max = i;
		}
		return L.get(max);
	}

	public static void main(String[] args)
	{
		/*
		 * Scanner sc = new Scanner(System.in); int n = sc.nextInt(); int ar[] =
		 * new int[n]; for (int i = 0; i < n; i++) ar[i] = sc.nextInt();
		 */
		int ar[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
		System.out.println(longestIncreasingSubSeq(ar, ar.length).toString());
	}
}