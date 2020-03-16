//[[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
using namespace Rcpp;

typedef Eigen::Map<Eigen::MatrixXd> MapMatrix;
NumericMatrix eigen_carre(NumericMatrix A) {
  MapMatrix a( as< MapMatrix >(A) );
  Eigen::MatrixXd b = a*a;
  return wrap(b);
}

RcppExport SEXP eigen_carre(SEXP ASEXP) {
  BEGIN_RCPP
  Rcpp::RObject rcpp_result_gen;
  Rcpp::RNGScope rcpp_rngScope_gen;
  Rcpp::traits::input_parameter< NumericMatrix >::type A(ASEXP);
  rcpp_result_gen = Rcpp::wrap(eigen_carre(A));
  return rcpp_result_gen;
  END_RCPP
}
