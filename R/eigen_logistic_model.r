
eigen_logistic_model <- function(Y, X = matrix(1, nrow=length(Y)), eps = 1e-8, max_iter = 25) {
  .Call('eigen_logistic_model', PACKAGE = 'matrixExamples', Y, X, eps, max_iter)
}
