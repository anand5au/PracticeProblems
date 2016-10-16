import java.util.Scanner;
import java.util.Stack;

public class CountZerosOnes
{
	public static int count(String s)
	{
		char temp = ' ';
		int result = 0;
		Stack<Character> zero = new Stack<Character>();
		Stack<Character> one = new Stack<Character>();
		for (int i = 0; i < s.length(); i++)
		{
			temp = s.charAt(i);
			if (temp == '0')
			{
				if (!one.empty())
				{
					one.pop();
					result++;
				}
				zero.push('0');
			}
			else if (temp == '1')
			{
				if (!zero.empty())
				{
					zero.pop();
					result++;
				}
				one.push('1');
			}
		}
		return result;
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println(count(sc.next()));
	}
}
