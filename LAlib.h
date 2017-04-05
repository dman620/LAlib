/*this is Derek's Linear Algebra library, called LAlib
Programmer: Derek Mandl
Start Date: 2/25/2017
Goals(to do list):
2. functions to fill the matrix and access information & constructors first
3. functions to do matrix operations. (addition, multiplication, etc)
4. advanced operations (determinant, system solutions, span,  etc)
   this goes beyond the scope of what I will use this for.
5. perhaps I will add other classes, such as subspace
lastly: optimize. Mostly the multiplication probably.  Everything else is trivial

the following is to make my algorithms easier to understand
--------------------------------------------------------------------------
TO CLEAR UP AMBIGUITY ABOUT HOW THE VECTORS ARE CONSTRUCTED:
If a matrix is nxm, then when we talk about (i, j)
then i corresponds to the ith element of every inside
vector
and j corresponds to the vectors on the inside, i.e. the jth
element of the containing vector.
this is a picture to help visualize how my algorihms will do work:


  [i,j] i corresponds to m and j corresponds to n when we use for loops
        this seems very confusing at first.
	it is backwards because n indicates how many rows there are, which
	is also the size of the collumns.

   [0,0|0,1|0,2] <--there are 3 elements of this vector,
    1,0|1,1|1,2            each one is a vector.
    2,0|2,1|2,2    for the purpose of calculations, the matrices will be
    3,0|3,1|3,2    "oriented" like this.


in order to access the (i, j)th element we use matrixname.data[i][j].
this format can only be used inside the member functions, since data
is private.

    

*/

#include <iostream>
#include <utility>
#include <vector>
#include <initializer_list>

using std::vector;
using std::make_pair;
using std::pair;
using std::initializer_list;
using std::cout; using std::cin;
using std::istream; using std::ostream;

//std_matrix means vector of vectors.
//using vec<vec> > can get confuing in a hurry, so I used this
using std_matrix = vector<vector<double> >;



class Matrix{
 private:
  std_matrix data;
  //pair is (# of rows, # of collumns)
  //which is also
  //        (size of collumns, size of rows)
  pair<unsigned, unsigned> order;
 public:
  Matrix() = default;

  //fill a matrix to nxm with 0 in every cell
  Matrix(unsigned n, unsigned m);

  //GETTERS:

  //pair<unsigned, unsigned> getOrder();
  //this function returns the order of a matrix as a pair, so
  //to use it we must use mymatrix.getOrder().first or .second;
  pair<unsigned, unsigned> getOrder()const;

  //SETTERS:

  //setOrder();
  //note: this function is not to be used by itself, it will be used to
  //update the order when data is pushed into the matrix.
  //I may also swap this function out for a more efficient one later,
  //this is primarily for debugging right now, so I can test the getters.
  //n is the number of rows, and m is the number of collumns.
  void setOrder(unsigned n, unsigned m);
  
  //void setElement:
  //this function will set the element Asub i j.
  //A is the matrix, and i is the row number, and j is the collumn number
  //in a 2d vector, this means data[i][j]
  //it needs to check if the i and j are in the bounds of the order

  void setElement(unsigned i, unsigned j);
  
  //void fillMatrixE
  //this will fill a matrix to nxm with all values equal to 0
  //that's about it! it will be used for constructor and other fillers
  void fillMatrixE(unsigned n, unsigned m); //E stands for empty
  
  //void fill MatrixI.
  //I want to use this for debugging, so i can quickly fill a matrix
  //with values I choose at run time.
  //it needs an isteam, such as cin or an ifstream
  //it is important to note that it fills the first COLLUMN first, then moves
  //to the next collumn.  This is oposite of what someone might find intuitive.  I am trying to change this right now
  void fillMatrixI(unsigned n, unsigned m, istream& in); // I stands for input stream


  //void fillMatrixR:
  //this is like the last one, but it will fill the matrix to order nxm
  //with random values
  //I will write them so that they can be used on empty or already filled
  //matrices.  That means they need to erase the matrix before filling it
  void fillMatrixR(unsigned n, unsigned m);//r stands for random

  //void fillMatrixL:
  //this is a function that fills a matrix, given an initializer list
  //of matrices that have the same number of rows (if they are nxm, then
  //their n values are equal.
  void fillMatrixL(initializer_list<Matrix> matrices);//l stands for list

  //void reset();
  //this will do as it sounds, and reset the matrix fully to an empty matrix
  //with zero elements.
  //I simply need to clear() the data[0] which will erase the contents of the
  //vector that holds the data vectors.  This will earase all elements.
  //also it needs to set the order to (0x0)
  void reset();

  //void print(ostream& out);
  //this prints the contents of the matrix by row.
  //this means the i and j will be backwards again so that rows will come first
  //it only requires the ostream that you want to use
  void print(ostream& out);

  //mult operator overload
  //this is exactly what it sounds like, it multiplies
  //matrices together to form a new matrix which is the product.
  Matrix operator* (const Matrix& m1);

  //addition operator overload
  //this will return a matrix, which is the result of adding the two
  //argument matrices together
  Matrix operator+ (const Matrix& m1);

};

