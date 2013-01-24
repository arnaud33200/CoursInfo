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
  (cond
    ((> n p) NIL)
    ((= n p) (funcall f n))
    ((+ (funcall f n) (sigma f (1+ n) p)))))


; ----- Excercie 2.3 -----

(defun buildmulti (n)
  (lambda (x) (* x n)))

; ----- Excercie 2.4 -----

; (defun approderiv (f

; ----- Excercie 2.5 -----

(defun operfunc (op f n p)
  (cond
    ((> n p) NIL)
    ((= n p) (funcall f n))
    ((funcall op (funcall f n) (operfunc op f (1+ n) p)))))

(operfunc #'+ (lambda (x) (+ 2 x)) 2 9)

(defun funcfacto (n)
  (operfunc #'* (lambda (x) x) 1 n))

; ~~~ ( 4 )

(defun sommechelou (f x p)
  (operfunc #'+ (lambda (n) (/ (* (f n) (sqrt x)) (funfacto (n)))) 0 p))

; ----- Excercie 2.6 -----

(defun produit ( f g n )
  (operfunc #'+
	    (lambda (x) (* (funcall f x) (funcall g (- n x))))
	    0
	    n
	    )
  )
	    
