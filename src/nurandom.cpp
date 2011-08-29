/*
 * nurandom.cpp
 * ------------
 * Main class file for nurandom.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "nurandom.h"

/* Private Methods */

NuRandom::setSources(NuRandom_ExternalSources sources)
{
    mySources = sources;

    // TODO - setup callbacks for each for population
}

NuRandom::populatePool()
{
    // TODO
}

/* Public Methods */

NuRandom::NuRandom(NuRandom_ExternalSources sources)
{
    setSources(sources);
    populatePool();
}

NuRandom::NuRandom()
{
    NuRandom_ExternalSources sources;
    sources.Urandom = 1;
    #ifdef NU_USE_RANDOMORG
    sources.RandomOrg = 0;
    #endif

    NuRandom(sources);
}

NuRandom::~NuRandom()
{
    // TODO
}
