/*this is Derek's Linear Algebra library, called LAlib
Programmer: Derek Mandl
Start Date: 2/25/2017
Finish Date: 9/7/2017



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
So you don't really need to worry about this unless you want to write additional functionality

    

*/

#include <iostream>
#include <utility>
#include <vector>
#include <initializer_list>
#include <string>

using std::string;
using std::vector;
using std::make_pair;
using std::pair;
using std::initializer_list;
using std::cout; using std::cin;
using std::istream; using std::ostream;

//std_matrix means vector of vectors.
//using vec<vec> > can get confuing in a hurry, so I used this


namespace LAlib{

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

  //fill a matrix using istream
  Matrix(unsigned n, unsigned m, istream& in);

  //fill matrix using other matrices
  Matrix(initializer_list<Matrix> matrices);
  
  //fill matrix using vectors
  Matrix(initializer_list<vector<double>> vectors);
  
  //GETTERS:

  //pair<unsigned, unsigned> getOrder();
  //this function returns the order of a matrix as a pair
  //to get either part you can use getOrder().first or .second
  pair<unsigned, unsigned> getOrder()const;

  //SETTERS:

  //setOrder();
  //note: this function is not to be used by itself, it will be used to
  //update the order when data is pushed into the matrix.
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
  //that's about it! it will be used for initializing matrices to the correct size
  void fillMatrixE(unsigned n, unsigned m); //E stands for empty
  
  //void fill MatrixI.
  //this is for filling a matrix
  //with values you choose at run time.
  //it needs an isteam, such as cin or an ifstream
  //it is important to note that it fills the first COLLUMN first, then moves
  //to the next collumn.  This is oposite of what someone might find intuitive.
  //the first argument is the number of rows
  void fillMatrixI(unsigned n, unsigned m, istream& in);
  // I stands for input stream


  //void fillMatrixL:
  //this is a function that fills a matrix, given an initializer list
  //of matrices that have the same number of rows (if they are nxm, then
  //their n values are equal.
  void fillMatrixL(initializer_list<Matrix> matrices);
  //L stands for list

  //void fillMatrixV:
  //this is a function that fills a matrix given a list of vectors,
  //which do not need to be predefined.  i.e.
  //matrix1.fillMatrixV({1, 2, 3}, {1, 2, 3}); will yeild a 2x3 matrix
  //need to make a function that will accept a bracket enclosed list.
  void fillMatrixV(initializer_list<vector<double>> vectors);
  
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
  //if you are unfamiliar with matrix multiplication operations,
  //I suggest you google it, it is not intuitive at all
  Matrix operator* (const Matrix& m1);

  //addition operator overload
  //this will return a matrix, which is the result of adding the two
  //argument matrices together
  Matrix operator+ (const Matrix& m1);

};//end class

}//end namespace
