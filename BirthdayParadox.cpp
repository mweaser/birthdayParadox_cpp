#include <iostream>
#include <vector>
#include <iostream>
#include "Hashtable.h"
#include <random>

using namespace std;

/* This program confirms the Birthday Paradox: With an initial size of 365, it add items until the first 
probe occurs or (very unlikely) the array is resized. Run this a bunch of times (at least 1000). 
You should find that approximately 50.7% of the time you insert 23 things or less, and the rest 
of the time you insert 24 things or more. 
*/

    
string randomString(int length) {
        string string;
        const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < length; ++i) {
            int size = sizeof(alphabet) - 1;
            string+= alphabet[rand() % (size)];
        }

     return string;
}
  
int main(){
    
    Hashtable<int> hashtable(true, 365);

    int counterLessThan23 = 0;
    int counter = 0;
    int tableSize = 2000;

    for (int i = 0; i < tableSize; i++){
        int y = hashtable.add(randomString(28), 0);
        while (y < 1){
            counter++; 
            y = hashtable.add(randomString(28), 0);
        }
        counter++;
        if (counter <= 23){
            counterLessThan23++;     
        }
        counter = 0; 
        // hashtable = temp; 
    }

    double dcounterLessThan23 = double(counterLessThan23);
    double dtableSize = double(tableSize);
    double result = dcounterLessThan23/dtableSize * 100;

    cout << result << "%" << endl; 
  
}

