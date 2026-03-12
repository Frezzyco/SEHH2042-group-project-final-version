#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstring>
#include <vector>

using namespace std;
const int maxuser = 100;

class User {
public:
    User() {
        totalSpent.resize(maxuser, 0);
    }

    void menu() {
        cout << endl << "*** Main Menu ***" << endl;
        cout << "[1] Load Starting Data\n";
        cout << "[2] Show User Records\n";
        cout << "[3] Edit Users\n";
        cout << "[4] Enter User View\n";
        cout << "[5] Show System Usage Summary\n";
        cout << "[6] Credits and Exit\n";
        cout << "*****************" << endl;
        cout << "Option (1 - 6): ";
    }

    void welcome() {
        cout << "Welcome to AI Service Token Management System! Please enter the number to obtain the corresponding service." << endl;
    }

    void loaddata() {
        string userID[] = { "SkyWalker", "Ocean123", "Forest99", "Valley777", "Desert2022", "River456", "Blaze2023", "Meadow888", "Galaxy", "Storm2024" };
        char type[] = { 'T', 'T', 'T', 'F', 'F', 'F', 'F', 'S', 'S', 'S' };
        int balance[] = { 20, 35, 6, 10, 25, 20, 100, 40, 15, 30 };
        char topup[] = { 'N', 'N', 'Y', 'Y', 'N', 'Y', 'N', 'Y', 'Y', 'N' };
        usercount = 10;

        for (int i = 0; i < usercount; i++) {
            userIDArray[i] = userID[i];
            typeArray[i] = type[i];
            balanceArray[i] = balance[i];
            topupArray[i] = topup[i];
            transactionHistory.push_back("");
        }
    }

    void sortdata() {
        for (int i = 0; i < usercount - 1; i++) {
            int smallest = i;

            for (int j = i + 1; j < usercount; j++) {
                if (userIDArray[j] < userIDArray[smallest]) {
                    smallest = j;
                }
            }

            swap(userIDArray[i], userIDArray[smallest]);
            swap(typeArray[i], typeArray[smallest]);
            swap(balanceArray[i], balanceArray[smallest]);
            swap(topupArray[i], topupArray[smallest]);
            swap(transactionHistory[i], transactionHistory[smallest]);
        }

        displayUsers();
    }

    void displayUsers() {
        cout << left;
        cout << setw(52) << "User ID" << setw(6) << "Type" << setw(15) << "Token Balance" << setw(13) << "Auto Top-up" << endl;

        for (int i = 0; i < usercount; i++) {
            cout << setw(52) << userIDArray[i] << setw(6) << typeArray[i] << setw(15) << balanceArray[i] << setw(13) << topupArray[i] << endl;
        }
    }

    void editUsers() {
        string inputUserID;
        cout << "Enter User ID: ";
        cin >> inputUserID;

        int index = findUser(inputUserID);
        if (index != -1) {
            cout << "User found: " << userIDArray[index] << " | Type: " << typeArray[index]
                << " | Balance: " << balanceArray[index] << " | Auto Top-up: " << topupArray[index] << endl;
            string confirmation;
            cout << "Do you want to delete this user? (Yes/No): ";
            cin >> confirmation;

            if (confirmation == "Yes" || confirmation == "No") {
                for (int i = index; i < usercount - 1; i++) {
                    userIDArray[i] = userIDArray[i + 1];
                    typeArray[i] = typeArray[i + 1];
                    balanceArray[i] = balanceArray[i + 1];
                    topupArray[i] = topupArray[i + 1];
                    transactionHistory[i] = transactionHistory[i + 1];
                }
                usercount--;
                cout << "User deleted successfully." << endl;
            }
            else {
                cout << "Delete operation canceled." << endl;
            }
        }
        else {
            cout << "User not found. Proceeding to add new user." << endl;
            addUser(inputUserID);
        }
    }

    void addUser(string inputUserID) {
        char inputType;
        int inputBalance;
        char inputTopup;
        int attempts = 0;

        while (attempts < 3) {
            cout << "Enter Type (T/F/S): ";
            cin >> inputType;
            if (inputType != 'T' && inputType != 'F' && inputType != 'S') {
                cout << "Wrong field value. Please input T, F, or S." << endl;
                attempts++;
                if (attempts > 2) {
                    cout << "Maximum attempts reached. User not added." << endl;
                    return;
                }
                continue;
            }

            cout << "Enter Token Balance (0-100): ";
            cin >> inputBalance;
            if (inputBalance < 0 || inputBalance > 100) {
                cout << "Invalid balance. Please input a value between 0 and 100." << endl;
                attempts++;
                if (attempts > 2) {
                    cout << "Maximum attempts reached. User not added." << endl;
                    return;
                }
                continue;
            }

            cout << "Enter Auto Top-up (Y/N): ";
            cin >> inputTopup;
            if (inputTopup != 'Y' && inputTopup != 'N') {
                cout << "Wrong field value. Please input Y or N." << endl;
                attempts++;
                if (attempts > 2) {
                    cout << "Maximum attempts reached. User not added." << endl;
                    return;
                }
            }
            else {
                userIDArray[usercount] = inputUserID;
                typeArray[usercount] = inputType;
                balanceArray[usercount] = inputBalance;
                topupArray[usercount] = inputTopup;
                transactionHistory.push_back("");
                usercount++;
                cout << "User added successfully." << endl;
                return;
            }
        }
    }

    int findUser(string userID) {
        for (int i = 0; i < usercount; i++) {
            if (userIDArray[i] == userID) {
                return i;
            }
        }
        return -1;
    }

    void userView() {
        string UserID;
        cout << "Enter User ID for view: ";
        cin >> UserID;

        int index = findUser(UserID);
        if (index == -1) {
            cout << "Error: User ID not found." << endl;
            return;
        }

        int userOption;
        do {
            cout << "Action for User ID: " << UserID << endl;
            cout << "***** User View Menu *****" << endl;
            cout << "[1] Select AI Service\n";
            cout << "[2] Purchase Tokens\n";
            cout << "[3] Edit Profile\n";
            cout << "[4] Show Transaction History\n";
            cout << "[5] Return to Main Menu\n";
            cout << "**************************" << endl;
            cout << "Option (1 - 5): ";
            cin >> userOption;

            switch (userOption) {
            case 1:
                selectAIService(index);
                break;
            case 2:
                purchaseTokens(index);
                break;
            case 3:
                editProfile(index);
                break;
            case 4:
                showTransactionHistory(index);
                break;
            case 5:
                cout << "Returning to Main Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (userOption != 5);
    }

    void selectAIService(int userIndex) {
        int service;
        cout << "Available AI Services:\n";
        cout << "[1] Image Recognition\n";
        cout << "[2] Speech-to-text transcription\n";
        cout << "[3] Predictive Analysis\n";
        cout << "[4] Natural Language Processing (NLP)\n";
        cout << "Choose an AI service (1-4): ";
        cin >> service;

        double cost = 0.0;
        bool validInput = true;
        string serviceName;

        switch (service) {
        case 1:
        {
            double size;
            cout << "Enter size of the image (in MB): ";
            cin >> size;
            if (typeArray[userIndex] == 'T' && size > 3) {
                cout << "Error: Trial accounts cannot use images over 3 MB." << endl;
                return;
            }
            cost = (size <= 3) ? 5 : 8;
            usageSummary[0] += cost;
            serviceName = "Image Recognition";
            break;
        }
        case 2:
        {
            double length;
            cout << "Enter length of speech audio file (in minutes): ";
            cin >> length;
            if (length <= 3) {
                cost = 2;
            }
            else {
                cost = 2 + (length - 3) * 3;
            }
            usageSummary[1] += cost;
            serviceName = "Speech-to-text";
            break;
        }
        case 3:
        {
            int task;
            cout << "Enter number of prediction tasks: ";
            cin >> task;
            cost = task * 10;
            usageSummary[2] += cost;
            serviceName = "Predictive Analysis";
            break;
        }
        case 4:
        {
            int characters;
            cout << "Enter number of characters in the text: ";
            cin >> characters;
            if (typeArray[userIndex] == 'T' && characters > 2500) {
                cout << "Error: Trial accounts can only process up to 2500 characters." << endl;
                return;
            }
            cost = (characters / 500) + (characters % 500 != 0);
            usageSummary[3] += cost;
            serviceName = "Natural Language Processing (NLP)";
            break;
        }
        default:
            cout << "Invalid AI service option." << endl;
            validInput = false;
            break;
        }

        if (validInput) {
            double balance = balanceArray[userIndex];
            char AT = topupArray[userIndex];

            if (balance >= cost) {
                balanceArray[userIndex] -= cost;
                transactionHistory[userIndex] += "Used AI Service: " + serviceName + " | Tokens Spent: " + to_string(cost) + "\n"; // Record transaction
                cout << "AI service authorized. Cost: " << cost << " tokens." << endl;
            }
            else if (AT == 'Y') {
                double requiredTokens = cost - balance;
                double extraCost = 0;

                if (requiredTokens > 0) {
                    extraCost = ((int)((requiredTokens + 19) / 20)) * 20;
                    balanceArray[userIndex] += extraCost / 2;
                    totalSpent[userIndex] += extraCost;
                    cout << "Auto Top-up activated. Extra cost: $" << extraCost << endl;
                }

                balanceArray[userIndex] -= cost;
                transactionHistory[userIndex] += "Used AI Service with Auto Top-up: " + serviceName + " | Tokens Spent: " + to_string(cost) + "\n"; 
                cout << "AI service authorized with auto top-up. Final balance: " << balanceArray[userIndex] << " tokens." << endl;
            }
            else {
                cout << "Error: Insufficient balance and auto top-up is disabled. Service not authorized." << endl;
                return;
            }
        }
        cout << "Your token balance is now: " << balanceArray[userIndex] << " tokens." << endl;
    }

    void purchaseTokens(int userIndex) {
        int amount;
        cout << "Enter amount of money to spend for purchasing tokens (must be even): ";
        cin >> amount;

        if (amount % 2 != 0) {
            cout << "Invalid input. Amount must be an even number." << endl;
            return;
        }

        int tokensPurchased = amount / 2;
        balanceArray[userIndex] += tokensPurchased;
        totalSpent[userIndex] += amount;
        transactionHistory[userIndex] += "Purchased Tokens: " + to_string(tokensPurchased) + " for $" + to_string(amount) + "\n"; // Record transaction
        cout << "Purchased " << tokensPurchased << " tokens. New balance: " << balanceArray[userIndex] << " tokens." << endl;
    }

    void editProfile(int userIndex) {
        char choice;
        int retries = 0;
        bool validInput = false;

        while (!validInput && retries < 3) {
            cout << "Choose which field to update:\n";
            cout << "[1] Account Type\n";
            cout << "[2] Auto Top-up\n";
            cout << "[3] Cancel\n";
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            switch (choice) {
            case '1': {
                char newT;
                cout << "Enter new Account Type (T/F/S): ";
                cin >> newT;

                if (newT == 'T' || newT == 'F' || newT == 'S') {
                    typeArray[userIndex] = newT;
                    cout << "Account Type updated successfully.\n";
                    validInput = true;
                }
                else {
                    cout << "Invalid Account Type. Please enter T, F, or S.\n";
                    retries++;
                }
                break;
            }

            case '2': {
                char newAT;
                cout << "Enable Auto Top-up? (Y/N): ";
                cin >> newAT;

                if (newAT == 'Y' || newAT == 'N') {
                    topupArray[userIndex] = newAT;
                    cout << "Auto Top-up setting updated successfully.\n";
                    validInput = true;
                }
                else {
                    cout << "Invalid input. Please enter Y or N.\n";
                    retries++;
                }
                break;
            }

            case '3':
                cout << "Profile update canceled.\n";
                return;

            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
                retries++;
                break;
            }

            if (retries >= 3) {
                cout << "Too many invalid attempts. Returning to User View Menu.\n";
            }
        }
    }

    void showTransactionHistory(int userIndex) {
        cout << "Transaction History for User ID: " << userIDArray[userIndex] << endl;

        if (transactionHistory[userIndex].empty()) {
            cout << "No transactions made." << endl;
        }
        else {
            cout << transactionHistory[userIndex] << endl;
        }

        double originalBalance = balanceArray[userIndex] + totalSpent[userIndex];
        double finalBalance = balanceArray[userIndex];
        double changeInBalance = finalBalance - originalBalance;
        double totalSpentAmount = totalSpent[userIndex];

        cout << "\n--- Transaction Summary ---" << endl;
        cout << "Original Token Balance: " << originalBalance << endl;
        cout << "Final Token Balance: " << finalBalance << endl;
        cout << "Change in Token Balance: " << changeInBalance << endl;
        cout << "Total Amount Paid for Tokens (including auto top-up): $" << totalSpentAmount << endl;
        cout << "---------------------------" << endl;
    }

    void systemUsageSummary() {
        double tokensum = 0;
        double moneysum = 0;
        cout << "\n--- System Usage Summary ---" << endl;
        cout << "Number of tokens spent on each of the AI service by all users" << endl;
        cout << left << setw(35) << "Image Recognition: " << right << setw(10) << usageSummary[0] << " tokens" << endl;
        cout << left << setw(35) << "Speech-to-text transcription: " << right << setw(10) << usageSummary[1] << " tokens" << endl;
        cout << left << setw(35) << "Predictive Analysis: " << right << setw(10) << usageSummary[2] << " tokens" << endl;
        cout << left << setw(35) << "Natural Language Processing (NLP): " << right << setw(10) << usageSummary[3] << " tokens" << endl;
        for (int i = 0; i < 4; i++)
            tokensum += usageSummary[i];
        cout << endl << "Total number of tokens spent on all AI services by all users: " << tokensum << " tokens" << endl;
        for (int i = 0; i < usercount; i++)
            moneysum += totalSpent[i];
        cout << endl << "Total Amount Paid for Tokens (including auto top-up) by all users: $" << moneysum << endl;
    }

    void creditAndExit() {
        string userInput;
        do {
            cout << "Do you want to exit?" << endl;
            cin >> userInput;
            if (userInput == "y" || userInput == "Y") {
                cout << "Are you sure you want to exit?" << endl;
                cin >> userInput;
                if (userInput == "y" || userInput == "Y") {
                    cout << left << setw(25) << "Member Name" << setw(20) << "Student Number" << setw(15) << "Tutorial Group" << endl;
                    cout << "===============================================================" << endl;
                    cout << setw(25) << "CHEUNG Ching Ching" << setw(20) << "23079982A" << setw(15) << "105A" << endl;
                    cout << setw(25) << "CHIU Cheuk Man" << setw(20) << "23001320A" << setw(15) << "105A" << endl;
                    cout << setw(25) << "FOK Ka Fai" << setw(20) << "23008320A" << setw(15) << "105B" << endl;
                    cout << setw(25) << "KONG Pak Lim" << setw(20) << "23051186A" << setw(15) << "105A" << endl;
                    cout << setw(25) << "LAU Wai Tat Winter" << setw(20) << "23039702A" << setw(15) << "105B" << endl;
                    cout << setw(25) << "O Ching Yin" << setw(20) << "23078672A" << setw(15) << "105A" << endl;
                    cout << setw(25) << "Credits and Exit. Thank you!" << endl;
                    exit(0);
                    break;
                }
            }

            else if (userInput == "n" || userInput == "N") {
                cout << "Returning to Main Menu" << endl;
                break;
            }
            else
                cout << "Invalid input. Please enter y/n/Y/N." << endl;

        } while (userInput != "n" || userInput != "N" || userInput != "y" || userInput != "Y");
    }

private:
    string userIDArray[maxuser];
    char typeArray[maxuser];
    int balanceArray[maxuser];
    char topupArray[maxuser];
    vector<string> transactionHistory;
    vector<double> totalSpent;
    int usercount = 0;
    double usageSummary[4];
};

int main() {
    int option;
    bool load = false;
    User mainmenu;
    mainmenu.welcome();


    do {
        mainmenu.menu();
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        cout << endl;

        switch (option) {
        case 1:
            load = true;
            mainmenu.loaddata();
            cout << "Starting data loaded successfully." << endl;
            break;

        case 2:
            if (load) {
                mainmenu.sortdata();
            }
            else {
                cout << "Please load the starting data first." << endl << endl;
            }
            break;

        case 3:
            if (load) {
                mainmenu.editUsers();
            }
            else {
                cout << "Please load the starting data first." << endl << endl;
            }
            break;

        case 4:
            if (load) {
                mainmenu.userView();
            }
            else {
                cout << "Please load the starting data first." << endl << endl;
            }
            break;

        case 5:
            if (load) {
                mainmenu.systemUsageSummary();
            }
            else {
                cout << "Please load the starting data first." << endl << endl;
            }
            break;

        case 6:
            mainmenu.creditAndExit();
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (true);

    return 0;
}