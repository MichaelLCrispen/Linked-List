#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {

	
	head = nullptr;
	sHead = nullptr;
	currentPos = nullptr;
	tail = nullptr;
	sTail = nullptr;

	length = 0;
}


LinkedList::~LinkedList() {
	NodePtr temp;
	NodePtr curr = head;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->forwardLink;
		delete temp;
	}
	head = nullptr;
	sHead = nullptr;
	currentPos = nullptr;
	tail = nullptr;
	sTail = nullptr;
	return;
}

LinkedList::LinkedList(const LinkedList & otherLinkedList){
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr) {
		head = nullptr;
		sHead = nullptr;
		return;
	}

	from = otherLinkedList.head;
	head = new NodeType;
	head->component = from->component;
	sHead = head;
	sTail = head;

	to = head;
	head->reverseLink = nullptr;
	from = from->forwardLink;
	while (from != nullptr) {
		to->forwardLink = new NodeType;
		to = to->forwardLink;
		to->component = from->component;
		to->reverseLink = from->reverseLink;
		to->sortedLink = from->sortedLink;
		if (to->component < sHead->component)
			sHead = to;
		if (to->component > sTail->component)
			sTail = to;
		from = from->forwardLink;
	}

	to->forwardLink = nullptr;
	tail = to;
}

const LinkedList & LinkedList::operator=(const LinkedList & otherLinkedList)
{
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr) {
		head = nullptr;
		sHead = nullptr;
	}

	else {
		from = otherLinkedList.head;
		head = new NodeType;
		head->component = from->component;
		sHead = head;
		sTail = head;

		to = head;
		from = from->forwardLink;
		while (from != nullptr) {
			to->forwardLink = new NodeType;
			to = to->forwardLink;
			to->component = from->component;
			to->reverseLink = from->reverseLink;
			to->sortedLink = from->sortedLink;
			from = from->forwardLink;

			if (to->component < sHead->component)
				sHead = to;
			if (to->component > sTail->component)
				sTail = to;
		}

		to->forwardLink = nullptr;
		tail = to;
	}
	return *this;
}

void LinkedList::Insert(int data) {
	NodePtr newNodePtr;
	NodePtr currPtr;
	NodePtr prevPtr;

	newNodePtr = new NodeType;
	newNodePtr->component = data;


	//New List
	if (head == nullptr) {
		newNodePtr->forwardLink = nullptr;
		newNodePtr->reverseLink = nullptr;
		newNodePtr->sortedLink = nullptr;
		head = newNodePtr;
		tail = newNodePtr;
		sHead = newNodePtr;
		sTail = newNodePtr;
	}

	//Insert at end of list
	else {
		currPtr = head;
		prevPtr = nullptr;
		while (currPtr != nullptr)
		{
			prevPtr = currPtr;
			currPtr = currPtr->forwardLink;
		}

		newNodePtr->forwardLink = currPtr;

		if (prevPtr == nullptr) {
			head = newNodePtr;
			head->reverseLink = nullptr;
		}

		else {
			newNodePtr->reverseLink = prevPtr;
			prevPtr->forwardLink = newNodePtr;
		}
		tail = newNodePtr;

		//Sorted Pointer
		currPtr = sHead;
		prevPtr = nullptr;

		while (currPtr != nullptr && currPtr->component < data)
		{
			prevPtr = currPtr;
			currPtr = currPtr->sortedLink;
		}
		newNodePtr->sortedLink = currPtr;
		if (prevPtr == nullptr)
			sHead = newNodePtr;
		else
			prevPtr->sortedLink = newNodePtr;
		if (currPtr == nullptr)
			sTail = newNodePtr;	

		sTail->sortedLink = nullptr;
	}

	length++;
	return;
}

void LinkedList::Delete(int data){
	NodePtr prevPtr = nullptr;
	NodePtr currPtr = sHead;

	while (currPtr != nullptr && currPtr->component != data && currPtr->component < data) {
		prevPtr = currPtr;
		currPtr = currPtr->sortedLink;
	}

	if (currPtr != nullptr && currPtr->component == data) {
		

		if (currPtr == sHead) {
			sHead = currPtr->sortedLink;
		}

		else {
			prevPtr->sortedLink = currPtr->sortedLink;
		}
		
		if (currPtr == sTail)
			sTail = prevPtr;

		currPtr = head;
		prevPtr = nullptr;
		while (currPtr->component != data) {
			prevPtr = currPtr;
			currPtr = currPtr->forwardLink;
		}


			if (currPtr == head) {
				head = currPtr->forwardLink;
				head->reverseLink = nullptr;
			}

			else {
				prevPtr->forwardLink = currPtr->forwardLink;
				prevPtr->reverseLink = currPtr->reverseLink;
			}

			if (currPtr == tail)
				tail = prevPtr;

		
		delete currPtr;
		length--;

	}
}

void LinkedList::ReWrite() {

}

void LinkedList::Destroy() {
	NodePtr temp;
	NodePtr curr = head;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->forwardLink;
		delete temp;
	}
	head = nullptr;
	sHead = nullptr;
	currentPos = nullptr;
	tail = nullptr;
	sTail = nullptr;
	length = 0;

	return;
}

void LinkedList::Divide() {

}

void LinkedList::Merge() {

}

bool LinkedList::Search(int data) {
	NodePtr prevPtr = nullptr;
	NodePtr currPtr = sHead;

	while (currPtr != nullptr && currPtr->component != data && currPtr->component < data) {
		prevPtr = currPtr;
		currPtr = currPtr->sortedLink;
	}

	if (currPtr != nullptr && currPtr->component == data) {
		return true;
	}

	return false;
}

bool LinkedList::isEmpty() const {
	if (length == 0)
		return true;
	return false;
}

int LinkedList::Length() const{
	return length;
}

void LinkedList::PrintListByArrival() {
	NodePtr curr = head;

	if (length == 0)
		std::cout << "This list is empty";

	while (curr != nullptr) {
		std::cout << curr->component << " ";
		curr = curr->forwardLink;
	}
	return;
}

void LinkedList::ReversePrintByArrival() {
	NodePtr currPtr = tail;

	if (length == 0)
		std::cout << "This list is empty";

	while (currPtr != nullptr) {
		std::cout << currPtr->component << " ";
		currPtr = currPtr->reverseLink;
	}
	return;

}

void LinkedList::PrintSorted() {
	
	NodePtr currentPointer = sHead;
		
	if (length == 0)
		std::cout << "This list is empty";

	while (currentPointer != nullptr) {
		std::cout << currentPointer->component << " ";
		currentPointer = currentPointer->sortedLink;
	}
	return;
	
}

void LinkedList::ReversePrintSorted() {

}




//*******************TESTING FUNCTIONS****************

bool LinkedList::HeadNull() {
	if (head == nullptr) {
		return true;
	}

	return false;

}

bool LinkedList::SHeadNull() {
	if (sHead == nullptr) {
		return true;
	}

	return false;
}

bool LinkedList::CurrentPosNull() {
	if (currentPos == nullptr) {
		return true;
	}

	return false;
}

bool LinkedList::TailNull() {
	if (tail == nullptr) {
		return true;
	}

	return false;
}

bool LinkedList::STailNull() {
	if (sTail == nullptr) {
		return true;
	}

	return false;
}

int LinkedList::ReturnHeadData() {
	return head->component;
}

int LinkedList::ReturnTailData() {
	return tail->component;
}

int LinkedList::ReturnSHeadData() {
	return sHead->component;
}

int LinkedList::ReturnSTailData() {
	return sTail->component;
}