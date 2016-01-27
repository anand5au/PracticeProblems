// 1->2->3->4->5->6->7
// 2->1->4->3->6->5->7
SwapList(Node *head)
{
	Node *temp = head;
	head  = head->next;
	while(temp && temp->next)
	{
		Node *temp1 = temp->next->next;
		temp->next->next = temp;
		temp->next = (temp1 && temp1->next) ? temp1->next : temp1;
		temp = temp1;
	}
	return head;
}

/*****************************************************************************************************************/

// Given an array of integers, give the most efficient algorithm to find if the array 
// has a majority element. If the array has a majority element, find this element. 
// (Note : The majority element is the element that occurs more than half of the size of the array)

/* Program for finding out majority element in an array */
# include<stdio.h>
# define bool int
  
int findCandidate(int *, int);
bool isMajority(int *, int, int);
  
/* Function to print Majority Element */
void printMajority(int a[], int size)
{
  /* Find the candidate for Majority*/
  int cand = findCandidate(a, size);
  
  /* Print the candidate if it is Majority*/
  if(isMajority(a, size, cand))
    printf(" %d ", cand);
  else
    printf("NO Majority Element");
}
  
/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for(i = 1; i < size; i++)
    {
        if(a[maj_index] == a[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
  
/* Function to check if the candidate occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
      if(a[i] == cand)
         count++;
    if (count > size/2)
       return 1;
    else
       return 0;
}
  
/* Driver function to test above functions */
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    printMajority(a, 5);
    getchar();
    return 0;
}

/*****************************************************************************************************************/
// Tree with root as 0 and has following children.
// If parent is 0, left is 0, right is 1
// If parent is 1, left is 1, right is 0
// Find the value of kth node in nth level
// Initially comp will be passed as false
Find(int n, int k, bool comp)
{
 cnt = (1<<(n-1))
 if k > cnt
 {
  print "invalid input"
  return
 }
 if n == 1
  return comp?k:k-1

 if k <= cnt/2
   Find(n-1,k,comp)
 else
   Find(n-1,k-cnt/2,!comp)
}

/*****************************************************************************************************************/
// WAP to print the node values of a binary tree 
// - Even level starting from right to left
// - Odd level starting from left to right 
// Assume that level of root is 1.

void ZigZag(Tree* root)
{
	Print root;
	StackOdd.Push(root);
	while(!StackOdd.IsEmpty())
	{
		while(!StackOdd.IsEmpty())
		{
			Tree* node = StackOdd.Pop();
			if(node->right) 
			{
				Print node->right;
				StackEven.Push(node->right);
			}
			if(node->left) 
			{
				Print node->left;
				StackEven.Push(node->left);
			}
		}
			
		while(!StackEven.IsEmpty())
		{
			Tree* node = StackEven.Pop();
			if(node->left) 
			{
				Print node->left;
				StackOdd.Push(node->left);
			}
			if(node->right) 
			{
				Print node->right;
				StackOdd.Push(node->right);
			}
		}
	}
}

/*****************************************************************************************************************/

// Iterative Pre-Order traversal of a tree
// Similar to level order traversal except that we should use a stack here and push right,left instead of left,root.

// constructing tree from preorder.
// 1. Make 1st number as root and push it to stack.
// 2. for every number n in the input array,
//		 temp = null
//       while stack is not empty and n > top()
//			temp = pop()
//		 if temp!=null then make n as right of temp and push the node(n) to stack
// 		 else make n left of top() and push the node(n) to stack


/*****************************************************************************************************************/
// Consider a memory management system in which free nodes are arranged in BST. 
// Find best fit for the input request.

int BestFit(node *root, int input)
{
    // Base case
    if( root == NULL )
        return -1;
 
    // We found equal key
    if( root->key == input )
        return root->key;
 
    // If root's key is smaller, BestFit must be in right subtree
    if( root->key < input )
        return BestFit(root->right, input);
 
    // Else, either left subtree or root has the BestFit value
    int fit = BestFit(root->left, input);
    return (fit >= input) ? fit : root->key;
}

/*****************************************************************************************************************/

// Modify stack to search a number in the stack
// Use Hashmap whose key is numbers in the stack and their value is freq of the numbers

/*****************************************************************************************************************/

/* 
Find the element that appears once
Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. 
Expected time complexity is O(n) and O(1) extra space.
Examples: 
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
*/

int getUniqueElement(int[] arr)
{
    int ones = 0 ; //At any point of time, this variable holds XOR of all the elements which have appeared "only" once.
    int twos = 0 ; //At any point of time, this variable holds XOR of all the elements which have appeared "only" twice.
    int not_threes ;

    for( int x : arr )
    {
        twos |= ones & x ; //add it to twos if it exists in ones
        ones ^= x ; //if it exists in ones, remove it, otherwise, add it

        // Next 3 lines of code just converts the common 1's between "ones" and "twos" to zero.

        not_threes = ~(ones & twos) ;//if x is in ones and twos, dont add it to Threes.
        ones &= not_threes ;//remove x from ones
        twos &= not_threes ;//remove x from twos
    } 
    return ones;
}

/*****************************************************************************************************************/

// Printing tree level by level w/o newline
public Void BFS()    
{      
 Queue q = new Queue();
 q.Enqueue(root);
 while (q.count > 0)
 {
    Node n = q.DeQueue();
    Print n.Value;
    if (n.left !=null)
    {
        q.EnQueue(n.left);
    }
    if (n.right !=null)
    {
		q.EnQueue(n.right);
    }
 }
}

// Printing tree level by level with newline
public Void BFS()    
{      
 Queue q = new Queue();
 q.Enqueue(root);
 currLevelCount = 1;
 nxtLevelCount = 0;
 while (q.count > 0)
 {
    Node n = q.DeQueue();
    Print n.Value;
	currLevelCount--;
    if (n.left !=null)
    {
        q.EnQueue(n.left);
		nxtLevelCount++;
    }
    if (n.right !=null)
    {
		q.EnQueue(n.right);
		nxtLevelCount++;
    }
	if(!currLevelCount)
	{
		Print newline;
		currLevelCount = nxtLevelCount;
		nxtLevelCount = 0;
	}
 }
}

/************************************************************************************************************************/

// Iterative Inorder
void Inorder(Node root)
{
	Stack *stack = new Stack();
	stack->Push(root);
	Node temp = root->left;

	while(true)
	{
		while(temp)
		{
			stack->Push(temp);
			temp = temp->left;
		}
		if(stack->IsEmpty()) break;
		temp = stack->Pop();
		printf("%d ",temp->value);
		temp = temp->right;
	}
}

/************************************************************************************************************************/

// Sorted linked list to BST
BinaryTree* sortedListToBST(ListNode *& list, int start, int end) 
{
  if (start > end) return NULL;
  
  // same as (start+end)/2, avoids overflow
  int mid = start + (end - start) / 2;
  
  BinaryTree *leftChild = sortedListToBST(list, start, mid-1);
  BinaryTree *parent = new BinaryTree(list->data);
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBST(list, mid+1, end);
  
  return parent;
}

struct Node* sortedListToBSTRecur(struct Node **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    struct Node *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* head_ref now refers to middle node, make middle node as root of BST*/
    struct Node *root = *head_ref;
 
    // Set pointer to left subtree
    root->prev = left;
 
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}

/************************************************************************************************************************/

// Printing a matrix spirally
void spiralPrint(int rowEnd, int colEnd, int a[R][C])
{
    int i, rowStart = 0, colStart = 0;
 
    while (rowStart < rowEnd && colStart < colEnd)
    {
        /* Print the first row from the remaining rows */
        for (i = colStart; i < colEnd; ++i)
        {
            printf("%d ", a[rowStart][i]);
        }
        rowStart++;
 
        /* Print the last column from the remaining columns */
        for (i = rowStart; i < rowEnd; ++i)
        {
            printf("%d ", a[i][colEnd-1]);
        }
        colEnd--;
 
        /* Print the last row from the remaining rows */
        if ( rowStart < rowEnd)
        {
            for (i = colEnd-1; i >= colStart; --i)
            {
                printf("%d ", a[rowEnd-1][i]);
            }
            rowEnd--;
        }
 
        /* Print the first column from the remaining columns */
        if (colStart < colEnd)
        {
            for (i = rowEnd-1; i >= rowStart; --i)
            {
                printf("%d ", a[i][colStart]);
            }
            colStart++;    
        }        
    }
}

/************************************************************************************************************************/

// Given a Binary Search Tree (BST), convert it to a Binary Tree such that every key of the 
// original BST is changed to key plus sum of all greater keys in BST.
void ConvertTree(Node root)
{
        static int sum = 0;
        if (root == NULL)
        return;

    ConvertTree(root->right);

    sum = sum + root->value;
        printf("Sum = %d\n",sum);
    root->value = sum;

    ConvertTree(root->left);
}

/************************************************************************************************************************/
// Given a Binary Search Tree (BST), convert it to a Binary Tree such that every key of the 
// original BST is changed to sum of its children.
// also check if node value shud be changed to 0 if no children
void Convert(node *&root) // post-order
{
	if(root == NULL) return;
       
        Convert(root->left);
        Convert(root->right);
        
        if(root->left) root->val = root->left->val;
        if(root->right) root->val += root->right->val;
}

void Convert(node *&root) // pre-order
{
    if (root == NULL) return;
    
    if (root->left) root->val = root->left->val;
	if (root->right) root->val += root->right->val;
    
	Convert(root->left);
    Convert(root->right);
}

/************************************************************************************************************************/

/*
 There are some glasses with equal volume of 1 litre. The glasses kept as follows

                   1
                 2   3
              4    5    6
            7    8    9   10

You can put water to only top glass. If you put more than 1 litre water to 1st glass, water overflow and fill equally both 2nd and 3rd glass. Glass 5 will get water from both 2nd glass and 3rd glass and so on..
If you have X litre of water and you put that water in top glass, so tell me how much water contained by jth glass in ith row.
*/
float getWater(int x,int i,int j)
{
    if ( i==1 and j==1)
        return x;
    else if (j==1)
        return ( (getWater(x,i-1,j)-1)/2 );
    else if (j==i)
        return (getWater(x,i-1,j-1)-1)/2 ;
    else
        return (getWater(x,i-1,j-1)-1)/2 + (getWater(x,i-1,j)-1)/2;
}

main()
{
    float val;
    int i=3,j=4,x=23;
    val = getWater(x,i,j);
    if (val>1)
        print 1;
    else if (val<0)
        print 0
    else
        print val;
}

/ ************************************************************************************************************************/

bool hasPathSum(Node node, int sum)
{
	/* return true if we run out of tree and sum==0 */
	if (node == NULL)
		return (sum == 0);
	
	/* otherwise check both subtrees */
	int subSum = sum - node->value;
	bool retVal = false;
	/* If we reach a leaf node and sum becomes 0 then return true*/
	if ( subSum == 0 && node->left == NULL && node->right == NULL )
	{
		printf("%d ",node->value);
		return true;
	}

	if(node->left) 
		retVal = retVal || hasPathSum(node->left, subSum);
	if(node->right) 
		retVal = retVal || hasPathSum(node->right, subSum);
	if(retVal)
		printf("%d ",node->value);
	return retVal;
}

// (sum of values at odd height)-(sum of values at even height)
double sum(Node root)
{
 if(root == null)
 {
  return 0;
 }
 
 return -(root.value + sum(root.left) + sum(root.right));
}


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
			// the 2nd condition is added so that we don't miss a valid station immediately after an invalid station
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

void VerticalSum(Node root, int level,int vsum[])
{
	if(root == NULL)
		return;
	VerticalSum(root->left,level-1,vsum);
	vsum[level]+=root->value;
	VerticalSum(root->right,level+1,vsum);
}


/************************************************************************************************************************/
int getDeepestOdd(node *root, int level)
{
    if(root == NULL) return 0;
    
    // if we encounter a leaf
    if(root->left == NULL && root->right == NULL) 
	{
        if(level%2 == 0) return 0; // if even level, return 0
        else return level; // else return the level 
    }
    return max(getDeepestOdd(root->left, level+1), 
                getDeepestOdd(root->right, level+1));
}

/*
Print N numbers of form 2^i.5^j in increasing order for all i >= 0 , j >= 0 ?
Example : - 1,2,4,5,8,10,16,20.....
*/

void print(int N)
{
    int arr[N];
    arr[0] = 1;
    int i = 0, j = 0, k = 1;
    int numJ, numI;
    int num;
    for(int count = 1; count < N; )
    {
       numI = arr[i] * 2;
       numJ = arr[j] * 5;
       if(numI < numJ)
       {
           num = numI;
           i++;
       }
       else
       {
           num = numJ;
           j++;
       }
       if(num > arr[k-1])
       {
          arr[k] = num;
          k++;
          count++;
       }
    }
    
    for(int counter = 0; counter < N; counter++)
    {
        printf("%d ", arr[counter]);
    }
}

/************************************************************************************************************************/
// Find if an element is present in a sorted 2d array

int row = 0;
int col = N-1;

while (row < M && col >= 0) 
{
  if (mat[row][col] == elem) 
  { 
    return true;
  }
  else if (mat[row][col] > elem) 
  { 
    col--;
  } 
  else 
  { 
    row++;
  } 
}

/************************************************************************************************************************/

/*
What is deque ? - double ended queue
Which data structures would u use to implement deque ?
Complexities of each data structure?
Implement it using array such tat all the operations are O(1).
operations are - insert at beginning,insert at end, delete at beginning ,delete at end. 
*/

/* 
Use doubly linked list to implement deque, straightforward and easy to understand.
We can also use an array, but it will be amortized O(1) (not worst case O(1)).
Treat the array like a circular array. When we run out of space, use the standard vector trick to double the size and copy over the elements.
*/

/************************************************************************************************************************/

/*
Given binary tree find the min weighted node.
Min weighted node is one which has minimun sum,where sum = Rootnode.getdata + leftnode.data + rightnode.data.
*/

Node minNode =null;
public Node findingTheMinimunWeightNode(Node node, int sum)
{
	if(node == null)
	return null;
	int temp = node.data;

	if(node.leftNode!=null)
		temp = temp+node.leftNode.data;

	if(node.rightNode!=null)
		temp = temp+node.rightNode.data;

	if(temp<sum)
	{
		minNode = node;
		sum= temp;
	}
	if(node.leftNode!=null)
		findingTheMinimunWeightNode( node.leftNode, sum);

	if(node.rightNode!=null)
		findingTheMinimunWeightNode( node.rightNode, sum);

	return minNode;

}

/* Extended version of power function that can work
 for float x and negative y*/
 
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);      
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 

/*

Following is the O(n) time and O(1) extra space approach. Let us understand the approach with a simple example where arr[] = {2, 3, 3, 5, 3, 4, 1, 7}, k = 8, n = 8 (number of elements in arr[]).

1) Iterate though input array arr[], for every element arr[i], increment arr[arr[i]%k] by k (arr[] becomes {2, 11, 11, 29, 11, 12, 1, 15 })

2) Find the maximum value in the modified array (maximum value is 29). Index of the maximum value is the maximum repeating element (index of 29 is 3).

3) If we want to get the original array back, we can iterate through the array one more time and do arr[i] = arr[i] % k where i varies from 0 to n-1.

*/

/*
What happens when you type a URL into a browser?

1. Browser contacts DNS to resolve IP address
2.DNS replies back with the IP address of the site
3. Browser opens TCP connection to the server at port 80
4. Fetches index.html file from /home directory.!
5.Displays the content in browser
6.Stores the IP in DNS cache for future use.
7.When broswer closed, TCP conn is terminated..!!!
*/

/*
Activity selection problem

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
	a) If the start time of this activity is greater than the finish time of previously selected activity then select this activity and print it.
*/

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}

/* Dutch National Flag */

void sort012(int a[], int arr_size)
{
   int lo = 0;
   int hi = arr_size - 1;
   int mid = 0;
 
   while(mid <= hi)
   {
      switch(a[mid])
      {
         case 0:
           swap(&a[lo++], &a[mid++]);
           break;
         case 1:
           mid++;
           break;
         case 2:
           swap(&a[mid], &a[hi--]);
           break;
      }
   }
}

/* 
Check if all leaves are at same level
1. Do a recursive call with level, cumulativeLevel and maxLevel as params
2. Store the maxLevel and add level at each leaf node
3. Do cumulativeLevel % maxLevel
*/

/* LCA with only parent node */

private int CalculateNodeHeight(Node node)
{
	if (node.Parent == null)
		return 1;
	return CalculateNodeHeight(node.Parent) + 1;
}

public static Node FindLowestCommonAncestor(Node node1, Node node2)
{
	int nodeLevel1 = node1.CalculateNodeHeight();
	int nodeLevel2 = node2.CalculateNodeHeight();

	while (nodeLevel1 > 0 && nodeLevel2 > 0)
	{
		if (nodeLevel1 > nodeLevel2)
		{
			node1 = node1.Parent;
			nodeLevel1--;
		}
		else if (nodeLevel2 > nodeLevel1)
		{
			node2 = node2.Parent;
			nodeLevel2--;
		}
		else
		{
			if (node1 == node2)
			{
				return node1;
			}

			node1 = node1.Parent;
			node2 = node2.Parent;
			nodeLevel1--;
			nodeLevel2--;
		}
	}
}

int IsBST(Node root)
{
	if(!root)
		return 1;
	if(root->left)
	{
		if(root->value >= root->left->value)
			return IsBST(root->left);
		else
			return 0;
	}
	if(root->right)
	{
		printf("right half\n");
		if(root->value <= root->right->value)
			return IsBST(root->right);
		else
			return 0;
	}
}

/******************************************************************************************************************/
/*

find smallest window in first array which covers all second array elements.

input= {6,7,1,3,2,4,5,2,3,1,2,5}
keys = {2,5,1}

answer: 9th to 11th index

Soln: Have another array sw[] of size of the keys.
1. For every element of keys[] get the position of it in input[] and fill it in corresponding index of sw[].
2. When positions of all elements of keys[] are available find the width of the current window and keep looking for width as we iterate the input[]
3. At the end of iteration we get min window :)

*/

/******************************************************************************************************************/
/*
In a incoming stream of numbers get min N numbers at any time

Solution: Maxheap
*/

/******************************************************************************************************************/
/*

A utility function to find the maximum sum between any
two leaves.This function calculates two values:
1) Maximum path sum between two leaves which is stored
   in res.
2) The maximum root to leaf path sum which is returned.
If one side of root is empty, then it returns INT_MIN

*/

int maxPathSumUtil(struct Node *root, int &res)
{
    // Base cases
    if (root==NULL) return 0;
    if (!root->left && !root->right) return root->data;
 
    // Find maximum sum in left and right subtree. Also
    // find maximum root to leaf sums in left and right
    // subtrees and store them in ls and rs
    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);
 
 
    // If both left and right children exist
    if (root->left && root->right)
    {
        // Update result if needed
        res = max(res, ls + rs + root->data);
 
        // Return maxium possible value for root being
        // on one side
        return max(ls, rs) + root->data;
    }
 
    // If any of the two children is empty, return
    // root sum for root being on one side
    return (!root->left)? rs + root->data:
                          ls + root->data;
}

/******************************************************************************************************************/

/*
SortedMerge of 2 LinkedLists
*/

struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

/******************************************************************************************************************/

/*
Merge k sorted arrays

1. Create an output array of size n*k.
2. Create a min heap of size k and insert 1st element in all the arrays into a the heap
3. Repeat following steps n*k times.
     a) Get minimum element from heap (minimum is always at root) and store it in output array.
     b) Replace heap root with next element from the array from which the element is extracted. If the array doesn’t have any more elements, then replace root with infinite. After replacing the root, heapify the tree.

*/

/******************************************************************************************************************/

/*
Check if 2 binary trees are same (numbers can be repeated.

Fill both trees into 2 HashSets and compare
*/

/******************************************************************************************************************/

/*

The minute hand moves 360 degree in 60 minute(or 6 degree in one minute) and hour hand moves 360 degree in 12 hours(or 0.5 degree in 1 minute). In h hours and m minutes, the minute hand would move (h*60 + m)*6 and hour hand would move (h*60 + m)*0.5.

*/

int calcAngle(double h, double m)
{
    // validate the input
    if (h <0 || m < 0 || h >12 || m > 60)
        printf("Wrong input");
 
    if (h == 12) h = 0;
    if (m == 60) m = 0;
 
    // Calculate the angles moved by hour and minute hands
    // with reference to 12:00
    int hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;
 
    // Find the difference between two angles
    int angle = abs(hour_angle - minute_angle);
 
    // Return the smaller angle of two possible angles
    angle = min(360-angle, angle);
 
    return angle;
}