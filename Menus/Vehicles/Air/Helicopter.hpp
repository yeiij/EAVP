class Helicopter
{
    targetType = 2;
    target = "Helicopter";

    class Actions
    {
        // Locks a vehicle
        class Lock: ExileAbstractAction
        {
            title = "Lock";
            condition = "((locked ExileClientInteractionObject) isEqualTo 0) && ((locked ExileClientInteractionObject) != 1)";
            action = "true spawn ExileClient_object_lock_toggle";
        };

        // Unlocks a vehicle
        class Unlock: ExileAbstractAction
        {
            title = "Unlock";
            condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
            action = "false spawn ExileClient_object_lock_toggle";
        };

        /*// Hot-wires a vehicle
        class Hotwire: ExileAbstractAction
        {
            title = "Hotwire";
            condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
            action = "['HotwireVehicle', _this select 0] call ExileClient_action_execute";
        };*/

        // Repairs a vehicle to 100%. Requires Duckttape
        class Repair: ExileAbstractAction
        {
            title = "Repair";
            condition = "true";
            action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
        };

        // Flips a vehicle so the player doesnt have to call an admin
        // Check if vector up is fucked
        class Flip: ExileAbstractAction
        {
            title = "Flip";
            condition = "call ExileClient_object_vehicle_interaction_show";
            action = "_this call ExileClient_object_vehicle_flip";
        };

        // Fills fuel from a can into a car
        class Refuel: ExileAbstractAction
        {
            title = "Refuel";
            condition = "call ExileClient_object_vehicle_interaction_show";
            action = "_this call ExileClient_object_vehicle_refuel";
        };

        // Drains fuel from a car into an empty jerry can
        class DrainFuel: ExileAbstractAction
        {
            title = "Drain Fuel";
            condition = "call ExileClient_object_vehicle_interaction_show";
            action = "_this call ExileClient_object_vehicle_drain";
        };

        class RotateLeft: ExileAbstractAction
        {
            title = "Rotate Left";
            condition = "call ExileClient_object_vehicle_interaction_show";
            action = "[ExileClientInteractionObject,-15] call ExileClient_object_vehicle_rotate";
        };

        class RotateRight: ExileAbstractAction
        {
            title = "Rotate Right";
            condition = "call ExileClient_object_vehicle_interaction_show";
            action = "[ExileClientInteractionObject,15] call ExileClient_object_vehicle_rotate";
        };

/******************************************************************************/
/* CUSTOM */
/******************************************************************************/
        class ClaimVehicle: ExileAbstractAction
        {
            title = "Claim Ownership";
            condition = "true";
            action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
        };

        /*class HackVG : ExileAbstractAction
        {
            title = "Hack Virtual Garage";
            condition = "call ExAd_fnc_canHackVG";
            action = "_this spawn ExAd_fnc_startHack";
        };*/

        /*class PackDeployedVehicle: ExileAbstractAction
        {
            title = "Pack Vehicle";
            condition = "call ExAd_XM8_DV_fnc_canPack";
            action = "call ExAd_XM8_DV_fnc_pack";
        };*/

        class Rearm: ExileAbstractAction
        {
            title = "Rearm";
            condition = "!(magazinesAllTurrets _this isEqualto [])"; //condition = "!(_this magazinesAllTurrets isEqualto [])";
            action = "['RearmVehicle', _this select 0] call ExileClient_action_execute";
        };

        class Salvage: ExileAbstractAction
        {
            title = "Salvage Vehicle";
            condition = "(!(alive (ExileClientInteractionObject)))";
            action = "_this call SV_fnc_SalvageVehicle";
        };

        /*class ScanLock: ExileAbstractAction
        {
            title = "Scan Lock";
            condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && !ExilePlayerInSafezone && ((locked ExileClientInteractionObject) != 1)";
            action = "_this call ExileClient_object_lock_scan";
        };*/
/******************************************************************************/
/* CUSTOM */
/******************************************************************************/
    };
};
