#include <RcppEigen.h>

using namespace Rcpp;
using namespace Eigen;
typedef Eigen::Map<Eigen::VectorXd> MapVector;
typedef Eigen::Map<Eigen::MatrixXd> MapMatrix;

// [[Rcpp::export]]
void eigen_nipals(MapMatrix a, MapVector x, int n) {
  for(int i = 0; i < n; i++) {
    // Rcout << &x[0] << "\n";
    x = a*x;
    x /= x.norm();
  }
}

RcppExport SEXP eigen_nipals(SEXP aSEXP, SEXP xSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< MapMatrix >::type a(aSEXP);
    Rcpp::traits::input_parameter< MapVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    eigen_nipals(a, x, n);
    return R_NilValue;
END_RCPP
}

