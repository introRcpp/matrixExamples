// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

// attention au passage par référence.
arma::mat arma_inverse_sdp(arma::mat & A) {
  return inv_sympd(A);
}

RcppExport SEXP arma_inverse_sdp(SEXP ASEXP) {
  BEGIN_RCPP
  Rcpp::RObject rcpp_result_gen;
  Rcpp::RNGScope rcpp_rngScope_gen;
  Rcpp::traits::input_parameter< arma::mat& >::type A(ASEXP);
  rcpp_result_gen = Rcpp::wrap(arma_inverse_sdp(A));
  return rcpp_result_gen;
  END_RCPP
}
