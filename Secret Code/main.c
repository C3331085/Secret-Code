//
//  main.c
//  Secret Code
//
//  Created by Mitchell Scales on 5/4/19.
//  Copyright © 2019 Mitchell Scales. All rights reserved.
//

#include <stdio.h> // to use printf and scanf functions
#include <string.h> //to manipulate strings

int key, i, selection; //key is the rotational key, i is increment counter for loops, selection used for menu selection
int x; //not used yet

int Alpha_index;// Index counter for the alphabet
int y;// another increment counter used when i is already being used
char str[1024]; //Message to encrypt
char str2[1024] ; //message to decrypt
char str3[1024] ; // message to encrypt through substitution
char str4[1024] ; // Encrypted text saved as str4
char str5[1024] ; //decryption message for substitution
char str6[1024]; //decrypted message from substition
char str7[1024]; // not used yet
void en(void); //Encryption function using rotation with no input or output requried
void de(void); //Decryption function  using rotation with no input of output required
void deSub(void); // Decryption function  using substitution with no input of output required
void enSub(void); // Encryption function  using substitution with no input of output required
int menu(void); //function for menu
int keys(void); //function for entering key for rotation
void Random_Rotation(void);

FILE *keyss; //Creating a file name called keyss to call later to store the key value
FILE *Outputs; // Creating a file named outputs to output the text to
FILE *Encryptions; //createing a file name called Encryptions to call later to hold words to encrypt
FILE *Decryptions; // creating a file name called decryptions to call later to hold words to decrypt
FILE *temp;
FILE *TEXT;
char* alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y","Z"}; //creating an array of characters to store the alphabet
char* sub_alphabet[26] = {"Q", "W", "E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","K","L","Z","X","C","V","B","N","M"};// creating an array for a substitution alphabet





int main() {
    
 //main structure is just to first call keys funtion to intialise the integer keys to a user determined value, then runs the menu for the user to select which function they need, with all the functions running in a switch case and all functions in their own function.
    
    keys();// calling the keys funtion to run
    menu();// calling the menu function to run
    switch(selection){ // adding a switch as a menu selector from the integer called selection that the user types in.
        case 2: de(); break;
        case 1: en();  break;
        case 3: enSub(); break;
        case 4: deSub(); break;
        case 5: Random_Rotation(); break;
     
     }
    }
/*
 Inputs: No inputs needed, just to be called.
 Outputs: integer called key
 Function: Opens a file called keyss where a number is stored for the rotational cypher, reads that number and stores it in an int called key.
 Limitations:Expects an integer
 */

int keys(void){
    keyss = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/File.txt", "r");
    if(keyss == NULL) {
        perror("fopen()");
        return 0;}
    fscanf(keyss, "%d", &key);
    return key;
}
/*
 Inputs: There are no inputs needed for the function, it just needs to be called
 Outputs: Returns the integer selection; that is the menu item number from scanf
 Function: Prints a menu to the terminal to select the function task, with a user to then type the menu number option which is stored in selection.
 Limitations: Expecting an int between 1-6.
 */
int menu(void){
    printf("Please select one of the following options\n");
    printf("1: Encryption with a rotation cipher\n");
    printf("2: Decryption with a rotation cipher\n");
    printf("3: Encryption with a substitution cipher\n");
    printf("4: Decryption with a substitution cipher\n");
    printf("5: Decryption with a rotation cipher (Advanced)\n");
    printf("6: Decryption with a substitution cipher (Advanced\n");
    printf("Selection: ");
    scanf("%d", &selection);
    return selection;
}
/*
 Inputs: No input just needs to be called
 Outputs: Outputs to terminal the string of the encrypted text
 Function: Calls a string from the file encryptions and saves it as str, then adds the value of key to it (ASCII code ) which then prints the final string of characters. Has a if statment to make sure if the letter is higher than z it minus 26 to get back to the start of the alphabet.
 Limitations: Must have only capital letters in the encryption file and terminates at the first space/ gap key.
 */
void en(){
    Encryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Encryption.txt", "r");
    if(Encryptions == NULL) {
        perror("fopen()");
        return;
        }
    
    fscanf(Encryptions, "%s", str);
    
    for(i=0; str[i] != '\0'; i++){
        str[i] = str[i] + key;
        if(str[i] > 'Z'){
            str[i] = str[i] - 26;
            break;}
    }
        printf("%s\n", str);
    Outputs = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Output.txt", "a");
    if(Outputs == NULL) {
        perror("fopen()");
        return;}
   fprintf(Outputs, "%s\n", str);
    }
            
    

/*
 Inputs: No input just needs to be called
 Outputs: Outputs to terminal the string of the decrypted text as str2
 Function: Calls a string from the file decryptions and saves it as str2, then takes away the value of key to it (ASCII code ) which then prints the final string of characters. Has a if statment to make sure if the letter is lower than 'a' it adds 26 to get back to the end of the alphabet.
 Limitations: Must have only capital letters in the decryption file and terminates at the first space/ gap key.
 */
void de(){
    Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r");
    if(Decryptions == NULL) {
        perror("fopen()");
        return;}
    fscanf(Decryptions, "%s", str2);
    for(i=0; str2[i] != '\0'; i++){
        str2[i] = str2[i] - key;
        
        if(str2[i] < 'A'){
            str2[i] = str2[i] + 26;
            break;}
    };
    printf("%s\n", str2);
}
/*
 Inputs: No input just needs to be called
 Outputs: to terminal the string of the encrypted text as str 4
 Function: Calls a file named encryption and saves it under str3, the value of each charater in the string is translated to a posistion in the array sub_alphabet which is then stored in str4 and printed to the terminal. Repeats for each letter to form a substitution cypher
 Limitations:Must have only capital letters in the decryption file and terminates at the first space/ gap key.
 */
void enSub(){
    Encryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Encryption.txt", "r");
    if(Encryptions == NULL) {
        perror("fopen()");
        return;}
    fscanf(Encryptions, "%s", str3);
    for(i=0; str3[i] != '\0';i++){
        x = (int)str3[i]- 65;
        str4[i] = *sub_alphabet[x];}
    
    printf("%s\n", str4);
    
}
/*
 Inputs: No input just needs to be called
 Outputs: to terminal the string of the decrypted text as str 6
 Function: Calls a file named decryption and saves it under str5, the value of each charater in the string is translated to a posistion in the array alphabet which is then stored in str5 and printed to the terminal. Repeats for each letter to form a substitution cypher
 Limitations:Must have only capital letters in the decryption file and terminates at the first space/ gap key.
 */
void deSub(){
    Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r");
    if(Decryptions == NULL) {
        perror("fopen()");
        return;}
    fscanf(Decryptions, "%s", str5);
    for(y = 0 ; str5[y] != '\0'; y++){
        for ( i = 0; i < 26; i++)
        {
            if (str5[y] == *sub_alphabet[i])
            {
                Alpha_index = i;
                str6[y] = *alphabet[Alpha_index];}
        }
    }
    
    printf("%s\n", str6);
    
    }
    
void Random_Rotation(void){
     Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r");
     temp = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/temp.txt", "w");
    
    char line[256];
    char str3[256];
    char str2[256];
    char str5[256];
    int key;
    int compare;
    int n;
    int t = 0;
    
    for(n = 0; n<25; n++){
        fscanf(Decryptions, "%s", str2);
        
        for(i=0; str2[i] != '\0'; i++){
            key = n;
            str3[i] = str2[i] - key;
            
            if(str3[i] <= 'a'){
                str3[i] = str3[i] + 25;}
            
        }
        fprintf(temp, "%s\n", str3);
        
    }
    fclose(temp);
    FILE* CLONE  = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/temp.txt", "r");
    while (fgets(str5, sizeof(str5), CLONE)) { //Reads words from dictionary
        t++;
        i=0;
        if(t<27){
            
            FILE* file = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/TEXT.txt", "r");
            while (fgets(line, sizeof(line), file)) { //Reads words from dictionary
                i++;
                if(i<300000)//10 words line= dict word
                {
                    compare = strcmp(line, str5);
                    if(compare == 0){
                        printf("%s\n",line);
                    }
                    
                }
            }
        }
        
    }

}
    


    




