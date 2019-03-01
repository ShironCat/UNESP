    list p=16f873A
    #include	<p16f873a.inc>

    __CONFIG _CP_OFF & _WDT_OFF & _BODEN_OFF & _PWRTE_ON & _RC_OSC & _WRT_OFF & _LVP_ON & _CPD_OFF

status		equ	H'03'
porta		equ	H'85'
trisa		equ	H'85'
portb		equ	H'86'
trisb		equ	H'86'
w_temp		equ	H'20'
w_temp1		equ	H'A0'
status_temp	equ	H'21'
pclath_temp	equ	H'22'
counter		equ	H'23'
input		equ	H'24'
convert_temp	equ	H'25'
convert_result	equ	H'26'
decoded_input	equ	H'29'
output		equ	H'2A'
hundreds	equ	H'2B'
bin		equ	H'2C'
tens_and_ones	equ	H'2D'
A0		equ	H'2E'
B0		equ	H'2F'
C0		equ	H'30'
C1		equ	H'31'

		org	H'000'
		nop
		goto	main

		org	H'004'
		movwf	w_temp
		movf	status, w
		bcf	status, RP0
		movwf	status_temp
		movf	PCLATH, w
		movwf	pclath_temp
		retfie

table		addwf	PCL, 1
		retlw	D'251'
		retlw	D'241'
		retlw	D'239'
		retlw	D'233'
		retlw	D'229'
		retlw	D'227'
		retlw	D'223'
		retlw	D'211'
		retlw	D'199'
		retlw	D'197'
		retlw	D'193'
		retlw	D'191'
		retlw	D'181'
		retlw	D'179'
		retlw	D'173'
		retlw	D'167'
		retlw	D'163'
		retlw	D'157'
		retlw	D'151'
		retlw	D'149'
		retlw	D'139'
		retlw	D'137'
		retlw	D'131'
		retlw	D'127'
		retlw	D'113'
		retlw	D'109'
		retlw	D'107'
		retlw	D'103'
		retlw	D'101'
		retlw	D'97'
		retlw	D'89'
		retlw	D'83'
		retlw	D'79'
		retlw	D'73'
		retlw	D'71'
		retlw	D'67'
		retlw	D'61'
		retlw	D'59'
		retlw	D'53'
		retlw	D'47'
		retlw	D'43'
		retlw	D'41'
		retlw	D'37'
		retlw	D'31'
		retlw	D'29'
		retlw	D'23'
		retlw	D'19'
		retlw	D'17'
		retlw	D'13'
		retlw	D'11'
		retlw	D'7'
		retlw	D'5'
		retlw	D'3'
		retlw	D'2'
		retlw	D'1'

setup		bsf	status, RP0
		movlw	H'FF'
		movwf	trisa
		movlw	H'F0'
		movwf	trisb
		bcf	status, RP0
		return

multi		clrf	C0
		clrf	C1
		movf	A0, 0
		movwf	C0
loop_multi	decf	B0, 1
		btfsc	status, Z
		return
		movf	A0, 0
		addwf	C0, 1
		btfsc	status, C
		incf	C1, 1
		goto	loop_multi

convert_d	movf	counter, 0
		movwf	convert_temp
		clrf	convert_result
multi_loop	incf	convert_temp, 1
		decfsz	convert_temp, 1
		movf	input, 0
		movwf	B0
		movlw	D'10'
		movwf	A0
		call	multi
		movf	C0, 0
		movwf	input
		addwf	convert_result,	1
		decf	convert_temp, 1
		btfsc	status, Z
		return
		goto	multi_loop

convert_e	clrf	hundreds
		swapf	bin, 0
		addwf	bin, 0
		andlw	B'00001111'
		btfsc	status, DC
		addlw	H'16'
		btfsc	status, DC
		addlw	H'06'
		addlw	H'06'
		btfss	status, DC
		sublw	H'06'
		btfsc	bin, 4
		addlw	H'21'
		btfss	status, DC
		sublw	H'06'
		btfsc	bin, 5
		addlw	H'30'
		btfsc	bin, 6
		addlw	H'60'
		btfsc	bin, 7
		addlw	H'20'
		addlw	H'60'
		rlf	hundreds, 1
		btfss	hundreds, 0
		sublw	H'60'
		movwf	tens_and_ones
		btfsc	bin, 7
		incf	hundreds, 1
		return

main		call	setup
		movlw	D'3'
		movwf	counter
		movlw	H'00'
		movwf	decoded_input
read_loop	movf	porta, 0
		movwf	input
		decfsz	counter, 1
		call	convert_d
		movf	convert_result, 0
		addwf	decoded_input, 1
		movf	counter, 1
		btfss	status, Z
		goto	read_loop
		movlw	H'FF'
		movwf	counter
compare		incf	counter, 0
		movwf	counter
		call	table
		movwf	output
		movf	decoded_input, 0
		bcf	status, C
		subwf	output, 0
		btfsc	status, C
		goto	compare
		movf	output, 0
		movwf	bin
		call	convert_e
		movf	hundreds, 0
		movwf	portb
		movlw	H'F0'
		andwf	tens_and_ones, 0
		movwf	portb
		movlw	H'0F'
		andwf	tens_and_ones, 0
		movwf	portb
		end