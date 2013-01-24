; ~~~~~~~~~~ EXCERCICE 1 ~~~~~~~~~~~~

(defun alea-histo (m n)
  (let ((tab (make-array n :initial-element 0)))
    (loop for i from 0 to (- m 1) collect
	 (incf (aref tab (random n))))
  tab))

(defun print-histo (h)
  (dotimes ( i (length h) t)
      (format t "~2A - [~A~3A " i (aref h i) '])
      (loop for j from 0 to (- (aref h i) 1)
	 collect (format t "*"))
      collect (format t "~%")))


; ~~~~~~~~ EXCERCICE 2 ~~~~~~~~~~~~~

(defun print-histo (h &optional (f *standard-output*))
  (dotimes ( i (length h) t)
      (format f "~2A - [~A~3A " i (aref h i) '])
      (loop for j from 0 to (- (aref h i) 1)
	 collect (format f "*"))
      collect (format f "~%")))


; ~~~~~~~~ EXCERCICE 3 ~~~~~~~~~~~~

(defclass color ()
  ((r :initarg :r :reader red-of)
   (g :initarg :g :reader green-of)
   (b :initarg :b :reader blue-of)))

(defmethod print-object ((c color) stream)
  (format stream "{ r=~D, g=~D, b=~D }"
	  (red-of c)
	  (green-of c)
	  (blue-of c)))

(defun make-color (&key (r 0) (g 0) (b 0))
  (make-instance 'color :r r :g g :b b))

(defgeneric warm-colorp (c))

(defmethod warm-colorp ((c color))
  (with-slots (r b) c
    (if (> r b) T NIL)))


(defparameter tabcolor (make-hash-table))

(setf (gethash 'Red tabcolor) (make-color :r 255))
(setf (gethash 'Blue tabcolor) (make-color :b 255))
(setf (gethash 'Green tabcolor) (make-color :g 255))
(setf (gethash 'White tabcolor) (make-color))
(setf (gethash 'Black tabcolor) (make-color :r 255 :b 255 :g 255))

(defun build-key-list (ht)
  (let ((l '()))
    (maphash (lambda (k v) (declare (ignore v)) (setf l (cons k l))) ht)
    l))

(defun warm-color-hash (ht)
  (let ((wl '()))
    (with-hash-table-iterator (it ht)
      (dotimes (i (hash-table-count ht) wl)
	(multiple-value-bind (m k v) (it)
	  (when (warm-colorp v)
	    (setf wl (cons k wl))))))))