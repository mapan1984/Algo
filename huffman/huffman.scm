;;;;;;;;;;;;;;;;;;;;;; leaf
(define (make-leaf symbol weight)
  (list 'leaf symbol weight))

(define (leaf? object)
  (eq? (car object) 'leaf))

(define (symbol-leaf leaf) (cadr leaf))

(define (weight-leaf leaf) (caddr leaf))


;;;;;;;;;;;;;;;;;;;;;; tree
(define (make-code-tree left right)
  (list left
        right
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))

(define (left-branch tree) (car tree))

(define (right-branch tree) (cadr tree))

(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

;;;;;;;;;;;;;;;;;;;;;; decode
(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch
                (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- CHOOSE-BRANCH" bit))))


;;;;;;;;;;;;;;;;;;;;; encode
;; 以message和tree为参数，得出message的Huffman编码
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

;; encode-symbol: 对于给出的symbol和tree，得出symbol的编码
(define (encode-symbol symbol tree)
  (cond ((leaf? tree) '())
        ((symbol-in-tree? symbol (left-branch tree))
         (cons 0
               (encode-symbol symbol (left-branch tree))))
        ((symbol-in-tree? symbol (right-branch tree))
         (cons 1
               (encode-symbol symbol (right-branch tree))))
        (else
          (error "symbol not in tree -- ENCODE-SYMBOL" symbol))))

(define (symbol-in-tree? symbol tree)
  (define (symbol-in-list? symbol symbol-list)
    (cond ((null? symbol-list) #f)
          ((eq? symbol (car symbol-list)) #t)
          (else (symbol-in-list? symbol (cdr symbol-list)))))
  (let ((symbol-list (symbols tree)))
    (symbol-in-list? symbol symbol-list)))

;;;;;;;;;;;;;;;;;;;;;; generate huffman tree
;; adjoin x to set
;; 按上升序排列表中的元素，加入集合的新元素不会出现在原来的集合中
(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) (cons x set))
        (else (cons (car set)
                    (adjoin-set x (cdr set))))))

;; make leaf set
;; 以symbol-weight对偶的表为参数，如((A 4) (B 1) (C 2) (D 1))
;; 构造处树叶的初始排序集合，以使Huffman算法能够去做归并
(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)  ; symbol
                               (cdr pair)) ; weight
                    (make-leaf-set (cdr pairs))))))

;; generate Huffman tree
(define (generate-huffman-tree pairs)
  (successive-merge (pairs->leaves (make-leaf-set pairs))))

(define (pairs->leaves pairs)
  (map (lambda (pair) (cons 'leaf pair))
       pairs))

(define (successive-merge ordered-set)
  (cond ((= 0 (length ordered-set)) '())
        ((= 1 (length ordered-set))
         (car ordered-set))
        (else
          (let ((new-sub-tree (make-code-tree (car ordered-set)
                                              (cadr ordered-set)))
                (remained-ordered-set (cddr ordered-set)))
            (successive-merge (adjoin-set new-sub-tree remained-ordered-set))))))


;;;;;;;;;;;;;;;;;;;;;;; sample
(define sample-tree
  (make-code-tree (make-leaf 'A 4)
                  (make-code-tree
                    (make-leaf 'B 2)
                    (make-code-tree (make-leaf 'D 1)
                                    (make-leaf 'C 1)))))

(define sample-message '(0 1 1 0 0 1 0 1 0 1 1 1 0))
