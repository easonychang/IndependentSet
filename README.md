![alt text](https://user-images.githubusercontent.com/17519982/30360875-cf3169b6-9808-11e7-8d0b-8bc837974acf.png)
# IndependentSet
This is a greedy algorithm for maximum independent set based on including nodes of smallest degree. 

Test it on random undirected graphs where each possible edge is in the graph with probability 1/2.

# Extension

This is a real life application using the independent set algorithm.

### Problem: 
	Given a data set of all users, assuming announcements made by a user will be seen by all their 
	followers, find how many users are required to make the announcement for all the people on the
	same network to see the announcement. Therefore, given a graph, find a subset of vertices, S, such
	that every vertex not in S is adjacent to at least one vertex not in S is adjacent to at least one 
	vertex in S.

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
