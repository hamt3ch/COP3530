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
#include "minHeap_HAM.h"

using namespace std;

class Edge {
private:
    int vert1; // connection from thisNode to other Vert
    int vert2; // for overLoad
    int weight; // weight of this Edge8

public:
    Edge(int connectedVert, int initWeight){
        vert1 = connectedVert;
        weight = initWeight;
    }

    Edge(int initVert1, int initVert2, int initWeight){
        vert1 = initVert1;
        vert2 = initVert2;
        weight = initWeight;
    }

    void print() {
        cout << "[" << vert1 << "," << vert2 << "] " << weight << endl;
    }

    int getWeight(){return weight;}
    int getVert1(){return vert1;}
    int getVert2(){return vert2;}
};


class Node {
public:
    int data; //value of Node
    bool visited;
    vector<Edge> connections; // list of connected

    Node(int initData){ // constructor
        data = initData;
        visited = false;
    }

    void addEdge(int vertToConnect, int weight){ //add connection to edge
        connections.push_back(*new Edge(data, vertToConnect, weight));
    }

    void print() {
        cout << "name: " << data << endl;
        cout << "visited:" << visited << endl;
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
    vector<Node> myGraph;
    vector<Edge> myEdges;
    int verts;

public:
    Graph(int numOfVerts){verts = numOfVerts;}//constructor

    void createEdge(int strVert, int endVert, int weight){ // add Vert to Graph
        Node* v1 = getVert(strVert); // int >> Node
        Node* v2 = getVert(endVert);

        //Both Verts exist
        if(v1 != NULL && v2 != NULL){
            //add vert.int to both connections list
            v1->addEdge(v2->data, weight);
            v2->addEdge(v1->data, weight);

            //add to list of edges
            myEdges.push_back(*new Edge(strVert,endVert,weight));

        }
    }

    void addVert(int toAppend){ //add vertice to graph
        myGraph.push_back(*new Node(toAppend)); // add new Node to graph
    }


    // Convert int >> Node value inside current graph
    Node* getVert(int toCheck){
        for(int i = 0; i < myGraph.size(); i++ ){
            Node* vert = &myGraph.at(i);
            if(vert->data == toCheck){
                return vert; // found vert
            }
        } return NULL;
//        for (auto && vert : myGraph){
//            if(vert.data == toCheck){
//                return &vert; // found vert
//            }
//        }  return NULL; // curent vert doesnt Exist
    };


    void print(){
        for(int i = 0; i < myGraph.size(); i++){
            Node* vert = &myGraph.at(i);
            cout << "Vert = ";
            cout << vert->data << endl; // print node name
        }
//        for(auto &&vert : myGraph){
//            for(auto && edges : vert.connections){
//                cout << "   " << edges.getVert1() << ":" << edges.getWeight() << endl; // print edge&weight
//            }
//        }
    }

    void printEdges(){
//        for (auto &&edge : myEdges){
//            edge.print();
//        }
    }

    void KruskalMST(){
        bool visited[verts];
        for (int i = 0; i < verts; i++) {visited[i]=false;}
        vector<Edge> mst;
        treeHeap<Edge*> minQ = *new ::treeHeap<Edge*>();

        //get all the edges
//        for (auto &&edge : myEdges){
//            minQ.push(&edge);
//        }

        for(int i = 0; i < myEdges.size(); i++){
            Edge* toPush = &myEdges.at(i);
            minQ.push(toPush);
        }

        //Do search
        for(int i = 0; i <= verts; i++){
            Edge smallestEdge = *minQ.top(); // get smallest edge

            //getHash for verts
            int hashForVert1 = smallestEdge.getVert1() % verts;
            int hashForVert2 = smallestEdge.getVert2() % verts;

            //check if they been visited
            if(!visited[hashForVert1] || !visited[hashForVert2]){ // havent been to Vert1
                mst.push_back(smallestEdge);
                visited[hashForVert1] = true; // mark as visited
                visited[hashForVert2] = true; // mark as visited

            }
            minQ.pop(); // remove edge from Q
        }

        cout << "Kruskal's MST:" << endl;
        int sum = 0;
        for (int i = 0; i < mst.size(); i++) {
            Edge edge = mst.at(i);
            edge.print();
            sum += edge.getWeight();
        }

        cout << "Total Weight:" << endl << sum << endl;
    }

    void PrimMST(int startNode){
        treeHeap<Edge*> minQ = *new ::treeHeap<Edge*>();
        bool visited[verts];
        for (int i = 0; i < verts; i++) {visited[i]=false;}
        vector<Edge> mst;

        //get startNode
        Node current = myGraph.at(startNode);

        while(!allVisited(visited, verts)){

            //add edges from this node minQ
            for(int i = 0; i < current.connections.size(); i++){
                Edge* toPush = &current.connections.at(i);
                minQ.push(toPush);
            }

            //mark node as visited
            int hash = current.data % verts;
            visited[hash] = true;

            //find smallest edge >>> Node connected
            do {
                Edge edgeToMove = *minQ.top();
                minQ.pop();
                int nextNode = edgeToMove.getVert2();
                int nextHash = nextNode % verts;
                if(!visited[nextHash]){
                    current = myGraph.at(nextNode); //found new unvisited Node
                    mst.push_back(edgeToMove);
                    break;
                }

            } while (!visited[hash]);

        }

        //print out MST
        cout << "Prim's MST:" << endl;
        int sum = 0;
        for (int i = 0; i < mst.size(); i++) {
            Edge edge = mst.at(i);
            edge.print();
            sum += edge.getWeight();
        }

        cout << "Total Weight:" << endl << sum << endl;
    }

    bool allVisited(bool array[], int nodes){
        for(int i = 0; i < nodes; i++){
            if(!array[i]){return false;}
        } return true;
    }

    void BoruvkaMST(int start=0){
        //init
        int nodeSet[verts];
        for (int i = 0; i < verts; i++) {nodeSet[i] = i;}
        vector<Edge> mst;
        vector<Node> ws = myGraph;

        for(int i = 0; i < myGraph.size(); i++){
            Node current = myGraph.at(i);
            Edge min = findMinEdge(current);
            int src = find(min.getVert1(), nodeSet);
            int dest = find(min.getVert2(), nodeSet);
            if(src != dest){
                mst.push_back(min);
                unionSet(src, dest, nodeSet);
                Node rep = myGraph.at(find(src,nodeSet));
                myGraph.push_back(rep);
            }
        }

        //print out MST
        cout << "Boruvka's MST:" << endl;
        int sum = 0;
        for (int i = 0; i < mst.size(); i++) {
            Edge edge = mst.at(i);
            edge.print();
            sum += edge.getWeight();
        }

        cout << "Total Weight:" << endl << sum << endl;
    }

    //minEdge
    Edge findMinEdge(Node n){
        //n.print();
        treeHeap<Edge*> minQ = *new::treeHeap<Edge*>();

        //add edges from this node minQ
        for(int i = 0; i < n.connections.size(); i++){
            Edge* toPush = &n.connections.at(i);
            minQ.push(toPush);
        }

        return *minQ.top();
    }

    //union find
    int find( int x, int uf[]) {
        if( uf[x] == x ) return x; // x is the leader
        return find( uf[x], uf);
    }
    void unionSet( int x, int y, int uf[]) {
        uf[find( x, uf)] = find( y, uf);
    }
};

#endif /* Graphs_HAM_h */
