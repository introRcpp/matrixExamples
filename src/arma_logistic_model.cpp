#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::export]]
List arma_logistic_model(arma::vec & y, arma::mat & x, double eps = 1e-8, int max_iter = 10) {
  int n(y.n_rows), p(x.n_cols);
  arma::vec W(n), pi(n), U(p), beta(p), Xbeta(n);
  arma::mat XWX(p,p), WX(n,p);

  beta.zeros();
  double dev(0), dev_old(0);

  for(int k = 0; k < max_iter; k++) {
    Xbeta = x * beta;    
 
    // update both pi and deviance 
    dev_old = dev;
    dev = dot(y, Xbeta);
    for(int i = 0; i < n; i++) {
      pi(i) = 1/( 1 + exp( -Xbeta(i) ) );
      W(i) = pi(i)*(1-pi(i));
      dev += log(1-pi(i));
    }

    if(k > 0 && fabs(dev - dev_old)/(fabs(dev) + 0.1) < eps)
      break;

    U = x.t() * (y - pi);

    WX = diagmat(W) * x;
    XWX = x.t() * WX;
    beta += solve(XWX, U);

  }

  List L;
  L["beta"] = wrap(beta);
  // L'inverse de XWX est la matrice de variance des beta
  L["cov.beta"] = wrap( inv_sympd(XWX) );
  return L;
}

RcppExport SEXP arma_logistic_model(SEXP ySEXP, SEXP xSEXP, SEXP epsSEXP, SEXP max_iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    rcpp_result_gen = Rcpp::wrap(arma_logistic_model(y, x, eps, max_iter));
    return rcpp_result_gen;
END_RCPP
}

