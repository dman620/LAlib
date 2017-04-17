//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//see LAlib.h for more information.
//it houses a main only for debugging purposes

#include "LAlib.h"

//CONSTRUCTORS:
Matrix::Matrix(unsigned n, unsigned m){
  fillMatrixE(n, m);
}

Matrix::Matrix(unsigned n, unsigned m, istream& in){
  fillMatrixI(n, m, in);
}

Matrix::Matrix(initializer_list<Matrix> matrices){
  fillMatrixL(matrices);
}


//GETTERS:
pair<unsigned, unsigned> Matrix::getOrder()const{
  return order;
}//end func


//SETTERS:
void Matrix::setOrder(unsigned n, unsigned m){
  order = make_pair(n, m);
}//end func

void Matrix::fillMatrixE(unsigned n, unsigned m){
  //reset the matrix to empty
  reset();

  //fill the matrix to size with empty values
  for(unsigned i = 0; i < m; i++)
    data.push_back(vector<double>(n, 0.0));
  //this vector constructor fills the vectors with n values, all set to 0.0

  setOrder(n, m);
}//end func

void Matrix::fillMatrixI(unsigned n, unsigned m, istream& in){
  //fill matrix to size with empty values first
  fillMatrixE(n, m);

  //j is first because I want to fill by row rather than by collumn.
  //this will make it easier to fill using filestreams
  for(unsigned j = 0; j < n; j++){
    for(unsigned i = 0; i < m; i++){
      in >> data[i][j];
    }//end for#2
  }//end for#1
}//end func

void Matrix::reset(){
  data.clear();
}//end func

void Matrix::fillMatrixR(unsigned n, unsigned m, int low_bound, int high_bound){
  default_random_engine dre;
  if(low_bound > high_bound){
    cout << "ERROR 02 - INVALID BOUNDS\n";
    return;
  }
  uniform_int_distribution<int> dr(low_bound, high_bound);
  dre.seed(time(nullptr));

  fillMatrixE(n, m);
  
  for(unsigned i = 0; i < n; i++){
    for(unsigned j = 0; j < m; j++){
      data[i][j] = dr(dre);
      //cout << dr(dre) << " ";
    }//end for#2
  }//end for#1
}//end func

void Matrix::fillMatrixL(initializer_list<Matrix> matrices){
  unsigned num_of_rows = matrices.begin()->order.first;
  unsigned num_of_collumns = 0;
  for(Matrix args : matrices){ //for all arguments in the init. list
    if(args.order.first != num_of_rows){
      cout << "ERROR 01 - ORDER MISMATCH\n";
      return;
      }
    num_of_collumns += args.order.second;
  }
  fillMatrixE(num_of_rows, num_of_collumns);

  //this will fill the calling matrix with the initializer matrices:
  unsigned i = 0;
  for(Matrix args : matrices){
    for(unsigned j = 0; j < args.order.second; j++){
      data[i] = args.data[j];
      i++;
    }//end for j
  }//end for args
}//end func


/*
void Matrix::fillMatrixF(unsigned n, unsigned m, string filename){
  ifstream fin;
  fin.open(filename);
  if(fin.fail()){
    cout << "ERROR 03 - FILE NOT FOUND\n";
    return;
  }

}
*/

void Matrix::print(ostream& out){
  order = getOrder();
  unsigned n = order.first;
  unsigned m = order.second;
  for(unsigned j = 0; j < n; j++){
    for(unsigned i = 0; i < m; i++){
      out << data[i][j]<< " ";
    }//end for#2
    cout << '\n';
  }//end for#1
}//end func

/*
void Matrix::print_clean(ostream& out){

}
this is a planned function which will print a matrix, but it will
insert spaces as needed to make each column appear to be in a
collumn.  imagine a matrix with values 1 1 10000 1 1
the extra 0's in the 10000 will throw the others off and make them
appear to not be in a collumn.  this will be easy to fix, with %10
operations and inserting spaces
i will need a func called find_largest_value

double Matrix::find_largest_value(){

}
*/

Matrix Matrix::operator* (const Matrix& m1){
  Matrix product;
  if (this->order.second != m1.order.first) {
    cout << "ERROR 01 - ORDER MISMATCH\n";
    return product;
  }
    
  //n, m is the order of the product matrix
  unsigned n = this->order.first; unsigned m =  m1.order.second;
  //unsigned t is used for iteration, it is equal to the number of collumns
  //of the first matrix, and the number of rows of the second matrix.
  //otherwise the multiplication would not be possible.
  unsigned t = this->order.second;

  product.fillMatrixE(n, m);

  //the k is on the outside because according to my CS professor,
  //"IT CAUSES FASTER CACHE" (in large matrices)
  //but it works exactly the same as if
  //the k was on the inside, so visualize it that way if you wish
  for(unsigned k = 0; k < t; k++){
    for(unsigned i = 0; i < m; i++){
      for(unsigned j = 0; j < n; j++){
	product.data[i][j] += data[k][j]*m1.data[i][k];
      }//end forj
    }//end fori
  }//end fork
  
return product;
}//end func

/*
Matrix operator+ (const Matrix& m1){
  Matrix product;
  //n is the order of the product matrix
  if(this->order != m1.order){
    cout << "ERROR 01 - ORDER MISMATCH\n";
    return product;
  }


}
*/






//this is for debugging purposes
//this is where I am testing all functions and classes
int main(){
  Matrix matrix1;
  Matrix matrix2;
  Matrix matrix3;

  //this creates some sort of memory error, however everything works
  //flawlessly when I make them all 2 x 2so that's either it has to
  //be square or it has to be small.  I will fix later

  
  
  /*initializer list test
  matrix1.fillMatrixI(4, 2, cin);
  matrix2.fillMatrixI(4, 1, cin);
  matrix3.fillMatrixL({matrix1, matrix2});
  */

  /*multiplication test
  matrix1.fillMatrixI(2, 4, cin);
  matrix2.fillMatrixI(4, 2, cin);
  matrix3 = matrix1*matrix2;
  */
 
  
  
  matrix1.print(cout);
  cout << '\n';
  matrix2.print(cout);
  cout << '\n';
  matrix3.print(cout);
  cout << '\n';
  
  
  return 0;
}
