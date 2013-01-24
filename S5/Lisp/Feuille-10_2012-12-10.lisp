
; ########### EXERCICE 1 ###############

(defmacro mamacro (var)
  `(list ,@var))

(defmacro mcro (var)
  `((format t ,@var)))


; ########## EXERCICE 2 #################

(macroexpand '(defvar testvar))

(macroexpand '(defun bibu (a b) (+ a b)))


; ########## EXERCICE 3 #################

(defmacro defpower (nom n)
  `(defun ,nom (v)
     (let ((r v))
       (dotimes (i (- ,n 1) r)
	 (setf r (* r v))))))

(defmacro defpower (nom n)
  (let ((listarg (cons '* (make-list (eval n) :initial-element 'x))))
    `(defun ,nom (x)
       ,listarg)))


; ########## EXERCICE 4 #################

(defmacro repeatuntil (pred result &body body)
  `(progn
     ,@body
     (do () (,pred ,result) ,@body)))


; ########## EXERCICE 5 #################

(setf *print-circle* t)

(defun circ (l)
  (nconc l l))

(defmacro def-sequencer (nom l)
  (let ((cl (gensym)))
    `(let ((,cl (circ (copy-list ,l))))
       (defun ,nom ()
	 (pop ,cl)))))

(defmacro with-sequencer (nom l &body body)
  (let ((cl (gensym)))
    `(let ((,cl (circ (copy-list ,l))))
	   (flet ((,nom () (pop ,cl)))
	     ,@body))))

