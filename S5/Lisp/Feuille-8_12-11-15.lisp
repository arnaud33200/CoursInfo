
(defclass polygon () ())

(defgeneric number-of-lenghts (p)
  (:documentation "returns the numbers of polygon's sides"))

(defgeneric sides-lengths (p)
  (:documentation "returns the liste of a polygon's sides"))

(defgeneric perimeter (p))

(defgeneric area (p))

(defmethod perimeter ((p polygon)) (reduce #'+ (sides-lengths p)))


; --------- Excercice 8.1 --------------

(defclass triangle (polygon)
  ( (number-of-sides :initform 3 :allocation :class :reader number-of-sides) ))

(number-of-sides (make-instance 'triangle))

(defmethod area ((p triangle))
  (let ((lc (sides-lengths p)))
    (let ((a (nth 0 lc))
	  (b (nth 1 lc))
	  (c (nth 2 lc)))
      (let ((s (/ (+ a b c) 2)))
	(sqrt (* s (- s a) (- s b) (- s c)))))))


; --------- Excercice 8.2 --------------

(defclass plain-triangle (triangle)
  ((side-a :initarg :a)
   (side-b :initarg :b)
   (side-c :initarg :c)))

(defun correct-side-length (a b c)
  (and (plusp a) (plusp b) (plusp c)
       (< a (+ b c))
       (> a (abs (- b c)))))

(defun make-plain-triangle (a b c)
  (if (correct-side-length a b c)
      (make-instance 'plain-triangle :a a :b b :c c)
      NIL))

(defmethod sides-lengths ((p plain-triangle))
  (with-slots (side-a side-b side-c) p
    (list side-a side-b side-c)))

(defmethod perimeter ((p triangle))
  (let ((lc (sides-lengths p)))
    (reduce #'+ lc)))

(defgeneric resize-a (p new)
  (:documentation "resize the slot side-a and check if valid for the triangle"))

(defmethod resize-a ((p plain-triangle) new)
  (with-slots (side-a side-b side-c) p
    (if (correct-side-length new side-b side-c)
	(setf side-a new)
	NIL)))



; --------- Excercice 8.3 --------------

(defclass isocele (triangle)
  ((base :initarg :b)
   (cote :initarg :c)))

(defun make-isocele (cote base)
  (if (correct-side-length base cote cote)
      (make-instance 'isocele :b base :c cote)
      NIL))

(defmethod sides-lengths ((p isocele))
  (with-slots (base cote) p
    (list base cote cote)))

(defmethod area ((p isocele))
  (with-slots (base cote) p
    (* 0.5 base (sqrt (- (* cote cote) (/ (* base base) 4))))))

(defmethod perimeter ((p isocele))
  (with-slots (base cote) p
    (+ base (* 2 cote))))

      ; ~~~~~~~~~~~~~~ EQUILATERAL 

(defclass equilateral (triangle)
  ((side :initarg :s)))

(defun make-equilateral (side)
  (if (correct-side-length side side side)
      (make-instance 'equilateral :s side)
      NIL))

(defmethod sides-lengths ((p equilateral))
  (with-slots (side) p
    (list side side side)))

(defmethod area ((p equilateral))
  (with-slots (side) p
    (* (* side side) (/ (sqrt 3) 4))))

(defmethod perimeter ((p equilateral))
  (with-slots (side) p
    (* 3 side)))


; --------- Excercice 8.4 --------------

(defclass triangle (polygon)
  ((number-of-sides :initform 3 :allocation :class :reader number-of-sides)
   (area :initform NIL)))

     ; ~~~~~~ methode 1 ~~~~~~~~~


(defmethod initialize-instance :after ((p triangle) &rest initargs &key &allow-other-keys)
  (with-slots (area) p
    (setf area (area p))))

(defmethod resize-a :after ((p triangle) new)
   (with-slots (area) p
    (setf area (area p))))

    ; ~~~~~~ methode 2 - 1 ~~~~~~~~~

(defmethod area


(defclass triangle-mix