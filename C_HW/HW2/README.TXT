
This readme file introduces the way to implement the arb_int_t functionalities.

arb_int_t is a char ** pointer that points to a char * pointer, which points to a char array. In the array it stores the arbitrary length of integer or the negative sign before the integer to signify the negative number.



**************************
void arb_free(arb_int_t i);

This function free the char* pointer pointing to the char array. Then it frees the arb_int_t pointing to the char * pointer.
**************************


**************************
arb_int_t arb_duplicate(const arb_int_t i);

This function copies the char array that is pointed by the i into the new char array that is contained by the returned arb_int_t
**************************

**************************
int arb_from_string (arb_int_t *i, const char* s);

This function first make sure the entered char array is valid(a negative or positive integer). If it is valid, the function store the char array into the arb_int_t *i, and return the length of array if successfully done.
**************************

**************************
int arb_from_int (arb_int_t * i, signed long int source);

This function first convert the long int source into an char array using sprintf function, then it copies the char array into the char array that arb_int_t *i is pointing to.
**************************

**************************
int arb_to_string (const arb_int_t i, char * buf, size_t max);

This function copies the char array pointed by arb_int_t into the buf if the max size of buf is large enough for the whole char array that is being copied. 
**************************

**************************
int arb_to_int (const arb_int_t i, long int * out);

This function convert the char array stored in the arb_int_t into a long int array. The char array is first cut into 8 digit char segment,then converted to a long int using atol function and stored in the long int array. 
**************************

**************************
void arb_add (arb_int_t x, const arb_int_t y);

This function first extract the positive integer and store them in the add1 and add2, then uses the appropriate arb_add_aux and arb_subtract function to get the result, then add the appropriate negative sign after that. 
**************************

**************************
void arb_add_aux (arb_int_t x, const arb_int_t y);

This function takes two positive integer and get the sum of them.

First we use the temp1 and temp2 to store the reversed char array *x and *y. 

Then we use add1 and add2 to extract the sum at each digit starting from the lowest digit, int sum store the sum of add1 and add2.

The int add show for the previous digit whether the sum was larger than 9.

The result of each digit was stored in temp3.

Then we reverse the result and store it in temp4. 

Then we copy the temp4 into *x.
**************************

**************************
void arb_subtract (arb_int_t x, const arb_int_t y);

This function first extract the positive integer and store them in the add1 and add2, then uses the appropriate arb_add_aux and arb_subtract function to get the result, then add the appropriate negative sign after that. 
**************************

**************************
void arb_subtract_aux (arb_int_t x, const arb_int_t y);

This function can only deal with two positive numbers.

This function first compare the x and y using the arb_compare and reversely store the larger one in the larger array, smaller one in the smaller array.

The int neg is 1 when x is larger, -1 when y is larger, 0 when two are the same and store 0 in x.

Then it subtract the smaller one from the larger one digit by digit. The int sub is 1 when the calculated digit is less than zero and need to borrow 1 from the higher digit.

The subtracted result is stored in the revResult array. Then it is reversed and stored in result array.

Then if x is smaller than y, in which case neg is -1, we add a negative sign to the beginning of *x and then copy the result array to it.

Else, we directly copy the result array to *x.
**************************

**************************
void arb_multiply (arb_int_t x, const arb_int_t y);

This function first extract the positive integer and store them in the add1 and add2, then uses the arb_multiply_aux function to get the result, then add the appropriate negative sign after that. 
**************************

**************************
void arb_multiply_aux (arb_int_t x, const arb_int_t y);

This function can only deal with positive numbers.

The function first use a and b as the digit index on x and y.

For each digit from x and y their multiplication is stored in int multi.

Then the result of multi is converted into an arb_int_t type result, in which *result is the char array.

Then depending on whether multi is two digit or one digit, we start to add zero after the *result char array. The number of 0 added depend on the digit location of *x and *y, we will add k=a-1-i+b-1-j '0' after the *result in total.

Then we add the result to the sum. 

After looping through all the digits in *x and *y, we get the multiplication result stored in sum.

Then we copy the sum into *x
**************************

**************************
int arb_compare(arb_int_t x,arb_int_t y);

This function can only handle two positive integer.

It first compare the length of two integers, the longer one is larger.

If they have the same length, we compare them digit by digit starting from the largest digit. If all the digits are the same, then these two integers are the same.
**************************