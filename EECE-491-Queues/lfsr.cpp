#include "lfsr.h"

LSFR::LFSR(string seed, int tap1, int tap2) 
{
	t1 = tap1;
	t2 = tap2;

}
// LFSR(...) 
// Initializes t1 and t2 to tap1 and tap2, respectively
// and parses seed string to loading queue with starting values