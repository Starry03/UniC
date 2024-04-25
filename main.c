#include "DataStructures/Graph/Graph.h"
#include "./Utils/Dealloc/Dealloc.h"
#include "Algebra/Matrix/Matrix.h"

int	main(int argc, char const *argv[])
{
	Matrix	matrix;

	matrix = Matrix_Init(10, 10);
	Matrix_LaplaceDet(matrix);
	Matrix_Print(matrix);
	Matrix_Free(matrix);
	return (0);
}
