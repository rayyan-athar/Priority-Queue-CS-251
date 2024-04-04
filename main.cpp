#include <iostream>
#include "prqueue.h"

using namespace std;

int main(){

    prqueue<int> pq;
    
 pq.enqueue(17,3);
    pq.enqueue(9,2);    
    pq.enqueue(8,2);
    pq.enqueue(16,2);
    // pq.enqueue(1,3);
    pq.enqueue(2,3);
    pq.enqueue(15,1);
    pq.enqueue(5,8);
    pq.enqueue(10,1);

    pq.enqueue(150,9);
    pq.enqueue(1,10);
    pq.enqueue(30,6);
    pq.enqueue(40,8);
    pq.enqueue(40,9);


    pq.enqueue(40,11);

    


    // cout << pq.toString();



    // pq.print();


    return 0;
}