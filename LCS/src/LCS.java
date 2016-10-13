import java.util.Scanner;

public class LCS
{
	public static void longestCommonSubseq(int[] a, int[] b, int n1, int n2)
	{
		if (n1 == 0 || n2 == 0)
			return;

		int L[][] = new int[n1 + 1][n2 + 1];

		for (int i = 0; i <= n1; i++)
		{
			for (int j = 0; j <= n2; j++)
			{
				if (i == 0 || j == 0)
					L[i][j] = 0;
				else
				{
					if (a[i - 1] == b[j - 1])
						L[i][j] = L[i - 1][j - 1] + 1;
					else
						L[i][j] = Math.max(L[i][j - 1], L[i - 1][j]);
				}
			}
		}
		int len = L[n1][n2];
		int lcs[] = new int[len];
		int i = n1, j = n2;
		while (i > 0 && j > 0)
		{
			if (a[i - 1] == b[j - 1])
			{
				lcs[--len] = a[i - 1];
				i--;
				j--;
			}
			else if (L[i - 1][j] > L[i][j - 1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
		for (i = 0; i < lcs.length; i++)
			System.out.print(lcs[i] + " ");
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n1 = sc.nextInt();
		int n2 = sc.nextInt();
		int[] a = new int[n1];
		int[] b = new int[n2];
		for (int i = 0; i < n1; i++)
			a[i] = sc.nextInt();
		for (int i = 0; i < n2; i++)
			b[i] = sc.nextInt();
		longestCommonSubseq(a, b, n1, n2);
	}
}