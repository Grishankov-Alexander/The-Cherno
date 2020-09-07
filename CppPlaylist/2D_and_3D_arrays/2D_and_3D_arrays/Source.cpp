

int main(int argc, char **argv)
{
	constexpr size_t size = 50;  // array size

	/** 2D array
	*
	*/
	// a2d - array of 50 int pointers/arrays
	int **a2d = new int *[size];
	for (size_t i = 0; i < size; ++i)
		// make each pointer point to 50 ints
		a2d[i] = new int[size];
	// assign 2 to the third int of the second pointer
	a2d[1][2] = 2;

	for (size_t i = 0; i < size; ++i)
		// deallocate the memory that stores ints for the "i" pointer
		delete[] a2d[i];
	// deallocate the memory that stores pointers
	delete[] a2d;


	/** 3D array
	*
	*/
	// a3d - array of 50 pointers to pointers to an int array
	int ***a3d = new int **[size];
	for (size_t i = 0; i < size; ++i) {
		// each pointer([i]) will point to 50 int pointers
		a3d[i] = new int *[size];
		for (size_t j = 0; j < size; ++j)
			// each int pointer([i][j]) will point to 50 ints
			a3d[i][j] = new int[size];
	}
	// assign 50 to the 4th int of the 3rd int pointer([i][2]) of the second pointer([1])
	a3d[1][2][3] = 50;

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j)
			// first deallocate int array of [i][j] pointer (a3d[i][j][*] space)
			delete[] a3d[i][j];
		// then deallocate pointer array of [i] pointer (a3d[i][*]) space)
		delete[] a3d[i];
	}
	// finally deallocate main array of pointers (a3d[*] space)
	delete[] a3d;
}