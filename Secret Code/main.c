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
        case 6: keys(); break;
     
     }
    }
/*
 Inputs: No inputs needed, just to be called.
 Outputs: integer called key
 Function: Opens a file called keyss where a number is stored for the rotational cypher, reads that number and stores it in an int called key.
 Limitations:Expects an integer
 */

int keys(void){
    keyss = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/File.txt", "r"); //Used to open a file and name it keyys, this file stores the value of the key
    if(keyss == NULL) { //wont attempt to open if it cant find the file
        perror("fopen()");
        return 0;}
    fscanf(keyss, "%d", &key); // promting user to enter a value for key and storing it under key
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
    
    fgets(str, "%s", Encryptions); //similar to scanf, it stores the string of data from encryptions to str. Str is used as the intial string to encrypt
    
    for(i=0; str[i] != EOF; i++){ //for loop used to increment the position in the string
        
        if(str[i] >= 'A' && str[i] <= 'Z'){ // Only adding the value key to the character if the intial character is between A-Z
            str[i] = str[i] + key;
           
            if(str[i] >= 'Z'){ // Making sure that the out put charter is between A&Z
                str[i] = str[i] - 26;
            }
        }
        
        else if(str[i] ==  '\0'){ // Once it detects the end of line it stops the loop as it is the end of the sentence
            break;
        }
        else  str[i] = str[i]; // used to detect the characters that are not between A-Z such as full stops
        
        
        
    }
        printf("%s\n", str); //outputting the new encrypted text to console
    Outputs = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Output.txt", "a"); //outputting the encrypted text to the output file.
    if(Outputs == NULL) {
        perror("fopen()");
        return;}
   fprintf(Outputs, "%s\n", str);
    
}
    

/*
 Inputs: No input just needs to be called
 Outputs: Outputs to terminal the string of the decrypted text as str2
 Function: Calls a string from the file decryptions and saves it as str2, then takes away the value of key to it (ASCII code ) which then prints the final string of characters. Has a if statment to make sure if the letter is lower than 'a' it adds 26 to get back to the end of the alphabet.
 Limitations: Must have only capital letters in the decryption file
 */
void de(){
    Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r"); // opening the decrypted file to call the text needed to decrypt
    if(Decryptions == NULL) {
        perror("fopen()");
        return;}

    fgets(str2, "%s", Decryptions); //adding the data from decryptions to str2
    
    for(i=0; str2[i] != EOF; i++){ //increment loop the characters inside each string
        
        if(str2[i] >= 'A' && str2[i] <= 'Z'){ //Only decrypting the letters between A&Z
            str2[i] = str2[i] - key;
            if(str2[i] < 'A'){ //used for the case that the character is below A
                str2[i] = str2[i] + 26;
            }
            
        }
        
        else if(str2[i] ==  '\0'){ //if end of text stop
            break;
        }
        else  str2[i] = str2[i]; //returns all the text that isnt between A and Z
        
        
        
    }
    
    printf("%s\n", str2); //printing decrypted text
}
/*
 Inputs: No input just needs to be called
 Outputs: to terminal the string of the encrypted text as str 4
 Function: Calls a file named encryption and saves it under str3, the value of each charater in the string is translated to a posistion in the array sub_alphabet which is then stored in str4 and printed to the terminal. Repeats for each letter to form a substitution cypher
 Limitations:Must have only capital letters in the decryption file
 */
void enSub(){
    Encryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Encryption.txt", "r");
    if(Encryptions == NULL) {
        perror("fopen()");
        return;}

        
    
    fgets(str3, "%s", Encryptions);
    
    for(i=0; str3[i] != EOF; i++){
        
        if(str3[i] >= 'A' && str3[i] <= 'Z'){
            x = (int)str3[i]- 65; //x being used as a place holder variable to indicate the position on the substituted alphabet
            str4[i] = *sub_alphabet[x]; //the character value from the substituted alphabet being stransferred to the position of i in str4 for the final encrypted text
            
        }
        
        else if(str3[i] ==  '\0'){
            break;
        }
        
        else  str4[i] = str3[i];
    
    }
    
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
    
    fgets(str5, "%s", Decryptions);
    
    for(y=0; str5[y] != EOF; y++){ //for loop used to increment the position of the string
        
        if(str5[y] >= 'A' && str5[y] <= 'Z'){ //making sure its between A and Z
            for ( i = 0; i < 26; i++) //increment used to go through the alphabet comparing the string character at y to the character in the substituted alphabet to find the index of the alphabet
            {
                if (str5[y] == *sub_alphabet[i])
                {
                    Alpha_index = i;
                    str6[y] = *alphabet[Alpha_index];} //determining the value of alphabet
            }
            
        }
        
        else if(str5[y] ==  '\0'){
            break;
        }
        
        else  str6[y] = str5[y];
        
    }
    
    printf("%s\n", str6);
    
    }
    
void Random_Rotation(void){
     Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r");
     temp = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/temp.txt", "w");
    
    char line[256]; //final string from decrypted text
    char str3[256]; // string to store all decrypted words
    char str2[256]; // string to store pre-decrypted words
    char str5[256]; //string used to compare decrypted words against dictionary
    int key; //the key value
    int compare; // variable to set if the word matches the dictionary word
    
    int t = 0;// increment counter for word in the dictionary
    
    
    fgets(str2, "%s", Decryptions); // getting the intial string of words to decrypt
    
    for(key = 1; key<=25; key++){ //for loop initalised for going through all the possible values that a key rotation could be
        
        for(i=0; str2[i] != EOF; i++){ //for loop used to go though all the characters in the string
            
            if(str2[i] >= 'A' && str2[i] <= 'Z'){
                    str3[i] = str2[i] - key; //taking the key value from the intial value of the string
                    if(str3[i] < 'A'){
                        str3[i] = str3[i] + 26;}
                    
                    
                }
                
              else  if(str2[i] ==  '\0'){
                break;
                }
                
                else if(str2[i] == ' '){ //placing a new line where a space is in the sentence so it can be decoded
                 
                    str3[i] = '\n';
                   
                }
                
               // else str3[i] = str2[i];
                
            }
            

            
        
       fprintf(temp, "%s\n", str3);  //  storing the decrypted words in the temp file
}
    
    fclose(temp); //closing the file
    FILE* CLONE  = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/temp.txt", "r");
    while (fgets(str5, sizeof(str5), CLONE)) { //Reads words from dictionary
        t++;// incrementing used for choosing the words
        i=0; //setting i to be zero to re use it as a counter for the word numbber in the dictionary
        if(t != EOF){
            
            FILE* file = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/TEXT.txt", "r");
            while (fgets(line, sizeof(line), file)) { //Reads words from dictionary
                i++;
                if(i<750000)//10 words line= dict word
                {
                    compare = strcmp(line, str5); //variable used to compare the word from the decrypted text to the dictionary and if they match returns 0 and a random number if they do not.
                    if(compare == 0){
                      
                        printf("%s \n",line);//if the word matches it prints that word to the console.
                        
                        Outputs = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Output.txt", "a");
                        if(Outputs == NULL) {
                            perror("fopen()");
                            return;}
                        fprintf(Outputs, "%s\n", line); //also outputing the word to the file named outputs \
                        
                    }
                    
                }
            }
        }
        
    }

}
    


    




