package petrol;

import java.util.ArrayList;

public class Petrol 
{
	int petrol;
	int distance;
		
	public Petrol(int p, int d)
	{
		petrol = p;
		distance = d;
	}
	
	public static void main(String args[])
	{
		ArrayList<Petrol> pd = new ArrayList<Petrol>();
		pd.add(new Petrol(4,6));
		pd.add(new Petrol(6,5));
		pd.add(new Petrol(7,3));
		pd.add(new Petrol(4,5));
		
		int index=0;
		boolean flag = false;
		int totalPetrol=0,totalDist=0;
		for(Petrol p:pd)
		{
			totalPetrol+=p.petrol;
			totalDist+=p.distance;
			// the 2nd condition is added so that we don't miss a valid station immediately after invalid station
			// In our case it is valid Station 1 which is immediately after invalid Station 0 
			if((totalPetrol < totalDist) && (p.petrol < p.distance))
				flag = false;
			else if(!flag)
			{
				index = pd.indexOf(p);
				flag = true;
			}
		}
		if(totalPetrol >= totalDist)
			System.out.println("Start index is "+index);
		else
			System.out.println("No Start");
	}
}
