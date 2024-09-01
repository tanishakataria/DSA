#include <iostream>
#include <string>

using namespace std;

// Function to identify and display pairs with at least one common friend
void findCommonFriends(bool friendshipMatrix[5][5]) {
    // Iterate through each unique pair of people
    for(int personA = 0; personA < 5; personA++) {
        for(int personB = personA + 1; personB < 5; personB++) {
            // Check for common friends between personA and personB
            for(int friendIndex = 0; friendIndex < 5; friendIndex++) {
                // A common friend exists if both personA and personB are friends with friendIndex
                if(friendshipMatrix[personA][friendIndex] && friendshipMatrix[personB][friendIndex]) {
                    cout << "\n" << personA << " and " << personB << " have a common friend " << friendIndex;
                }
            }
        }
    }
}

int main() {
    // Initialize the 5x5 friendship matrix
    bool friendshipMatrix[5][5] = {
        {false, true,  false, true,  true}, 
        {true,  false, true,  false, true}, 
        {false, true,  false, false, false}, 
        {true,  false, false, false, true}, 
        {true,  true,  false, true,  false}  
    };

    // Display the friendship matrix
    cout << "{\n";
    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            // Print '*' if there's a friendship, otherwise print a space
            cout << (friendshipMatrix[row][col] ? "*" : " ") << "\t";
        }
        cout << "\n";
    }
    cout << "}\n";
    
    // Call the function to find and display common friends
    findCommonFriends(friendshipMatrix);
    
    return 0;
}
