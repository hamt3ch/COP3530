//
//  Graphs_HAM.h
//  Assignment4_HAM
//
//  Created by Hugh A. Miles on 12/5/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef Graphs_HAM_h
#define Graphs_HAM_h

#include <iostream>
#include <vector>
using namespace std;

class Edge {
private:
    int vert; // connection from thisNode to other Vert
    int weight; // weight of this Edge8

public:
    Edge(int connectedVert, int initWeight){
        vert = connectedVert;
        weight = initWeight;
    }

    int getWeight(){return weight;}
    int getVert(){return vert;}
};


class Node {
public:
    int data; //value of Node
    vector<Edge> connections; // list of connected

    Node(int initData){ // constructor
        data = initData;
    }

    void addEdge(int vertToConnect, int weight){ //add connection to edge
        connections.push_back(*new Edge(vertToConnect, weight));
    }
};

//Node ->> Overloading
bool operator== (const Node& lhs, const Node& rhs) {
    return lhs.data == rhs.data;
}

bool operator!= (const Node& lhs, const Node& rhs) {
    return lhs.data != rhs.data;
}

bool operator&& (const Node& lhs, const Node& rhs) {
    return lhs == rhs;
}

class Graph {
private:
    int numOfVerts;
    bool *hash;
    vector<Node> myGraph;
    
public:
    Graph(int numOfVerts){ //constructor
        //intialize adjaceny list
    }

    void createEdge(int strVert, int endVert, int weight){ // add Vert to Graph
        Node* v1 = getVert(strVert); // int >> Node
        Node* v2 = getVert(endVert);
        
        //Both Verts exist
        if(v1 != NULL && v2 != NULL){
            cout << "Both Exist" << endl;
            //add vert.int to both connections list
            v1->addEdge(v2->data, weight);
            v2->addEdge(v1->data, weight);
        }
        
        //1 of 2 Verts exist
        else if((v1 == NULL && v2 != NULL ) || (v1 != NULL && v2 == NULL)){
            cout << "one exist" << endl;
        }

        //Neither Verts exist
        else {
            cout << "Neither Exist" << endl;
        }
    }

    void addVert(int toAppend){ //add vertice to graph
        myGraph.push_back(*new Node(toAppend)); // add new Node to graph
    }
    
    
    // Convert int >> Node value inside current graph
    Node* getVert(int toCheck){
        for (auto && vert : myGraph){
            if(vert.data == toCheck){
                return &vert; // found vert
            }
        }  return NULL; // curent vert doesnt Exist
    };

    
    void print(){
        for(auto &&vert : myGraph){
            cout << "Vert = ";
            cout << vert.data << endl; // print node name
            for(auto && edges : vert.connections){
                cout << "   " << edges.getVert() << ":" << edges.getWeight() << endl; // print edge&weight
            }
        }
    }
};

#endif /* Graphs_HAM_h */
