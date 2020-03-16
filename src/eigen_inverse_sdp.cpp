//[[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
using namespace Rcpp;

typedef Eigen::Map<Eigen::MatrixXd> MapMatrix;

NumericMatrix eigen_inverse_sdp(NumericMatrix A) {
  if(A.nrow() != A.ncol()) 
    stop("Pas une matrice carrée");
  int n = A.nrow();
  MapMatrix a( as< MapMatrix >(A) );
  Eigen::MatrixXd b(a.llt().solve( Eigen::MatrixXd::Identity(n,n) ));
  return wrap(b);
}

RcppExport SEXP eigen_inverse_sdp(SEXP ASEXP) {
  BEGIN_RCPP
  Rcpp::RObject rcpp_result_gen;
  Rcpp::RNGScope rcpp_rngScope_gen;
  Rcpp::traits::input_parameter< NumericMatrix >::type A(ASEXP);
  rcpp_result_gen = Rcpp::wrap(eigen_inverse_sdp(A));
  return rcpp_result_gen;
  END_RCPP
}
