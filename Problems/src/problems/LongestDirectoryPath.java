package problems;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LongestDirectoryPath
{
	public static int longestDirPath(String s)
	{
		Map<Integer, Integer> dirMap = new HashMap<Integer, Integer>();
		int maxLen = 0;
		for (String entry : s.split("\n"))
		{
			if (entry.isEmpty())
				continue;

			int currLevel = 0, currLen = 0;
			currLevel = entry.length() - entry.replaceAll("^\\s+", "").length();
			String dirEntry = entry.substring(currLevel);
			if (dirEntry.indexOf('.') == -1)
			{
				currLen = ((currLevel == 0) ? 0 : (dirMap.get(currLevel - 1) + 1)) + dirEntry.length();
				System.out.println("Putting " + dirEntry + ", level " + currLevel + " and len " + currLen);
				dirMap.put(currLevel, currLen);
			}
			else
			{
				maxLen = Math.max(maxLen, (dirMap.containsKey(currLevel - 1) ? (dirMap.get(currLevel - 1) + 1) : 0));
				System.out.println("maxLen " + maxLen + " until file " + dirEntry);
			}
		}
		return maxLen;
	}

	public static void main(String[] args)
	{
		Scanner sc = null;
		try
		{
			sc = new Scanner(new File("/Users/Anand/Documents/input.txt"));
			StringBuilder sb = new StringBuilder();
			while (sc.hasNext())
			{
				sb.append(sc.nextLine());
				sb.append(System.lineSeparator());
			}
			System.out.println(sb.toString());
			System.out.println(longestDirPath(sb.toString()));
		}
		catch (FileNotFoundException e)
		{
			System.out.println("Error reading input: " + e.getMessage());
		}
		finally
		{
			sc.close();
		}
	}
}
