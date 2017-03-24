/*this is Derek's Linear Algebra library, called LAlib
Programmer: Derek Mandl
Start Date: 2/25/2017
Goals:
create the following:
1. class for matrix.  At first I thought to have multiple classes, but I
  have realized that it will me much more simple if I only have one class
  called Matrix
2. functions to fill the matrix and access information first
3. functions to do matrix operations.
4. finished

I had arrays to implement matrix before, but now I am using vector,
so that this library will be able to handle matrices of any size once
it is complete


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

//std_matrix means vector of vectors.
//using vec<vec> > can get confuing in a hurry, so I used this
using std_matrix = vector<vector<double> >;

class Matrix{
 private:
  std_matrix data;
  pair<int, int> order;
 public:
  Matrix() = default;

  //GETTERS:

  //pair<int, int> getOrder();
  //this function returns the order of a matrix as a pair, so
  //to use it we must use mymatrix.getOrder().first or .second;
  pair<int, int> getOrder();

  //SETTERS:

  //setOrder();
  //note: this function is not to be used by itself, it will be used to
  //update the order when data is pushed into the matrix.
  //I may also swap this function out for a more efficient one later,
  //this is primarily for debugging right now, so I can test the getters.
  //n is the number of rows, and m is the number of collumns.
  void setOrder(int n, int m);
  
  //void setElement:
  //this function will set the element Asub i j.
  //A is the matrix, and i is the row number, and j is the collumn number
  //in a 2d vector, this means data[i][j]
  //it needs to check if the i and j are in the bounds of the order
  void setElement(int i, int j);
  
  //void fill Matrix.
  //I want to use this for debugging, so i can quickly fill a matrix
  //with values I choose at run time.
  //it also needs to erase all data before filling it with user input.
  //right now, it will accept an n and m to fill it to a certain size.
  //it is important to note that it fills the first COLLUMN first, then moves
  //to the next collumn.  This is oposite of what someone might find intuitive
  void fillMatrixu(int n, int m); //u stands for user

  //void fillMatrixr:
  //this is like the last one, but it will fill the matrix to order nxm
  //with random values
  //I will write them so that they can be used on empty or already filled
  //matrices.  That means they need to erase the matrix before filling it
  void fillMatrixr(int n, int m);//r stands for random

  //void fillMatrixl:
  //this is a function that fills a matrix, given an initializer list
  //of matrices that have the same number of rows (if they are nxm, then
  //their n values are equal.
  void fillMatrixl(initializer_list<Matrix> matrices);//l stands for list

  //void reset();
  //this will do as it sounds, and reset the matrix fully to an empty matrix
  //with zero elements.
  //I simply need to clear() the data[0] which will erase the contents of the
  //vector that holds the data vectors.  This will earase all elements.
  //also it needs to set the order to (0x0)
  void reset();
};


