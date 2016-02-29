package problems;

class ListNode<T>
{
	public T data;
	public ListNode<T> next;

	public ListNode()
	{
		next = null;
	}

	public ListNode(T d)
	{
		data = d;
		next = null;
	}

}

public class LinkedList<T>
{
	ListNode<T> head;
	ListNode<T> tail;

	public LinkedList()
	{
		head = null;
		tail = null;
	}

	public ListNode<T> getHead()
	{
		return head;
	}

	public void setHead(ListNode<T> h)
	{
		head = h;
	}

	public ListNode<T> getTail()
	{
		return tail;
	}

	public int length()
	{
		ListNode<T> t = head;
		int len = 0;
		while (t != null)
		{
			len++;
			t = t.next;
		}

		return len;
	}

	void insertAtStart(T d)
	{
		ListNode<T> newNode = new ListNode<T>(d);

		if (head != null)
			newNode.next = head;
		else
			tail = newNode;
		head = newNode;
	}

	void insertAtEnd(T d)
	{
		ListNode<T> newNode = new ListNode<T>(d);

		if (head == null)
			head = newNode;
		else
			tail.next = newNode;
		tail = newNode;
	}

	void printList()
	{
		if (head == null)
			return;

		ListNode<T> node = head;
		while (node != null)
		{
			System.out.print(node.data);
			if (node.next != null)
				System.out.print("->");
			node = node.next;
		}
		System.out.println();
	}
	
	void reverseList()
	{
		ListNode<T> curr = head;
		ListNode<T> prev = null;
		ListNode<T> next = null;
		
		while(curr != null)
		{
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}
		
		head = prev;
	}
	
}
