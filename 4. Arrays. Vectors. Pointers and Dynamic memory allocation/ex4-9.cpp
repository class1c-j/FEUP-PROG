 

// Consider the two program fragments:

int x = 1, y = 2;
int &ref_x = x, &ref_y = y;
ref_x = ref_y;
cout << "x = " << x << "; y = " << y << endl;
cout << "ref_x = " << ref_x << "; ref_y = " << ref_y << endl;

int x = 1, y = 2; int *ptr_x = &x, *ptr_y = &y;
ptr_x = ptr_y;
cout << "x = " << x << "; y = " << y << endl;
cout << "ptr_x = " << ptr_x << "; ptr_y = " << ptr_y << endl;
cout << "*ptr_x = " << *ptr_x << "; *ptr_y = " << *ptr_y << endl;

// Without running the code, say which will be the output of each fragment.

// FIRST: x = 2, y = 2, ref_x = 2, ref_y = 2
// SECOND: x = 1, y = 2, ptr_x = address of y, ptr_y = address of y, *ptr_x = 2, *ptr_y = 2
