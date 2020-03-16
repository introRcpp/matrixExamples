#include <RcppEigen.h>

using namespace Rcpp;
typedef Eigen::Map<Eigen::VectorXd> MapVector;
typedef Eigen::Map<Eigen::MatrixXd> MapMatrix;

// [[Rcpp::export]]
List eigen_logistic_model(NumericVector Y, NumericMatrix X, double eps = 1e-8, int max_iter = 25) {

  MapVector y( as<MapVector>(Y) );
  MapMatrix x( as<MapMatrix>(X) );

  int n(y.rows()), p(x.cols());
  Eigen::VectorXd W(n), pi(n), U(p), Xbeta(n), beta(p);
  Eigen::MatrixXd XWX(p,p), WX(n,p);
  double dev(0), dev_old(0);

  beta.setZero();

  for(int k = 0; k < max_iter; k++) {

    Xbeta.noalias() = x * beta;

    // update both pi and deviance 
    dev_old = dev;
    dev = y.dot(Xbeta);
    for(int i = 0; i < n; i++) {
      pi(i) = 1/( 1 + exp( - Xbeta(i) ) );
      dev += log(1-pi(i));
    }

    // NOTE computing dev as follows is much slower !
    // dev = y.dot(Xbeta) + (Eigen::VectorXd::Ones(n) - pi).log().sum();

    if(k > 0 && fabs(dev - dev_old)/(fabs(dev) + 0.1) < eps)
      break;
 
    W.noalias() = pi.cwiseProduct(Eigen::VectorXd::Ones(n) - pi);
    U.noalias() = x.transpose()*(y - pi);

    WX.noalias() = W.asDiagonal() * x;
    XWX.noalias() = x.transpose() * WX;

    beta.noalias() += XWX.llt().solve(U);  
  }

  List L;
  L["beta"] = wrap(beta);
  // L'inverse de XWX est la matrice de variance des beta
  L["var.beta"] = wrap( XWX.llt().solve( Eigen::MatrixXd::Identity(p,p) ) );
  return L;
}

RcppExport SEXP eigen_logistic_model(SEXP YSEXP, SEXP XSEXP, SEXP epsSEXP, SEXP max_iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type Y(YSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    rcpp_result_gen = Rcpp::wrap(eigen_logistic_model(Y, X, eps, max_iter));
    return rcpp_result_gen;
END_RCPP
}

