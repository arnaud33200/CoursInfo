; ~~~~~~~ Excercice 1 ~~~~~~~
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~

(defun display-list (l stream &key sep)
  (if (endp l) nil
      (display-list (cdr l) (format stream "~D~D" (car l) sep) :sep sep)))


					;
;~~~~~~~ Excercice 2 ~~~~~~~
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~

(defun split (l pred)
  (labels ((aux (l pred)
	     (if (endp l) nil
		 (if (funcall pred (car l))
		     (cons (car l) (aux (cdr l) pred))
		     (aux (cdr l) pred))))
	   (not-aux (l pred)
	     (if (endp l) nil
		 (if (funcall pred (car l))
		     (not-aux (cdr l) pred)
		     (cons (car l) (not-aux (cdr l) pred))))))
    (cons (aux l pred) (cons (not-aux l pred) nil))))
 
      
(defun split-value (l pred)
  (labels ((aux (l pred)
	     (if (endp l) nil
		 (if (funcall pred (car l))
		     (cons (car l) (aux (cdr l) pred))
		     (aux (cdr l) pred))))
	   (not-aux (l pred)
	     (if (endp l) nil
		 (if (funcall pred (car l))
		     (not-aux (cdr l) pred)
		     (cons (car l) (not-aux (cdr l) pred))))))
    (values (aux l pred) (not-aux l pred))))

(multiple-value-bind (a b) 
	     (split-value '(1 2 4 5 6) (lambda (x) (> x 2)))
	   (format t "oui : ~D~%non : ~D" a b))


; ~~~~~~~ Excercice 3 ~~~~~~~
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~

(defun none (&rest l)
  (labels ((aux (l)
	     (cond ((endp l) t)
		   ((car l) nil)
		   ((aux (cdr l))))))
    (aux l)))


; ~~~~~~~~ Excercice 4 ~~~~~~~~~
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

