;;;; LISP program for finding a factorial of a number with recursion
(format t"Enter a number - ")
(defvar *num* (read))
(defun fact (num)
	(when (= num 1) (return-from fact 1))
	(return-from fact (* num (fact (- num 1))))
)

(format t"The factorial of ~d is ~d. ~%" *num* (fact *num*))