#include <stdio.h>
#include <math.h>

#define VSTUP "cisla.txt"
#define VYSTUP "vyhovujici_valce.txt"
void header(){
    printf("\nVALCE");
    printf("\n-------");
    printf("\n    polomer    vyska   objem valce    mnozstvi vody");
    printf("\n    (cm)       (cm)  (dm krychlove)         (litry)");
    printf("\n---------------------------------------------------");
}
void Fheader(FILE *vystup){
    fprintf(vystup,"\nVALCE S VYHOVUJICIM OBJEMEM");
    fprintf(vystup,"\n---------------------------");
    fprintf(vystup,"\n    polomer    vyska   objem valce    mnozstvi vody   vyska hladiny");
    fprintf(vystup,"\n    (cm)       (cm)  (dm krychlove)         (litry)            (cm)");
    fprintf(vystup,"\n-------------------------------------------------------------------");
}

int main() {
    FILE *Vr, *Vw;
    int polomer = 0;
    int vyska = 0;
    int voda = 0;
    int poradi = 0;
    int Fporadi = 0;
    float vyskaVody = 0;
    if ((Vr = fopen(VSTUP, "r")) == NULL ){
        printf("\nNastala chyba pri otevirani souboru %s", VSTUP);
    }
    else if ((Vw = fopen(VYSTUP, "w")) == NULL ){
        printf("\nNastala chyba pri otevirani souboru %s", VYSTUP);
    }
    else{
        header();
        Fheader(Vw);
        while(fscanf(Vr, "%d%d%d",&polomer, &vyska,&voda )!=EOF){
            poradi++;

            float objem =(float)(M_PI * (polomer * polomer)) * vyska;
            printf("\n%2d. %5d cm  %5d cm   %6.2f dm  %12d l",poradi, polomer, vyska, objem/1000, voda);
            if(voda * 1000 <= objem){
                Fporadi++;
                vyskaVody = (float)(voda * 1000) / (M_PI * (polomer * polomer));
                fprintf(Vw,"\n%2d. %5d cm  %5d cm   %6.2f dm  %12d l      %8.2f cm",Fporadi, polomer, vyska, (float)(M_PI * (polomer * polomer))/1000 * vyska, voda, vyskaVody);
            }

        }
    }
    if(fclose(Vr) == EOF){
        printf("\nNastala chyba pri zavirani souboru %s", VSTUP);
    }
    if (fclose(Vw) == EOF){
        printf("\nNastala chyba pri zavirani souboru %s", VYSTUP);
    }
    else{
        printf("\nSoubor %s byl vytvore.",VYSTUP );
    }



    return 0;
}
