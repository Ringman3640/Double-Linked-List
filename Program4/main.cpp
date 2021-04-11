////
//Name: Franz Alarcon
//Section: A
//Program Name: Program 4 Linked List
//
//Description: This main program uses the DoubleLinkedList class
//  read from two input files and stort them in alphabetical order.
//  Various modifications are made to each list, and their node
//  count is printed after every modification to the console. After
//  all modifications are made, the FAString's static variables are
//  printed to console and modList1 and modList2 are outputted to 
//  seperate text files.
////

#include <iostream>
#include <fstream>
#include "FAString.h"
#include "DoubleLinkedList.h"

#define DLL DoubleLinkedList

void printListCounts(DLL& list1, DLL& list2, DLL& modList1, DLL& modList2);
void changer(DLL list);

int main() {
	DoubleLinkedList list1, list2, modList1, modList2;
	FAString currWord;
	std::ifstream fin;
	std::ofstream fout;

	fin.open("infile1.txt");
	if (fin.fail()) {
		fin.close();
		std::cout << "Failed to open file . . . " << std::endl;
		std::cin.ignore();
		return 1;
	}
	while (fin >> currWord) {
		list1.insert(currWord);
	}
	fin.close();

	fin.open("infile2.txt");
	if (fin.fail()) {
		fin.close();
		std::cout << "Failed to open file . . . " << std::endl;
		std::cin.ignore();
		return 1;
	}
	while (fin >> currWord) {
		list2.insert(currWord);
	}
	fin.close();
	printListCounts(list1, list2, modList1, modList2);

	modList1 = list1;
	modList2 = list2;
	printListCounts(list1, list2, modList1, modList2);

	while (list2.hasMore()) {
		modList1.remove(list2.next());
	}
	while (list1.hasMore()) {
		modList2.remove(list1.next());
	}
	printListCounts(list1, list2, modList1, modList2);

	changer(modList1);
	changer(modList2);
	printListCounts(list1, list2, modList1, modList2);

	std::cout << "FAString createdCount: " << FAString::getCreatedCount() << std::endl;
	std::cout << "FAString currentCount: " << FAString::getCurrentCount() << "\n\n";

	fout.open("outfile1.txt");
	fout << modList1;
	fout.close();
	fout.open("outfile2.txt");
	fout << modList2;
	fout.close();
}

void printListCounts(DLL& list1, DLL& list2, DLL& modList1, DLL& modList2) {
	std::cout << "Size of list1: " << list1.getCount() << std::endl;
	std::cout << "Size of list2: " << list2.getCount() << std::endl;
	std::cout << "Size of modList1: " << modList1.getCount() << std::endl;
	std::cout << "Size of modList2: " << modList2.getCount() << std::endl;
	std::cout << std::endl;
}

void changer(DLL list) {
	list.insert("ZIP");
	list.insert("ZAP");
	std::cout << "Size of list inside changer function: " << list.getCount();
	std::cout << "\n\n";
}

//Console Output:

//Size of list1: 1104
//Size of list2: 1040
//Size of modList1: 0
//Size of modList2: 0
//
//Size of list1: 1104
//Size of list2: 1040
//Size of modList1: 1104
//Size of modList2: 1040
//
//Size of list1: 1104
//Size of list2: 1040
//Size of modList1: 759
//Size of modList2: 695
//
//Size of list inside changer function: 761
//
//Size of list inside changer function: 697
//
//Size of list1: 1104
//Size of list2: 1040
//Size of modList1: 759
//Size of modList2: 695
//
//FAString createdCount: 12722603
//FAString currentCount: 3599