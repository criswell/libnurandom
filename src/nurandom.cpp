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

bool NuRandom::openFile(char *filename)
{
    // FIXME - Would be nice if we had some locking here

    // Check for existance of file
    struct stat buf;
    if(stat(filename, &buf) == 0) {
        fileID = open(filename, O_RDONLY);
        isFileOpen = true;
        return true;
    } else {
        // File not found
        return false;
    }
}

void NuRandom::closeFile();
{
    if(isFileOpen) {
        close(fileID);
        isFileOpen = false;
    }
}

void NuRandom::populateSourcePool()
{
    if(openFile("/dev/urandom")) {
    } else {
        // Problem openning urandom
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
