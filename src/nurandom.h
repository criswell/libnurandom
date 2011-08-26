/*
   Copyright 2011 Sam Hart <hartsn@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
 * Random number library.
 */

/*! \mainpage nurandom, random number library
 * \author Sam Hart
 * \copyright Apache License, Version 2.0
 * \version 2011.08.0
 *
 * nurandom is a random number library that pulls random numbers from  a
 * variety of external sources.
 *
 * Its homepage can be found here https://bitbucket.org/criswell/libnurandom .
 */

#ifndef nurandom_H
#define nurandom_H

//! The size of the memory pool of random ints (in 64bit Integers)
#define MEMORY_POOL_SIZE 256

//! The struct for the external sources weights
/*!
 * Here, you set the weights for each of the potential external sources.
 * A higher number indicates a lower weight. E.g., a 1 would be the highest
 * weight possible.
 *
 * Zero (0) is a special case, however. A weight of 0 means that the
 * particular external source is disabled.
 *
 * \remarks At least one of the external sources available must be enabled.
 * If none are, then Urandom becomes the default.
 */
struct NuRandom_ExternalSources
{
    //! Use /dev/urandom
    uint Urandom;

    #ifdef NU_USE_RANDOMORG
    //! Use random.org (only compiled in when NU_USE_RANDOMORG is defined)
    uint RandomOrg
    #endif
};

class NuRandom
{
    private:
        int64_t numPool[MEMORY_POOL_SIZE];

        int currentCount;

        NuRandom_ExternalSources mySources;

        void setSources(NuRanndom_ExternalSources sources);

        void populatePool();

    public:
        //! Default constructor for nurandom class
        NuRandom();

        //! Constructor for nurandom class
        /*!
         * Use this constructor to determine which external sources to use.
         *
         * \param sources Structure definining which external sources to use.
         *
         * \remarks At least one of the structures for external sources must
         * be enabled. If none of them are, the /dev/urandom one will be
         * automatically enabled.
         */
        NuRandom(NuRandom_ExternalSources sources);

        //! Destructor for nurandom class
        ~NuRandom();

        //! Set the external sources to use.
        /*!
         * \param sources Structure defining which external sources to use.
         *
         * \remarks At least one of the structures for external sources must
         * be enabled. If none of them are, the /dev/urandom one will be
         * automatically enabled.
         */
        void SetSources(NuRandom_ExternalSources sources);

        //! Get the next random number
        /*!
         * Pulls the next random number from the pool. If no more random
         * numbers exist, will populate the pool with more random numbers.
         *
         * \remarks Due to dependencies on external sources for random
         * numbers, the pool poputlation might take a bit of time. You can
         * tweak the external sources we use for random numbers (thus reducing
         * potential delays, but possibly losing entropy) in the constructor
         * or
         */
        int64_t nextRandom();
};

#endif /* nurandom_H */
