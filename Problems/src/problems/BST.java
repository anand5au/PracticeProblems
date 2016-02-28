package problems;

public class BST extends BinaryTree
{
	public BST()
	{
		root = null;
	}

	public TreeNode find(TreeNode root, int d)
	{
		if (root == null)
			return null;

		while (root != null)
		{
			if (root.data == d)
				return root;

			if (d < root.data)
				root = root.left;
			else
				root = root.right;
		}

		return null;
	}

	public TreeNode insert(TreeNode root, int d)
	{
		if (root == null)
			return new TreeNode(d);

		if (d < root.data)
			root.left = insert(root.left, d);

		else
			root.right = insert(root.right, d);

		return root;
	}

	public static void main(String[] args)
	{
		BinaryTree tree = new BST();
		tree.root = tree.insert(tree.root, 10);
		tree.root = tree.insert(tree.root, 6);
		tree.root = tree.insert(tree.root, 8);
		tree.root = tree.insert(tree.root, 14);
		tree.root = tree.insert(tree.root, 16);
		tree.root = tree.insert(tree.root, 9);
		tree.root = tree.insert(tree.root, 5);

		TreeNode temp = tree.find(tree.root, 9);
		System.out.println("temp: " + ((temp == null) ? "null" : temp.data));

		System.out.println(tree.inOrderSuccessor(tree.root, temp).data);

		System.out.println(tree.BFS(tree.root, 7));
		
		System.out.println(tree.DFS(tree.root, 7));

	}
}
