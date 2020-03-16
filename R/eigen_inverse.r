
eigen_inverse <- function(A) {
  .Call('eigen_inverse', PACKAGE = 'matrixExamples', A)
}

