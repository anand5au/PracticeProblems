package problems;

import java.util.*;
import java.util.LinkedList;

class TreeNode
{

	public int data;
	public TreeNode left = null;
	public TreeNode right = null;

	public TreeNode(int d)
	{
		data = d;
	}
}

public class BinaryTree
{
	TreeNode root;

	public void deleteTree()
	{
		root = null;
	}

	public int height(TreeNode root)
	{
		if (root == null)
			return 0;

		return Math.max(height(root.left), height(root.right)) + 1;
	}

	public void printInOrder(TreeNode root)
	{
		if (root == null)
			return;
		printInOrder(root.left);
		System.out.print(root.data + " ");
		printInOrder(root.right);
	}
	
	static TreeNode last_node = null;
	public TreeNode inOrderSuccessor(TreeNode root, TreeNode node)
	{
		if (root == null || node == null)
			return null;
		TreeNode succ = null;

		succ = inOrderSuccessor(root.left, node);
		if (last_node != null && last_node == node)
			return root;
		last_node = root;
		succ = inOrderSuccessor(root.right, node);

		return succ;
	}
	
	public TreeNode find(TreeNode root, int d)
	{
		if (root == null)
			return null;

		if (root.data == d)
			return root;

		TreeNode temp;
		
		temp = find(root.left,d);
		if(temp != null)
			return temp;
		temp = find(root.right,d);
		return temp;
		
	}
	
	public TreeNode insert(TreeNode root, int d)
	{
		return null;
	}
	
	public void printPaths()
	{
		int[] path = new int[height(root)];
		printPaths(root, path, 0);
	}

	private void printPaths(TreeNode node, int[] path, int level)
	{
		if (node == null)
			return;

		path[level] = node.data;
		//System.out.println("level: " + level);
		
		if (node.left == null && node.right == null)
		{
			printArray(path, level);
		}
		else
		{
			printPaths(node.left, path, level+1);
			printPaths(node.right, path, level+1);
		}
	}

	private void printArray(int[] ints, int level)
	{
		for (int i = 0; i <= level; i++)
			System.out.print(ints[i] + " ");
		System.out.println();
	}
	
	public boolean BFS(TreeNode root, int d)
	{
		if(root == null) return false;
		
		if(root.data == d) return true;
		
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		TreeNode temp;
		q.offer(root);
		
		while(!q.isEmpty())
		{
			 temp = q.poll();
			 if(temp != null)
			 {
				 if(temp.data == d)
					 return true;
    			 if(temp.left != null)
    				 q.offer(temp.left);
    			 if(temp.right != null)
    				 q.offer(temp.right);
			 }
		}
		return false;
	}
	
	public boolean DFS(TreeNode root, int d)
	{
		if(root == null) return false;
		
		if(root.data == d) return true;
		
		return (DFS(root.left, d) || DFS(root.right,d));
	}
	
}
