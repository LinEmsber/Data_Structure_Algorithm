/* A memory pool
 * File: mp.c
 * Author: Lin Emsber
 * Create Date: 2017, Feb, 1
 */

#include <stdio.h>
#include <stdlib.h>

#include "mem_pool.h"

// ========== private functions ==========


// ========== functions ==========


/* create a memory pool which has block_count number of block, and each of block's size is block_size
 *
 * @block_size: the size of one block
 * @block_count: the number of block
 */
mem_pool_t * mem_pool_create (uint32_t block_size, uint32_t block_count)
{

	// create a mem_pool
	mem_pool_t * mp;
	mp = malloc ( sizeof( *mp ) );
	if( !mp )
		return NULL;

	// allocate a space
	void * space = malloc(block_count * block_size);
	if ( !space ){
		free(mp);
		return NULL;
	}

	// set the pool's space
	mp->start = space;
	mp->end = space + (block_count * block_size);
	mp->current = space;

	mp->block_size = block_size;
	mp->block_count = block_count;
	mp->next = 0;

	return mp;
}

mem_pool_t * mem_pool_add_block (mem_pool_t * mp, uint32_t size)
{
	// create a mem_block
	mem_block_t * mb;
	mb = malloc ( sizeof ( *mb ) );
	if ( !mb )
		return NULL;

	// assign memory for this block
	mb->mem_block_start = mp->current;
	mb->mem_block_end = mp->current + size;
	mp->current = mp->current + size;

	// check
}


/* align byte boundary
 */
uint32_t mem_pool_align(uint32_t size)
{
	return (size + (MEM_POOL_ALIGN_SIZE - 1)) & ~(MEM_POOL_ALIGN_SIZE - 1);
}

/* decide mp_entry size
 */
uint32_t mem_pool_check_size(uint32_t size)
{
	return size <= 0 ? MEM_POOL_SIZE : mem_pool_align(size);
}