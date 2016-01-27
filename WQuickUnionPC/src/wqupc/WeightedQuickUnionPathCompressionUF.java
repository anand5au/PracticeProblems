package wqupc;

import java.util.Scanner;

public class WeightedQuickUnionPathCompressionUF {
    private int[] id;    // id[i] = parent of i
    private int[] sz;    // sz[i] = number of objects in subtree rooted at i
    private int count;   // number of components

    // Create an empty union find data structure with N isolated sets.
    public WeightedQuickUnionPathCompressionUF(int N) 
    {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) 
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // Return the number of disjoint sets.
    public int count() 
    {
        return count;
    }

    // Return component identifier for component containing p
    public int root(int p) 
    {
        while (p != id[p])
		{
			id[p] = id[id[p]];
            p = id[p];
		}
        return p;
    }

   // Are objects p and q in the same set?
    public boolean connected(int p, int q) 
    {
        return root(p) == root(q);
    }

  
   // Replace sets containing p and q with their union.
    public void union(int p, int q) 
    {
        int i = root(p);
        int j = root(q);
        if (i == j) return;

        // make smaller root point to larger one
        if   (sz[i] < sz[j]) 
        { 
        	id[i] = j; 
        	sz[j] += sz[i]; 
        }
        else                 
        { 
        	id[j] = i; 
        	sz[i] += sz[j]; 
        }
        count--;
    }


    public static void main(String[] args) 
    {
    	Scanner input = new Scanner(System.in);
    	System.out.print("No: of components = ");
        int N = input.nextInt();
        WeightedQuickUnionPathCompressionUF uf = new WeightedQuickUnionPathCompressionUF(N);

        // read in a sequence of pairs of integers (each in the range 0 to N-1),
         // calling find() for each pair: If the members of the pair are not already
        // call union() and print the pair.
        while (input.hasNextInt()) 
        {
            int p = input.nextInt();
            int q = input.nextInt();
            if (uf.connected(p, q))
            {
            	System.out.println("Already connected!");
            	continue;
            }
            uf.union(p, q);
            System.out.println(p + " and " + q + " are now connected");
        }
        System.out.println(uf.count() + " components");
    }
}
