//
//  main.cpp
//  Assignment4_HAM
//
//  Created by Hugh A. Miles on 12/5/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include "Graphs_HAM.h"
#include "minHeap_HAM.h"


int main(int argc, const char * argv[]) {
    
    int numOfEdges;
    int numOfNodes;
    
    cout << "Enter number of Node and Edges:" << endl;
    cin >> numOfNodes;
    cin >> numOfEdges;
    
    //create nodes in graph class
    Graph* graph = new Graph(numOfNodes);
    for(int i = 0; i < numOfNodes; i++){graph->addVert(i);}
    
    cout << "Enter Node A and Node B and Undirected Edge Weight(s):" << endl;
    int nodeA;
    int nodeB;
    int weight;
    vector<Edge> graphEdges;
    for(int i = 0; i < numOfEdges; i++){
        cin >> nodeA;
        cin >> nodeB;
        cin >> weight;
        
        //organize edges into graph class
        graph->createEdge(nodeA, nodeB, weight);
    }
    
    graph->KruskalMST();

    cout << "enter the start Node:" << endl;
    int startNode;
    cin >> startNode;

//    graph->addVert(0);
//    graph->addVert(1);
//    graph->addVert(2);
//    graph->addVert(3);
//    graph->addVert(4);
//    graph->addVert(5);
//
//    graph->createEdge(0,2,1);
//    graph->createEdge(0,6,2);
//    graph->createEdge(0,8,3);
//
//    graph->primmsSPT( 0);
}
