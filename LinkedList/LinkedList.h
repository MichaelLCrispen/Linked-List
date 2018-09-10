#ifndef LinkedList_H
#define LinkedList_H


class LinkedList {
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& otherLinkedList);
	const LinkedList& operator=(const LinkedList& otherLinkedList);

	void Insert(int data);
	void Delete(int data);
	void ReWrite();
	void Destroy();
	void Divide();
	void Merge();
	bool Search(int data);
	bool isEmpty() const;
	int  Length() const;
	void PrintListByArrival();
	void ReversePrintByArrival();
	void PrintSorted();
	void ReversePrintSorted();

	//For Testing Purposes
	bool HeadNull();
	bool SHeadNull();
	bool CurrentPosNull();
	bool TailNull();
	bool STailNull();
	int ReturnHeadData();
	int ReturnTailData();
	int ReturnSHeadData();
	int ReturnSTailData();
	

private:
	typedef int ItemType;
	struct NodeType;
	typedef NodeType* NodePtr;

	struct NodeType
	{
		ItemType component;
		NodePtr forwardLink;
		NodePtr reverseLink;
		NodePtr sortedLink;
	};

	NodePtr head;
	NodePtr sHead;		//Sorted Head
	NodePtr currentPos;
	NodePtr tail;
	NodePtr sTail;		//Sorted Tail


	int length;
};


#endif