//
//  main.c
//  Secret Code
//
//  Created by Mitchell Scales on 5/4/19.
//  Copyright © 2019 Mitchell Scales. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int key, i, selection; //key is the rotational key, i is increment counter, selection used for menu
char x; //not used yet
char str[1024]; //Message to encrypt
char str2[1024] = "LIPPS"; //message to decrypt
void en(char* str); //Encryption function
void de(char* str2); //Decryption function
int menu(void); //function for menu
int keys(void); //function for entering key for rotation
FILE *keyss;
FILE *Encryptions;
FILE *Decryptions;






int main() {
    
  
    keys();
    menu();
    switch(selection){
        case 2: de(str2); break;
        case 1: en(str);  break;
        case 3: ; break;
        case 4: ; break;
        case 5: ; break;
   
    }}
int keys(void){
    keyss = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/File.txt", "r");
    if(keyss == NULL) {
        perror("fopen()");
        return 0;}
    fscanf(keyss, "%d", &key);
    return key;
}

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

void en(char* str){
    Encryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Encryption.txt", "r");
    if(Encryptions == NULL) {
        perror("fopen()");
        return;}
    
    fscanf(Encryptions, "%s", str);
    
    for(i=0; str[i] != '\0'; i++){
        str[i] = str[i] + key;
        if(str[i] >= 'Z'){
            str[i] = str[i] - 26;
            break;}
    }
            printf("%s\n", str);
            
    
}

void de(char* str2){
    for(i=0; str2[i] != '\0'; i++){
        str2[i] = str2[i] - key;
        
        if(str2[i] <= 'A'){
            str2[i] = str2[i] + 26;
            break;}
    };
    printf("%s\n", str2);
}


    

    




