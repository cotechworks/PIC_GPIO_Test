/*
 * File:   main.c
 * Author: KOKUBO
 *
 * Created on 2018/08/02, 21:47
 */

#include <xc.h>
#define _XTAL_FREQ  8000000     // delay�p(�N���b�N8MHz�œ��쎞)

// �R���t�B�M�����[�V�����P�̐ݒ�
#pragma config FOSC = INTOSC    // �����ۯ����g�p����(INTOSC)
#pragma config WDTE = OFF       // �����ޯ����ϰ����(OFF)
#pragma config PWRTE = ON       // �d��ON����64ms�����۸��т��J�n����(ON)
#pragma config MCLRE = OFF      // �O��ؾ�ĐM���͎g�p�������޼��ٓ���(RA5)��݂Ƃ���(OFF)
#pragma config CP = OFF         // ��۸�����ذ��ی삵�Ȃ�(OFF)
#pragma config CPD = OFF        // �ް���ذ��ی삵�Ȃ�(OFF)
#pragma config BOREN = ON       // �d���d���~���펞�Ď��@�\ON(ON)
#pragma config CLKOUTEN = OFF   // CLKOUT��݂�RA6��݂Ŏg�p����(OFF)
#pragma config IESO = OFF       // �O���E�����ۯ��̐ؑւ��ł̋N���͂Ȃ�(OFF)
#pragma config FCMEN = OFF      // �O���ۯ��Ď����Ȃ�(FCMEN_OFF)

// �R���t�B�M�����[�V�����Q�̐ݒ�
#pragma config WRT = OFF        // Flash��ذ��ی삵�Ȃ�(OFF)
#pragma config PLLEN = OFF      // ����N���b�N��32MHz�ł͓��삳���Ȃ�(OFF)
#pragma config STVREN = ON      // �X�^�b�N���I�[�o�t���[��A���_�[�t���[�����烊�Z�b�g������(ON)
#pragma config BORV = HI        // �d���d���~���펞�Ď��d��(2.5V)�ݒ�(HI)
#pragma config LVP = OFF        // ��d���v���O���~���O�@�\�g�p���Ȃ�(OFF)

void main(void) {
     OSCCON = 0b01110010 ;     // �����N���b�N�͂W�l�g���Ƃ���
     ANSELA = 0b00000000 ;     // AN0-AN4�͎g�p���Ȃ��S�ăf�W�^��I/O�Ƃ���
     ANSELB = 0b00000000 ;     // AN5-AN11�͎g�p���Ȃ��S�ăf�W�^��I/O�Ƃ���
     TRISA  = 0b00000000 ;     // �s��(RA)�͑S�ďo�͂Ɋ����Ă�(RA5�͓��݂͂̂ƂȂ�)
     TRISB  = 0b00000000 ;     // �s��(RB)�͑S�ďo�͂Ɋ����Ă�
     PORTA  = 0b00000000 ;     // RA�o�̓s���̏�����(�S��LOW�ɂ���)
     PORTB  = 0b00000000 ;     // RB�o�̓s���̏�����(�S��LOW�ɂ���)

	while(1) {
          RB4 = 1 ;            // 10�ԃs��(RB4)��HIGH(5V)���o�͂���(LED ON)
          __delay_ms(1000) ;     // 1�b�E�G�C�g
          RB4 = 0 ;            // 10�ԃs��(RB4)��LOW(0V)���o�͂���(LED OFF)
          __delay_ms(1000) ;     // 1�b�E�G�C�g
    }
}
