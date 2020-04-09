
// Consider the program fragment:

int values[] = { 2, 3, 5, 7, 11, 13 };
int *p = values + 1;
cout << values[1] << endl;
cout << values + 1 << endl;
cout << *p << endl;
cout << *(values + 3) << endl;
cout << p+1 << endl;
cout << p[1] << endl;
cout << p-values << endl;

// Explain the meaning of the following expressions: values[1], values + 1,
// *p, *(values+3), p+1, p[1], p-values 


//  values[1] is the value stored at index 1 of the array values
//  values + 1 is the address of the value at index 1 of the array values
//  *p is the value stored 4 bytes after the the base address of the array values
//  *(values + 3) is the value stored 12 bytes after the base address of the array values
//  p + 1 is the address where the element at index 2 of the array values is stored
//  p[1] is the value stored 4 bytes after the value stored on the address given by p + 1, which in this case is the 5
//  p - values is the index in the array of the value stored 4 bytes after the base address
