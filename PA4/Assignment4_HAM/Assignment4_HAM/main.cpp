//
//  main.cpp
//  Assignment4_HAM
//
//  Created by Hugh A. Miles on 12/5/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include "Graphs_HAM.h"

int main(int argc, const char * argv[]) {
    Graph* graph = new Graph(3);

    graph->addVert(1);
    graph->addVert(2);
    graph->addVert(3);
    graph->addVert(4);
    graph->addVert(5);
    graph->addVert(6);

    graph->createEdge(1,2,1);
    graph->createEdge(1,6,2);
    graph->createEdge(7,8,3);

    graph->print();
}
