import java.util.Scanner;

public class CountInversions
{
	static int inv = 0;

	public static long countInversions(int[] arr)
	{
		inv = 0;
		MergeSort(arr, 0, arr.length - 1);
		return inv;
	}

	static int[] MergeSort(int[] arr, int low, int high)
	{
		if (high < low)
			return null;

		if (high == low)
			return new int[] { arr[low] };

		int mid = low + (high - low) / 2;
		int[] leftarr = MergeSort(arr, low, mid);
		int[] rightarr = MergeSort(arr, mid + 1, high);
		return Merge(leftarr, rightarr);
	}

	static int[] Merge(int[] a, int[] b)
	{
		int[] temp = new int[a.length + b.length];
		int i = 0, j = 0, k = 0;
		for (; i < a.length && j < b.length;)
		{
			if (a[i] > b[j])
			{
				inv = inv + a.length - i;
				temp[k++] = b[j++];
			}
			else
			{
				temp[k++] = a[i++];
			}
		}
		while (i < a.length)
			temp[k++] = a[i++];
		while (j < b.length)
			temp[k++] = b[j++];

		return temp;
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int a0 = 0; a0 < t; a0++)
		{
			int n = in.nextInt();
			int arr[] = new int[n];
			for (int arr_i = 0; arr_i < n; arr_i++)
			{
				arr[arr_i] = in.nextInt();
			}
			System.out.println(countInversions(arr));
		}
	}

}
