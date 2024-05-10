#include "..\..\common\gui_base_classes.hpp"
#include "ui_macros.hpp"
#include "..\functions\script_macros.hpp"

class RscNiLOCDialog {
    idd = IDD_NILOCGUI_RSCNILOCDIALOG;
    movingEnable = false;
    enableSimulation = 1;

    controls[]=
    {
        lbSavedPlayers,
        lbOnlinePlayers,
        tbSavedPlayers,
        tbOnlinePlayers,
        ctrlGrpInfoArea,
        ctrlGrpConfirmation
    };

    class lbSavedPlayers: RscListbox
    {
        idc = IDC_NILOCGUI_LBSAVEDPLAYERS;
        sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
        x = 4.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
        y = 2.4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
        w = 13 * GUI_GRID_CENTER_W;
        h = 12.7 * GUI_GRID_CENTER_H;
        colorBackground[] = { .1, .1, .1, .7 };
    };
    class lbOnlinePlayers: lbSavedPlayers
    {
        idc = IDC_NILOCGUI_LBONLINEPLAYERS;
        x = 17.9 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    };
    class tbSavedPlayers: RscText
    {
        idc = -1;
        text = "SAVED PLAYERS"; //--- ToDo: Localize;
        x = 4.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
        y = 1.2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
        w = 13 * GUI_GRID_CENTER_W;
        h = 1.1 * GUI_GRID_CENTER_H;
        colorBackground[] = {
            "(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.3843])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.7019])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.8862])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_A', 0.7])"
        };
    };
    class tbOnlinePlayers: RscText
    {
        idc = -1;
        text = "ONLINE PLAYERS"; //--- ToDo: Localize;
        x = 17.9 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
        y = 1.2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
        w = 13 * GUI_GRID_CENTER_W;
        h = 1.1 * GUI_GRID_CENTER_H;
        colorBackground[] = {
            "(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.3843])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.7019])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.8862])",
            "(profilenamespace getvariable ['GUI_BCG_RGB_A', 0.7])"
        };
    };
    // Control Group
    class ctrlGrpInfoArea: RscControlsGroup {
        idc = IDC_NILOCGUI_CTRLGRPINFOAREA;
        x = 5.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
        y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
        w = 26 * GUI_GRID_CENTER_W;
        h = 17 * GUI_GRID_CENTER_H;

        class bnApply: RscButton
        {
            idc = IDC_NILOCGUI_BNAPPLY;
            text = "APPLY"; //--- ToDo: Localize;
            x = 21.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24.1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4.5 * GUI_GRID_CENTER_W;
            h = 1.1 * GUI_GRID_CENTER_H;
            onButtonClick = QUOTE([] call FUNCMAIN(guiApplyBtnClicked));
        };
        class bnClose: bnApply
        {
            idc = IDC_NILOCGUI_BNCLOSE;
            text = "CLOSE"; //--- ToDo: Localize;
            x = 26.4 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            onButtonClick = QUOTE(closeDialog IDC_EXIT_TO_MAIN);
        };
        class tbThinLine: RscText
        {
            idc = -1;
            x = 4.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 15.1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 26.1 * GUI_GRID_CENTER_W;
            h = 0.2 * GUI_GRID_CENTER_H;
            colorBackground[] = {
                "(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.3843])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.7019])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.8862])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_A', 0.7])"
            };
        };
        class stbInfo: RscStructuredText
        {
            idc = IDC_NILOCGUI_STBINFO;
            x = 4.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 15.2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 26.1 * GUI_GRID_CENTER_W;
            h = 8.8 * GUI_GRID_CENTER_H;
            colorBackground[] = { .1, .1, .1, .7 };
        };
    };

    // Control Group
    class ctrlGrpConfirmation: RscControlsGroup {
        idc = IDC_NILOCGUI_CTRLGRPCONFIRMATION;
        x = 5.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
        y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
        w = 26 * GUI_GRID_CENTER_W;
        h = 17 * GUI_GRID_CENTER_H;

        class Controls {
            class tbConfirmation: RscText
            {
                idc = -1;
                text = "CONFIRMATION"; //--- ToDo: Localize;
                x = 6.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
                y = 6 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
                w = 17 * GUI_GRID_CENTER_W;
                h = 1.1 * GUI_GRID_CENTER_H;
                colorBackground[] = {
                    "(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.3843])",
                    "(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.7019])",
                    "(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.8862])",
                    "(profilenamespace getvariable ['GUI_BCG_RGB_A', 0.7])"
                };
            };
            class stbConfirmation: RscStructuredText
            {
                idc = IDC_NILOCGUI_STBCONFIRMATION;
                x = 6.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
                y = 7.2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
                w = 17 * GUI_GRID_CENTER_W;
                h = 7.2 * GUI_GRID_CENTER_H;
                colorBackground[] = { 0, 0, 0, 1 };
            };
            class bnNo: RscButton
            {
                idc = -1;
                text = "NO"; //--- ToDo: Localize;
                x = 19.7 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
                y = 14.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
                w = 3.8 * GUI_GRID_CENTER_W;
                h = 1.1 * GUI_GRID_CENTER_H;
                colorBackground[] = { 0, 0, 0, 1 };
                onButtonClick = QUOTE(((findDisplay IDD_NILOCGUI_RSCNILOCDIALOG) displayCtrl IDC_NILOCGUI_CTRLGRPCONFIRMATION) ctrlShow false; \
                                      ((findDisplay IDD_NILOCGUI_RSCNILOCDIALOG) displayCtrl IDC_NILOCGUI_BNAPPLY) ctrlEnable true);
            };
            class bnYes: bnNo
            {
                idc = -1;
                text = "YES"; //--- ToDo: Localize;
                x = 15.8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
                onButtonClick = QUOTE([] call FUNCMAIN(guiYesBtnSetProfile));
            };
        };
    };
};
