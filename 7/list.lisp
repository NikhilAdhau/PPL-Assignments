;;;; To find the n'th element from the list

(defvar *nums* '(5 8 3 1 10 11 14 12))
(print *nums*)
(format t "~%Enter the index of element you want - ")
(defvar index (read))
(cond	((< index (list-length *nums*))
			(format t"~d ~%" (nth index *nums*))
		)
		((>= index (list-length *nums*))
			(format t"Enter valid input!!!")
		)
)
