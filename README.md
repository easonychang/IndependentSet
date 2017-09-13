![alt text](https://user-images.githubusercontent.com/17519982/30360875-cf3169b6-9808-11e7-8d0b-8bc837974acf.png)
# IndependentSet

The max independent set problem explored in this program is an NP-hard optimization problem, so optimal solutions
are not likely to be efficient.

#### Functions

##### buildGraph: 
	Builds a random undirected graphs where each possible edge is in the graph with probability 1/2 
	based on the number of nodes we pass in as parameter.
##### printGraph:
	Given a graph, print out the content in the C++ vector.	
##### independentSet:	
	In this function, we implemented a greedy algorithm for maximum independent set based by including 
	nodes of smallest degree. However, the greedy algorithm does not always find the best solution.
	Run Time: O(n)
##### independentSetBT:
	Instance (Input): Undirected Graph
	Solution Format: Subset of the vertices
	Constraint: No two vertices are connected with an edge, For each edge e={u,v}, if u is in S, v is not in S
	Objective: Maximize the size of the subset
	
	Solution Space: all subsets S of V, |V|= n, number of nodes
	Exhasutive search: $O(2^n)$
	
	Backtracking: Do exhaustive search locally, but use constraints to simplify problem as we go
	What is a local decision? For a vertex u, is u part of the optimal solution ot not.
	What are the possible answers to this decision? Yes or No
	
	This is implemented with a backtracking algorithm, with constraints to prune cases that have a dead end,
	thus giving us a more efficient algorithm compared to an exhastive search.
	Although much slower (running in sub-exponential time) than the greedy algorithm, the backtracking 
	algorithm gives the actual size of the maximum independent set in a random set.
	
	Run time: $O(2^(0.6n)$
##### Testing
	These two functions are being tested on randomized graph generated by the buildGraph method.
	With the data recorded below, it shows that the backtracking algorithm consistently finds a 
	larger independent set, at the rate that’s double of the size of independent set greedy 
	algorithm finds on the same “randomized graph”, which is an indication that it’s giving us 
	the optimal solution as discussed in class. 

Greedy Heuristic | Backtracking Algorithm


Nodes (n) | Independent Set (|S|) | Nodes (n) | Independent Set (|S|)
:---: | :---: | :---: | :---:
4  | 1 | 4 | 2  
8  | 2 | 8 | 3 
16 | 3 | 16 | 5 
32 | 3 | 32 | 6 
64 | 5 | 64 | 7 
128 | 6 | 128 | 10 
256 | 7 | 256 | 11 
512 | 9 | 512 | Took too long to run  




# Extension

This is a real life application using the independent set algorithm, which is a use of the minimum spanning set.

### Problem: 
	Given a data set of all users on Twitter/Facebook or any social media, assuming announcements made 
	by a user will be seen by all their followers, find how many users are required to make the 
	announcement for all the people on the same network to see the announcement. Therefore, 
	given a graph, find a subset of vertices, S, such that every vertex not in S is adjacent to at 
	least one vertex not in S is adjacent to at least one vertex in S.

### How we solved it: 
	We have implmeneted a simple greedy algorithm, and to find the dominant set of vertices and return it.
	To do that, we marked all the vertices as "uncovered" in each User's constructor. we then initialize 
	the an empty vector. While the number of covered edges is not the same as the amount of vertices in 
	allUser, then we iterate through allUser to find the user vertex with the most followers, also if a 
	vertex cover field is true, then we simply increment the amount of covered vertex and continue with 
	the loop without trying to find the vertex.
	
	Once we have found the vertex user with the most followers, we add it to the dominant set we have 
	initialized and simply set its covered field to true, and we loop through it's followers, find the
	followers in allUser and set their covered field to true as well. Then at the end we return the 
	sets with all the vertices that was used to cover the entire graph.


### How we tested our program:
	I came up with some general test cases, the first being smallgraph.tsv, it contains 4 nodes,
	1-(3), 2-(3,4), 3-(1,2), 4-(2). The 1,2,3,4 are vertices of the grpah, and - denotes edge 
	relationship. It is a directed graph. Therefore, we are trying to figure out how many nodes 
	I have to explore before all the users are reached by the announcement, assuming that all the 
	nodes that are directly connected by the announcer will see the announcement. We find that Node 2
	has the 2 edges, which is the most, so does Node 3 but it doesn't matter in this case. We explore
	set 2, 3, 4 all to true. Then we see Node 1 is the only vertex that has yet to be explored. 
	Thus, the output file tells us that User 2 and 1 has to announce the news so that all the nodes 
	will see it. Of course, other answer exists, but this algorithm's simply tasked to find one solution, 
	and not all the possible solutions.

	Same goes for smallgraph2.tsv, in which there are Node 1,2,3,4,5,6,7,8. In which all nodes are connected
	to 1, but 6, which is only connected to 2. Therefore, we know the answer has to either be 1,6. Node 1 
	must be explored because it has the most edges, and afterwards, 2 through 8 with the exception of Node 6
	are all explored. Then we go and explore Node 6. In our output file it gives us the correct output. 


### How to run this program:

	To run the program please use the following command.
	./extension file1 file2

#### For example:

	files provided by me:
	> ./extension smallgraph.tsv test.tsv
	> ./extension smallgraph1.tsv test1.tsv

	Any data sets in this format would work:
	Where column1 is the user number, and the column2 is the user that is a follower of the user
	in column 1. C1 and C2 are divided by a space. The data does not need processing. 
