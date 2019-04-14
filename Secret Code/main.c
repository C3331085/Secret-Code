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
int x; //not used yet

int Hi;
int y;
char str[1024]; //Message to encrypt
char str2[1024] ; //message to decrypt
char str3[1024] ;
char str4[1024] ;
char str5[1024] ;
char str6[1024];
char str7[1024];
void en(char* str); //Encryption function
void de(char* str2); //Decryption function
void deSub(char* str3);
void enSub(char* str5);
int menu(void); //function for menu
int keys(void); //function for entering key for rotation

FILE *keyss;
FILE *Encryptions;
FILE *Decryptions;
char* alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y","Z"};
char* sub_alphabet[26] = {"Q", "W", "E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","K","L","Z","X","C","V","B","N","M"};





int main() {
    for(i = 0; str7[i] != '\0'; i++){
        
    }
        
    
    keys();
    menu();
    switch(selection){
        case 2: de(str2); break;
        case 1: en(str);  break;
        case 3: enSub(str3); break;
        case 4: deSub(str5); break;
        case 5: ; break;
     
     }
    }


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
        return;
        }
    
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
    Decryptions = fopen("/Users/mitchellscales/Desktop/UNI/ENGG1003/Assesments/Secret Code/Secret Code/Decryption.txt", "r");
    if(Decryptions == NULL) {
        perror("fopen()");
        return;}
    fscanf(Decryptions, "%s", str2);
    for(i=0; str2[i] != '\0'; i++){
        str2[i] = str2[i] - key;
        
        if(str2[i] <= 'A'){
            str2[i] = str2[i] + 26;
            break;}
    };
    printf("%s\n", str2);
}

void enSub(char* str3){
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
    
void deSub(char* str5){
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
                Hi = i;
                str6[y] = *alphabet[Hi];}
        }
    }
    
    printf("%s\n", str6);
    
    }
    

    


    




