/**
 *  Simple RAM allocation benchmark by DoITCreative.
 *  License: no license here, use this code as you like.
 */
#include <iostream>
#include <cstdlib>

/**
 * Tries to allocate memory
 * - Returns 1 on error
 * - Returns 0 on success
 */
int allocate_n_bytes(size_t n)
{
    int* ram_address;
    if ((ram_address = (int *)malloc(n)) == nullptr)
    {
        return 1;
    }
    free(ram_address);
    return 0;
}

int main(int argc, char** argv)
{
    size_t memory_to_allocate {0};
    size_t gigs {0};
    size_t megs {0};
    size_t kilobytes {0};
    size_t bytes {0};
    while (true) 
    {
        memory_to_allocate = gigs * 1024 * 1024 * 1024 + megs * 1024 * 1024 + kilobytes * 1024 + bytes;
        if (allocate_n_bytes(memory_to_allocate) == 0)
        {
            gigs += 1;
        }
        else
        {
            gigs -= 1;
            break;
        }
    }
    while (true) 
    {
        memory_to_allocate = gigs * 1024 * 1024 * 1024 + megs * 1024 * 1024 + kilobytes * 1024 + bytes;
        if (allocate_n_bytes(memory_to_allocate) == 0)
        {
            megs += 1;
        }
        else
        {
            megs -= 1;
            break;
        }
    }
    while (true) 
    {
        memory_to_allocate = gigs * 1024 * 1024 * 1024 + megs * 1024 * 1024 + kilobytes * 1024 + bytes;
        if (allocate_n_bytes(memory_to_allocate) == 0)
        {
            kilobytes += 1;
        }
        else
        {
            kilobytes -= 1;
            break;
        }
    }
    while (true) 
    {
        memory_to_allocate = gigs * 1024 * 1024 * 1024 + megs * 1024 * 1024 + kilobytes * 1024 + bytes;
        if (allocate_n_bytes(memory_to_allocate) == 0)
        {
            bytes += 1;
        }
        else
        {
            bytes -= 1;
            break;
        }
    }
    std::cout<<"Max allocation: "<<gigs<<"G "<<megs<<"M "<<kilobytes<<"K "<<bytes<<"B."<<std::endl;
    return 0;
}
