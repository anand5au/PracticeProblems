package array;

import java.util.Scanner;

public class Test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter value for n");
		int n = sc.nextInt();
		System.out.println("Enter value for k");
		int k = sc.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter values for array");
		for (int i = 0; i < arr.length; i++)
		{
			arr[i] = sc.nextInt();
		}
		int start = 0;
		boolean high = false;
		boolean low = false;
		int sum = 0;
		int j = 0;
		for (int i = 0; i < n - k + 1; i++)
		{
			start = i;
			for (j = i; j < k + i - 1; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					high = true;
					if (low == true)
					{
						sum -= cal(arr, start, j);
						start = j;
						low = false;
					}
				}
				else if (arr[j] > arr[j + 1])
				{
					low = true;
					if (high == true)
					{
						sum += cal(arr, start, j);
						start = j;
						high = false;
					}
				}
				else
				{
					if (high == true)
					{
						sum += cal(arr, start, j);
						high = false;
					}
					if (low == true)
					{
						sum -= cal(arr, start, j);
						low = false;
					}
				}
			}
			if (high == true)
			{
				sum += cal(arr, start, j);
				high = false;
			}
			if (low == true)
			{
				sum -= cal(arr, start, j);
				low = false;
			}
			System.out.println("The value is " + sum);
			sum = 0;
			high = false;
			low = false;
		}
	}

	static int cal(int[] arr, int start, int end)
	{
		int num = end - start + 1;
		return (num * (num - 1)) / 2;
	}
}