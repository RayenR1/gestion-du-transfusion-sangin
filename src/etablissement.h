#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include<gtk/gtk.h> 
#include <stdbool.h>
typedef struct etablissement{
char nom_etablissement[20];
char region[20];
char capacite[20];
char adress[20];
char numero[20];
char responsable[20];}etab;

int ajouterj(char *, etab );
int modifierj( char *, char *, etab );
int supprimerj(char *, char * );
etab chercherj(char *, char *);
int unique(char * filename, char * id);
void afficher_etab(GtkWidget *list,char * filename );
int ETSparRegion(char * filename , char* reg);
void ETSTriecapacite (char * filename ,int mode);
int region(char * filename,char * id);

///////////////////////////////////////////////////////ALA////////////////////////////////////////////////
struct date{
char jour[10];
char mois[10];
char annee[10];};

typedef struct utilisateur{
char poste[30];
char nom_utilisateur[30];
char prenom_utilisateur[30];
char etablissement[30];
char email[30];
char carte_d_identite[9] ;
char numero_de_telephone[30];
char sexe[20];
struct date ddn;
}utl;

int ajouter(char *,utl);
int modifier(char*,char*,utl);
int supprimer(char *,char*);
utl chercher (char*,char*);
int Poste(char poste[]);
int Etablissement(char etablissement[]);
void vider_treeview_ala(GtkWidget * liste);
void afficher_utl_sexeala(char sexeRCH[],GtkWidget * liste);
void afficher_utl_roleala(char sexeRCH[],GtkWidget * liste);
void statistique(float *nb_h, float *nb_f, char *filename) ;





void afficher_utl_poste(GtkWidget * liste,char *filename);
int utl_poste(char * filename , char* poste);
//////////////////////////////RAslen//////////////////////
typedef struct {
 int jj;
 int mm;
 int yy;
}Date;
typedef struct {
 char id[50];
 char etab[50];

 char typeSang[50];
 char urgence[50];

 int quantite;
 Date date;
 char status[50];

}Demande;
void afficherDemande(GtkWidget *liste, char *filename);
void viderDemande(GtkWidget *liste);
int ajouterDemande(char *,Demande);
int modifierDemande(char *,char *,Demande);
int supprimerDemande(char *,char *);
Demande chercherDemande(char *, char *);
float afficherPourcentageDemandes(char *,char *);
int quantiteDemandeType(char *,char *);
char*  afficherTypeSangPlusDemande(char *);
void rechercherDemande(GtkWidget *liste, char *filename,char *id[50]);
////////////////////////////////ska//////////////////
typedef struct don{
char cin[20];
char typedusang[20] ;
char etablissement_du_don[20];
char sexe[20];
char quantite[20];
struct date ddn ;
char analysedusang[20];}Don;
int ajouters(char *,Don);
int modifiers(char*,char* , Don);
int supprimers(char*,char*);
Don cherchers(char*,char*);
int analysesang(char analysedusang[]);
void afficher_type(GtkWidget *liste,char * don  );
 int affichepartype(char * don , char  typesang[]);
void afficher_tous(GtkWidget * liste);
int quantite_type(char *don , char type[]);
char* sang_rare(char * don );
/////////////////////yass////////////////////////

typedef struct infirmier{
char nom[20];
char  prenom[20];
char CIN[20] ;
char email[20] ;
char num_de_telephone[20] ;
char etablissement_du_don[20];
char adresse[20] ;
struct date ddn;
char sexe[20];}
inf;
int ajoutery(char *,inf);
int modifiery(char*,char*,inf);
int supprimery(char*,char*);
struct infirmier cherchery(char*,char*);
int choix_etablissement(char etablissement_du_don[]);
int listeRDV(char rendez_vous[], char *ETS, char *jour, char *mois , char *annee);
void afficher_rdv(GtkWidget *liste,char * infirmier );
int nbETS( char ETS[]);
float moyRDV_ETS (char nomFichier[], char *jour, char *mois , char *annee);

////////////////////////////////////////////firaaaaaaaaaaaaaaaaaaaaas/////////////////////////////////////////////
typedef struct {
    char id[10];
    char jour[3];
    char mois[3];
    char annee[5];
    char Ets[50];
    char h[6];
}RDV;

bool chercherRDV(char *nomFichier, RDV r);
RDV chercheraff(char * filename, char * id);
int ajouterRDV(char *nomFichier, RDV r);
int modifierRDV(char *nomFichier, RDV r);
int supprimerRDV(char *nomFichier, char *idToDelete);
int regionn(char * nomFichier,char * id);
void afficher_his(GtkWidget * liste);
void afficher_cr(char roleRCH[],char jourRCH[],char moisRCH[],char anneeRCH[],GtkWidget * liste);
void vider_treeview_firas(GtkWidget * liste);



#endif
