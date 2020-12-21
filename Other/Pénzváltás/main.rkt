#lang racket

(define (dp ls idx rem)
    (if (equal? 0 rem)
        1
        (if (< rem 0)
            0
            (if (>= idx 8)
                0
                (+ (dp ls (+ idx 1) rem) (dp ls idx (- rem (list-ref ls idx))))
            )
        )
    )
)

(let loop ()
    (define a (read))
    (when (not (eof-object? a))
        (printf "~a\n" (dp (list 1 2 5 10 20 50 100 200) 0 a))
        (loop)))