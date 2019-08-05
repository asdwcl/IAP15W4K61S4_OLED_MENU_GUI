/*
 * Copyright        : Shendong MCU studio
 * File Description : Desktop Dialog
 * Created          : oliverzhang@shendongmcu.com
 */

#include "gui.h"

static void InitDesktop(void)  //��ʼ������������Ϊ0
{
    struct dlg_desktop_param *p = &g_all_dlg.desktop_param;
    memset(p,0,sizeof(*p));
    p->oldticks = time_GetTicks();   
}

static void ShowLogo(void)
{
    struct dlg_desktop_param *p = &g_all_dlg.desktop_param;
    uint32 ticks = time_GetTicks();
    if(ticks - p->oldticks < 15*1000ul) return;
    gui_DlgMainMenuOpen();
}

void gui_DlgDesktopProc(uint8 msg_type, uint8 msg_code)
{
    msg_code = msg_code;
    if(msg_type == WM_KEYPRESSED)
    {
        gui_DlgMainMenuOpen();
    }
    else if(msg_type == WM_TIMER)
    {
        ShowLogo();  //����ֻ�����ó�ʱ��Ϣ  ��������ʱ����ʱ����ʾ���˵�����
    }
}

void gui_DlgDesktopOpen(void)
{
    OLED_ShowCHinese2(36,3,"����ϵͳ",NOMALCOLORMODE);
    gui_DlgSetActive(DLG_DESKTOP);
    InitDesktop();
}



/********************************End of File************************************/