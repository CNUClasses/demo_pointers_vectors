//============================================================================
// Name        : demo_pointers_vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <memory>
#include <vector>
#include <time.h>
#include "JustAClass.h"
void vectors_with_pointers(){
	std::vector<JustAClass*> myClasses;

	//add a few classes
	for (int i=0;i<10;i++)
		myClasses.push_back(new JustAClass(i));

	//talk
	for (int i=0;i<10;i++)
		myClasses[i]->speak();

	//time to go delete what the pointers point to and let the vector
	//manage the pointers themselvescause vector will not delete, gotta be a better way
	for (std::vector<JustAClass*>:: iterator myiter = myClasses.begin(); myiter != myClasses.end(); ++myiter)
		delete (*myiter);
}

void vectors_with_unique_pointers(){
	//BETTER THAN ABOVE SINCE YOU DO NOT NEED TO DELETE THE POINTERS
	//use smart pointers, specifically unique pointer, kind of RIAA for pointers they auto delete themselves
	//note C++11 only!
	std::vector<std::unique_ptr<JustAClass>> myUniqueClasses;

	//add a few classes
	for (int i=0;i<10;i++){
		myUniqueClasses.push_back(std::unique_ptr<JustAClass>(new JustAClass(i)));

		//or new in  c++11, same function as above but with  abridged syntax
		myUniqueClasses.emplace_back(new JustAClass(i));
	}

	//talk, enhanced for, type is automatically inferred
	//note that you get x by reference, without the & x would be a copy
	//which is forbidden with unique pointers, so it would not compile
	for (auto &x : myUniqueClasses)
		x->speak();

	//dont need to delete, Yay smart pointer
}

int main(){
	vectors_with_pointers();
	vectors_with_unique_pointers();
}

