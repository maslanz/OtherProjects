ORG 00H
	LJMP MAIN
	ORG 0003H
		LJMP KESME ;int0 external hardware kesmesi.	
		
	KESME:
		ACALL SAYAC ;timeri cagirarak belli araliklarla tum ledlerin yakilmasini saglar.
		SETB P1.0
		ACALL SAYAC
		SETB P1.1
		ACALL SAYAC
		SETB P1.2
		ACALL SAYAC
		SETB P1.3
		ACALL SAYAC 
		SETB P1.4
		ACALL SAYAC
		ACALL SAYAC
		CLR P1.0 ;tum ledler yandiktan sonra ledlerin ayni anda sonme islemini gerceklestirir.
		CLR P1.1
		CLR P1.2
		CLR P1.3
		CLR P1.4
		RETI
		
	SAYAC2: ;timer
		MOV TH0, #0FFH
		MOV TL0, #0FFH
		SETB TR0
		RET
		
	SAYAC:
		MOV R0,#200
		MOV R1,#200
		
	SAYAC3:	
		ACALL SAYAC2
		DJNZ R1, SAYAC3
		DJNZ R0, SAYAC3
		RET
	MAIN:
	DONGU:
		SETB EX0 ;int0 kesmesini aktif yapar.
		MOV IE,#83H ;tum kesmeleri aktif yapar.
		CLR P1.0 ;portlari temizleme islemi
		CLR P1.1
		CLR P1.2
		CLR P1.3
		CLR P1.4

SJMP $
END