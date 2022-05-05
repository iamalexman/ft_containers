#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"

int main() {
//	STACK
	std::stack<int> intStack;
	ft::stack<int> myIntStack;

	std::cout << "=========================" << std::endl;
	std::cout << "   STD    STACK     FT   " << std::endl;
	std::cout << "____________|____________" << std::endl;
	std::cout << "Size: \t" << intStack.size() << "\t|\t" << myIntStack.size() << "\n";
	for (int i = 1; i < 4; i++) {
		intStack.push(i);
		myIntStack.push(i);
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "push: 1, 2, 3" << std::endl;
	std::cout << "Size: \t" << intStack.size() << "\t|\t" << myIntStack.size() << "\n";
	std::cout << "-------------------------" << std::endl;
	std::cout << "pop: 1" << std::endl;
	intStack.pop();
	myIntStack.pop();
	std::cout << "Size: \t" << intStack.size() << "\t|\t" << myIntStack.size() << "\n";
	std::cout << "-------------------------" << std::endl;
	std::cout << "print top:" << std::endl;
	std::cout << "Top: \t" << intStack.top() << "\t|\t" << myIntStack.top() << "\n";
	std::cout << "-------------------------" << std::endl;
	ft::stack<int> newIntStack;
	for (int i = 1; i < 4; i++) {
		newIntStack.push(i);
	}
	std::cout << "Size: \t" << newIntStack.size() << "\t|\t" << myIntStack.size() << "\n";
	if (newIntStack > myIntStack)
		std::cout << "newIntStack > myIntStack\n";
	else if (newIntStack == myIntStack)
		std::cout << "newIntStack == myIntStack\n";
	else
		std::cout << "newIntStack < myIntStack\n";
	std::cout << std::endl;

//  VECTOR
	std::vector<int> stdVector;
	ft::vector<int> myVector;

	std::vector<int> constStdVector;
	ft::vector<int> myConstVector;

	std::cout << "=========================" << std::endl;
	std::cout << "   STD    VECTOR    FT   " << std::endl;
	std::cout << "____________|____________" << std::endl;


	constStdVector.push_back(21);
	myConstVector.push_back(21);

	std::vector<int>::const_reference stdRef = constStdVector[0];
	ft::vector<int>::const_reference myRef = myConstVector[0];

	std::cout << "Reference: \t" << std::endl;
	std::cout << "       " << stdRef << "\t|\t" << myRef << "\n";
	std::cout << "Size: \t" << stdVector.size() << "\t|\t" << myVector.size() << "\n";
	std::cout << "-------------------------" << std::endl;

	for (int i = 10; i < 12; i++) {
		stdVector.push_back(i);
		myVector.push_back(i);
	}
	std::cout << "push_back: 10, 11" << std::endl;
	std::cout << "Size: \t" << stdVector.size() << "\t|\t" << myVector.size() << "\n";
	std::cout << "-------------------------" << std::endl;
	std::cout << "Max size: \n" << "std: " << stdVector.max_size() << "\nft:  " << myVector.max_size() << "\n";
	std::cout << "-------------------------" << std::endl;

//  constructor
	ft::vector<int> small(21, 42);
	ft::vector<int> copy(small);
	ft::vector<int> test;
	ft::vector<int> testCopy(copy.begin(), copy.end());

	test = copy;

	std::cout << "constructors: " << std::endl;
	std::cout << "size: small.size: " << small.size() << " back: " << small.back() << std::endl;
	std::cout << "size: copy(small): " << copy.size() << std::endl;
	std::cout << "size: test: " << test.size() << std::endl;
	std::cout << "size: testCopy(iters): " << testCopy.size() << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	insert
	std::cout << "insert: " << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "myVector.insert(77)" << std::endl;
	std::cout << "myVector: ";
	myVector.insert(myVector.end(), 77);
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
    myVector.insert(myVector.end(), 2, 21);
	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	myVector.insert(myVector.begin(), myVector.begin() + 1, myVector.begin() + 3);
	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	clear
	std::cout << "clear: " << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
    myVector.clear();
	std::cout << "after clear: myVector.size " << myVector.size() << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	assign
	std::cout << "assign: " << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
    myVector.assign(5, 21);
	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
  	std::cout << "myVector.size: " << myVector.size() << std::endl;
	ft::vector<int>::iterator iter = myVector.begin() + 1;
	myVector.assign(iter, myVector.begin() + 4);
	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	erase
	std::cout << "erase: " << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "erase begin + 2: "<< *myVector.erase(myVector.begin() + 2, myVector.begin() + 3) << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "erase end - 1: "<< *myVector.erase(myVector.begin(), myVector.end() - 1) << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	swap
	std::cout << "swap: " << std::endl;
	ft::vector<int> anotherVector;

	anotherVector.push_back(4);
	anotherVector.push_back(2);

	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "anotherVector: ";
	for (ft::vector<int>::iterator i = anotherVector.begin(); i < anotherVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "swap............." << std::endl;
	myVector.swap(anotherVector);

	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "anotherVector: ";
	for (ft::vector<int>::iterator i = anotherVector.begin(); i < anotherVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	resize()
	std::cout << "resize: " << std::endl;
	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "stdVector.size: " << stdVector.size() << std::endl;
	std::cout << "resize (3)............." << std::endl;

	myVector.resize(3);
	stdVector.resize(3);

	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "stdVector.size: " << stdVector.size() << std::endl;
	std::cout << "-------------------------" << std::endl;

// 	capacity / reserve
	std::cout << "capacity: " << std::endl;
	std::cout << "myVector.capacity: " << myVector.capacity() << std::endl;
	std::cout << "stdVector.capacity: " << stdVector.capacity() << std::endl;
	std::cout << "reserve (11)............." << std::endl;

	myVector.reserve(11);
	stdVector.reserve(11);

	std::cout << "myVector.size: " << myVector.size() << std::endl;
	std::cout << "stdVector.size: " << stdVector.size() << std::endl;
	std::cout << "myVector.capacity: " << myVector.capacity() << std::endl;
	std::cout << "stdVector.capacity: " << stdVector.capacity() << std::endl;
	std::cout << "-------------------------" << std::endl;

//  iterator
	std::cout << "iterator: " << std::endl;
    std::vector<int>::iterator stdIterator = stdVector.begin();
    ft::vector<int>::iterator myIterator = myVector.begin();

//	std::cout << "stdIterator: " << *stdIterator << std::endl;

//  ++ / --
	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "myIterator: " << *myIterator << std::endl;
	std::cout << "myIterator++\n";
	*myIterator++;
	std::cout << "myIterator: " << *myIterator << std::endl;
	std::cout << "++myIterator\n";
	*++myIterator;
	std::cout << "myIterator: " << *myIterator << std::endl;
	std::cout << "myIterator--\n";
	*myIterator--;
	std::cout << "myIterator: " << *myIterator << std::endl;
	std::cout << "--myIterator\n";
	*--myIterator;
	std::cout << "myIterator: " << *myIterator << std::endl;

//  const / noconst
	ft::vector<int>::const_iterator myConstIterator = myVector.begin();
	ft::vector<int>::const_iterator mySecondConstIterator(myVector.begin());
	std::vector<int>::const_iterator realConst(stdIterator + 1);

	std::cout << "myConstIterator: " << *myConstIterator << std::endl;
	std::cout << "mySecondConstIterator: " << *mySecondConstIterator << std::endl;

	myConstIterator = myIterator + 1;
	std::cout << "myConstIterator = myIterator + 1: " << *myConstIterator << std::endl;

	myIterator = myIterator + 1;

//	myConstIterator = 21;
	std::cout << "(mySecondConstIterator != myIterator): " << (mySecondConstIterator != myIterator) << std::endl;
	std::cout << "(myConstIterator == myIterator): " << (myConstIterator == myIterator) << std::endl;
	std::cout << "((myIterator + 2) - mySecondConstIterator): " << ((myIterator + 2) - mySecondConstIterator) << std::endl;
	std::cout << "-------------------------" << std::endl;

//  reverse iterator
	std::cout << "reverse_iterator: " << std::endl;
	ft::vector<int>::reverse_iterator myReverseIterator = myVector.rbegin();
	std::vector<int>::reverse_iterator stdReverseIterator = stdVector.rbegin();
	ft::vector<int>::const_reverse_iterator myConstReverseIterator(myVector.rbegin());

	for (int i = 0; i < 5; ++i) {
		myReverseIterator[i] = (5 - i) * 5;
		stdReverseIterator[i] = (5 - i) * 5;
	}

	std::cout << "stdVector: ";
	for (std::vector<int>::iterator i = stdVector.begin(); i < stdVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "myVector: ";
	for (ft::vector<int>::iterator i = myVector.begin(); i < myVector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "stdReverseIterator += 2: " << *(stdReverseIterator += 2) << std::endl;
	std::cout << "myReverseIterator += 2: " << *(myReverseIterator += 2) << std::endl;
	std::cout << "stdReverseIterator -= 1: " << *(stdReverseIterator -= 1) << std::endl;
	std::cout << "myReverseIterator -= 1: " << *(myReverseIterator -= 1) << std::endl;
	std::cout << "stdReverseIterator: " << *stdReverseIterator << std::endl;
	std::cout << "(myReverseIterator < myConstReverseIterator): " << (myReverseIterator < myConstReverseIterator) << std::endl<<std::endl;

//  MAP
	std::cout << "=========================" << std::endl;
	std::cout << "   STD     MAP      FT   " << std::endl;
	std::cout << "____________|____________" << std::endl;

//  upper bound / lower bound
	std::map<int, int> stdMap;
	std::map<int, int>::iterator stdItLowBound;
	std::map<int, int>::iterator stdItUpBound;

	stdMap[1]=1;
	stdMap[1]=9;
	stdMap[2]=2;
	stdMap[3]=3;
	stdMap[4]=4;
	stdMap[5]=5;
	stdItLowBound = stdMap.lower_bound(2);
	stdItUpBound = stdMap.upper_bound(4);

	ft::map<int, int> myMap;
	ft::map<int, int>::iterator myItLowBound;
	ft::map<int, int>::iterator myItUpBound;

	myMap[1]=1;
	myMap[1]=9;
	myMap[2]=2;
	myMap[3]=3;
	myMap[4]=4;
	myMap[5]=5;
	myItLowBound = myMap.lower_bound(2);
	myItUpBound = myMap.upper_bound(4);

	std::cout << "key   value  key   value" << std::endl;
	std::map<int, int>::iterator i = stdMap.begin();
	ft::map<int, int>::iterator j = myMap.begin();
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

	std::cout << "lower bounds / upper bounds / make_pair: " << std::endl;
	if (stdItLowBound != stdMap.end())
		std::cout << "stdItLowBound(2): " << stdItLowBound->first << std::endl;
	if (stdItUpBound != stdMap.end())
		std::cout << "stdItUpBound(4): " << stdItUpBound->first << std::endl;
	if (stdItLowBound != stdMap.end())
		std::cout << "myItLowBound(2): " << myItLowBound->first << std::endl;
	if (stdItUpBound != stdMap.end())
		std::cout << "myItUpBound(4): " << myItUpBound->first << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::map<int, std::string> realMap;
	ft::map<int, std::string> myStrMap;

	std::cout << "make pair: " << std::endl;
	std::pair<int, std::string> stdPair = std::make_pair(1, "FIRST");
	ft::pair<int, std::string> myPair = ft::make_pair(1, "FIRST");
	ft::pair<int, std::string> copyPair(myPair);

	std::cout << "stdPair: key->" << stdPair.first << " value->" << stdPair.second << std::endl;
	std::cout << "myPair: key->" << myPair.first << " value->" << myPair.second << std::endl;
	std::cout << "copyPair: key->" << copyPair.first << " value->" << copyPair.second << std::endl;
	std::cout << "-------------------------" << std::endl;

//  max size
	std::cout << "size / max_size: " << std::endl;
	std::cout << "realMap.size: " << realMap.size() << std::endl;
	std::cout << "myStrMap.size: " << myStrMap.size() << std::endl;
	std::cout << "realMap.max_size: " << realMap.max_size() << std::endl;
	std::cout << "realMap.max_size: " << myStrMap.max_size() << std::endl;
	std::cout << "-------------------------" << std::endl;

	myMap.clear();
	stdMap.clear();

//  insert
	std::cout << "insert: " << std::endl;

	i = stdMap.begin();
	j = myMap.begin();

	for (int i = 1; i < 4; ++i) {
		myMap.insert(ft::make_pair(i, 21));
		stdMap.insert(std::make_pair(i, 21));
	}

	i = stdMap.begin();
	j = myMap.begin();

	std::cout << "key   value  key   value" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}

	i = stdMap.begin();
	j = myMap.begin();

	stdMap.insert(i, std::pair<int, int>(0,42));
	myMap.insert(j, ft::pair<int, int>(0,42));

	i = stdMap.begin();
	j = myMap.begin();

	std::cout << "after insert pair(0, 42)" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}

	std::map<int, int> anotherStdMap;
	ft::map<int, int> anotherFtMap;

	for (int i = 9; i > 6; --i) {
		anotherFtMap.insert(ft::make_pair(i, 77));
		anotherStdMap.insert(std::make_pair(i, 77));
	}

	i = anotherStdMap.begin();
	j = anotherFtMap.begin();
	std::cout << "another map(i, 77)" << std::endl;
	std::cout << "key   value  key   value" << std::endl;
	for (; i != anotherStdMap.end() and j != anotherFtMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}

	std::cout << "myMap insert from another map: " << std::endl;
	stdMap.insert(anotherStdMap.begin(), anotherStdMap.find(9));
	myMap.insert(anotherFtMap.begin(), anotherFtMap.find(9));
	i = stdMap.begin();
	j = myMap.begin();
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

//  erase
	std::cout << "erase: " << std::endl;
	std::cout << "erase from iterator(3)" << std::endl;
	i = stdMap.find(3);
	j = myMap.find(3);

	stdMap.erase(i);
	myMap.erase(j);

	i = stdMap.begin();
	j = myMap.begin();
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	stdMap.erase(8);
	myMap.erase(8);

	i = stdMap.begin();
	j = myMap.begin();
	std::cout << "erase from key(8)" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}

	i = stdMap.find(1);
	j = myMap.find(1);

	stdMap.erase(i, stdMap.find(7));
	myMap.erase(j, myMap.find(7));
	i = stdMap.begin();
	j = myMap.begin();

	std::cout << "erase from range(1 - 7)" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

//  value compare / key compare
	ft::map<int, int>::const_iterator constIt = myMap.begin();
	ft::pair<int, int> myNewPair = *myMap.rbegin();
	j = myMap.begin();

	std::cout << "key compare / value compare: " << std::endl;
	std::cout <<  "key compare(0,21): " << myMap.key_comp()(0, 21) << std::endl;
	std::cout <<  "value compare(0,77): " << myMap.value_comp()(*j, myNewPair) << std::endl;
	std::cout << "-------------------------" << std::endl;

//  equal_range
	std::cout << "equal_range: " << std::endl;
	std::map<char,int> myCharMap;

	myCharMap['a']=10;
	myCharMap['b']=20;
	myCharMap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = myCharMap.equal_range('b');

	std::cout << "lower bound: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "-------------------------" << std::endl;

//  clear
	i = stdMap.begin();
	j = myMap.begin();

	std::cout << "clear" << std::endl;
	std::cout << "key   value  key   value" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	std::cout << "clear:" << std::endl;
	myMap.clear();
	stdMap.clear();
	std::cout << "key   value  key   value" << std::endl;
	for (; i != stdMap.end() and j != myMap.end(); i++, j++) {
		std::cout << i->first << "     " << i->second << "      " <<  j->first << "     " << j->second << std::endl;
	}
	std::cout << std::endl;

//  SET
	std::cout << "=========================" << std::endl;
	std::cout << "   STD     SET      FT   " << std::endl;
	std::cout << "____________|____________" << std::endl;

	std::set<char> stdSet;
	ft::set<char> mySet;

	std::cout << "size / max_size: " << std::endl;
	std::cout << "stdSet.size: " << stdSet.size() << std::endl;
	std::cout << "mySet.size: " << mySet.size() << std::endl;
	std::cout << "stdSet.max_size: " << stdSet.max_size() << std::endl;
	std::cout << "mySet.max_size: " << mySet.max_size() << std::endl;
	std::cout << "-------------------------" << std::endl;

//	methods
	std::cout << "methods" << std::endl;
	std::cout << "insert(a - d): " << std::endl;
	for (char i = 'a'; i < 'd'; i++) {
		stdSet.insert(i);
		mySet.insert(i);
	}

	std::set<char>::iterator itStdSet = stdSet.begin();
	ft::set<char>::iterator itFtSet = mySet.begin();

	std::cout << "std   ft" << std::endl;
	for (; itStdSet != stdSet.end() and itFtSet != mySet.end(); itStdSet++, itFtSet++) {
		std::cout << *itStdSet  << "      " <<  *itFtSet << "     " << std::endl;
	}

	std::cout << "		        std    ft" << std::endl;
	std::cout << "set.begin():     " << *stdSet.begin() << "      " <<  *mySet.begin() << std::endl;
	std::cout << "set.end():       " << *(--stdSet.end()) << "      " <<  *(--mySet.end()) << std::endl;
	std::cout << "set.rbegin():    " << *stdSet.rbegin() << "      " <<  *mySet.rbegin() << std::endl;
	std::cout << "set.rend():      " << *(--stdSet.rend()) << "      " <<  *(--mySet.rend()) << std::endl;
	std::cout << "set.size():      " << stdSet.size() << "      " <<  mySet.size() << std::endl;
	itStdSet = stdSet.find('b');
	itFtSet = mySet.find('b');
	std::cout << "set.find(b):     " << *itStdSet << "      " <<  *itFtSet << std::endl;
	std::cout << "set.empty():     " << stdSet.empty() << "      " <<  mySet.empty() << std::endl;
	std::cout << "set.erase('a'):  " << stdSet.erase('a') << "      " <<  mySet.erase('a') << std::endl;

	itStdSet = stdSet.begin();
	itFtSet = mySet.begin();

	std::cout << "set.erase(it)   " << std::endl << std::endl;

	stdSet.erase(itStdSet);
	mySet.erase(itFtSet);
	itStdSet = stdSet.begin();
	itFtSet = mySet.begin();

	std::cout << "std   ft" << std::endl;
	for (; itStdSet != stdSet.end() and itFtSet != mySet.end(); itStdSet++, itFtSet++) {
		std::cout << *itStdSet  << "      " <<  *itFtSet << "     " << std::endl;
	}
	std::cout << "set.clear()   " << std::endl;

	stdSet.clear();
	mySet.clear();
	itStdSet = stdSet.begin();
	itFtSet = mySet.begin();
	
	std::cout << "std   ft" << std::endl;
	for (; itStdSet != stdSet.end() and itFtSet != mySet.end(); itStdSet++, itFtSet++) {
		std::cout << *itStdSet  << "      " <<  *itFtSet << "     " << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	return 0;
 }
