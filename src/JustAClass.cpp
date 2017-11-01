/*
 * JustAClass.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: keith
 */
#include <iostream>
#include "JustAClass.h"

JustAClass::JustAClass(int i):i(i) {
	// TODO Auto-generated constructor stub
}

JustAClass::~JustAClass() {
	// TODO Auto-generated destructor stub
}
void JustAClass::speak(){
	std::cout<<"I am instance:"<<i<<std::endl;
}

