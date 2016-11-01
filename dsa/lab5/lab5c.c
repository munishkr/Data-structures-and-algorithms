#include <stdio.h>
#include <glib.h>

typedef Glist list;
list* st= malloc(sizeof(list));

list* iterator;
for(i=st;i;i=i->next)
