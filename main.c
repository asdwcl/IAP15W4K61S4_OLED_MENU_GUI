/********************************Copyright (c)**********************************\
**
**                   (c) Copyright 2019, Main, China, QD.
**                           All Rights Reserved
**
**                                 By(wo4fisher)
**                           http://www.wo4fisher.com
**
**----------------------------------�ļ���Ϣ------------------------------------
** �ļ�����: main.c
** ������Ա: wht
** ��������: 2019-02-17
** �ĵ�����:
**
**----------------------------------�汾��Ϣ------------------------------------
** �汾����: V0.1
** �汾˵��: ��ʼ�汾
**
**------------------------------------------------------------------------------
\********************************End of Head************************************/
#include <15W4KxxS4.h>
#include <intrins.h>
#include "stdio.h"
#include "config.h"
#include "delay.h"
#include "oled.h"
#include "bmp.h"
#include "led.h"
#include "key.h"
#include "ds1302.h"
#include "usart.h"
#include "DHT11.H"
#include "timer.h"
#include "gui.h"
#include "buzzer.h"

void PWMIO_init(void);
//void ProcessKey(void)
//{
//    unsigned char ret, keycode, keystate;

//    ret = key_GetKeyCode(&keycode, &keystate);
//    if(ret == 0) return;
//    printf("keycode=%bu   key_state=%bu\r\n", keycode, keystate);
//}
int main ( void )
{
    PWMIO_init();
    AUXR = 0X00;//����1 ����2  ��ʱ��1 ��ʱ��2 �ٶ�ѡ��bit1��extram����λ��
    usart_init ( USART1 );
    //usart_init ( USART2 );
    //Ds1302Init();
    led_init();
    key_init();
	
    play_tick();
	
    OLED_DC_Clr();
    delayxms ( 500 );
    OLED_CS_Clr();

    delayxms ( 1000 );
    OLED_Init();            //��ʼ��OLED
    OLED_Clear()    ;
    delayxms ( 200 );

    Timer4Init();     //���������ʱ��Ƭ��ʱ����ʼ��
    printf("Hello world.\r\n");

    OLED_Clear();
    delayxms ( 300 );

    EA = 1;    //ʹ��ȫ���ж�

    gui_DlgDesktopOpen(); //GUI��ʼ����/�Ի����֮�󣬿�ʼʹ��gui_task()���ȶԻ���

    while ( 1 )
    {
        key_Task();
        //ProcessKey();
        gui_Task();
    }

}
void PWMIO_init(void)
{
    /////////////////////////////////////////////////
    //ע��: STC15W4K32S4ϵ�е�оƬ,�ϵ��������PWM��ص�IO�ھ�Ϊ
    //      ����̬,�轫��Щ������Ϊ׼˫��ڻ�ǿ����ģʽ��������ʹ��
    //���IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
    //        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
    /////////////////////////////////////////////////
    P0M1 = 0x00;
    P0M0 = 0x00;    //����P0.0~P0.7Ϊ׼˫���
    P1M1 = 0x00;
    P1M0 = 0x00;    //����P1.0~P1.7Ϊ׼˫���
    P2M1 = 0x00;
    P2M0 = 0x00;    //����P2.0~P2.7Ϊ׼˫���
    P3M1 = 0x00;
    P3M0 = 0x00;    //����P3.0~P3.7Ϊ׼˫���
    P4M1 = 0x00;
    P4M0 = 0x00;    //����P4.0~P4.7Ϊ׼˫���
    P5M1 = 0x00;
    P5M0 = 0x00;    //����P5.0~P5.5Ϊ׼˫���
    P6M1 = 0x00;
    P6M0 = 0x00;    //����P6.0~P6.7Ϊ׼˫���
    P7M1 = 0x00;
    P7M0 = 0x00;    //����P7.0~P7.7Ϊ׼˫���
}
/********************************End of File************************************/

