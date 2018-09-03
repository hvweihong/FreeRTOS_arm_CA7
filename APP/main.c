/*
 * @Author: harvey.zheng
 * @Date: 2018-09-03 14:53:23
 */
#include <stdio.h>
#include <limits.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

int main( void )
{
	static uint32_t test_cnt = 0;
	while(1)
	{
		test_cnt++;
	}
	/* Don't expect to reach here. */
	return 0;
}


