; ---------------- Exercice 7.1 --------------

(let ((nouveau 0))

  (defun ticket ()
    (incf nouveau))

  (defun raz ()
    (setf nouveau 0)))


; ---------------- Exercice 7.2 --------------

(defparameter *g* 9.81)

(defun pendule (l)
  (* 2 pi (sqrt (/ l *g*))))


; ---------------- Exercice 7.3 --------------



(defun iota (n &optional &key (init 0) (step 1))
  (let ((l '(1)))
    (do ((x init (+ x step)))
	((>= x (+ (* step n) init)) l)
      (setf l (append l (list x))))))


(defun iota-loop (n)
  (loop for i from 0 to (- n 1)
	collect i))


; ---------------- Exercice 7.4 --------------

(defun triangle (n)
  (flet ((next-line (l) (mapcar #'+ (cons 0 l) (append l (list 0)))))
    (let ((l '((1))))
      (dotimes (x n l)
	(setf l (append l (list (next-line l))))))))

(defun triangle-loop (n)
  (flet ((next-line (l) (mapcar #'+ (cons 0 l) (append l (list 0)))))
    (let ((l '(1)))
      (append '((1)) (loop for i from 0 to (- n 2)
	    collect (setf l (next-line l)))))))


; ---------------- Exercice 7.5 --------------


; ---------------- Exercice 7.6 --------------

(defun test-randomize-list (n)