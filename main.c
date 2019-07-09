#include <stdio.h>
void GetNumber(char*);
void InitFreq(unsigned short*);
void GetFreq(char*, unsigned short*);
void NoOf_Two_Three(unsigned short*, unsigned short*, unsigned short*);
void Display(unsigned short*, unsigned short, unsigned short);
int main(){
    unsigned short t, XTwo, XThree, Freq[10];
    char Str[16];
    scanf("%hu", &t);
    GetNumber(Str);
    InitFreq(Freq);
    GetFreq(Str, Freq);
    NoOf_Two_Three(&XTwo, &XThree, Freq);
    Display(Freq, XTwo, XThree);
    return 0;
}
void GetNumber(char* Str){
    scanf("%s", Str);
}
void InitFreq(unsigned short* Freq){
    unsigned short i;
    for(i = 0; i < 10; i++){ Freq[i] = 0; }
}
void GetFreq(char* Str, unsigned short* Freq){
    unsigned short i = 0;
    while(Str[i] != '\0'){ Freq[Str[i] - '0']++; i++; }
}
void NoOf_Two_Three(unsigned short* XTwo, unsigned short* XThree, unsigned short* Freq){
    *XTwo = Freq[2] + 2 * Freq[4] + 3 * Freq[8] + Freq[9];
    *XThree = Freq[3] + Freq[6] + 2 * Freq[9];
}
void Display(unsigned short* Freq, unsigned short XTwo, unsigned short XThree){
    unsigned short i, j, k;
    for(i = 9; i > 3; i--){
        j = i;
        if( 8==j || 9==j ){ j = 7; }
        else if( 6==j ){ j = 5; }
        else if( 4==j ){ j = 3; }
        for(k = 0; k < Freq[i]; k++){ printf("%hu", j); }
    }
    for(k = 0; k < XThree; k++){ printf("3"); }
    for(k = 0; k < XTwo; k++){ printf("2"); }
}
