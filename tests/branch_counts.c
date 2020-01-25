/*
 ============================================================================
 Name        : GcovTest.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

int global_value = 0;

void graph_simpleblock()
{
	global_value = global_value + 1;
}

void graph_simplebranch_not_taken(int taken)
{
	if(taken > 0)
	{
		global_value = global_value + 1;
	}
}

void graph_simplebranch_taken(int taken)
{
	if(taken > 0)
	{
		global_value = global_value + 1;
	}
}

void graph_nestedbranch_simple(int taken)
{
	if (taken > 0)
	{
		global_value = global_value + taken;

		if (taken > 1)
		{
			global_value = global_value + taken;
		}
	}
	else
	{
		global_value = global_value + taken;
	}
}

void graph_nestedbranch_complex(int taken)
{
	if ((taken == 0) || (taken == 1) || (taken == 3))
	{
		global_value = global_value + taken;

		if ((taken == 1) || (taken == 2))
		{
			global_value = global_value + taken;
		}
	}
	else
	{
		global_value = global_value + taken;
	}
}

void graph_simplebranch_withcall_not_taken(int taken)
{
	if(func_compare(1, taken))
	{
		global_value = global_value + 1;
	}
}

void graph_simplebranch_withcall_taken(int taken)
{
	if(func_compare(1, taken))
	{
		global_value = global_value + 1;
	}
}

void graph_simplebranch_withnestedcalls_not_taken(int taken)
{
	if(func_compare(1, func_compare(1, taken)))
	{
		global_value = global_value + 1;
	}
}

void graph_simplebranch_withnestedcalls_taken(int taken)
{
	if(func_compare(1, func_compare(1, taken)))
	{
		global_value = global_value + 1;
	}
}

int graph_simpleelse(int taken)
{
	if(taken > 0)
	{
		global_value = global_value + 1;
	}
	else
	{
		global_value = global_value + 2;
	}
}

int graph_simpleelse_withcall(int taken)
{
	if(taken > 0)
	{
		global_value = global_value + 1;
	}
	else
	{
		global_value = global_value + func_call(2);
	}
}

void graph_simpleelse_taken(int taken)
{
	if(taken > 0)
	{
		global_value = global_value + 1;
	}
	else
	{
		global_value = global_value + 2;
		return;
	}

}

void graph_simplecall()
{
	func_call(0);
}

void graph_simplecall_throw()
{
	func_call(1);
}

void graph_multiplecall()
{
	func_call(0);
	func_call(0);
	func_call(0);
}

void graph_multiplepaths_one(int pathSelect)
{
	if(pathSelect == 1)
	{
		global_value = global_value + 1;
	}
	else if(pathSelect == 2)
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}

	return;
}

void graph_multiplepaths_two(int pathSelect)
{
	if(pathSelect == 1)
	{
		global_value = global_value + 1;
	}
	else if(pathSelect == 2)
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}

	return;
}

void graph_multiplepaths_three(int pathSelect)
{
	if(pathSelect == 1)
	{
		global_value = global_value + 1;
	}
	else if(pathSelect == 2)
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}

	return;
}

void graph_multiplepaths_decisioncall_one(int pathSelect)
{
	if(func_compare(1, pathSelect))
	{
		global_value = global_value + 1;
	}
	else if(func_compare(2, pathSelect))
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}
	
	return;
}

void graph_multiplepaths_decisioncall_two(int pathSelect)
{
	if(func_compare(1, pathSelect))
	{
		global_value = global_value + 1;
	}
	else if(func_compare(2, pathSelect))
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}
	
	return;
}

void graph_multiplepaths_decisioncall_three(int pathSelect)
{
	if(func_compare(1, pathSelect))
	{
		global_value = global_value + 1;
	}
	else if(func_compare(2, pathSelect))
	{
		global_value = global_value + 2;
	}
	else
	{
		global_value = global_value + 3;
	}
	
	return;
}

void graph_multiplepaths_withcalls_one(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(0);
	}
	else if(pathSelect == 2)
	{
		func_call(0);
	}
	else
	{
		func_call(0);
	}
}

void graph_multiplepaths_withcalls_two(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(0);
	}
	else if(pathSelect == 2)
	{
		func_call(0);
	}
	else
	{
		func_call(0);
	}
}

void graph_multiplepaths_withcalls_three(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(0);
	}
	else if(pathSelect == 2)
	{
		func_call(0);
	}
	else
	{
		func_call(0);
	}
}

void graph_multiplepaths_withcalls_throw_not(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(1);
	}
	else if(pathSelect == 2)
	{
		func_call(1);
	}
	else
	{
		func_call(1);
	}
}

void graph_multiplepaths_withcalls_throw_one(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(1);
	}
	else if(pathSelect == 2)
	{
		func_call(1);
	}
	else
	{
		func_call(1);
	}
}

void graph_multiplepaths_withcalls_throw_two(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(1);
	}
	else if(pathSelect == 2)
	{
		func_call(1);
	}
	else
	{
		func_call(1);
	}
}

void graph_multiplepaths_withcalls_throw_three(int pathSelect)
{
	if(pathSelect == 1)
	{
		func_call(1);
	}
	else if(pathSelect == 2)
	{
		func_call(1);
	}
	else
	{
		func_call(1);
	}
}

void graph_whilewithgotos_one(int pathSelect)
{
	do
	{
		if(pathSelect == 1)
		{
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 2)
		{
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 3)
		{
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		break;
	} while(1);

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_whilewithgotos_two(int pathSelect)
{
	do
	{
		if(pathSelect == 1)
		{
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 2)
		{
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 3)
		{
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		break;
	} while(1);

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_whilewithgotos_three(int pathSelect)
{
	do
	{
		if(pathSelect == 1)
		{
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 2)
		{
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		if(pathSelect == 3)
		{
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
		}

		break;
	} while(1);

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_switchwithbreaks_one(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			break;

		case 2:
			global_value = global_value + 2;
			break;

		default:
			global_value = global_value + 3;
			break;
	}

	return;
}

void graph_switchwithbreaks_two(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			break;

		case 2:
			global_value = global_value + 2;
			break;

		default:
			global_value = global_value + 3;
			break;
	}

	return;
}

void graph_switchwithbreaks_three(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			break;

		case 2:
			global_value = global_value + 2;
			break;

		default:
			global_value = global_value + 3;
			break;
	}

	return;
}

void graph_switchwithgotos_one(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		case 2:
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		default:
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
	}

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_switchwithgotos_two(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		case 2:
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		default:
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
	}

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_switchwithgotos_three(int pathSelect)
{
	switch(pathSelect)
	{
		case 1:
			global_value = global_value + 1;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		case 2:
			global_value = global_value + 2;
			goto GRAPH_WHILEWITHGOTOS_EXIT;

		default:
			global_value = global_value + 3;
			goto GRAPH_WHILEWITHGOTOS_EXIT;
	}

GRAPH_WHILEWITHGOTOS_EXIT:
	return;
}

void graph_loop_dowhile(int stopIndex)
{
	int index = 0;
	
	do
	{
		global_value = global_value + 1;
		
		index += 1;
	} while (index < stopIndex);
}

void graph_loop_for(int stopIndex)
{
	int index = 0;
	
	for (index = 0; index < stopIndex; index += 1)
	{
		if ((index % 2) == 0)
		{
			global_value = global_value + 1;
		}
	}
}

void graph_loop_while(int stopIndex)
{
	int index = 0;
	
	while (index < stopIndex) 
	{
		global_value = global_value + 1;
		
		index += 1;
	}
}


typedef void (*branchFuncPtr)(int);

int main(void)
{
	puts("!!! Starting Probes !!!");

	probe_simpleblock();

	probe_simplebranch();

	probe_simplebranch_withcalls();

	probe_simplecall();

	probe_simpleelse();

	probe_multiplecall();

	probe_multiplepaths();
	
	probe_multiplepaths_decisioncall();

	probe_multiplepaths_withcalls();

	probe_whilewithgotos();

	probe_switchwithbreaks();

	probe_switchwithgotos();
	
	graph_loop_dowhile(3);
	
	graph_loop_for(4);
	
	graph_loop_while(5);

	puts("!!! Finished Probes !!!");

	return EXIT_SUCCESS;
}

void func_call(int throw)
{
	if(throw)
	{
		puts("Called 'func_call' with throw.");

		//Cause a memory access violation
		int* ptr = 0;
		*ptr = 5;
	}
	else
		puts("Called 'func_call' with no-throw.");
}

int func_echo(int val)
{
	return val;
}

int func_compare(int eval, int aval)
{
	return eval == aval ? 1 : 0;
}

void memory_access_signal_handler(int signum)
{
	//Reset the signal handler
	signal(SIGSEGV, memory_access_signal_handler);
}

void probe_simpleblock()
{
	graph_simpleblock();
}

void probe_simplebranch()
{
	//Probe branch count for the 'Simple Branch' case
	graph_simplebranch_not_taken(0);

	graph_simplebranch_taken(1);
	graph_simplebranch_taken(1);
}

void probe_simplebranch_withcalls()
{
	graph_simplebranch_withcall_not_taken(0);

	graph_simplebranch_withcall_taken(1);
	graph_simplebranch_withcall_taken(1);

	graph_simplebranch_withnestedcalls_not_taken(0);

	graph_simplebranch_withnestedcalls_taken(1);
	graph_simplebranch_withnestedcalls_taken(1);
}

void probe_simpleelse()
{
	graph_simpleelse(1);
	graph_simpleelse_withcall(2);
}

void probe_multiplepaths()
{
	graph_multiplepaths_one(1);

	graph_multiplepaths_two(2);
	graph_multiplepaths_two(2);

	graph_multiplepaths_three(3);
	graph_multiplepaths_three(3);
	graph_multiplepaths_three(3);
}

void probe_multiplepaths_withcalls_nothrow()
{
	graph_multiplepaths_one(1);

	graph_multiplepaths_two(2);
	graph_multiplepaths_two(2);

	graph_multiplepaths_three(3);
	graph_multiplepaths_three(3);
	graph_multiplepaths_three(3);
}

void probe_multiplepaths_decisioncall()
{
	graph_multiplepaths_decisioncall_one(1);
	
	graph_multiplepaths_decisioncall_two(2);
	graph_multiplepaths_decisioncall_two(2);
	
	graph_multiplepaths_decisioncall_three(3);
	graph_multiplepaths_decisioncall_three(3);
	graph_multiplepaths_decisioncall_three(3);
}

void probe_simplecall()
{
	graph_simplecall();

	/*
	signal(SIGSEGV, memory_access_signal_handler); // initial set of signal handler

	graph_simplecall_throw();
	graph_simplecall_throw();

	signal(SIGSEGV, SIG_DFL);  // restore default behavior
	 */
}

void probe_multiplecall()
{
	graph_multiplecall();
}

void probe_multiplepaths_withcalls()
{
	graph_multiplepaths_withcalls_one(1);

	graph_multiplepaths_withcalls_two(2);
	graph_multiplepaths_withcalls_two(2);

	graph_multiplepaths_withcalls_three(3);
	graph_multiplepaths_withcalls_three(3);
	graph_multiplepaths_withcalls_three(3);

	/*
	signal(SIGSEGV, memory_access_signal_handler); // initial set of signal handler

	graph_multiplepaths_withcalls_throw_not(0);

	graph_multiplepaths_withcalls_throw_one(1);

	graph_multiplepaths_withcalls_throw_two(2);
	graph_multiplepaths_withcalls_throw_two(2);

	graph_multiplepaths_withcalls_throw_three(3);
	graph_multiplepaths_withcalls_throw_three(3);
	graph_multiplepaths_withcalls_throw_three(3);

	signal(SIGSEGV, SIG_DFL);  // restore default behavior
	 */
}

void probe_whilewithgotos()
{
	graph_whilewithgotos_one(1);

	graph_whilewithgotos_two(2);
	graph_whilewithgotos_two(2);

	graph_whilewithgotos_three(3);
	graph_whilewithgotos_three(3);
	graph_whilewithgotos_three(3);
}

void probe_switchwithbreaks()
{
	graph_switchwithbreaks_one(1);

	graph_switchwithbreaks_two(2);
	graph_switchwithbreaks_two(2);

	graph_switchwithbreaks_three(3);
	graph_switchwithbreaks_three(3);
	graph_switchwithbreaks_three(3);
}

void probe_switchwithgotos()
{
	graph_switchwithgotos_one(1);

	graph_switchwithgotos_two(2);
	graph_switchwithgotos_two(2);

	graph_switchwithgotos_three(3);
	graph_switchwithgotos_three(3);
	graph_switchwithgotos_three(3);
}
