#include "Vector.h"
#include "SetList.h"
#include "Utils.h"

int main() {
    SetType arr[] = {InitVector3(1, 1, 1), InitVector3(2, 2, 2)};
    SetList set = SetInitFromArray(arr, VECTOR3_SIZE, 2);
    SetAdd(&set, InitVector3(1, 1, 1), VECTOR3_SIZE);

    while (set != NULL) {
        Vector3_Print(set->info);
        set = set->next;
    }
    return 0;
}
