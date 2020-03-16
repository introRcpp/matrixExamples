// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

// attention au passage par référence.
arma::mat arma_inverse(arma::mat & A) {
  return A.i();
}

/* Utiliser Rcpp::compileAttributes() pour générer RcppExports.Cpp
 * (ou "install and restart" dans Rstudio) pose des problèmes quand
 * on utilise à la fois RcppEigen et RcppArmadillo dans un package ;
 * c'est lié à l'impossibilité d'inclure RcppArmadillo.h et RcppEigen.h 
 * dans le même fichier. 
 * Il faut donc se débrouiller pour générer le code ci-dessous
 * par exemple avec Rcpp::sourceCpp(fichier, verbose = TRUE, dry = TRUE)
 * et puis supprimer le Rcpp::export ...
 */

RcppExport SEXP arma_inverse(SEXP ASEXP) {
  BEGIN_RCPP
  Rcpp::RObject rcpp_result_gen;
  Rcpp::RNGScope rcpp_rngScope_gen;
  Rcpp::traits::input_parameter< arma::mat& >::type A(ASEXP);
  rcpp_result_gen = Rcpp::wrap(arma_inverse(A));
  return rcpp_result_gen;
  END_RCPP
}
