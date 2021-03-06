#include "pch.h"
#include <iostream>
#include "Graph.h"
#include <sstream>
#include <vector>
int main()
{
	std::cout << "To create a graph, type in it`s name. Better use a single character." << std::endl;
	std::string gName;
	std::getline(std::cin, gName);
	Graph g;
	int j = 0;
	g.setName(gName);
	std::cout << "Now, add all nodes of your graph. To add them, type their name, and then press 'Enter'. To end adding nodes, simply enter a blank name." << std::endl;
	std::string line;
	while (std::getline(std::cin, line) && !line.empty()) {
		Node tempNode;
		tempNode.setName(line);
		g.nodeList.push_back(tempNode);
	}
	std::cout << "These are your nodes, each of them has a number, written before their name. Now, to add a line, simply type '<node number 1>< ><node number 2>. To end adding lines, simply enter a blank line." << std::endl;
	for (std::list<Node>::iterator i = g.nodeList.begin(); i != g.nodeList.end(); ++i)
	{
		j += 1;
		std::cout << j << "--" << *i << std::endl;
	}
	std::vector<Node> nodeVector(g.nodeList.begin(), g.nodeList.end());
	while (std::getline(std::cin, line) && !line.empty()) {
		int n1, n2;
		Node tmpNode1, tmpNode2;
		std::stringstream ss(line);
		ss >> n1 >> n2;
		tmpNode1.setName(nodeVector[n1-1].name);
		tmpNode2.setName(nodeVector[n2-1].name);
		Line tempLine(tmpNode1, tmpNode2);
		g.lineList.push_back(tempLine);
	}
	g.getGraphCode();
	std::cout << "Programm generated .TXT file with DOT code for you to share or use in graphvix or similar GUI software." << std::endl;
	std::cout << "Number of 1-, 2-, 3-, 4- and 5- cycles in your graph: " << g.findMaxTree() << std::endl;
	std::cout << "Fundamental group of graph " << g.graphName << " is " << g.countFundGroup() << std::endl;
}