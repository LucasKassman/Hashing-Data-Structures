#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
unsigned int val;
    for(int i=0;i<K;i++){
        val = hash_functions[i](s);
        val = val%M;
        bits[val]= true;
    }





    
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    unsigned int val;
    for(int i=0;i<K;i++){
        val = hash_functions[i](s);
        if (!bits[val%M]) return false;
    }
    return true;


}
