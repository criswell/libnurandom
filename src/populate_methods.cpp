/*
 * populate_methods.cpp
 * --------------------
 * The methods for populating various pools.
 */

#include "nurandom.h"

void NuRandom::populatePool_Urandom()
{
    populatePoolFromFile("/dev/urandom", numPool, MEMORY_POOL_SIZE);
}

#ifdef NU_USE_RANDOMORG
void NuRandom::populatePool_RandomOrg()
{
    // TODO
}
#endif