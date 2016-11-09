package problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class PowerSetIterative
{

	static String[] buildSubsequences(String s)
	{
		ArrayList<String> subsequence = new ArrayList<String>();
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (subsequence.size() > 0)
			{
				int l = subsequence.size();
				for (int j = 0; j < l; j++)
				{
					subsequence.add(subsequence.get(j) + s.charAt(i));
				}
			}
			subsequence.add(s.charAt(i) + "");
		}

		Collections.sort(subsequence);
		String[] returnstr = new String[subsequence.size()];

		for (int i = 0; i < subsequence.size(); i++)
		{
			returnstr[i] = subsequence.get(i);
		}
		return returnstr;
	}

	public static void main(String[] args)
	{
		String[] arr = buildSubsequences("abcdef");
		System.out.println(Arrays.toString(arr));
	}
}
