//WRitten by Otis Ding
//Student ID: 251220811
//This program takes in user input to create an array with various integers inside. Then, various functions are called to manipulate and use the array in various ways

#include<stdio.h>


//Declaring our functions
//Each one will take in the length of the array and the arry itself as parameters
void Positions(int arr[], int x);
void Largest(int arr[], int x);
void ReverseOrder(int arr[], int x);
void Sum(int arr[], int x);
void Descending(int arr[], int x);
void Swap(int arr[], int x);

void main (){

    //Declaring various variables that we'll be using for the program, mostly for the user's inputs
    int numOfInputs, inputInteger, integer;
    char space;

    //Prompt for and take in user input into one of the variables we've declared above
    printf("How many inputs would you like to provide? (5-12): ");
    scanf("%d", &numOfInputs);

    //Declares the array to the length specified by the user
    int rayray[numOfInputs];

    //Output the length of the array in terms of its number of elements and its size in bytes
    printf("You entered: %d, that is %d bytes \n", numOfInputs, sizeof rayray);


    //Prompts the user to input the elements into the array
    printf("Please enter the integers: ");
    //A for loop that runs the number of elements in the array
    //Scans the user input for 1 integer and 1 character value, the character being the space in between the integers
    for (int i=0; i < numOfInputs; i++){
        scanf("%d%c", &integer, &space);
        
        //Stores the user's input into the right place in the array
        rayray[i] = integer;
    }

    //Calls all the functions we'll be using and needing for th rest of our program
    Positions(rayray, numOfInputs);
    Largest(rayray, numOfInputs);
    ReverseOrder(rayray, numOfInputs);
    Sum(rayray, numOfInputs);
    Descending(rayray, numOfInputs);
    Swap(rayray, numOfInputs);


}

//Functions that prints each element and the element's position in the array
void Positions(int arr[], int numOfInputs){
    printf("Part 1: \n");

    //For loop through the array and uses i for the position of the element
    for (int i=0; i < numOfInputs; i++){
        printf("%d in position %d of the array \n", arr[i], i);
    }
}


//Function that finds and outputs the largest element in the array
void Largest(int arr[], int numOfInputs){

    //Creates and integer variable set to 0
    int largest = 0;

    //Compares the largest variable with each element of the array, setting largest to each new element that's larger than itself
    for (int i=0; i < numOfInputs; i++){
        if (largest < arr[i]){
            largest = arr[i];
        }
    }

    //Outputs the final result
    printf("Part 2: \n");
    printf("The largest element in the array is: %d\n", largest);
}


//Functions that outputs the array in reverse order
void ReverseOrder(int arr[], int numOfInputs){
    printf("Part 3: \n");
    printf("The array in reverse order is: \n");

    //Sets the for loop such that i goes from the last element of the array to the first
    for (int i = (numOfInputs-1); i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


//Function that sums all the elements in the array together and outputs it
void Sum(int arr[], int numOfInputs){

    //Makes an array that represents the sum of all the elements
    int sum = 0;
    for (int i=0; i < numOfInputs; i++){
        //Just adds each of the elements of the array into sum
        sum = sum + arr[i];
    }
    
    //Outputs the final result
    printf("Part 4: \n");
    printf("The sum of all the integers in the array is: %d\n", sum);

}


//Function that outputs the array in descending order
void Descending(int rayray[], int numOfInputs){
    printf("Part 5: \n");
    printf("Printing the array in descending order: \n");

    //Makes a second array in which we'll input our original one
    int arr[numOfInputs];

    //Declaring some variables we'll be using
    //Highest so we'll know which is the current largest number
    //Position so we can record where that current largest number is
    int highest = 0;
    int position;

    //Copies all the elements of our original array into our new one
    for (int i=0; i < numOfInputs; i++){
        arr[i] = rayray[i];
    }

    //First we find the largest number in the array, then we find its position, and store that value into its appropriate position in our new array
    for (int i=0; i < numOfInputs; i++){
        for (int i=0; i < numOfInputs; i++){
            if (highest < arr[i]){
                highest = arr[i];
            }
        }
    
        //We record the position in which the current largest is found so that we can replace it with 0, thereby gradually moving down the array from largest down
        for (int i=0; i < numOfInputs; i++){
                if (highest == arr[i]){
                    position = i;
                }
            }

        //Prints our outputs
        //Sets replaces the element we've just used with a 0, and resetting highest to 0 so the algorithm will work again the next loop over
        printf("%d ", highest);
        arr[position] = 0;
        highest = 0;

    }
    printf("\n");

    
}


//Function that swaps the first and last elements of the array
void Swap(int arr[], int numOfInputs){
    printf("Part 6: \n");
    printf("Swapped the first and last elements of the array: \n");

    //Copies our original array into a new one that we'll be manipulating
    int copyArr[numOfInputs];
    for (int i=0; i < numOfInputs; i++){
        copyArr[i] = arr[i];
    }

    //Sets the new arrays first element with the original array's last, and our new array's last element with our original's first
    copyArr[numOfInputs-1] = arr[0];
    copyArr[0] = arr[numOfInputs-1];

    //Outputs our new array
    for (int i=0; i < numOfInputs; i++){
        printf("%d ", copyArr[i]);
    }
    printf("\n");


}