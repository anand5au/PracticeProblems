package problems;

import java.util.Date;

public class MinCoins
{
	public static int minCoinsFast(int coins[], int m, int V)
	{
		// table[i] will be storing the minimum number of coins
		// required for i value. So table[V] will have result
		int[] table = new int[V + 1];

		// Base case (If given value V is 0)
		table[0] = 0;

		// Initialize all table values as Infinite
		for (int i = 1; i <= V; i++)
			table[i] = Integer.MAX_VALUE;

		// Compute minimum coins required for all
		// values from 1 to V
		for (int i = 1; i <= V; i++)
		{
			// Go through all coins smaller than i
			for (int j = 0; j < m; j++)
			{
				if (coins[j] < i)
				{
					int sub_res = table[i - coins[j]];
					if (sub_res != Integer.MAX_VALUE && sub_res + 1 < table[i])
						table[i] = sub_res + 1;
				}
				// comment this part if only exact amount is required
				else
				{
					table[i] = 1;
				}
			}
		}
		for (int i = 0; i < table.length; i++)
			System.out.print(table[i] + " ");
		System.out.println();
		return table[V];
	}

	public static int minCoinsSlow(int coins[], int m, int V)
	{
		if (V <= 0)
			return 0;

		int res = Integer.MAX_VALUE;

		for (int j = 0; j < m; j++)
		{
			if (coins[j] <= V)
			{
				int sub_res = minCoinsSlow(coins, m, V - coins[j]);
				if (sub_res + 1 < res)
					res = sub_res + 1;
			}
			else
			{
				return 1;
			}
		}

		return res;
	}

	public static void main(String[] args)
	{
		int coins[] = { 3, 5 };
		System.out.println(new Date());
		System.out.println("Minimum coins required is " + minCoinsFast(coins, coins.length, 103));
		System.out.println(new Date());
		System.out.println("Minimum coins required is " + minCoinsSlow(coins, coins.length, 103));
		System.out.println(new Date());
	}
}
