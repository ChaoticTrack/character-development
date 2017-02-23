#include <iostream>
#include <locale> // std::locale, std::tolower
#include <cstdlib> // system()

using namespace std;

/*
int checkPoints(inputStrength)
{
    if ()
}
*/

int main()
{
    int selfStrength,
        selfHealth,
        selfLuck;
    string selfName,
        endAcceptStats;
    bool selfTotalExceed = 0,
        characterCreation = 1; // main program loop
    locale loc;


    while (characterCreation) {
        system("cls");

        selfStrength = 0,
            selfHealth = 0,
            selfLuck = 0;
        selfName = "";
        selfTotalExceed = 0,
            characterCreation = 1;
        endAcceptStats = "";

        cout << "*****************************************" << endl;
        cout << "\tWelcome to Yertle's Quest" << endl;
        cout << "*****************************************" << endl;

        cout << "What is your hero's name?" << endl;

        for (;;) {
            cout << ">> ";
            getline(cin, selfName);

            if (selfName.length() >= 21 || selfName.length() <= 2) {
                cout << "Name must be between 3 and 20 characters." << endl;
            } else {
                break;
            }
        }

            // tutorial text
        cout << "\nYour character has 3 main stats. Strength, Health, and Luck. \n"
                "You may choose the initial value of each stat between 1 and 10." << endl;


        /*
         * ##### START of stat input #####
        */

        // start of STRENGTH stat assignment
            // will skip input if total is already at 15
        if ( (selfStrength + selfHealth + selfLuck) < 15 || selfTotalExceed != 1) {
            cout << "\nYou have " << (15 - (selfStrength + selfHealth + selfLuck)) << " points left to spend." << endl;
            cout << "Enter Strength (1-10):" << endl;

            for (;;) {
                cout << ">> ";
                cin >> selfStrength;

                    // check if input is valid for data type AND between 1-10
                if (!cin.good() || selfStrength < 1 || selfStrength > 10) {
                    cout << "That is not a valid number. You must choose a value between 1 and 10." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }
                // if the total is greater than 15 AFTER the check,
                // exceed is true and default stats will be applied
            if ((selfStrength + selfHealth + selfLuck) > 15) {
                selfTotalExceed = 1;
            }
        }
        //  end of STRENGTH stat assignment

        // start of HEALTH stat assignment
            // will skip input if total is already at 15
        if ( (selfStrength + selfHealth + selfLuck) < 15 || selfTotalExceed != 1) {
            cout << "\nYou have " << (15 - (selfStrength + selfHealth + selfLuck)) << " points left to spend." << endl;
            cout << "Enter Health (1-10):" << endl;

            for (;;) {
                cout << ">> ";
                cin >> selfHealth;

                    // check if input is valid for data type AND between 1-10
                if (!cin.good() || selfHealth < 1 || selfHealth > 10) {
                    cout << "That is not a valid number. You must choose a value between 1 and 10." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }
                // if the total is greater than 15 AFTER the check,
                // exceed is true and default stats will be applied
            if ((selfStrength + selfHealth + selfLuck) > 15) {
                selfTotalExceed = 1;
            }
        }
        //  end of HEALTH stat assignment

        // start of LUCK stat assignment
            // will skip input if total is already at 15
        if ( (selfStrength + selfHealth + selfLuck) < 15 || selfTotalExceed != 1) {
            cout << "\nYou have " << (15 - (selfStrength + selfHealth + selfLuck)) << " points left to spend." << endl;
            cout << "Enter Luck (1-10):" << endl;

            for (;;) {
                cout << ">> ";
                cin >> selfLuck;

                    // check if input is valid for data type AND between 1-10
                if (!cin.good() || selfLuck < 1 || selfLuck > 10) {
                    cout << "That is not a valid number. You must choose a value between 1 and 10." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }
                // if the total is greater than 15 AFTER the check,
                // exceed is true and default stats will be applied
            if ((selfStrength + selfHealth + selfLuck) > 15) {
                selfTotalExceed = 1;
            }
        }
        //  end of LUCK stat assignment

        /*
         * ##### END of stat input #####
        */

        if ( (selfStrength + selfHealth + selfLuck) <= 15 && selfTotalExceed == 0) {

            if ( (selfStrength + selfHealth + selfLuck) < 15) {
                cout << "\nNOTE: You still have " << (15 - (selfStrength + selfHealth + selfLuck)) << " unused points.";
            }

            cout << "\n\tCharacter Name: " << selfName << " ============================" << endl;
            cout << "\n\t\tStrength:  " << selfStrength << endl;
            cout << "\t\tHealth:    " << selfHealth << endl;
            cout << "\t\tLuck:      " << selfLuck << endl;

            cout << "\n\tTo accept these stats enter       Y" << endl;
            cout << "\tTo reassign stats enter           N" << endl;
            cout << ">> ";

            for (;;) {
                cin >> endAcceptStats;

                    // converts input to lowercase
                for (string::size_type i=0; i < endAcceptStats.length(); i++)
                    endAcceptStats[i] = tolower(endAcceptStats[i],loc);

                if (endAcceptStats == "y" || endAcceptStats == "n") {
                    if (endAcceptStats == "y") {
                        characterCreation = 0;
                    } else {
                        characterCreation = 1;
                        cin.clear();
                        cin.ignore(1);
                    }
                    break;
                } else {
                    cout << "\nThat is not a valid option. Y or N?" << endl;
                }
            }
        } else {
            selfStrength = 5,
                selfHealth = 5,
                selfLuck = 5;

            cout << "\nYou have given your character too many points! Default values have been assigned: " << endl;
            cout << "\tCharacter Name: " << selfName << " ============================" << endl;
            cout << "\n\t\tStrength:  " << selfStrength << endl;
            cout << "\t\tHealth:    " << selfHealth << endl;
            cout << "\t\tLuck:      " << selfLuck << endl;

            cout << "\n\tTo accept default stats enter     Y" << endl;
            cout << "\tTo reassign stats enter           N" << endl;
            cout << ">> ";

            for (;;) {
                cin >> endAcceptStats;

                    // converts input to lowercase
                for (string::size_type i=0; i < endAcceptStats.length(); i++)
                    endAcceptStats[i] = tolower(endAcceptStats[i],loc);

                if (endAcceptStats == "y" || endAcceptStats == "n") {
                    if (endAcceptStats == "y") {
                        characterCreation = 0;
                    } else {
                        characterCreation = 1;
                        cin.clear();
                        cin.ignore(1);
                    }
                    break;
                } else {
                    cout << "\nThat is not a valid option. Y or N?" << endl;
                }
            }

        }
    // end of character creation loop
    }

    for (string::size_type i=0; i < selfName.length(); i++)
        selfName[i] = toupper(selfName[i],loc);

    system("Color E");
    cout << "\n\n"
            << selfName << ": I didn't think it would end this way.\n"
            "GANDALF: End? No, the journey doesn't end here. Death is just another \n"
                "  path, one that we all must take. The grey rain-curtain of this world \n"
                "  rolls back, and all turns to silver glass, and then you see it. \n"
            << selfName << ": What? Gandalf? See what? \n"
            "GANDALF: White shores, and beyond, a far green country under a swift sunrise. \n"
            << selfName << ": Well, that isn't so bad. \n"
            "GANDALF: No. No, it isn't. \n"
            << endl;
            cout << "## Peyton Seigo. February 22, 2017. ##" << endl;

    return 0;
}
