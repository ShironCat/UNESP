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
multi10_temp1	equ	H'27'
multi10_temp2	equ	H'28'
decoded_input	equ	H'29'
output		equ	H'2A'
BCDvalH		equ	H'2B'
BCDvalM		equ	H'2C'
BCDvalL		equ	H'2D'
MCount		equ	H'2E'
Num		equ	H'2F'
Temp		equ	H'30'

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
		movlw	B'11111111'
		movwf	trisa
		movlw	B'11110000'
		movwf	trisb
		bcf	status, RP0
		return

multi10		movlw	D'10'
		movwf	multi10_temp1
		movf	input, 0
		movwf	multi10_temp2
		movlw	B'0'
booth_loop_m	rrf	multi10_temp1, 1
		btfsc	status, C
		addwf	multi10_temp2, 0
		movf	multi10_temp1, 1
		btfsc	status, Z
		retfie
		rlf	multi10_temp2, 1
		goto	booth_loop_m

convert_d	movf	counter, 0
		movwf	convert_temp
		incf	convert_temp, 1
		movlw	B'0'
		movwf	convert_result
multi_loop	decfsz	convert_temp, 1
		call	multi10
		addwf	convert_result,	1
		movf	convert_temp, 1
		btfsc	status, Z
		retfie
		goto	multi_loop

HexBCD		movlw	d'8'
		movwf	MCount
		clrf	BCDvalH
		clrf	BCDvalM
		clrf	BCDvalL
		bcf	STATUS, C

loop8		rlf	Num, F
		rlf	BCDvalL, F
		rlf	BCDvalM, F
		rlf	BCDvalH, F
		decf	MCount, F
		btfsc	STATUS, Z
		return

adjDEC		movlw	BCDvalL
		movwf	FSR
		call	adjBCD
		movlw	BCDvalM
		movwf	FSR
		call	adjBCD
		movlw	BCDvalH
		movwf	FSR
		call	adjBCD
		goto	loop8

adjBCD		movlw	d'3'
		addwf	INDF,W
		movwf	Temp
		btfsc	Temp,3
		movwf	INDF
		movlw	30h
		addwf	INDF,W
		movwf	Temp
		btfsc	Temp,7
		movwf	INDF
		return

main		call	setup
		movlw	D'2'
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
		btfsc	status, Z
		goto	read_loop
		movlw	D'0'
		movwf	counter
compare		incf	counter, 1
		call	table
		movwf	output
		movf	decoded_input, 0
		subwf	output, 0
		btfsc	status, C
		goto	compare
		movf	output, 0
		movwf	Num
		call	HexBCD
		movf	BCDvalH, 0
		movwf	portb
		movf	BCDvalM, 0
		movwf	portb
		movf	BCDvalL, 0
		movwf	portb
		end