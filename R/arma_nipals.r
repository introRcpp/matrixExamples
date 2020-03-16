
arma_nipals <- function(A, x = rnorm( nrow(A) ), n) {
  .Call('arma_nipals', PACKAGE = 'matrixExamples', A, x, n)
}
