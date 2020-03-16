
# Il faut écrire cette fonction soi-même aussi (voir commentaire dans arma_carre.cpp)
arma_carre <- function(A) {
  .Call('arma_carre', PACKAGE = 'matrixExamples', A)
}