package problems;

import java.util.HashSet;

public class Permutation
{
	public static HashSet<String> perm(String s)
    {
        if(s==null)
            return null;
        
        HashSet<String> permList = new HashSet<String>();
        if(s.isEmpty())
        {
            permList.add("");
            return permList;
        }
        
        char first = s.charAt(0);
        String remaining = s.substring(1);
        HashSet<String> inter = perm(remaining);
        
        for(String str : inter)
        {
            for(int i=0; i<= str.length(); i++)
            {
                permList.add(insertAt(str,first,i));
            }
        }
        return permList;
    }
    
    public static String insertAt(String s, char c, int i)
    {
        return (s.substring(0,i) + c + s.substring(i));
    }
    
	public static void main (String[] args)
	{
		String a = "abca";
		System.out.println(perm(a));
	}

}
