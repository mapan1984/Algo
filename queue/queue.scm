;; fifo queue

; 采用指针的形式定义queue
; 与C中结构体与指针的组合相似
(define (front-ptr queue) (car queue))
(define (rear-ptr queue) (cdr queue))
(define (set-front-ptr! queue item) (set-car! queue item))
(define (set-rear-ptr! queue item) (set-cdr! queue item))

(define (empty-queue? queue) (null? (front-ptr queue)))

(define (make-queue) (cons '() '()))

(define (front-queue queue)
  (if (empty-queue? queue)
      (error "FRONT called with an empty queue" queue)
      (car (front-ptr queue))))

(define (insert-queue! queue item)
  (let ((new-pair (cons item '())))
    (cond ((empty-queue? queue)
           (set-front-ptr! queue new-pair)
           (set-rear-ptr! queue new-pair)
           queue)
          (else
            (set-cdr! (rear-ptr queue) new-pair)
            (set-rear-ptr! queue new-pair)
            queue))))

(define (delete-queue! queue)
  (cond ((empty-queue? queue)
         (error "DELETE! called with an empty queue" queue))
        (else
          (set-front-ptr! queue (cdr (front-ptr queue)))
          queue)))

(define (print-queue queue)
  (front-ptr queue))

; 采用消息传递的方式定义queue
(define (make-queue)
  (let ((front-ptr '())
        (rear-ptr '()))

    (define (empty-queue?) (null? front-ptr))

    (define (print-queue) front-ptr)

    (define (insert-queue! item)
      (let ((new-pair (cons item '())))
      (cond ((empty-queue?)
             (set! front-ptr new-pair)
             (set! rear-ptr new-pair)
             front-ptr)
            (else
              (set-cdr! rear-ptr new-pair)
              (set! rear-ptr new-pair)
              front-ptr))))

    (define (delete-queue!)
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue" front-ptr))
            (else
              (set! front-ptr (cdr front-ptr))
              front-ptr)))

    (define (dispatch m)
      (cond ((eq? m 'empty) empty-queue?)
            ((eq? m 'print) print-queue)
            ((eq? m 'insert) insert-queue!)
            ((eq? m 'delete) delete-queue!)
            (else (error "DISPATCH! called with a error message" m))))
    dispatch))
