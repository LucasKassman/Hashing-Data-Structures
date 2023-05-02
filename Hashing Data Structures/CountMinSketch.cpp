#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
unsigned int val;
    for(int i=0;i<K;i++){
        val = hash_functions[i](s);
        val = val%M;
        count[i][val]++;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
unsigned int val;
int minCount =10000000;
    for(int i=0;i<K;i++){
        val = hash_functions[i](s);
        val = val%M;
       if  (count[i][val]<minCount) minCount = count[i][val];
    }
    return minCount;
}
