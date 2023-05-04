; 테스트 케이스 리스트
;(setq testList '(11 33 23 45 13 25 8 135))
(setq testList '(83 72 65 54 47 33 29 11))
; 결과 저장 리스트
(setq ansList '())
; 중간에 한번 거치는 리스트
(setq myList '())

(setq len (length testList))
(setq len (- len 1))

; a와 b를 비교하여 작은 수를 리턴
(defun small (a b) (cond ((< a b) a) (t b)))

; 맨 처음 값 ansList에 넣기
(setq ansList (cons (car testList) ansList))
; 맨 처음 값 testList에서 삭제
(setq testList (cdr testList))
; 가장 첫 번째 작업 후 리스트의 모습
(print (append ansList testList))


(loop repeat len
; testList의 맨 처음 값 추출
do (setq num1 (car testList))
; testList의 맨 처음 값 삭제
do (setq testList (cdr testList))
; ansList의 길이 구하기
do (setq lenAL (length ansList))
; ansList안의 원소의 개수만큼 비교
do (loop repeat lenAL
; ansList의 맨 마지막 값(가장 큰 수) 추출 후
do (setq num2 (car (last ansList)))
; ansList에서 추출했던 맨 마지막 값 삭제
do (setq ansList (butlast ansList))
; num1과 num2중 작은 수를 num3에 저장
do (setq num3 (small num1 num2))
; num1 = num3이면 num1놔두고 num2를 삽입.
; 여기서 중요한 것은 비교하는 두 수중 큰 수를 myList에 삽입한다는 것.
do (if (= num1 num3)
(setq myList (cons num2 myList))
(setq myList (cons num1 myList))
)
; num3를 num1으로 다시 바꿈
do (setq num1 num3)
)

; 비교가 다 끝난 후 num3는 가장 작은 수가 남아있는 상태.
; myList에 가장 작은 수 넣기
do (setq myList (cons num3 myList))
; ansList 앞쪽에 myList 붙여넣기 (ansList는 비어있고, myList는 꽉차있으므로 사실상 myList를 ansList에 복사하는 것)
do (setq ansList (append myList ansList))
; ansList와 testList 합친거 보여주기 (현재까지 정렬된 상황)
do (print (append ansList testList))
; myList 다시 비우기
do (setq myList '())
)
