;;;; LISP program for finding a factorial of a number without recursion
(format t"Enter a number - ")
(defvar *num* (read))
(defvar *sum*)
(setf *sum* 1)
(defun fact (num)
	(loop
		(setf *sum* (* *sum* num))
		(setf num (- num 1))
		(when (< num 2) (return *sum*))
	)
	(format t"The factorial of ~d is ~d. ~%" *num* *sum*)
)

(fact *num*)