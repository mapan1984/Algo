; 将总值为amount的钱换为面值为50,25,10,5,1的硬币，共有多少种方法？
;; 基本情况
; amount == 0, result = 1: 即当amount递归减到0后，即找到一种解
; amount < 0, result = 0: 递归减到负数
; kinds-of-coins == 0, result = 0: 硬币数减到0，然而amount未减到0或负数
;;
; 对硬币排序，可能的兑换结果数为：  不使用第一种硬币的可能结果
;                                 + 使用第一种硬币的可能结果
;  而使用第一种硬币的可能结果 == amount - 第一种硬币币值 后使用所有硬币的可能结果

(define (count_change amount)

  (define (first-denomination kinds-of-coins)
    (cond ((= kinds-of-coins 1) 1)
          ((= kinds-of-coins 2) 5)
          ((= kinds-of-coins 3) 10)
          ((= kinds-of-coins 4) 25)
          ((= kinds-of-coins 5) 50)))

  (define (cc amount kinds-of-coins)
    (cond ((= amount 0) 1)
          ((or (< amount 0) (= kinds-of-coins 0)) 0)
          (else (+ (cc amount
                       (- kinds-of-coins 1))
                   (cc (- amount
                          (first-denomination kinds-of-coins))
                       kinds-of-coins)))))

  (cc amount 5))

;;

(define us-coins (list 50 25 10 5 1))

(define uk-coins (list 100 50 20 10 5 2 1 0.5))

(define (except-first-denomination coin-values)
  (cdr coin-values)))

(define (first-denomination coin-values)
  (car coin-values))

(define (no-more? coin-values)
  (null? coin-values)))

(define (cc amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
          (+ (cc amount
                 (except-first-denomination coin-values))
             (cc (- amount
                    (first-denomination coin-values))
                 coin-values)))))

(cc 100 us-coins)
