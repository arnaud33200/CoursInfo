; ---------- EXERCICE 6.1 --------------

(defun derivee-simple (a b)
  (cond ((and (atom a) (atom b))
	 (if (eq a b) 1 0))
	((eq (car b) '+) (+ (derivee-simple a (nth 1 b)) (derivee-simple a (nth 2 b))))
	((eq (car b) '*) (+ (* (nth 1 b) (derivee-simple a (nth 1 b)))
			    (* (nth 2 b) (derivee-simple a (nth 2 b)))))
	(T NIL)))

(defun derivee-simple (a b)
  (cond ((and (atom a) (atom b))
	 (if (eq a b) 1 0))
	((eq (car b) '+) (list '+ (derivee-simple a (nth 1 b)) (derivee-simple a (nth 2 b))))
	((eq (car b) '*) (list '+ (list '* (nth 1 b) (derivee-simple a (nth 1 b)))
			    (list '* (nth 2 b) (derivee-simple a (nth 2 b)))))
	(T NIL)))

; avantages : permet facilement d'ajouter une nouvelle rêgle pour la dérivée simple
; inconveniant : n'offre pas une formule général de dérivée

; ----------- EXERCICE 6.2 ---------------

(defparameter *regle-derivee* (make-hash-table))

(defun derivee-simple (a b)
  (if (atom b) (if (eq a b) 1 0)
      (funcall (gethash (car b) *regle-derivee*) a b)))

(setf (gethash '+ *regle-derivee*) 
      (lambda (a b)
	(list '+ (derivee-simple a (nth 1 b)) (derivee-simple a (nth 2 b)))))

(setf (gethash '* *regle-derivee*) 
      (lambda (a b)
	(list '+ (list '* (nth 1 b) (derivee-simple a (nth 1 b)))
	      (list '* (nth 2 b) (derivee-simple a (nth 2 b))))))

(setf (gethash 'e *regle-derivee*) 
      (lambda (a b)
	(list '* (derivee-simple a (nth 1 b)) (list 'exp (nth 1 b)))))

(setf (gethash '+ *regle-derivee*) 
      (lambda (a b)
	(cons '+ (mapcar (lambda (x) (derivee-simple a x)) (nthcdr 1 b)))))

; ----------- EXERCICE 6.3 ------------

(defparameter *regle-simpli* (make-hash-table))

(defun correcteur (l)
  (if (atom l) l
      (funcall (gethash (car l) *regle-simpli*) (cdr l))))

(setf (gethash '+ *regle-simpli*)
      (lambda (a) 
	(cond 
	  ((and (rationalp (nth 0 a)) (rationalp (nth 1 a))) (+ (nth 0 a) (nth 1 a)))	       
	  ((and (rationalp (nth 0 a)) (zerop (nth 0 a))) (nth 1 a))
	  ((and (rationalp (nth 1 a)) (zerop (nth 1 a))) (nth 0 a))
	  (T (correcteur (nth 0 a)) (correcteur (nth 1 a))))))

(setf (gethash '* *regle-simpli*)
      (lambda (a)
	(cond
	  ((and (rationalp (nth 0 a)) (rationalp (nth 1 a))) (* (nth 0 a) (nth 1 a)))
	  ((and (rationalp (nth 0 a)) (zerop (nth 0 a))) 0)
	  ((and (rationalp (nth 1 a)) (zerop (nth 1 a))) 0)
	  (T (correcteur (nth 0 a)) (correcteur (nth 1 a))))))

(setf (gethash 'e *regle-simpli*)
      (lambda (a) a))

	
      