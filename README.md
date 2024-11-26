Author: 1113556

Question 1: Binary Tree - Find the Diameter of a Binary Tree
Problem Statement:
Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root.
You are required to:
1.	Build the binary tree using level-order input. Use -1 to represent null nodes.
2.	Implement a function to calculate the diameter of the binary tree efficiently using recursion.
Input Format:
1.	The first line contains a list of integers representing the level-order traversal of the binary tree. Use -1 for null nodes.
Output Format:
Print an integer representing the diameter of the binary tree.
Example:
Input:
[1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7]
Output:
5

Question 2: Heap Sort - Build a Priority Queue for Tasks
Problem Statement:
Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Your program should allow:
1.	Add a Task: Add a task with a given priority.
2.	Get the Highest Priority Task: Remove and return the task with the highest priority.
3.	Display the Remaining Tasks: Print the remaining tasks in descending order of priority.
Input Format:
1.	The first line contains an integer N, the number of operations.
2.	The next N lines contain either:
o	"ADD task_name priority" to add a task.
o	"GET" to fetch the highest-priority task.
Output Format:
1.	For every "GET" operation, print the name of the task with the highest priority.
2.	At the end, print the list of remaining tasks in descending order of priority.
Example:
Input:
6
ADD Task1 10
ADD Task2 15
ADD Task3 5
GET
ADD Task4 20
GET

Output:
Task2
Task4
Remaining tasks: [('Task1', 10), ('Task3', 5)]
