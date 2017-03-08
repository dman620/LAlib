/*this is Derek's Linear Algebra library, called LAlib
Programmer: Derek Mandl
Start Date: 2/25/2017
Goals:
create the following:
1. vector class, herein reffered to as vec, to stop any confusion with the 
   vector class.
2. matrix class.  Implement this as a vector of vectors.
3. Global constants for transformation matrixes
4. Functions for scalar multiplication, matrix multiplication
5. Implement matrix first, so that vec is a public matrix using inheritence

note: for my purposes, I only need to worry about Rn, vectors and matrices 
with two entries.  Otherwise I would be wokring in 3 dimensions.
thus I am using arrays of size 2 because they are much easier to understand


*/

#include <vector>

using std::vector;
using std::pair;

//this keyworrd "col_vector" is synonymous with a vector of doubles
using col_vector = vector<double>;
//and "std_matrix" is a vector of vectors, making it a 2-d vector.
using std_matrix = vector<col_vector>;

class matrix{
 private:
  std_matrix data;
  pair<int, int> order;
 public:
  matrix() = default;
  void fillMatrix();
};

class vec: public matrix{
 private:
  col_vector data;
  pair<int, int> order;
 public:
  vec() = default;
  
};

