//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//see LAlib.h for more information.
//it houses a main only for debugging purposes

#include "LAlib.h"

//CONSTRUCTORS:
Matrix::Matrix(unsigned n, unsigned m){
  fillMatrixE(n, m);
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

void Matrix::fillMatrixL(initializer_list<Matrix> matrices){
  unsigned num_of_rows = matrices.begin()->order.first;
  unsigned num_of_collumns = 0;
  for(Matrix args : matrices){ //for all arguments in the init. list
    if(args.order.first != num_of_rows){
      cout << "ERROR 01 - ORDER MISMATCH\n";
      break;
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
    }
  }



}//end func


/*
void Matrix::fillMatrixF(unsigned n, unsigned m, string filename){

}*/


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
      }//end for#3
    }//end for#2
  }//end for#2
  
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

  matrix1.fillMatrixI(4, 2, cin);
  matrix2.fillMatrixI(4, 1, cin);
  matrix3.fillMatrixL({matrix1, matrix2});
  

  /*multiplication test
  matrix1.fillMatrixI(2, 4, cin);
  matrix2.fillMatrixI(4, 2, cin);
  matrix3 = matrix1*matrix2;
  */
  //constructor testing:
  
  
  matrix1.print(cout);
  cout << '\n';
  matrix2.print(cout);
  cout << '\n';
  matrix3.print(cout);
  cout << '\n';
  
  
  return 0;
}
