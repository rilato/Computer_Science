; N = 4이므로 길이가 4인 일차원 배열을 만든다.
(setq arr (make-array '(4)))

; 배열 arr의 모든 값을 0으로 초기화한다.
(loop for x from 0 to 3
    do (setf (aref arr x) 0)
)

; 다음 행에 퀸을 배치할지, 같은 행의 다른 열에 퀸을 배치할지 결정하는 함수
(defun check (num index)
; arr[num] = index
(setf (aref arr num) index)
; target = arr[num]
(setq target (aref arr num))
; myNum = num - 1
(setq myNum (- num 1))
; 참인지 거짓인지를 결정할 flag 인 bool
; 초기 값은 0으로 설정
(setq bool 0) ; flag
; 0번부터 myNum번까지 반복
(loop for x from 0 to myNum
    ; arrValue = arr[x]
    do (setq arrValue (aref arr x))
    ; a는 동일 선상에 있는 경우
    ; arrValue == target이면 a는 true 저장, arrValue != target이면 a는 false 저장
    do (setq a (= arrValue target))
    ; b는 대각선에 있는 경우
    ; ㅣtarget - valueㅣ  == num - x인 경우 b에 true 저장, 그렇지 않으면 b에 false저장
    do (setq b (= (abs (- target arrValue)) (- num x)))
    ; a와 b가 모두 true이면 bool을 1로 바꿔줌
    ; 둘 중 하나라도 false이면 건너뜀
    do (if (or a b) (setq bool 1) (continue))
) ; end loop
; bool이 1이라는 것은 위의 loop에서 조건을 만족한 경우로, false를 리턴하도록 하고
; bool이 0이라는 것은 위의 loop에서 조건을 만족하지 못한 경우로, true를 리턴하도록 함
(if (= bool 1) NIL T)
) ; end defun

; n queen 함수
; 재귀적으로 구현
(defun nqueen (number)
; number < 4인 경우는, 모두 nqueen 조건을 만족하지 못하므로 출력하지 않음
; n == 4라는 것은, nqueen이 요구하는 배치에 맞게 정렬되었음을 의미 -> 출력 진행
(if (= number 4) (terpri))
(if (= number 4) (princ "( "))
(if (= number 4)
    (loop for i from 0 to 3
        do (princ "(")
        ; 행 출력
        do (princ (+ i 1))
        do (princ ",")
        ; 열 출력
        do (princ (+ (aref arr i) 1))
        do (princ ") ")
    ); true인 경우 print, end loop
;start else case ( number < 4인 경우 )
(loop for j from 0 to 3
    ; 참인지 거짓인지를 결정할 flag인 flag를 설정
    ; 초기 값은 0으로 설정
    do (setq flag 0)
    ; check함수의 조건을 만족하면, flag에 1을 저장하고, 그렇지 않으면 flag에 0을 저장 
    do (if (check number j) (setq flag 1) (setq flag 0))
    ; flag가 1이라는 것은, check의 조건을 만족했다는 의미이므로 nqueen을 재귀적으로 실행
    ; flag가 0이라는 것은, check의 조건을 만족하지 못했다는 의미이므로, flag를 그냥 0으로 둠
    do (if (= flag 1) (nqueen (+ number 1)) (setq flag 0))
); end else case
); end if
; 출력 형식을 맞춰주기 위해 출력
(if (= number 4) (princ ")"))
); end defun

; nqueen에 number가 0이 들어갔을 때 부터 순차적으로 진행
(nqueen 0)
