#include "Queue.h"
#include <stdio.h>

int main() {
    Queue queue = Queue_Init(104);
    Queue_Add(queue, 105);

    Queue_Print(queue);

    return 0;
}
