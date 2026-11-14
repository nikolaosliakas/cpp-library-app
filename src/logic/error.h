//
// Created by n-l on 14/11/2026.
//

#ifndef LIBRARYSYSTEM_ERROR_H
#define LIBRARYSYSTEM_ERROR_H

enum class ErrorCode {
// Domain errors
  /*
   * ISBNnotvalid
   * NoCopiesAvailable
   * LoanLimitReached etc.
   */
  // internal errors
  DevelopmentPlaceholderError
};

struct LibraryError {
  ErrorCode code;
  std::string message;
};
#endif // LIBRARYSYSTEM_ERROR_H
