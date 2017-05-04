/**

 NOTE: it is undirected so each connection goes two ways

 create separate function to build graphs or varying sizes?
*/



#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Each individual AdjList, a vector of AdjList would be our graph
class Vertex {

public:

int vertex;//vertex number
vector<int> neighbors; //its neighbors
bool independent; //if it's independent

//Construction of a vertex
Vertex(int num);

};

//Constructor
//Each node has a vertex, a neigbor array, and a bool saying if it's independent
Vertex::Vertex(int num) : vertex(num),neighbors(0), independent(true){
}

//Min Heap's Comp
class pairComp {
public:
bool operator()(Vertex lhs, Vertex rhs) const {
        return lhs.neighbors.size() < rhs.neighbors.size();
}
};

vector<int> independentSet(vector<Vertex> inputGraph) {

        vector<int> indepSet;

        //dclaring priority queue
        priority_queue<Vertex, vector<Vertex>, pairComp> pq;

        //push every pair from inputGraph into pq
        for(int i = 0; i < inputGraph.size(); i++) {
                pq.push(inputGraph[i]);
        }

        //while pq is not empty, we keep popping
        while(pq.size() > 0) {
                //explore the node with lowest degree
                Vertex toExplore = pq.top();
                pq.pop();

                //if toExplore is true, set neighbors to false
                if (toExplore.independent) {
                        for(int index = 0; index < toExplore.neighbors.size(); index++) {
                                for(int i = 0; i < inputGraph.size(); i++) {
                                        if(inputGraph[i].vertex==
											toExplore.neighbors[index]) {
                                                inputGraph[i].independent = false;
                                        }
                                }
                        }
                        //add it to the return list
                        indepSet.push_back(toExplore.vertex);
                }
        }

        return indepSet;
}

int main(){

        vector <Vertex> graph;
        //creating the inputGraph
        srand(time(0));
        for (int i = 0; i < 3; i++) {
                cerr << "in for loop " << endl;			   
                Vertex vertex = Vertex(i);
                vector<int> vec;
                for(int j = 0; j < 2; j++) {
                        
						int w = rand() % 2;
						vec.push_back(w);

                }
                vertex.neighbors = vec;

                graph.push_back(vertex);
        }

        cerr << "second" << endl;
        //find the independentSet of this grpah
        vector<int> returned = independentSet(graph);
        for(int i = 0; i < returned.size(); i++) {
                cout << returned[i] << "; " << endl;
        }

}
