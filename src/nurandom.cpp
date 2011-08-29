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

void NuRandom::setSources(NuRandom_ExternalSources sources)
{
    mySources = sources;

    // TODO - setup callbacks for each for population
}

void NuRandom::populatePoolFromFile(
    char *filename, int64_t *array, int arrayLen)
{
    struct stat buf;
    int fileID;
    int64_t randomNum;

    if(stat(filename, &buf) == 0) {
        fileID = open(filename, O_RDONLY);

        for(int i = 0; i < arrayLen; i++) {
            read(fileID, &randomNum, sizeof randomNum);
            array[i] = randomNum;
        }
    } else {
        // File not found
    }
}

void NuRandom::populatePool()
{
    // TODO
}

/* Public Methods */

NuRandom::NuRandom(NuRandom_ExternalSources sources)
{
    setSources(sources);
    populateSourcePool();
    populatePool();
}

NuRandom::NuRandom()
{
    NuRandom_ExternalSources sources;
    sources.Urandom = 1;
    sources.Crandom = 0;
    #ifdef NU_USE_RANDOMORG
    sources.RandomOrg = 0;
    #endif

    NuRandom(sources);
}

NuRandom::~NuRandom()
{
    // TODO
}
