/*
 * Copyright        : Shendong MCU studio
 * File Description : GUI frame implementation.
 * Created          : oliverzhang@shendongmcu.com
 */
#include "gui.h"
#include "key.h"
static uint8 idata g_current_dlg;//��ǰ�Ի���������

void gui_DlgSetActive(uint8 dlg_index) //��ȡ��ǰ����ĶԻ���������
{
    g_current_dlg = dlg_index;
}

void gui_Task(void)
{
    uint32 xdata ticks;
    static uint32 xdata oldticks;
    uint8 xdata ret, key_code, key_state;
    uint8 msg_type = 0xffu, msg_code = 0xffu;

    ticks = time_GetTicks();
    if(ticks - oldticks < 10) //��ʱ��Ϣ
    {
        /*Do nothing.*/
    }
    else
    {
        oldticks = ticks;
        msg_type = WM_TIMER;
        msg_code = 0;
    }
    if(msg_type == 0xffu)//��ȡ����״̬����ֵ  ��Ϣ
    {
        ret = key_GetKeyCode(&key_code, &key_state);
        if(ret != 0)
        {
            msg_code = key_code;
            msg_type = key_state;
        }
    }
    if(msg_type != 0xffu)//��Ϣ��Ϊ��
    {
        switch(g_current_dlg)//���ݵ�ǰ�Ի��򼤻ͬ�Ĵ��ں���
        {
        case 0:
            break;
        case DLG_DESKTOP:
            gui_DlgDesktopProc(msg_type, msg_code);
            break;
        case DLG_MAINMENU:
            gui_DlgMainMenuProc(msg_type, msg_code);
            break;
        case DLG_KEYDEMO:
            gui_DlgKeyDemoProc(msg_type, msg_code);
            break;
        case DLG_LEDDEMO:
            gui_DlgLedDemoProc(msg_type, msg_code);
            break;
        case DLG_RTCDEMO:   /*add function here*/
            gui_DlgRTCDemoProc(msg_type, msg_code);
            break;
        case DLG_BUZZERDEMO: /*add function here*/
					  gui_DlgBuzzerDemoProc(msg_type, msg_code);
            break;
        case DLG_DHTDEMO: /*add function here*/
            gui_DlgDHTDemoProc(msg_type, msg_code);
            break;
        default:
            printf("No dialog proc.\r\n");
            break;
        }
    }
}

void gui_DlgDefaultProc(uint8 msg_type, uint8 msg_code)
{
    /*Add your default proc here.*/
    msg_type = msg_type;
    msg_code = msg_code;
}

//��ȡ��Ϣ�����ַ���
const char *gui_GetMsgTypeString(uint8 msg_type)
{
    switch(msg_type)
    {
    case WM_KEYPRESSED:
        return "0";
    case WM_KEYREPEATED:
        return "1";
    case WM_KEYRELEASED:
        return "2";
    case WM_TIMER:
        return "WM_TIMER";
    default:
        return "unknown type";
    }
}
//��ȡ��Ϣ����  Ŀǰ����Ϊ�ĸ�����
const char *gui_GetMsgCodeString(uint8 msg_code)
{
    switch(msg_code)
    {
    case KEY_PLUS:
        return("KEY_PLUS: ");
        break;
    case KEY_MINUS:
        return("KEY_MINUS: ");
        break;
    case KEY_RETURN:
        return("KEY_RETURN: ");
        break;
    case KEY_SET:
        return("KEY_SET: ");
        break;
    case KEY_NONE:
        return("KEY_NONE or unknown: ");
        break;
    default:
        return("impossible to run here:");
        break;
    }
}

void gui_DrawAllControls(const struct gui_control *plist, uint8 active)
{
    uint8 i;
    if(plist == NULL) return;
    for(i = 0; plist[i].type != CON_ENDFLAG && i < CON_MAX_ITEMS; i++)
    {
        gui_DrawControl(&plist[i], (i == active));
    }
}

void gui_DrawControl(const struct gui_control *pcon, uint8 is_active)
{
    if(pcon == NULL) return;
    if(pcon->type == CON_TXTBUTTON)//Ӣ���ı���ť�ؼ�
    {
        OLED_ShowString(pcon->x, pcon->y, pcon->str, 8, (is_active) ? g_style_reverse : g_style_normal);
    }
    else if(pcon->type == CON_BMPBUTTON)//ͼ�ΰ�ť
    {
        OLED_DrawBMP(pcon->x, pcon->y, pcon->x + 14, pcon->y, pcon->str, (is_active) ? g_style_reverse : g_style_normal);
    }
    else if(CON_TXTBUTTON_CHS == pcon->type ) //�����ı���ť
    {
        OLED_ShowCHinese2(pcon->x, pcon->y, pcon->str, (is_active) ? g_style_reverse : g_style_normal);
    }
    else if(CON_NUMBUTTON == pcon->type) //���ְ�ť�ؼ�
    {
        OLED_ShowString(pcon->x, pcon->y, pcon->str, 8, (is_active) ? g_style_reverse : g_style_normal);
    }
}

void gui_SearchPrevControl(const struct gui_control *plist, uint8 *pactive)
{
    uint8 end, active = *pactive;
    if(plist == NULL) return;
    gui_DrawControl(&plist[active], 0);
    for(end = 0; plist[end].type != CON_ENDFLAG && end < CON_MAX_ITEMS; end++);
    if(active == 0) active = end - 1;
    else active --;
    gui_DrawControl(&plist[active], 1);
    *pactive = active;
}

void gui_SearchNextControl(const struct gui_control *plist, uint8 *pactive)
{
    uint8 active = *pactive;
    if(plist == NULL) return;
    gui_DrawControl(&plist[active], 0);
    active ++;
    if(plist[active].type == CON_ENDFLAG) active = 0;
    gui_DrawControl(&plist[active], 1);
    *pactive = active;
}

uint8 idata g_con_param_list[CON_MAX_ITEMS];  //ÿһҳһ���Ի��򣬶Ի����а����ؼ���������
union gui_all_dlg xdata g_all_dlg;




/********************************End of File************************************/