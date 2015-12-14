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
    
    cout << "enter the start Node:" << endl;
    int startNode;
    cin >> startNode;
    
    graph->PrimMST(startNode);
    
    graph->KruskalMST();
    
    graph->BoruvkaMST();
    
}
