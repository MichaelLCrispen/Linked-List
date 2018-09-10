#include "LinkedList.h"
#include <iostream>


using namespace std;


void TestCreate();
void TestInsert(LinkedList);
void TestPass(LinkedList);
void TestEqualOperator(LinkedList);

int main() {
	cout << "Start Of Program" << endl;
	LinkedList test;

	test.Insert(9);
	test.Insert(6);
	test.Insert(4);
	test.Insert(10);
	test.Insert(12);
	test.Insert(5);
	test.Insert(3);
	test.Insert(7);
	test.Insert(1);
	test.Insert(2);

	cout << "Created Linked List" << endl << endl;
	TestCreate();
	cout << endl << "Ending Creation Test...." << endl << endl << endl;

	cout << "Insert Test" << endl << endl;
	TestInsert(test);
	cout << "Ending Insert Test...." << endl << endl << endl;

	cout << "Normal Print Test" << endl << endl;
	test.PrintListByArrival();
	cout << endl << endl << "End Normal Print Test " << endl << endl;

	cout << "Sorted Print Test" << endl << endl;
	test.PrintSorted();
	cout << endl << endl << "End Sorted Print Test " << endl << endl;

	cout << "Print Reverse by Arrival Test" << endl << endl;
	test.ReversePrintByArrival();
	cout << endl << endl << "End Reverse Print Test....." << endl << endl;


	cout << "Starting Pass test" << endl << endl;
	TestPass(test);
	cout << endl << endl << "Ending Print Test....." << endl << endl;

	cout << "Starting &= Test" << endl << endl;
	TestEqualOperator(test);
	cout << endl << endl << "Ending Equal Test....." << endl << endl;
	
	
	cout << "Starting Delete Test" << endl << endl;
	cout << "Deleting an item in the list (10)" << endl << endl;
	test.Delete(10);
	test.PrintListByArrival();
	cout << endl;
	test.PrintSorted();
	cout << endl << endl << "Deleting an item not in the list(50)" << endl << endl;
	test.Delete(50);
	test.PrintListByArrival();
	cout << endl << endl << "Ending Delete Test....." << endl << endl;

	cout << "Starting Search Test" << endl << endl;
	cout << "Searching an item in the list (3)" << endl << endl;
	if (test.Search(3))
		cout << "A 3 Has been found" << endl << endl;
	else
		cout << "3 Was not found" << endl << endl;

	cout << "Searching an item not in the list (500)" << endl << endl;
	if (test.Search(500))
		cout << "A 500 Has been found" << endl << endl;
	else
		cout << "500 Was not found";

	cout << endl << endl << "Ending Search Test....." << endl << endl;

	cout << "Starting Destroy Test" << endl << endl;
	test.Destroy();
	test.PrintListByArrival();
	cout << endl << endl << "Ending Destroy Test....." << endl << endl;


	cout << endl << endl << "End Of Tests" << endl << endl;
	system("pause");
	return 0;
}


void TestCreate() {
	LinkedList test;
	cout << "Checking Correct Values:" << endl << endl;
	cout << "head Null        :  " << test.HeadNull() << endl;
	cout << "sHead Null       :  " << test.SHeadNull() << endl;
	cout << "currentPos Null  :  " << test.CurrentPosNull() << endl;
	cout << "tail Null        :  " << test.TailNull() << endl;
	cout << "sTail Null       :  " << test.STailNull() << endl;
	cout << "length           :  " << test.Length() << endl;

	return;
}

void TestInsert(LinkedList test){

	cout << "Head Data        :  " << test.ReturnHeadData() << endl;
	cout << "Tail Data        :  " << test.ReturnTailData() << endl;
	cout << "sHead Data        :  " << test.ReturnSHeadData() << endl;
	cout << "sTail Data        :  " << test.ReturnSTailData() << endl;
	cout << "length           :  " << test.Length() << endl << endl;
	return;
}


void TestPass(LinkedList test) {
	test.PrintListByArrival();
	cout << endl;
	test.PrintSorted();
	return;
}

void TestEqualOperator(LinkedList test) {
	LinkedList equalTest = test;
	equalTest.PrintListByArrival();
	return;
}