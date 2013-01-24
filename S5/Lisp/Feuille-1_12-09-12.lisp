; ----- Excercice 2.1 -----

(defun returnfuncone (f)
  (funcall f 1 ))

(defun test (x)
	   (* 2 x))

(returnfuncone 'test)

(defun f (x)
  (+ (* 3 (sqrt x)) 4.7))

(returnfuncone 'f)

; ----- Excercie 2.2 -----

(defun sigma (f n p)
  (cond ((< p n) NIL)
	((= n p) (funcall f n))
	((+ (funcall f n) (sigma 'f (1+ n) p)))))

(sigma (lambda (x) (sqrt x)) 2 9)

; ----- Excercice 2.3 -----

(defun bibucreate (n)
  (lambda (x) (* x n)))

(funcall (bibucreate 8) 7)

(defun doublearg (n)
  (funcall (bibucreate 2) n))

; ----- Excercice 2.4 -----

(defun aproderiv (f x)
  (let ((mx (1- x))
    (px (1+ x)))
  (/ (- (funcall f px) (funcall f mx))
     (- px mx))))

(defun niemderiv (f x n)
  (if (<= n 1)
      (aproderiv f x)
      (niemderiv f (aproderiv f x) (1- n))))

(defun secondderiv (f x)
  (let ((mx (1- x))
	(px (1+ x)))
    (/ (+ (- (funcall f px) (funcall f x)) (funcall f mx))
       (sqrt (- px mx)))
))

; ----- Excercice 2.5 -----