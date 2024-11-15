#ifndef _BpTree_H_
#define _BpTree_H_

#include "BpTreeNode.h"
#include "BpTreeDataNode.h"
#include "BpTreeIndexNode.h"
#include "FlightData.h"
// BpTree

class BpTree{
private:
	BpTreeNode*	root;
	int			order;		// m children
	ofstream* fout;

public:
	BpTree(ofstream *fout, int order = 3){
		root = NULL;
		this->order = order;
		this->fout = fout;
	}
	~BpTree() {
		if (root != nullptr) {
			delete root; 
		}
	}
	bool		Insert(FlightData* newData);
	bool		excessDataNode(BpTreeNode* pDataNode);
	bool		excessIndexNode(BpTreeNode* pIndexNode);
	void		splitDataNode(BpTreeNode* pDataNode);
	void		splitIndexNode(BpTreeNode* pIndexNode);
	BpTreeNode* getRoot() { return root; }
	BpTreeNode*	searchDataNode(string n); 

	bool	SearchRange(string start, string end);
	void	Print(); // print all 
	FlightData* findFlightData(string key);
	BpTreeDataNode* findDataNode(string key); //find Node with key

};

#endif
