#ifndef countOneChild_h_
#define countOneChild_h_

#include "d_tnode.h"

#ifndef NULL
#include <cstddef>
#endif


void countOneChild(tnode<char> *t, int& count)
{
    if(t != NULL)
    {
        if((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL))
            count++;
        countOneChild(t->left, count);
		countOneChild(t->right, count);
    }
}

tnode<char> *buildCharTreeLab01()
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