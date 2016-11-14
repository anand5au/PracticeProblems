package problems;

public class LongestPalindromicSubstring
{
	public static String longestPalindrome(String s)
	{
		int len = s.length();
		if (len == 1)
			return s;
		String longest = "";
		for (int i = 0; i < len; i++)
		{
			String tmp = isPalindrome(s, i, i);
			if (tmp.length() > longest.length())
				longest = tmp;

			tmp = isPalindrome(s, i, i + 1);
			if (tmp.length() > longest.length())
				longest = tmp;
		}
		return longest;
	}

	private static String isPalindrome(String s, int start, int end)
	{
		while (start >= 0 && end <= s.length() - 1 && (s.charAt(start) == s.charAt(end)))
		{
			start--;
			end++;
		}
		return s.substring(start + 1, end);
	}

	public static void main(String[] args)
	{
		String s = "456789zazasxabcdeedcba123";
		System.out.println(longestPalindrome(s));
	}
}
