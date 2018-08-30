;hello with name
(define hello
	(lambda (name)
		(string-append "hello " name " !")))



;sum of three numbers
(define sum
	(lambda (a b c)
		(+ a b c)))


;
(define abs
	(lambda (x)
		(if (< x 0)
			(-x) x)))

(sum 1 2 3)




