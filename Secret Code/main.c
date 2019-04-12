//
//  main.c
//  Secret Code
//
//  Created by Mitchell Scales on 5/4/19.
//  Copyright © 2019 Mitchell Scales. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int key, i, ii, selection;
char x;
char str[1024] = "AZ";
char str2[1024] = "AZ";
void en(char* str);
void de(char* str2);
int menu(void);




int main() {
    
    printf("Please Enter a key value:");
    scanf("%d", &key);
    menu();
    switch(selection){
        case 2: de(str2);break;
        case 1: en(str); break;
        case 3: ; break;
        case 4: ; break;
        case 5: ; break;
   
    }}
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
    for(i=0; str[i] != '\0'; i++){
        str[i] = str[i] + key;
        if(str[i] >= 'Z'){
            str[i] = str[i] - 26;
            break;}
            printf("%s\n", str);
            
        }
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


    

    




