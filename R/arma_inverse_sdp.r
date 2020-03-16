
arma_inverse_sdp <- function(A) {
  .Call('arma_inverse_sdp', PACKAGE = 'matrixExamples', A)
}

