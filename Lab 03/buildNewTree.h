#ifndef BUILDNEWTREE_H_
#define BUILDNEWTREE_H_

#include "d_tnode.h"

#ifndef NULL
#include <cstddef>
#endif

using namespace std;

tnode<char> *buildTreeLab01()
{
    tnode<char> *root, *b, *c, *d, *e, *f, *g;
    g = new tnode<char> ('G');
	d = new tnode<char> ('D');
	e = new tnode<char> ('E', (tnode<char> *)NULL, g);
	f = new tnode<char> ('F');
	b = new tnode<char> ('B', d, (tnode<char> *)NULL);
	c = new tnode<char> ('C', e, f);
	root = new tnode<char> ('A', b, c);
    return root;
}

#endif