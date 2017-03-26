/* main */

/* An main function of doubly linked list.
 * File: main.c
 * Author: Lin Emsber
 * Create Date: 2017, Mar, 19
 */

#include <stdio.h>
#include <stdlib.h>

#include "doubly_list.h"
#include "generic.h"


int main()
{
        node_t * n_tmp;
        list_t * list_entry = list_create();

        node_t * n1 = node_create(10);
        node_t * n2 = node_create(30);
        node_t * n3 = node_create(50);
        node_t * n4 = node_create(20);
        node_t * n5 = node_create(40);
        node_t * n6 = node_create(130);
        node_t * n7 = node_create(100);

        list_head_insert_node(list_entry, n1);
        list_head_insert_node(list_entry, n2);
        list_head_insert_node(list_entry, n3);
        list_head_insert_node(list_entry, n4);
        list_head_insert_node(list_entry, n5);

        list_tail_insert_node(list_entry, n6);
        list_tail_insert_node(list_entry, n7);
        printf("list_count(list_entry): %d\n", list_count(list_entry));

        n_tmp = list_head_pop_node(list_entry);
        node_free(n_tmp);
        // n_tmp = NULL;
        printf("list_count(list_entry): %d\n", list_count(list_entry));

        n_tmp = list_tail_pop_node(list_entry);
        node_free(n_tmp);
        printf("list_count(list_entry): %d\n", list_count(list_entry));

        print_list(list_entry->head);

        list_free(list_entry);

	return 0;
}