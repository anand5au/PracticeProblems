package stack;

import java.util.HashMap;

public class StackHashMap 
{
	int[] data;
	int top;
	HashMap<Integer,Integer> StackData;
	
	public StackHashMap(int size)
	{
		data = new int[size];
		top = -1;
		StackData = new HashMap<Integer, Integer>();
	}
	
	void Push(int a)
	{
		data[++top]=a;
		if(StackData.containsKey(a)) 
			StackData.put(a,StackData.get(a)+1);
		else
			StackData.put(a,1);
	}
	
	int Pop()
	{
		int pop = data[top--];
		int val = StackData.get(pop);
		if(val==1)
			StackData.remove(pop);
		else if(val > 0)
			StackData.put(pop,val-1);
		return pop;
	}
	
	boolean IsPresent(int a)
	{
		return StackData.containsKey(a);
	}
	
	public static void main(String[] args) 
	{
		
	}
}
