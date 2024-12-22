	.include "MPlayDef.s"

	.equ	se_low_health_grp, voicegroup127
	.equ	se_low_health_pri, 3
	.equ	se_low_health_rev, 0
	.equ	se_low_health_mvl, 100
	.equ	se_low_health_key, 0
	.equ	se_low_health_tbs, 1
	.equ	se_low_health_exg, 1
	.equ	se_low_health_cmp, 1

	.section .rodata
	.global	se_low_health
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_low_health_1:
	.byte	KEYSH , se_low_health_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte	TEMPO , (150*se_low_health_tbs+1)/2
	.byte		VOICE , 15
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*se_low_health_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		BEND  , c_v+17
	.byte		N12   , Dn4 , v080
	.byte	W12
@ 002   ----------------------------------------
	.byte		BEND  , c_v+31
	.byte		N12   , An3 
	.byte	W12
@ 003   ----------------------------------------
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Dn4 , v100
	.byte	W12
@ 005   ----------------------------------------
	.byte		        An3 
	.byte	W12
@ 006   ----------------------------------------
	.byte	W12
@ 007   ----------------------------------------
	.byte		N11   , Dn4 
	.byte	W11
	.byte		N12   , An3 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W12
@ 009   ----------------------------------------
	.byte	W11
	.byte	FINE

@******************************************************@
	.align	2

se_low_health:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_low_health_pri	@ Priority
	.byte	se_low_health_rev	@ Reverb.

	.word	se_low_health_grp

	.word	se_low_health_1

	.end
