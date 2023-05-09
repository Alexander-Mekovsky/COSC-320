#ifndef MAX_h_
#define MAX_h_

#include "d_tnode.h"

#ifndef NULL
#include <cstddef>
#endif

void countMax(tnode<int> *t, int& max)
{
    if(t != NULL)
    {
        if(t->nodeValue > max)
            max = t->nodeValue;
        countMax(t->left, max);
		countMax(t->right, max);
    }
}

tnode<int> *buildIntTreeLab02()
{
    tnode<int> *root, *b, *c, *d, *e, *f;
	d = new tnode<int> (5);
	e = new tnode<int> (48);
	f = new tnode<int> (12);
	b = new tnode<int> (40, d, (tnode<int> *)NULL);
	c = new tnode<int> (15, e, f);
	root = new tnode<int> (35, b, c);
    return root;
}

#endif