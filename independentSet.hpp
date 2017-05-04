#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <random>

using namespace std;

//Each individual AdjList, a vector of AdjList would be our graph
class Vertex {

public:
int vertex;
vector<int> neighbor;
bool independent;

Node();

};

//Each node has a vertex, a neigbor array, and a bool saying if it's independent
Vertex::Node(int num) : vertex(num),neighbor(0), independent(true){
}


int main(){

        vector <Vertex> graph;
        //creating the inputGraph

        for(int i = 0; i < 3; i++) {
                Vertex vertex = Node(i);
                vector<int> vec;
                for(int j = 0; j < 2; j++) {
                        vec[j] = rand()%2;
                }
                vertex.neighbor = vec;

                graph.insert(vertex);
        }

        //find the independentSet of this grpah
        independentSet(graph);

}

//Min Heap's Comp
class pairComp {
public:
bool operator()(pair<int,int> lhs, pair<int,int> rhs) const {
        return lhs.second.size() < rhs.second.size();
}
};



vector<int> independentSet(vector<Vertex> inputGraph) {

        vector<int> indepSet;

        //dclaring priority queue
        priority_queue<pair<int,vector<int> >, vector<pair<int,int> >, pairComp> pq;

        //push every pair from inputGraph into pq
        for(int i = 0; i < inputGraph.size(); i++) {
                pq.push(inputGraph[i]);
        }

        //while pq is not empty, we keep popping
        while(pq.size > 0) {
                //explore the node with lowest degree
                Vertex toExplore = pq.top();
                pq.pop();

                //if toExplore is true, set neighbors to false
                if(toExplore.independent == true) {
                        for(int index = 0; index < toExplore.neighbors.size(); index++) {
                                for(int i = 0; i < inputGraph.size(); i++) {
                                        if(inputGraph[i]== toExplore.neighbors[index]) {
                                                inputGraph[i].independent = false;
                                        }
                                }
                        }
                        //add it to the return list
                        indepSet.insert(toExplore.vertex);
                }
        }

        return indepSet;

}
