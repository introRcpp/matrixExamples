// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

//[[Rcpp::export]]
arma::vec arma_nipals(arma::mat & a, arma::vec & x, int n) {
  for(int i = 0; i < n; i++)  {
    // Rcout << &x[0] << "\n";
    x = a*x;
    x /= norm(x);
  }
  return x;
}

RcppExport SEXP arma_nipals(SEXP aSEXP, SEXP xSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type a(aSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(arma_nipals(a, x, n));
    return rcpp_result_gen;
END_RCPP
}

