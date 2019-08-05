//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   :
//  ��������   : OLED 4�ӿ���ʾ����(51ϵ��)
//              ˵��:
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              D0   P1^0��SCL��
//              D1   P1^1��SDA��
//              RES  ��P12
//              DC   ��P13
//              CS   ��P14
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   :
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//******************************************************************************/
#ifndef __OLED_H
#define __OLED_H

#include <15W4KxxS4.h>
#include "config.h"
#include "oledfont.h"
//#include "sys.h"
//#include "stdlib.h"

#define OLED_CMD  0 //д����
#define OLED_DATA 1 //д����
#define OLED_MODE 0


sbit OLED_SCL=P3^3;//ʱ�� D0��SCLK�
sbit OLED_SDIN=P3^4;//D1��MOSI�� ����
sbit OLED_CS=P1^6;
sbit OLED_DC=P3^2;

#define OLED_CS_Clr()  OLED_CS=0
#define OLED_CS_Set()  OLED_CS=1

#define OLED_RST_Clr() OLED_RST=0
#define OLED_RST_Set() OLED_RST=1

#define OLED_DC_Clr() OLED_DC=0
#define OLED_DC_Set() OLED_DC=1

#define OLED_SCLK_Clr() OLED_SCL=0
#define OLED_SCLK_Set() OLED_SCL=1

#define OLED_SDIN_Clr() OLED_SDIN=0
#define OLED_SDIN_Set() OLED_SDIN=1


#define   NOMALCOLORMODE    1  //������ɫģʽ
#define   INVERTCOLORMODE   0  // ��ɫģʽ


//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ

#define SIZE 16
#define XLevelL     0x02
#define XLevelH     0x10
#define Max_Column  128
#define Max_Row     64
#define Brightness  0xFF
#define X_WIDTH     128
#define Y_WIDTH     64
//-----------------OLED�˿ڶ���----------------


//OLED�����ú���
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8 x,uint8 y,uint8 t);
void OLED_Fill(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 dot);
void OLED_ShowChar(uint8 x,uint8 y,uint8 chr,uint8 Char_Size,bit mode);
void OLED_ShowNum(uint8 x,uint8 y,uint16 num,uint8 size,bit mode);
void OLED_ShowString(uint8 x,uint8 y, uint8 *p,uint8 Char_Size,bit mode);
void OLED_Set_Pos(uint8 x, uint8 y);
void OLED_ShowCHinese(uint8 x,uint8 y,uint8 no,bit mode);
void OLED_DrawBMP(uint8 x0, uint8 y0,uint8 x1, uint8 y1,uint8 *BMP,bit mode);
//void Delay_50ms(unsigned int Del_50ms);
//void Delay_1ms(unsigned int Del_1ms);
void fill_picture(uint8 fill_Data);
void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(uint8 IIC_Command);
void Write_IIC_Data(uint8 IIC_Data);
void Write_IIC_Byte(uint8 IIC_Byte);
void IIC_Wait_Ack();

uint8 find_index(uint16 a);
void OLED_ShowCHinese2(uint8 x, uint8 y, uint8 *chr,bit mode);
#endif




