class MatrixChainMultiplication
{
	static int MatrixChainOrder(int p[], int n)
	{
		int m[][] = new int[n][n];

		int i, j, k, L, q;

		for (i = 1; i < n; i++)
			m[i][i] = 0;

		// L is diff bet i and j in each iteration
		for (L = 1; L < n; L++)
		{
			for (i = 1, j = i + L; i < n && j < n; i++, j++)
			{
				m[i][j] = Integer.MAX_VALUE;
				for (k = i; k < j; k++)
				{
					q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
					if (q < m[i][j])
						m[i][j] = q;
					for (int id = 0; id < m.length; id++)
					{
						for (int jd = 0; jd < m[0].length; jd++)
							System.out.print(m[id][jd] + " ");
						System.out.println();
					}
					System.out.println();
				}
			}
		}
		return m[1][n - 1];
	}

	public static void main(String args[])
	{
		int arr[] = new int[] { 30, 35, 15, 5, 10, 20, 25 };
		int size = arr.length;

		System.out.println("Minimum number of multiplications is "
				+ MatrixChainOrder(arr, size));
	}
}