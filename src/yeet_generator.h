/*
 *  Generates a unique 'yeet looking' string based on
 *  the bits of a provided number
 *  
 *      n |  bits  | string
 *      --+--------+-------
 *      0 |  0000  | yeet
 *      1 |  0001  | yeeT
 *           ...
 *      5 |  0101  | yEeT
 *           ...  
 *     69 | 101010 | YeEeEt
 *  
 *  Minimal length is 4, as numbers get bigger so do the strings
 */
char *generate_yeet(unsigned int n);
