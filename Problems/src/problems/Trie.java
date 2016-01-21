package problems;

import java.util.HashMap;
import java.util.Map;

class TrieNode {
    char c;
    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    boolean isLeaf;
 
    public TrieNode() {}
 
    public TrieNode(char c)
    {
        this.c = c;
    }
}

public class Trie 
{
	private TrieNode root;
	 
    public Trie() 
    {
        root = new TrieNode();
    }
    
    public static void PrintChildren(HashMap<Character, TrieNode> children, int level)
    {
    	if(children == null) return;
    	
    	
    	for (Map.Entry<Character, TrieNode> entry : children.entrySet()) 
    	{
    		System.out.println("At level: " + level);
    	    System.out.println(entry.getKey() + " : " + entry.getValue().c);
    	    if(!entry.getValue().children.isEmpty())
    	    {
    	    	System.out.println("Children:");
    	    	PrintChildren(entry.getValue().children, level+1);
    	    }
    	}
    }
 
    // Inserts a word into the trie.
    public void insert(String word) 
    {
        HashMap<Character, TrieNode> children = root.children;
        if(!children.isEmpty())
        {
	        System.out.println("root children:");
	        PrintChildren(children,0);
        }
        for(int i=0; i<word.length(); i++)
        {
            char c = word.charAt(i);
            System.out.println("Processing char " + c);
            TrieNode t;
            if(children.containsKey(c))
            {
                t = children.get(c);
            }
            else
            {
                t = new TrieNode(c);
                children.put(c, t);
            }
 
            children = t.children;
            if(!children.isEmpty())
            {
            	System.out.println("new children:");
            	PrintChildren(children,0);
            }
            //set leaf node
            if(i==word.length()-1)
                t.isLeaf = true;    
        }
    }
 
    // Returns if the word is in the trie.
    public boolean search(String word) 
    {
        TrieNode t = searchNode(word);
 
        if(t != null && t.isLeaf) 
            return true;
        else
            return false;
    }
 
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) 
    {
        if(searchNode(prefix) == null) 
            return false;
        else
            return true;
    }
 
    public TrieNode searchNode(String str)
    {
        Map<Character, TrieNode> children = root.children; 
        TrieNode t = null;
        for(int i=0; i<str.length(); i++)
        {
            char c = str.charAt(i);
            if(children.containsKey(c))
            {
                t = children.get(c);
                children = t.children;
            }
            else
            {
                return null;
            }
        }
        return t;
    }
    
    public static void main(String args[])
    {
    	Trie t = new Trie();
    	t.insert("to");
    	t.insert("ten");
    	t.insert("ted");
    	t.insert("tea");
    	t.insert("inn");
    	System.out.println("Searching...");
    	System.out.println(t.search("ten"));
    }
}