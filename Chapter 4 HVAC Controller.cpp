#include <iostream>
using namespace std;

/*HVAC Controller by Elijah Stultz
CISP 360, September 18, 2019
*/


int main()
{
    enum controllerStatus {HVAC_OFF, FURNACE_ON, AC_ON};
    enum damperStatus {DAMPER_OPEN, DAMPER_CLOSED};

    int zoneOneTemp = 75, zoneTwoTemp = 80,
        zoneOneTherm = 75, zoneTwoTherm = 80,
        menuSelection, numTurns;

    bool waitTurn, zoneOneEqual = false, zoneTwoEqual = false, bothEqual = false,
                   zoneOneNeedsToCool = false, zoneTwoNeedsToCool = false,
                   zoneOneNeedsToHeat = false, zoneTwoNeedsToHeat = false;

    controllerStatus HVACStatus = HVAC_OFF;
    damperStatus zoneOneDamper = DAMPER_CLOSED, zoneTwoDamper = DAMPER_CLOSED;

    while (menuSelection != 0)
    {
        cout << "Status: " << endl;

        switch (HVACStatus)
        {
            case 0:
                cout << "HVAC OFF" << endl;
                break;
            case 1:
                cout << "Furnace ON" << endl;
                break;
            case 2:
                cout << "AC ON" << endl;
                break;
            default:
                cout << "Unknown" << endl;
        }

       
        cout << "Zone 1 thermostat: " <<  zoneOneTherm << endl << "Zone 2 thermostat: " << zoneTwoTherm << endl;

        if (zoneOneDamper == DAMPER_OPEN)
            cout << "Zone 1 damper is OPEN" << endl;
        else
            cout << "Zone 1 damper is CLOSED" << endl;

        if (zoneTwoDamper == DAMPER_OPEN)
            cout << "Zone 2 damper is OPEN" << endl;
        else
            cout << "Zone 2 damper is CLOSED" << endl;            

        cout << "Zone 1 temperature: " << zoneOneTemp << endl << "Zone 2 temperature: " << zoneTwoTemp << endl;

        cout << "Enter a menu choice: \n" << "0)  Quit\n" << "1)  Set thermostats\n" << "2)  Wait 1 turn\n" << "3)  Wait 10 turns\n";

        cin >> menuSelection;

        switch (menuSelection)
        {
            case 0:
                return 0;
            case 1:
                cout << "Set the thermostat for zone 1: ";
                cin >> zoneOneTherm;
                cout << "Set the thermostat for zone 2: ";
                cin >> zoneTwoTherm;
                break;
            case 2:
                waitTurn = true;
                numTurns = 1;
                break;
            case 3:
                waitTurn = true;
                numTurns = 10;
                break;
            default:
                cout << "Error";
                return 1;

        }

        zoneOneNeedsToCool = (zoneOneTherm < zoneOneTemp) ? true : false;
        zoneTwoNeedsToCool = (zoneTwoTherm < zoneTwoTemp) ? true : false;
        zoneOneNeedsToHeat = (zoneOneTherm > zoneOneTemp) ? true : false;
        zoneTwoNeedsToHeat = (zoneTwoTherm > zoneTwoTemp) ? true : false;

        if (zoneOneNeedsToCool)
        {
            HVACStatus = AC_ON;
            zoneOneDamper = DAMPER_OPEN;
        }
        else if (zoneOneNeedsToHeat)
        {
            HVACStatus = FURNACE_ON;
            zoneOneDamper = DAMPER_OPEN;
        }

        if (zoneTwoNeedsToCool)
        {
            HVACStatus = AC_ON;
            zoneTwoDamper = DAMPER_OPEN;
        }
        else if (zoneTwoNeedsToHeat)
        {
            HVACStatus = FURNACE_ON;
            zoneTwoDamper = DAMPER_OPEN;
        }

        if (waitTurn)
        {

            for (int i = 0; i < numTurns; ++i)
            {
                if (zoneOneNeedsToCool)
                {
                    zoneOneTemp--;
                    zoneOneEqual = false;

                }
                else if (zoneOneNeedsToHeat)
                {
                    zoneOneTemp++;
                    zoneOneEqual = false;
                }

                if (zoneTwoNeedsToCool)
                {
                    zoneTwoTemp--;
                    zoneTwoEqual = false;
                }
                else if (zoneTwoNeedsToHeat)
                {
                    zoneTwoTemp++;
                    zoneTwoEqual = false;
                }
                
                zoneOneEqual = (zoneOneTherm == zoneOneTemp) ? true : false;
                zoneTwoEqual = (zoneTwoTherm == zoneTwoTemp) ? true : false;
                bothEqual = (zoneOneEqual && zoneTwoEqual) ? true : false;

                if (zoneOneEqual)
                {
                    zoneOneDamper = DAMPER_CLOSED;
                    zoneOneNeedsToCool = false;
                    zoneOneNeedsToHeat = false;
                } 

                if (zoneTwoEqual)
                {
                    zoneTwoDamper = DAMPER_CLOSED;
                    zoneTwoNeedsToCool = false;
                    zoneTwoNeedsToHeat = false;
                }
                    
                if (bothEqual)
                    HVACStatus = HVAC_OFF;
            }
        }
    }
 return 0;
}