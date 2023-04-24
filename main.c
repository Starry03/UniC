#include "Vector.h"
#include "LinkedList.h"

int main() {
    Vector3 vec = InitVector3(1, 1, 1);

    P_Node list = ListCreate(
            3,
            vec,
            VECTOR3_SIZE
    );
    
    return 0;
}
