; ------ Excercice 3 . 2 ------

(defun swap-first-last (l)
  (let ( (fi (car l))
	(la (car (last l)))
	(ll ( reverse (cdr (reverse (cdr l))))))
    (cons la (append ll (cons fi nil)))))

; ------ Excercice 3 . 3 ------

(defun rotate-left (l)
  (append (cdr l) (cons (car l) nil)))

; ------ Excercice 3 . 4  ------

(defun rotate-right (l)
  (cons (car (last l)) (reverse (cdr (reverse l)))))

; ------ Excercice 3 . 5 ------

(defparameter *prop*
  '(large red shiny cube -vs- small shiny red four-sided pyramid))

(defun right-side (l)
  (cond
    ( (endp l) NIL )
    ( (equal (car l) (car '(-VS-)))
     (cdr l) )
    ( (right-side (cdr l))) ))

(defun left-side (l)
  (cond 
    ( (endp l) NIL )
    ( (equal (car (last l)) (car '(-VS-)))
      (reverse (cdr (reverse l))) )
    ( (left-side (reverse (cdr (reverse l))) ))))

(defun compare (l)
   (let ( (el (length (intersection (left-side l) (right-side l)))))
     (cons el (if (<= el 1)
		  '(PROPRIETE COMMUNE)
		  '(PROPRIETES COMMUNES)))))

; ------ Excercice 3 . 6 ------

(defun my-length (l)
  (if (endp l)
      0
      (1+ (my-length (cdr l)))))

; ------ Excercice 3 . 7 ------

(defun randomize-list (l n)
  (if (zerop n)
      NIL
      (if (endp l)
	  NIL
	  (cons (random n) (randomize-list (cdr l) n)))))
    
(defun random-list (x n)
  (randomize-list (make-list x :initial-element 0) n))

(defun test-randomize-list-once (m n)
  (let ( (l (random-list m n)))
    (cond (not (= m (length l)))
	  (error "LA LISTE DE SORTIE N'A PAS UNE TAILLE CORRECT")  
	  (intersection '(NIL) (mapcar (lambda (x) (and (> x 0) (< x n)) l)))
	  (error "LES ELEMENTS DE LA LISTE NE SONT PAS COMPRIS DANS ]0;n["))))
	
    
