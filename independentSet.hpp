#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <random>

using namespace std;


class AdjList {
public:
int vertex;
vector<int> neighbor;
bool independent;

};


createRandomGraph(int n){


}

int main(){
        vector <pair<int,vector<int> > > g;
        //creating the inputGraph
        for(int i = 0; i < 3; i++) {
                vector<int> vec;
                for(int j = 0; j < 2; j++) {
                        vec[j] = rand()%2;
                }
                auto gpair = pair<int, vector<int> >(i,vec);
                g[i] = gpair;
        }
        independentSet(g);



}

//Min Heap's Comp
class pairComp {
public:
bool operator()(pair<int,int> lhs, pair<int,int> rhs) const {
        return lhs.second.size() < rhs.second.size();
}
};

vector<int> independentSet(vector<AdjList> inputGraph) {

        //dclaring priority queue
        std::priority_queue<pair<int,vector<int> >, vector<pair<int,int> >, pairComp> pq;

        //push every pair from inputGraph into pq
        for(i = 0; i < inputGraph.size(); i++) {
                pq.push(inputGraph[i]);
        }

        toExplore = pq.top();

}
