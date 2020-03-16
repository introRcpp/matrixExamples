
eigen_nipals <- function(A, x = rnorm( nrow(A) ), n) {
  .Call('eigen_nipals', PACKAGE = 'matrixExamples', A, x, n)
  return(x)
}
