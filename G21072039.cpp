//Student Name - Vishwa Ampavila
//Student UCL ID number - 3000608
//Student G number - G21072039

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//I placed all the functions below int main() and called them again above int main()
//This was done so that all the functions can work properly
void menuScreen(float currentCredit, int& menuOpt);

bool hasTwoDecimalPlaces(float inputedValue);

void addCreditScreen(float& currentCredit, float& credit);

void orderBurgerScreen(float& currentCredit, int& burgerSizeOpt, int& menuOpt, bool& exitAtSize,
int& toppingOpt, string burgerSizeName[], float burgerSizePriceArray[],
string toppingNames[], char& moreToppingChoice, float& orderPrice, float toppingPriceArray[]
, char& insuffCreditChoice, float& credit, char& anothBurgerChoice, bool& exit, vector<string>& recentOrderVector, int& orderNumber, int& numOfToppings);

void anotherBurgerFunction(float& currentCredit, int& burgerSizeOpt, int& menuOpt, bool& exitAtSize,
int& toppingOpt, string burgerSizeName[], float burgerSizePriceArray[],
string toppingNames[], char& moreToppingChoice, float& orderPrice, float toppingPriceArray[]
, char& insuffCreditChoice, float& credit, char& anothBurgerChoice, bool& exit, vector<string>& recentOrderVector, int& orderNumber, int& numOfToppings);

void recentOrderScreen(vector<string>& recentOrderVector);

int main()
{
    // Variable declarations and initializations
    int numOfToppings = 0;
    int orderNumber = 1;
    int menuOpt = 0;
    int burgerSizeOpt = 0;
    int toppingOpt = 0;
    bool exit = false;
    bool exitAtSize = false;
    char insuffCreditChoice;
    char moreToppingChoice;
    char anothBurgerChoice;
    float credit = 0.00;
    float currentCredit = 0.00;
    float burgerSizePriceArray[] = { 0.00, 3.00, 5.50, 7.25 };
    float toppingPriceArray[] = { 0.00, 0.80, 0.50, 1.00, 0.30, 0.30, 1.50 };
    float orderPrice = 0.00;
    string burgerSizeName[] = { "blank", "small", "medium", "large" };
    string toppingNames[] = { "blank", "Cheese", "Salad", "Bacon", "Ketchup", "Mayo", "Extra Burger" };
    vector<string> recentOrderVector;

    do
    {
        cout << fixed << setprecision(2);
        menuScreen(currentCredit, menuOpt);

        if (menuOpt == 1)
        {
            addCreditScreen(currentCredit, credit);
        }
        else if (menuOpt == 2)
        {
            do
            {
                orderBurgerScreen(currentCredit, burgerSizeOpt, menuOpt, exitAtSize, toppingOpt,
                burgerSizeName, burgerSizePriceArray, toppingNames, moreToppingChoice,
                orderPrice, toppingPriceArray, insuffCreditChoice, credit, anothBurgerChoice, exit, recentOrderVector, orderNumber, numOfToppings);
            } 
            while (anothBurgerChoice == 'Y' || anothBurgerChoice == 'y');
        }
        else if (menuOpt == 3)
        {
            recentOrderScreen(recentOrderVector);
        }
        else if (menuOpt == 0)
        {
            exit = true;
        }

    } while (!exit);

    return 0;
}

// Function to display main menu screen
void menuScreen(float currentCredit, int& menuOpt)
{
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "UCLan BURGER" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    cout << "MAIN MENU" << endl;
    cout << "1. Add Credits (Current Balance: " << currentCredit << " credits)" << endl;
    cout << "2. Order Burger" << endl;
    cout << "3. Recent Order" << endl;
    cout << "0. Exit" << endl;

    //validation check
    bool validInput = false;
    do
    {
        cout << "Please enter a number: ";
        cin >> menuOpt;

        if ((cin.fail() || menuOpt < 0 || menuOpt > 3))
        {
            cout << "Invalid input. Please enter a number from 0 and 3." << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            if (cin.peek() != '\n')
            {
                cout << "Invalid input. Please enter a number from 0 and 3." << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                validInput = true;
            }
        }
        
    } while (!validInput);

}

// Function to check if the inputed value has two decimal places or not
bool hasTwoDecimalPlaces(float inputedValue)
{

    float decimalSectOfNum = modf(inputedValue * 100, nullptr);
    return decimalSectOfNum < 0.01;
}

//Function to add credits
void addCreditScreen(float& currentCredit, float& credit)
{
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "ADD CREDITS" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    //validation check
    bool validInput = false;
    do
    {
        cout << "How much credit do you want to add: ";
        cin >> credit;

        if (cin.fail() || credit < 0 || hasTwoDecimalPlaces(credit) == false)
        {
            cout << "Invalid input. Please enter a valid credit with 2 or less decimal places." << endl;
            cin.clear(); 
            cin.ignore();
        }
        else
        {
            if (cin.peek() != '\n')
            {
                cout << "Invalid input. Please enter a valid credit with 2 or less decimal places." << endl;
                cin.clear(); 
                cin.ignore(); 
            }
            else
            {
                validInput = true;
            }
        }
        
    } while (!validInput);

    currentCredit += credit;
}

// Function to order a burger and select its size and toppings
void orderBurgerScreen(float& currentCredit, int& burgerSizeOpt, int& menuOpt, bool& exitAtSize,
int& toppingOpt, string burgerSizeName[], float burgerSizePriceArray[],
string toppingNames[], char& moreToppingChoice, float& orderPrice, float toppingPriceArray[]
, char& insuffCreditChoice, float& credit, char& anothBurgerChoice, bool& exit, vector<string>& recentOrderVector, int& orderNumber, int& numOfToppings)
{

    recentOrderVector.push_back("Order Number " + to_string(orderNumber));

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "ORDER BURGER - Select Size [Current Balance: " << currentCredit << " credits]" << endl;
    cout << endl;
    cout << "Please choose from the following options:" << endl;
    cout << "1. Small\t[3.00 credits]" << endl;
    cout << "2. Medium\t[5.50 credits]" << endl;
    cout << "3. Large\t[7.25 credits]" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    //validation check
    bool validBurgerSizeInput = false;
    do
    {
        cout << "Please enter a number: ";
        cin >> burgerSizeOpt;

        if ((cin.fail() || burgerSizeOpt < 0 || burgerSizeOpt > 3))
        {
            cout << "Invalid input. Please enter a number from 0 and 3." << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            if (cin.peek() != '\n')
            {
                cout << "Invalid input. Please enter a number from 0 and 3." << endl;
                cin.clear();
                cin.ignore();
            }
            else
            {
                validBurgerSizeInput = true;
            }
        }
        
    } while (!validBurgerSizeInput);


    if (burgerSizeOpt == 0)
    {
        recentOrderVector.pop_back();
        exitAtSize = false;
        menuOpt = 0;
        return;
    }
    else if (burgerSizeOpt >= 1 && burgerSizeOpt <= 3)
    {
        cout << "You have selected a " << burgerSizeName[burgerSizeOpt] << " burger." << endl;
        orderPrice += burgerSizePriceArray[burgerSizeOpt];
    }

    recentOrderVector.push_back("Burger Size: " + burgerSizeName[burgerSizeOpt]);

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    if (!exitAtSize)
    {
        do
        {
            cout << "Please choose from the following toppings:" << endl;
            cout << "1. Cheese\t[0.80 credits]" << endl;
            cout << "2. Salad\t[0.50 credits]" << endl;
            cout << "3. Bacon\t[1.00 credits]" << endl;
            cout << "4. Ketchup\t[0.30 credits]" << endl;
            cout << "5. Mayo\t\t[0.30 credits]" << endl;
            cout << "6. Extra Burger\t[1.50 credits]" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            //validation check
            bool validToppingInput = false;
            do
            {
                cout << "Please enter a number: ";
                cin >> toppingOpt;

                if ((cin.fail() || toppingOpt < 0 || toppingOpt > 6))
                {
                    cout << "Invalid input. Please enter a number from 0 and 6." << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    if (cin.peek() != '\n')
                    {
                        cout << "Invalid input. Please enter a number from 0 and 6." << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        validToppingInput = true;
                    }
                }
                
            } while (!validToppingInput);


            if (toppingOpt == 0)
            {
                recentOrderVector.pop_back();
                recentOrderVector.pop_back();

                while(numOfToppings > 0)
                {
                    recentOrderVector.pop_back();
                    numOfToppings -= 1;
                }

                menuOpt = 0;
                exitAtSize = false;
                burgerSizeOpt = 0;
                toppingOpt = 0;
                orderPrice = 0;
                moreToppingChoice = 'N';
                numOfToppings = 0;
                return;
            }
            else if (toppingOpt >= 1 && toppingOpt <= 6)
            {
                orderPrice += toppingPriceArray[toppingOpt];
                cout << "You have added " << toppingNames[toppingOpt] << " to your burger. Your current price is: " << orderPrice << " credits." << endl;
            }

            //add toppings to display on the recent order screen
            recentOrderVector.push_back("Topping: " +toppingNames[toppingOpt]);
            //increases the count to keep track of how many toppings added
            numOfToppings += 1;

            cout << "Current Balance: " << currentCredit << " credits" << endl;
            cout << "Current Price: " << orderPrice << " credits" << endl;
            cout << "Would you like to add additional toppings?" << endl;
            
            //validation check
            bool validmoreToppingChoiceInput = false;
            do 
            {
                cout << "Please input 'Y' for yes and 'N' for no: ";
                cin >> moreToppingChoice;
                cout << endl;

                if (cin.fail() || (moreToppingChoice != 'Y' && moreToppingChoice != 'y' && moreToppingChoice != 'N' && moreToppingChoice != 'n'))
                {
                    cout << "Invalid input. Please enter (Y/N)." << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validmoreToppingChoiceInput = true;
                }

            } while (!validmoreToppingChoiceInput);


        } while (moreToppingChoice == 'Y' || moreToppingChoice == 'y');

        if (currentCredit < orderPrice)
        {
            cout << "You have insufficient credits available. You require " << orderPrice - currentCredit << " credits." << endl;
            cout << "Would you like to add more credits?" << endl;

            //validation check
            bool validinsuffCreditChoiceInput = false;
            do 
            {
                cout << "Please enter 'Y' for yes and 'N' for no: ";
                cin >> insuffCreditChoice;
                cout << endl;

                if (cin.fail() || (insuffCreditChoice != 'Y' && insuffCreditChoice != 'y' && insuffCreditChoice != 'N' && insuffCreditChoice != 'n'))
                {
                    cout << "Invalid input. Please enter (Y/N)." << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validinsuffCreditChoiceInput = true;
                }

            } while (!validinsuffCreditChoiceInput);

            if (insuffCreditChoice == 'Y' || insuffCreditChoice == 'y')
            {
                do
                {
                    addCreditScreen(currentCredit, credit);

                    if (currentCredit <  orderPrice)
                    {
                        cout << "You have insufficient credits available. You require " << orderPrice - currentCredit << " credits." << endl;
                    }
                }
                while (currentCredit < orderPrice);
            }

            if (insuffCreditChoice == 'N' || insuffCreditChoice == 'n')
            {
                recentOrderVector.pop_back();
                recentOrderVector.pop_back();

                while(numOfToppings > 0)
                {
                    recentOrderVector.pop_back();
                    numOfToppings -= 1;
                }
                menuOpt = 0;
                exitAtSize = false;
                burgerSizeOpt = 0;
                toppingOpt = 0;
                orderPrice = 0;
                moreToppingChoice = 'N';
                numOfToppings = 0;
                return;
            }
        }

        if (currentCredit >= orderPrice)
        {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "Available Balance:\t" << currentCredit << endl;
            cout << "Burger Price:\t\t" << orderPrice << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            currentCredit -= orderPrice;

            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "Your new Balance = " << currentCredit << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            //increases the order number represented in the recent order screen
            orderNumber += 1;

            recentOrderVector.push_back("Order Price: " + to_string(orderPrice) + " credits");
            recentOrderVector.push_back("\n");

            cout << "Would you like to order another burger?" << endl;

            //validation check
            bool validanothBurgerChoiceInput = false;
            do 
            {
                
                cout << "Please input 'Y' for yes and 'N' for no: ";
                cin >> anothBurgerChoice;
                cout << endl;

                if (cin.fail() || (anothBurgerChoice != 'Y' && anothBurgerChoice != 'y' && anothBurgerChoice != 'N' && anothBurgerChoice != 'n'))
                {
                    cout << "Invalid input. Please enter (Y/N)." << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validanothBurgerChoiceInput = true;
                }

            } while (!validanothBurgerChoiceInput);


            if (anothBurgerChoice == 'N' || anothBurgerChoice == 'n')
            {
                cout << "Thank You, Goodbye!" << endl;
                exitAtSize = false;
                burgerSizeOpt = 0;
                toppingOpt = 0;
                orderPrice = 0;
                moreToppingChoice = 'N';
                menuOpt = 0;
                numOfToppings = 0;
            }
            else if (anothBurgerChoice == 'Y' || anothBurgerChoice == 'y')
            {
                anotherBurgerFunction(currentCredit, burgerSizeOpt, menuOpt, exitAtSize, toppingOpt,
                burgerSizeName, burgerSizePriceArray, toppingNames, moreToppingChoice,
                orderPrice, toppingPriceArray, insuffCreditChoice, credit, anothBurgerChoice, exit, recentOrderVector, orderNumber, numOfToppings);
            }
        }
    }
}

// Function to allow the user to order another burger
void anotherBurgerFunction(float& currentCredit, int& burgerSizeOpt, int& menuOpt, bool& exitAtSize,
int& toppingOpt, string burgerSizeName[], float burgerSizePriceArray[],
string toppingNames[], char& moreToppingChoice, float& orderPrice, float toppingPriceArray[]
, char& insuffCreditChoice, float& credit, char& anothBurgerChoice, bool& exit, vector<string>& recentOrderVector, int& orderNumber, int& numOfToppings)
{
    //Reset variables in order to order another burger
    exitAtSize = false;
    burgerSizeOpt = 0;
    toppingOpt = 0;
    orderPrice = 0;
    moreToppingChoice = 'N';
    anothBurgerChoice = 'N';
    numOfToppings = 0;

    orderBurgerScreen(currentCredit, burgerSizeOpt, menuOpt, exitAtSize, toppingOpt,
    burgerSizeName, burgerSizePriceArray, toppingNames, moreToppingChoice,
    orderPrice, toppingPriceArray, insuffCreditChoice, credit, anothBurgerChoice, exit, recentOrderVector, orderNumber, numOfToppings);
}

// Function to display the Recent Order screen
void recentOrderScreen(vector<string>& recentOrderVector)
{
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Recent Orders:" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    for (int i = 0; i < recentOrderVector.size(); i++)
    {
        cout << recentOrderVector[i] << endl;
    }
}