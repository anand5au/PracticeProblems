package array;

import java.util.*;

public class Solution 
{
    public static void main(String[] args) 
    {
        int test_case_count = 0, m=0, currIndex=0;
        boolean isCurrIndexUpdated = true;
        List<Integer> array = new ArrayList<Integer>();
        Scanner s = new Scanner(System.in);
        if(s.hasNextLine())
            test_case_count = Integer.parseInt(s.nextLine());
        for(int i=0;i<test_case_count;i++)
        {
            if(s.hasNextLine())
            {
                String temp = s.nextLine();
                //n = Integer.parseInt(temp.split(" ")[0]);
                m = Integer.parseInt(temp.split(" ")[1]);
                temp = s.nextLine();
                String[] tempArray = temp.split(" ");
                for(int j=0;j<tempArray.length;j++)
                	array.add(Integer.parseInt(tempArray[j]));
                
                for(int j=0;j<array.size();)
                {
                	System.out.println(j);
            		if((j+m) >= array.size() || array.get(j+m) == 0)
            		{
            			currIndex = j+m;
            			j+=m;
            		}
            		else if(j>0 && (j+m-1) < array.size() && array.get(j+m-1) ==0 && array.get(j-1) == 0)
            		{
            			currIndex = j-1;
            			j--;
            		}
            		else if((j+1) >= array.size() || array.get(j+1) == 0)
            		{
            			currIndex = j+1;
            			j++;
            		}
            		else
            		{
            			isCurrIndexUpdated = false;
            			break;
            		}
                }
                if(currIndex >= array.size())
                {
                	System.out.println("YES");
                }
                else if(!isCurrIndexUpdated)
                {
                	System.out.println("NO");
                	isCurrIndexUpdated = true;
                }
            }
        }
        s.close();
    }
}
