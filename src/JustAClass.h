/*
 * JustAClass.h
 *
 *  Created on: Nov 1, 2017
 *      Author: keith
 */

#ifndef JUSTACLASS_H_
#define JUSTACLASS_H_


class JustAClass {
public:
	JustAClass(int i);
	virtual ~JustAClass();
	void speak();
private:
	int i;
};

#endif /* JUSTACLASS_H_ */
