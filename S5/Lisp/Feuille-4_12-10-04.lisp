(defun point-in-zone-p (point zone)
  (funcall zone point))

(defparameter +nowhere+
  (lambda (p)
    (declare (ignore p))
    nil))

(defun make-disk (radius)
  (assert (realp radius))
  (lambda (p)
    (<= (abs p) radius)))

(defun zone-intersection (zone1 zone2)
  (lambda (p)
    (and (point-in-zone-p p zone1)
	 (point-in-zone-p p zone2))))

(defun move-zone (zone vector)
  (lambda (p)
    (point-in-zone-p (- p vector) zone)))


;; ---------------------------------------------------------------------------

(defun test-point-zone ()
  (assert (point-in-zone-p #C(4 1) (make-disk 6)))
  (error-message (point-in-zone-p #C(4 1) (make-disk #C(2 1))) "MAKE-DISK : RADIUS DOIT ÊTRE UN REEL~%")
  (assert (point-in-zone-p "KARTOFUN" +everyhere+))
  (assert (point-in-zone-p #C(3 8) (make-rectangle 7 8)))
  (assert (point-in-zone-p #C(3 8) (zone-union (make-rectangle 7 8) (make-rectangle 1 1))))
  (assert (point-in-zone-p #C(3 8) (zone-difference (make-rectangle 7 8) (make-rectangle 1 1))))
  (assert (point-in-zone-p #C(3 8) (move-zone (make-rectangle 7 8) #C(1 1))))
;  (ignore-errors (assert (point-in-zone-p #C(3 8) (move-zone (make-rectangle 7 8) 1))))
)

(defparameter +everyhere+
  (lambda (p)
    (declare (ignore p))
    T))


(defun zone-union (zone1 zone2)
  (lambda (p)
    (or (point-in-zone-p p zone1)
	 (point-in-zone-p p zone2))))

(defun zone-difference (zone1 zone2)
  (lambda (p)
    (and (point-in-zone-p p zone1)
	 (not (point-in-zone-p p zone2)))))

(defun make-rectangle (width height)
  (error-message (and (realp width) (realp height)) "MAKE RECTANGLE : WIDTH ET HEIGHT DOIVENT ETRE DES REELS~%")
  (lambda (p)
    (and (<= 0 (realpart p) width)
	 (<= 0 (imagpart p) height))))

(defun divide-complex (c1 c2)
  (assert (and (complexp c1) (complexp c2)))
  (complex (/ (realpart c1) (realpart c2)) (/ (imagpart c1) (imagpart c2))))

(defun scale-zone (zone trans &optional (c #(0 0)))
  (assert (and (complexp trans) (complexp c)))
  (lambda (p)
    (and (move-zone zone (complex (- (realpart c)) (- (imagpart c))))
	 (point-in-zone-p (divide-complex p trans) zone)
	 (move-zone zone c))))

(defun rotate-zone (zone radius)
(assert (realp radius))
  (lambda (p)
	 (point-in-zone-p 
	  (complex (- (* (realpart p) (cos (- radius))) (* (imagpart p) (sin (- radius))))
		   (+ (* (realpart p) (sin (- radius))) (* (imagpart p) (cos (- radius))))) zone)))

(defun determinant (p1 p2)
  (assert (and (complexp p1) (complexp p2)))
  (- (* (realpart p1) (imagpart p2)) (* (realpart p2) (imagpart p1))))

(defun make-half-plane (p1 p2)
  (assert (and (complexp p1) (complexp p2)))
  (lambda (p)
    (<= (determinant (- p2 p1) (- p p1)) 0)))

(defun make-triangle (p1 p2 p3)
  (assert (and (complexp p1) (complexp p2) (complexp p3)))
  (lambda (p)
    (and (point-in-zone-p p (make-half-plane p1 p2))
	 (point-in-zone-p p (make-half-plane p2 p3))
	 (point-in-zone-p p (make-half-plane p3 p1)))))
 
(defun error-message (p m)
  (let ((w nil))
    (ignore-errors (assert p)
	    (setq w t))
    (unless w (format t m))
    w))
