#include "UserGraph.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char** argv) {
  

  //invalid arguments
  if(argc != 3) {
    cerr << "Incorrect amount of arguments" << endl;
    cerr << "Please run the program by ./extension file1 file2" << endl;
    return -1;
  }


  UserGraph* graph = new UserGraph();
  
  //load the graph
  if(argv[1] != 0){
    graph->loadFromFile(argv[1]);  
  } else {
    cerr << "invalid file";
    delete graph;
    return -1;
  }
 
  //initialize ofstream base on argv
  const char * outfile_name = argv[2];
  ofstream outFile(outfile_name);
  
  //output file's header
  outFile << "We would need these Users to make announcements for everyone"
          <<  "on the twitter network to see" << endl;
  
  //Call findDominantSet and return all the users that needs to announce the
  //news
  vector<int> domSet;
  domSet = graph->findDominantSet();


  //output each user's number to outFile
  for(auto it = domSet.begin(); it !=  domSet.end(); it++){
    outFile << "User: " << *it  << endl;
  }

  
  outFile.close();
  delete graph;  
  return 0;
}
