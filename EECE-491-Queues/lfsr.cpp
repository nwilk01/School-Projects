#include "lfsr.h"
#include <iostream>
#include <string>

LFSR::LFSR(string seed, int tap1, int tap2) 
{
	t1 = tap1;
	t2 = tap2;
	for(int i=0; i<seed.length();i++)
	{
		int key = seed[i] - '0';
		q.Enqueue(key);
	}
	
}
// LFSR(...) 
// Initializes t1 and t2 to tap1 and tap2, respectively
// and parses seed string to loading queue with starting values

void LFSR::NextState()
{
	int temp = q.Peek(t1)^q.Peek(t2);
	q.Dequeue();
	q.Enqueue(temp);
}
