//
//  main.cpp
//  p5-4
//
//  Created by Jakob Hammond on 9/21/23.
//

#include <iostream>
using namespace std;

int main(void){
    
    int cardNumber;
    int firstSum = 0;
    int secondSum = 0;
    int finalSum;
    
    cout << "Please enter 8-digit card number: ";
    cin >> cardNumber;
    
    
    int currentDigit;
    int partialCard = cardNumber;
    
    //take sum of every other digit (starting from rightmost digit)
    do{
        currentDigit = partialCard % 10; //takes rightmost digit
        partialCard = partialCard / 100; //shifts number over 2
        firstSum += currentDigit; //adds digits together
    }while(partialCard > 0);
   
    
    //double each digit not included previously, add those digits together
    partialCard = cardNumber; //sets partial card number back to full card number
    int subDigit1;
    int subDigit2;
    do{
        partialCard /= 10;
        currentDigit = partialCard % 10;
        currentDigit *= 2;
        if(currentDigit >= 10){
            subDigit1 = currentDigit % 10;
            subDigit2 = currentDigit / 10;
            secondSum = secondSum + subDigit1 + subDigit2;
        }
        else{
            secondSum += currentDigit;
        }
        partialCard /= 10;
    
    }while(partialCard > 0);
    
    
    finalSum = firstSum + secondSum;
    
    if(finalSum % 10 == 0){
        cout << "Card is valid.\n";
    }
    else{
        cout << "Card is not valid.\n";
    }
}
