#include "script_macros.hpp"
/*
 * Author: Pixelated_Grunt
 * Initialise the niloc system from cfgfunctions
 *
 * Arguments:
 * Nil
 *
 * Return Value:
 * Nil
 *
 * Example:
 * [] call XDF_fnc_niloc_init
 *
 * Public: No
**/


if (!isServer) exitWith {};
INFO("==================== NiLOC Initialisation Starts ====================");

// Keep this EH before database initiation
addMissionEventHandler [
    "PlayerConnected", {
        params ["", "_uid", "_name", "_jip"];

        if (_name isNotEqualTo "__SERVER__") then {
            private _sectionHash = ["session"] call FUNCMAIN(getSectionAsHashmap);
            private _startTime = diag_tickTime;

            _sectionHash set ["session.player." + _uid, [_name, _startTime, _jip]];
            ["session", [_sectionHash]] call FUNCMAIN(putSection);
        };
    }
];

INFO("---------- Setting Up Database ----------");
waitUntil { [] call FUNCMAIN(dbInit) };

private _sessionHash = ["session", ["session.number"]] call FUNCMAIN(getSectionAsHashmap);
private _sessionNo = _sessionHash get "session.number";
private _vicCount = 0;

INFO_1("Database loaded, current game session is (%1).", _sessionNo);

//waitUntil { time > 0 };
INFO("---------- Tagging Vehicles ----------");
{
    if (IS_VEHICLE(_x)) then {
        _vicCount = _vicCount + 1;
        _x setVariable [QGVAR(tag), "vic_" + str _vicCount];
        INFO_2("Vechile (%1) is tagged as (%2).", str _x, _x getVariable QGVAR(tag));
    };
} forEach ALL_VEHICLES;
INFO_1("%1 vehicles had been tagged.", _vicCount);

if (_sessionNo > 1) then {
    private _result = 0;

    if(missionNamespace getVariable [QGVAR(preloadMarkers), true]) then {
        INFO("---------- Loading User Map Markers ----------");
        _result = [] call FUNCMAIN(restoreUserMarkers);

        INFO_1("%1 user markers loaded.", _result);
        ["session", ["session.loaded.markers", _result]] call FUNCMAIN(putSection);
        missionNamespace setVariable [QGVAR(loadedMarkers), _markers, true];
    };
};

addMissionEventHandler [
    "EntityKilled", {
        params ["_unit", "", "", ""];

        [_unit] call FUNCMAIN(handleDeadEntity);
    }
];

// This EH only available in dev branch 2.18
//addMissionEventHandler [
//    "EntityDeleted", {
//        params ["_entity"];
//
//        [_entity] call FUNCMAIN(handleDeadEntity);
//    }
//];

addMissionEventHandler [
    "HandleDisconnect", {
        params ["_unit", "", "_uid", "_name"];

        private ["_playersHash", "_sessionPlayerStats", "_playedTime"];

        _playersHash = ["players"] call FUNCMAIN(getSectionAsHashmap);
        _sessionPlayerStats = (["session"] call FUNCMAIN(getSectionAsHashmap)) get "session.player." + _uid;
        _playedTime = diag_tickTime - (_sessionPlayerStats select 1);

        // Only save if record doesn't already exist and connect time is > 5 mins
        if (((count _playersHash == 0) || !(_uid in _playersHash)) && _playedTime > 300) then {
            [_unit, _uid, _name] call FUNCMAIN(savePlayersStates);
        };
    }
];

addMissionEventHandler [
    "MPEnded", {
        private _lastSave = (["session", ["session.last.save"]] call FUNCMAIN(getSectionAsHashmap)) get "session.last.save";

        if (_lastSave > 0) then {
            [] call FUNCMAIN(backupDatabase);
        } else {
            INFO_1("There was (%1) save in this session ... skipping backup.", _lastSave);
        }
    }
];

INFO("==================== NiLOC Initialisation Finished ====================");
