; ------ Excercice I ------

(defun mapcar-fill (f l1 l2)
  (cond ((endp l1) l2)
	((endp l2) l1)
	(t (cons (funcall f (car l1) (car l2)) (mapcar-fill f (cdr l1) (cdr l2))))))


(values
  (mapcar-fill #'+ '(1 2 3) '(4 5 6))
  (mapcar-fill #'+ '(1 2 3) '(4 5 6 7 8))
  (mapcar-fill #'+ '(1 2 3 7 8) '(4 5 6)))


; ------ Excercice II ------

(defun mappend (f l)
  (if (endp l) nil
      (append (funcall f (car l)) (mappend f (cdr l)))))

(mappend (lambda (x) (list x (1+ x))) '(5 3 6 9))
(mappend (lambda (x) (list x (1+ x))) (make-list 10000 :initial-element 0))

(defun mappend (f l)
  (reduce #'append (mapcar f l)))

(defun mappend (f l)
  (reduce #'append (mapcar f l) :from-end t))

; avec from-end, la fonction reduce est bien plus rapide
; Dans le cas de (mappend (lambda (x) (list x (1+ x))) '(1 5 6 8))
;     sans : (append (append (append '(1 2) '(5 6)) '(6 7)) '(8 9))
;     avec : (append '(1 2) (append '(5 6) (append '(6 7) '(8 9))))
;
; avec, il à déjà évalue une valeur avant d'évaluer la prochaine, il gagne du temps


; ------ Excercice III -----

(defun next-line (l)
  (mapcar #'+ (cons 0 l) (append l (list 0))))

(defun apply-n (n l)
  (if (zerop n) l
      (next-line (apply-n (1- n) l))))

(defun triangle-pascal (n)
  (labels ((aux (i n)
	     (if (= i n) (list (apply-n n '(1)))
		 (cons (apply-n i '(1)) (aux (1+ i) n)))))
    (aux 0 n)))
	
(defun triangle-pascal (n)
  (labels ((aux (n)
	     (if (= n 0) (list (apply-n n '(1)))
		 (cons (apply-n n '(1)) (aux (1- n))))))
    (nreverse (aux n))))


; ------ Excercice IV -----

(defun partition (pred l)
  (values (remove-if-not pred l) (remove-if pred l)))

(defun quicksort (p l)
  (if (or (endp l) (= 1 (length l))) l
      (multiple-value-bind (l1 l2) (partition (lambda (x) (funcall p x (car l))) (cdr l))
	(append (quicksort p l1) (cons (car l) (quicksort p l2))))))
    
(quicksort #'< '(5 8 2 9 56 8 4 9))
(quicksort #'string< '("az" "ab" "cd" "aa" "a" "d" "cd" "ef"))


; ------ Excercice V -----

(defparameter empty-set '())

(defun set-emptyp (ensemble)
  (endp (union ensemble empty-set)))

(defun set-member (element ensemble)
  (not (endp (intersection (list element) ensemble))))

(defun set-adjoin (element ensemble)
  (adjoin element ensemble))

(defun set-from-list (list &key (test #'eq))
  (remove-duplicates list :test test))

(defun set-remove (element ensemble &key (test #'eq))
  (if (endp ensemble) '()
      (if (funcall test element (car ensemble))
	  (set-remove element (cdr ensemble))
	  (cons (car ensemble) (set-remove element (cdr ensemble))))))
  

(defun set-union (e1 e2 &key (test #'eq))
  (if (set-emptyp e1) (set-from-list e2 :test test)
      (set-union (cdr e1) (set-adjoin (car e1) e2))))

(defun set-inter (e1 e2)
  (if (or (endp e1) (endp e2)) e2
      (if (set-member (car e1) e2)
	  (cons (car e1) (set-inter (cdr e1) e2))
	  (set-inter (cdr e1) e2))))

(defun set-diff (e1 e2 &key (test #'eq))
  (if (endp e1) (set-from-list e2 :test test)
      (if (set-member (car e1) e2)
	  (set-diff (set-remove (car e1) e1 :test test) (set-remove (car e1) e2 :test test))
	  (set-diff (set-remove (car e1) e1 :test test) (cons (car e1) e2)))))

(defun set-equal (e1 e2 &key (test #'eq))
  (endp (set-diff e1 e2 :test test)))

(defun set-include (e1 e2 &key (test #'eq))
  (set-equal e1 (set-inter e1 e2) :test test))


(defun eq-graph (g1 g2)
  (or 
   (and (eq (car g1) (car g2)) (eq (car (last g1)) (car (last g2))))
   (and (eq (car g1) (car (last g2))) (eq (car (last g1)) (car g2)))))

(values
  (set-from-list '((1 3) (1 4) (8 9) (1 4)) :test 'eq-graph))

;; A REFAIRE !


; ------ Excercice VI -----

(defun compress (l &key (test #'equal))
  (labels ((aux (n e l &key (test #'equal))
	     (if (funcall test e (car l)) 
		 (aux (1+ n) e (cdr l))
		 (values n l))))
    (if (endp l) nil
	(multiple-value-bind (n nl) (aux 0 (car l) l :test test)
	  (cons (cons (car l) n) (compress nl :test test)))))) 


(defun decompress (l)
  (labels ((aux (n e)
	     (if (zerop n) nil
		 (cons e (aux (1- n) e)))))
    (if (endp l) nil
	(append (aux (cdr (car l)) (car (car l))) (decompress (cdr l))))))