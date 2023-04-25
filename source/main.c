#include "header/SMSlib.h" 

// Déclaration des entête pour les jeux SEGA (c'est obligatoir)
SMS_EMBED_SEGA_ROM_HEADER(0,0) ;
SMS_EMBED_SDSC_HEADER(0,0,2023,01,02,"Zisquier","MonProjet","Engine") ;




/* ---------------------------------------------------------------------------
-------------------  Initialisation du jeu et des affichages  ----------------
----------------------------------------------------------------------------*/
 int main (void) 
    {
        // recupération des tableaux "extérieur" à ce fichier 
        extern const unsigned char Font_Namco [];
        extern const unsigned char MonSprite [];
        
        // déclaration de variables servant à remplir l'écran de coeur
        unsigned char x = 0;
        unsigned char y = 0;

        unsigned char PosX = 0;
        unsigned char PosY = 0;

        // Initialisation de la palette des Tiles ainsi que celle des sprites 
        SMS_setBGPaletteColor(0,0);
        SMS_setBGPaletteColor(1,63);
        SMS_setBGPaletteColor(2,19);
        SMS_setBGPaletteColor(3,23);
        
        SMS_setSpritePaletteColor(0,0);
        SMS_setSpritePaletteColor(4,12);
        
        // Initialiation des sprites
        SMS_initSprites();

        // Coordonnées de départ des 4 sprites
        SMS_addSprite(PosX,PosY,256);
        SMS_addSprite(PosX,PosY+8,256);
        SMS_addSprite(PosX+8,PosY,256);
        SMS_addSprite(PosX+8,PosY+8,256);

        // remplissage de la mémoire vidée avec les tiles et les sprites 
        SMS_loadTiles(Font_Namco,1,0x38*32);
        SMS_loadTiles(MonSprite,256,32);

        // on remplis l'écran de tiles à l'aide d'une boucle 
        for (x=0 ; x < 32 ; x++) 
            {
                for (y = 0; y < 30 ; y++) 
                    {
                         SMS_setTileatXY(x,y,1);
                    }                   
            }

        // on envoie les sprites vers l'écran 
        SMS_copySpritestoSAT();

        // on "allume" l'écran de la master system
        SMS_displayOn();



/* ---------------------------------------------------------------------------
-------------------------  BOUCLE PRINCIPALE DU JEU  -------------------------
----------------------------------------------------------------------------*/
    while (1) {
        SMS_waitForVBlank();
        
        SMS_initSprites();
       
        PosX = PosX + 2;
        PosY = PosY + 1;

        SMS_addSprite(PosX,PosY,256);
        SMS_addSprite(PosX,PosY+8,256);
        SMS_addSprite(PosX+8,PosY,256);
        SMS_addSprite(PosX+8,PosY+8,256);

        SMS_copySpritestoSAT();
        }
/* ---------------------------------------------------------------------------
------------------------------------------------------------------------------
----------------------------------------------------------------------------*/
    
    }
