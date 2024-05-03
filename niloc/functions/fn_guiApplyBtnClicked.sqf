#include "script_macros.hpp"
/*
 * Author: Pixelated_Grunt
 * Call the confirmation dialog to apply saved to select player
 *
 * Arguments:
 * Nil
 *
 * Return Value:
 * Nil
 *
 * Example:
 * [] spawn XDF_fnc_guiApplyBtnClicked
 *
 * Public: No
**/


if !(hasInterface) exitWith {};

private ["_display", "_idx", "_savedName", "_playerName", "_confirmBox"];
disableSerialization;

// Online player
_idx = lbCurSel IDC_NILOCGUI_LBONLINEPLAYERS;
_playerName = lbText [IDC_NILOCGUI_LBONLINEPLAYERS, _idx];

// Saved player
_idx = lbCurSel IDC_NILOCGUI_LBSAVEDPLAYERS;
_savedName = lbText [IDC_NILOCGUI_LBSAVEDPLAYERS, _idx];

_display = findDisplay IDD_NILOCGUI_RSCNILOCDIALOG;
_confirmBox = _display displayCtrl IDC_NILOCGUI_STBCONFIRMATION;
//(_display displayCtrl IDC_NILOCGUI_BNAPPLY) ctrlEnable false;
//(_display displayCtrl IDC_NILOCGUI_BNCLOSE) ctrlEnable false;
(_display displayCtrl IDC_NILOCGUI_CTRLGRPCONFIRMATION) ctrlShow true;

_confirmBox ctrlSetStructuredText parseText format [
    "<t align='left'>Really apply </t><t color='#ff0000'>%1</t><t color='#ffffff'> save file to </t><t color='#0000ff'>%2</t><t color='#ffffff'>?</t>",
    _savedName,
    _playerName
]
