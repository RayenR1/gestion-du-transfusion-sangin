#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include "etablissement.h"
#include<string.h>
#include <gtk/gtk.h>
#include <stdbool.h>
//ajouuuuuuuuuuuuut
int ajouterj(char * filename , etab e ){
int v1,v2,v3,v4,i;
etab p;
FILE * f=fopen(filename, "a");
 if(f!=NULL)
    {
  
         //rewind(f); // Rembobiner le fichier à la position de départ
       /* while (fscanf(f, "%s %s %s %s %s %s\n", p.nom_etablissement, p.region, p.capacite, p.adress, p.numero, p.responsable) != EOF) {
            if (strcmp(p.nom_etablissement, e.nom_etablissement) == 0) {
                fclose(f);
                return -2; // L'enregistrement existe déjà
            }
        }*/
       
     //fclose(f);
    // f=fopen(filename, "a");
        fprintf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable);
        fclose(f);
        return 1;}
     
    else return 0;
}

////////////////modifiiiiiiiiiiiiiier/////////////////////
int modifierj( char * filename, char * id, etab  nouv )
{
    int tr=0;
    etab p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable)!=EOF)
        {
            if(strcmp(p.nom_etablissement,id)==0)
            {
 
  /* //meme controle de saisie
int v1,v2,v3,v4,i;
   // controle du nom etablissement 
v1=1;
i=0;
if(strlen(nouv.nom_etablissement)!=0){
while(i<strlen(nouv.nom_etablissement)&&v1==1){
if(nouv.nom_etablissement[i]<'a'||'z'<nouv.nom_etablissement[i])
{v1=0;}
i++;
}}else v1=0;
   //controle saisie region 
v2=1;
i=0;
if(strlen(nouv.region)!=0){
while(i<strlen(nouv.region)&&v2==1){ 
if(nouv.region[i]<'a'||'z'<nouv.region[i])
{v2=0;}
i++;
}}else v2=0;
   //controle saisie numero
v3=1,i=0;
if(strlen(p.numero)==8)
{
while(i<strlen(p.numero)&&v3==1){
if(p.numero[i]<'0'||'9'<p.numero[i])
{v3=0;}
i++;
}
}else{v3=0;}
  //controle du saisie responsable 
v4=1;
i=0;
if(strlen(nouv.responsable)!=0){
while(i<strlen(nouv.responsable)&&v4==1){ 
if(nouv.responsable[i]<'a'||'z'<nouv.responsable[i])
{v4=0;}
i++;
}}else v4=0;
//ecrire dans le fichier
        if(v1==1&&v2==1&&v3==1&&v4==1){*/
                fprintf(f2,"%s %s %s %s %s %s\n",nouv.nom_etablissement,nouv.region,nouv.capacite,nouv.adress,nouv.numero,nouv.responsable);
                tr=1;}
                  //  else return(-1);//si la return -1 erreur cause par le saisie  si return 0  erreur causer par fichier 
           // }
            else
                fprintf(f2,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//suuuuuuuuuprimer
int supprimerj(char * filename, char *id)
{
    int tr=0;
    etab e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable)!=EOF)
        {
            if(strcmp(e.nom_etablissement ,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
///////////////chercher//////////// 
etab chercherj(char * filename, char * id)
{ 
    etab e;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable)!=EOF)
        {
            if(strcmp(e.nom_etablissement, id)==0)
                tr=1;// 1 si on trrouve la valeur 
        }
    }
    fclose(f);
    if(tr==0){
       strcpy( e.nom_etablissement,"-1");
       
      }
    return e;
}
//////////////////unicite du nom etab //////////////
int unique(char * filename, char * id)
{ 
    etab e;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable)!=EOF)
        {
            if(strcmp(e.nom_etablissement, id)==0)
              {
                tr=1;// 1 si on trrouve la valeur 
                return(1);
            }
        }
    }
    fclose(f);
    return 0;
}
////////////////////////////////region//////////////////////////////////
int region(char * filename,char * id)
{
int tr;
char c[50];
FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %d\n",c,&tr)!=EOF)
        {
            if(strcmp(c, id)==0)
              {
               return(tr);// 1 si on trrouve la valeur 
          }
        }
    }
    fclose(f);

return(tr);

}

///////////////////////////////treeview////////////////////////////

enum {
  Enom_etablissement,
  Eregion,
  Ecapacite,
  Eadress,
  Enumero,
  Eresponsable,
  ECOLUMNS,
};

// affichage
void afficher_etab(GtkWidget *list,char * filename  ){

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  etab p;
  /*char nom_etablissement[20];
  char region[20];
  char capacite[20];
  char adress[20];
  char numero[20];
  char responsable[20];*/
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(list));
if(store==NULL){
renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom_etablissement",renderer,"text",Enom_etablissement,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",Eregion,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("capacite",renderer,"text",Ecapacite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("adress",renderer,"text",Eadress,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("numero",renderer,"text",Enumero,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("responsable",renderer,"text",Eresponsable,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);}

store=gtk_list_store_new (ECOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(filename,"r");
 if(f==NULL)
{
  return;
}
else if(f!=NULL)
{
f=fopen(filename,"a+");
while(fscanf(f,"%s %s %s %s %s %s \n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Enom_etablissement,p.nom_etablissement,Eregion,p.region,Ecapacite,p.capacite,Eadress,p.adress,Enumero,p.numero,Eresponsable,p.responsable,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (list), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


///////////////////affichage par region ////////////////////////
  int ETSparRegion(char * filename , char* reg)
    {
int tr=0;
etab p;
 FILE *f=fopen(filename, "r");
 FILE *f2=fopen("affichereg.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable)!=EOF)
          {
              if(strcmp(p.region,reg)==0)
              {
                  fprintf(f2,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable);
                  tr++;
              
             }
          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }

//////////////////affichage par capacite//////////////
void ETSTriecapacite(char* filename, int mode)
{
    int tr = 0, i, j, min, n;
    etab T[8000], tampon;
    etab p;
    FILE* f = fopen(filename, "r");
    FILE* f2 = fopen("afficheparcap.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        n = 0;
        while (fscanf(f, "%s %s %s %s %s %s\n", p.nom_etablissement, p.region, p.capacite, p.adress, p.numero, p.responsable) != EOF)
        {
            // remplissage du tableau par les etablissements
            T[n] = p;
            n++;
        }

        // trie le tableau selon la capacite
        if (mode == 1)
        {
            for (i = 0; i < n - 1; i++)
            {
                min = i;

                for (j = i + 1; j < n; j++)
                {
                    if (strcmp(T[j].capacite, T[min].capacite) < 0)
                        min = j;
                }

                tampon = T[i];
                T[i] = T[min];
                T[min] = tampon;
            }
        }
        else if (mode == 2)
        {
            for (i = 0; i < n - 1; i++)
            {
                min = i;

                for (j = i + 1; j < n; j++)
                {
                    if (strcmp(T[j].capacite, T[min].capacite) > 0)
                        min = j;
                }

                tampon = T[i];
                T[i] = T[min];
                T[min] = tampon;
            }
        }

        // ecriture dans le fichier 2
        for (i = 0; i < n; i++)
        {
            fprintf(f2, "%s %s %s %s %s %s\n", T[i].nom_etablissement, T[i].region, T[i].capacite, T[i].adress, T[i].numero, T[i].responsable);
        }
        fclose(f);
        fclose(f2);
    }
}

////////////////////////////////////////////////ALA//////////ALA///////////////////ALA//////////////ALA/////////////////////////////////////////////////////////////////////////////////////////////
enum
{
EPOSTE,
ENOM_UTILISATEUR,
EPRENOM_UTILISATEUR,
EETABLISSEMENT,
EEMAIL,
ECARTE_D_IDENTITE,
ENUMERO_DE_TELEPHONE,
ESEXE,
EJOUR,
EMOIS,
EANNEE,
COLUMNS
};

int ajouter(char * filename, utl p )
{
    FILE * f=fopen(filename, "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
/*int modifier(char *filename, char *id, utl nouv)
{
    int tr = 0;
    utl p;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w+");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s\n",p.poste,
                      p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe,p.ddn.jour, p.ddn.mois, p.ddn.annee) != EOF)
        {
            printf("Lecture depuis le fichier : %s %s %s %s %s %s %s %s %s %s %s \n",p.poste,
                   p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email,p.carte_d_identite, 
                   p.numero_de_telephone,p.sexe,p.ddn.jour, p.ddn.mois, p.ddn.annee);

            if (strcmp(id,p.carte_d_identite) != 0)
            {
            printf("Pas de modification pour ID %s\n", p.carte_d_identite);
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s\n",p.poste,
                        p.nom_utilisateur, p.prenom_utilisateur, p.etablissement,
                        p.email,p.carte_d_identite, p.numero_de_telephone,p.sexe,
                        p.ddn.jour, p.ddn.mois, p.ddn.annee);
            }
            else
            {
                    printf("Modification pour ID %s\n", id);
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s \n", nouv.poste,
                        nouv.nom_utilisateur, nouv.prenom_utilisateur, nouv.etablissement,
                        nouv.email, nouv.carte_d_identite, nouv.numero_de_telephone,nouv.sexe,
                        nouv.ddn.jour, nouv.ddn.mois, nouv.ddn.annee);
                tr = 1;
            }
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}*/
int modifier( char * filename, char * id, utl  nouv )
{
    int tr=0;
    utl p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,
p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
            if(strcmp(p.carte_d_identite,id)==0)
            {
 
  
                fprintf(f2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,nouv.poste,nouv.nom_utilisateur,nouv.prenom_utilisateur,nouv.etablissement,nouv.email,nouv.carte_d_identite,nouv.numero_de_telephone,nouv.sexe,nouv.ddn.jour,nouv.ddn.mois,nouv.ddn.annee);
                tr=1;}
                 
            else
                fprintf(f2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}





int supprimer(char * filename, char * id)
{
    int tr=0;
    utl p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,
p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
          if(strcmp(p.carte_d_identite, id)!=0)
               {  
                fprintf(f2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee);}
            else
               tr=1 ;
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utl chercher(char * filename, char * id)
{
    utl p;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" ,p.poste,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite,p.numero_de_telephone,p.sexe,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
            if(strcmp(p.carte_d_identite, id)==0)
{tr=1; }
           

        }
    }
    
    if(tr==0)
        strcpy(p.carte_d_identite,"-1");
fclose(f);
    return p;

}

int Poste(char poste[])
{
    int p;
    if (strcmp(poste, "administrateur") == 0) {
        p = 0;
    } else if (strcmp(poste, "infirmier") == 0) {
        p = 1;
    } else if (strcmp(poste, "medecin") == 0) {
        p = 2;
    } else if (strcmp(poste, "donneur") == 0) {
        p = 3;
    }
    else
        p= -1;
return p;
}
//////////////////////////////////////////////////////////////////////////////
int Etablissement(char etablissement[])
{
    int e;
    if (strcmp(etablissement, "vb") == 0) {
        e = 0;
    } else if (strcmp(etablissement, "vc") == 0) {
        e = 1;
    } else if (strcmp(etablissement, "cv") == 0) {
        e = 2;
   // } else if (strcmp(poste, "donneur") == 0) {
      //  p = 3;
  }
    else
        e= -1;
return e;
}

//affichage 
void afficher_utl_poste(GtkWidget * liste,char *filename)
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter ;
	GtkListStore *store;
  	


 /* char poste[30];
  char nom_utilisateur[30];
  char prenom_utilisateur[30];
  char etablissement[30];
  char email[30];
  char carte_d_identite[9] ;
  char numero_de_telephone[30];
  char sexe[20];
  struct date{
char jour[10];
char mois[10];
char annee[10];}ddn;*/
 utl p;
  store=NULL ;

FILE *f;

store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",EPOSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom d'utilisateur",renderer,"text",ENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom d'utilisateur",renderer,"text",EPRENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etablissement",renderer,"text", EETABLISSEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("       Email    ",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Carte d'identite",renderer,"text",ECARTE_D_IDENTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Num de telephone",renderer,"text",ENUMERO_DE_TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(filename,"r");
if(f==NULL)
{
return ;
}




else 
f=fopen(filename,"a+") ;
while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee) != EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,EPOSTE,p.poste,ENOM_UTILISATEUR,p.nom_utilisateur,EPRENOM_UTILISATEUR,p.prenom_utilisateur,EETABLISSEMENT,p.etablissement,EEMAIL,p.email,
ECARTE_D_IDENTITE,p.carte_d_identite,ENUMERO_DE_TELEPHONE,p.numero_de_telephone,ESEXE,p.sexe,EJOUR,p.ddn.jour,EMOIS,p.ddn.mois,EANNEE,p.ddn.annee,-1) ;
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);

}
////////////////////////////////////////////////////////////////////////////////////////


int utl_poste(char * filename , char* poste)
    {
int tr=0;
utl p;
 FILE *f=fopen(filename, "r");
 FILE *f2=fopen("utlposte.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee)!=EOF)
          {
              if(strcmp(p.poste,poste)==0)
              {
                  fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee);
                  tr++;
             
             }

          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }





/*
//// geeeeeeeeennnnnnre donneur

void sexe(int teste ,char msg[])
{
if(test==1)
strcpy(msg,"femme");
else if(analyse==2)
strcpy(msg,"homme");
}

*/


/*int utl_sexe(char * filename , char* sexe)
{
   
  utl p;

    FILE *f = fopen("utl.txt", "r");
   
    if (f == NULL) {
        g_printerr("Error opening the file.\n");
        return 0;
    }

    
    int totalUsers = 0;
    int maleCount = 0;
    int femaleCount = 0;

    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee) != EOF) {
        if (strcmp(p.sexe, "homme") == 0) {

            maleCount++;
        } 
	else if (strcmp(p.sexe, "femme") == 0) 
            femaleCount++;
        

        totalUsers++;
    }
    fclose(f);
	double malePercentage = (double)maleCount / totalUsers * 100;
    double femalePercentage = (double)femaleCount / totalUsers * 100;*/

void statistique(float *nb_h, float *nb_f, char *filename) {
    int total = 0;
    utl p;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        *nb_h = 0.0;
        *nb_f = 0.0;
        return;
    }

    while (fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee) != EOF) {
        if (strcmp(p.sexe, "femme") == 0) (*nb_f)++;
        if (strcmp(p.sexe, "homme") == 0) (*nb_h)++;
        total++;
    }
    fclose(file);

    if (total > 0) {
        *nb_h = (*nb_h / total) * 100;
        *nb_f = (*nb_f / total) * 100;
    } else {
        *nb_h = 0.0;
        *nb_f = 0.0;
    }
}

   
    

   
    /*gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, ESEXE, "Homme", PACKAGE, malePercentage, -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, ESEXE, "Femme", PACKAGE, femalePercentage, -1);

    
    gtk_tree_view_set_model(GTK_TREE_VIEW(sexe), GTK_TREE_MODEL(store));
    g_object_unref(store);
return malePercentage;
}



int utl_sexee(char * filename, char* sexe)int utl_poste(char * filename , char* poste)
    {
int tr=0;
utl p;
 FILE *f=fopen(filename, "r");
 FILE *f2=fopen("utlsexe.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee)!=EOF)
          {
              if(strcmp(p.sexe,sexe)==0)
              {
                  fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.poste,p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone,p.sexe, p.ddn.jour, p.ddn.mois, p.ddn.annee);
                  tr++;
             
             }

          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }
*/



///////////////////////////////





/*int supprimer(int id, char * filename) {
{
 FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("utl.txt", "w");

    if (file == NULL || tempFile == NULL) {
      
        return 0;
    }

    char line[2000000];

    while (fgets(line, sizeof(line), file) != NULL) {
        int line_Cin;
        if (sscanf(line, "%d", &line_Cin) == 1) {
            if (line_Cin != id) {
                fputs(line, tempFile);
            }
        }
    }
    
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("utl.txt", filename);
    return 1;
}
}*/

void vider_treeview_ala(GtkWidget * liste)
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter ;
	GtkListStore *store;
  	


  char poste[30];
  char nom_utilisateur[30];
  char prenom_utilisateur[30];
  char etablissement[30];
  char email[30];
  char carte_d_identite[9] ;
  char numero_de_telephone[30];
  char sexe[20];
char jour[10];
char mois[10];
char annee[10];

  store=NULL ;

FILE *f;

store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",EPOSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom d'utilisateur",renderer,"text",ENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom d'utilisateur",renderer,"text",EPRENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etablissement",renderer,"text", EETABLISSEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("       Email    ",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Carte d'identite",renderer,"text",ECARTE_D_IDENTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Num de telephone",renderer,"text",ENUMERO_DE_TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append (store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

}
///////////////////////////
/////////////////////////////////
/////////////////////////////////////////////////
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void afficher_utl_sexeala(char sexeRCH[],GtkWidget * liste)
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter ;
	GtkListStore *store;
  	


  char poste[30];
  char nom_utilisateur[30];
  char prenom_utilisateur[30];
  char etablissement[30];
  char email[30];
  char carte_d_identite[9] ;
  char numero_de_telephone[30];
  char sexe[20];
char jour[10];
char mois[10];
char annee[10];

  store=NULL ;

FILE *f;

store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",EPOSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom d'utilisateur",renderer,"text",ENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom d'utilisateur",renderer,"text",EPRENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etablissement",renderer,"text", EETABLISSEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("       Email    ",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Carte d'identite",renderer,"text",ECARTE_D_IDENTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Num de telephone",renderer,"text",ENUMERO_DE_TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("utl.txt","r");
if(f==NULL)
{
return ;
}




else {
f=fopen("utl.txt","a+") ;
while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n",poste,nom_utilisateur, prenom_utilisateur, etablissement, email, carte_d_identite,
                      numero_de_telephone,sexe, jour, mois, annee) != EOF)
{
if(strcmp(sexeRCH,sexe)==0)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,EPOSTE,poste,ENOM_UTILISATEUR,nom_utilisateur,EPRENOM_UTILISATEUR,prenom_utilisateur,EETABLISSEMENT,etablissement,EEMAIL,email,
ECARTE_D_IDENTITE,carte_d_identite,ENUMERO_DE_TELEPHONE,numero_de_telephone,ESEXE,sexe,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1) ;
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}


void afficher_utl_roleala(char roleRCH[],GtkWidget * liste)
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter ;
	GtkListStore *store;
  	


  char poste[30];
  char nom_utilisateur[30];
  char prenom_utilisateur[30];
  char etablissement[30];
  char email[30];
  char carte_d_identite[9] ;
  char numero_de_telephone[30];
  char sexe[20];
char jour[10];
char mois[10];
char annee[10];

  store=NULL ;

FILE *f;

store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",EPOSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom d'utilisateur",renderer,"text",ENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom d'utilisateur",renderer,"text",EPRENOM_UTILISATEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etablissement",renderer,"text", EETABLISSEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("       Email    ",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Carte d'identite",renderer,"text",ECARTE_D_IDENTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Num de telephone",renderer,"text",ENUMERO_DE_TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("utl.txt","r");
if(f==NULL)
{
return ;
}




else {
f=fopen("utl.txt","a+") ;
while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n",poste,nom_utilisateur, prenom_utilisateur, etablissement, email, carte_d_identite,
                      numero_de_telephone,sexe, jour, mois, annee) != EOF)
{
if(strcmp(roleRCH,poste)==0)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,EPOSTE,poste,ENOM_UTILISATEUR,nom_utilisateur,EPRENOM_UTILISATEUR,prenom_utilisateur,EETABLISSEMENT,etablissement,EEMAIL,email,
ECARTE_D_IDENTITE,carte_d_identite,ENUMERO_DE_TELEPHONE,numero_de_telephone,ESEXE,sexe,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1) ;
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
////////////////////////////////////////////////RASLEN//////////RASLEN///////////////////RASLEN///////////RASLEN///////////////////////////////////////////////////////////////////////////////////
enum{EID,
     EETAB,
     EDATEJJ,
     EDATEMM,
     EDATEYY,
     EQUANTITE,
     ETYPESANG,
     EURGENCE,
     ESTATUS,
     RCOLUMNS
      };





void afficherDemande(GtkWidget *liste, char *filename){

     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Demande d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(RCOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {

         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  EETAB, d.etab, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EQUANTITE,quantite,ETYPESANG,d.typeSang,EURGENCE,d.urgence,ESTATUS,d.status,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }

}
void viderDemande(GtkWidget *liste){

     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste


    store = NULL;
  
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(RCOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,RCOLUMNS);



}

void rechercherDemande(GtkWidget *liste, char *filename,char *id[50]){




   GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Demande d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(RCOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
             if(strcmp(d.id,id)==0){
         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  EETAB, d.etab, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EQUANTITE,quantite,ETYPESANG,d.typeSang,EURGENCE,d.urgence,ESTATUS,d.status,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }










}





















int ajouterDemande(char *filename,Demande d){

     FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        fclose(f);
        return 1;
    }
    else return 0;

}

int modifierDemande(char *filename,char *id,Demande nouv){


 int tr=0;
    Demande d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
            {
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",nouv.id,nouv.etab,nouv.typeSang,nouv.urgence,nouv.quantite,nouv.date.jj,nouv.date.mm,nouv.date.yy,nouv.status);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerDemande(char *filename,char *id){

int tr=0;
    Demande d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
            {

                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}


Demande chercherDemande(char *filename, char *id){
 Demande d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
      strcpy(d.id,"-1");
    return d;







}


float afficherPourcentageDemandes(char *filename, char *etab){

float poucentageDemande = 0;
 Demande d;
    int nombreDemande=0;
    int nombreEtabil=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            nombreDemande++;

            if (strcmp(d.etab,etab)== 0)
            {
                nombreEtabil++;
            }




        }

    }
    fclose(f);

    if (nombreDemande > 0)
    {
        poucentageDemande = (float)nombreEtabil / (float)nombreDemande * 100;

    return poucentageDemande;
    }

    return poucentageDemande;

}


int quantiteDemandeType(char *filename,char *typeSang){


   Demande d;
   int quantiteTotale=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {


            if (strcmp(d.typeSang, typeSang) == 0)
            {
               quantiteTotale+=d.quantite;
            }




        }

    }
    fclose(f);

     return quantiteTotale;
}


char* afficherTypeSangPlusDemande(char *filename ){
       char typesSangConnus[][5] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    int maxQuantite = 0;
    char sangPlusDemande[5] = "";
 Demande d;
         for(int i =0; i<8;i++){

            int quantite = quantiteDemandeType(filename,typesSangConnus[i]);
             if (quantite > maxQuantite) {
            maxQuantite = quantite;
            strcpy(sangPlusDemande, typesSangConnus[i]);
            }








}
  char *resultat = (char *)malloc((strlen(sangPlusDemande) + 1) * sizeof(char));

   strcpy(resultat,sangPlusDemande);
return resultat;

}

/////////////////////////////////////////////////////ska////////////////////ska///////////////////ska//////////////////////////////

enum
{
    SECIN,
    SETYPEDUSANG,
    SEANALYSEDUSANG,
    SEETABLISSEMENTDUDON,
    SEJOUR,
    SEMOIS,
    SEANNEE,
    SEQUANTITE,
    SESEXE,
    SCOLUMNS
};



int ajouters(char * don, Don p ){

    FILE * f=fopen("don.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee);
        fclose(f);
        return 1;
    }
    else return 0;
} 

int modifiers( char * don, char *id, Don nouv )
{
    int tr=0;
    Don p;
    FILE * f=fopen("don.txt","r" ) ;
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {  

     if(strcmp(p.cin,id)==0)
            {
fprintf(f2,"%s %s %s %s %s %s %s %s %s\n",nouv.cin,nouv.sexe,nouv.etablissement_du_don,nouv.typedusang,nouv.analysedusang,nouv.quantite,nouv.ddn.jour,nouv.ddn.mois,nouv.ddn.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove("don.txt");
    rename("nouv.txt", "don.txt");
    return tr;

} 

int supprimers(char * don, char *id)
{
    int tr=0;
    Don p;
Don nouv ;
    FILE * f=fopen("don.txt", "r+");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)

        {  if(strcmp(p.cin,id)==0)
              // fprintf(f2,"%s %s %s %s %s %s %s %s %s\n",nouv.cin,nouv.sexe,nouv.etablissement_du_don,nouv.typedusang,nouv.analysedusang,nouv.quantite,nouv.ddn.jour,nouv.ddn.mois,nouv.ddn.annee);
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove("don.txt");
    rename("nouv.txt", "don.txt");
    return tr;
}
Don cherchers(char * don, char *id)
{
    Don p;
    int tr=0;
    FILE * f=fopen("don.txt", "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
          if(strcmp(p.cin,id)==0){
                tr=1;}
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(p.cin,"-1");
    return p;

}

void afficher_tous(GtkWidget * liste)
{

Don p ;
GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
store=NULL ;

FILE *f;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",SECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etablissement_du_don",renderer,"text",SEETABLISSEMENTDUDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("typedusang",renderer,"text",SETYPEDUSANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("analysedusang",renderer,"text", SEANALYSEDUSANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",SEQUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.jour",renderer,"text",SEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.mois",renderer,"text",SEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.annee",renderer,"text",SEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);}





//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(SCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("don.txt","r");
if(f==NULL)
{
return ;
}
else 

f=fopen("don.txt","a+") ;
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)

{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,& iter,SECIN,p.cin,SESEXE,p.sexe,SEETABLISSEMENTDUDON,p.etablissement_du_don,SETYPEDUSANG,p.typedusang,SEANALYSEDUSANG,p.analysedusang,SEQUANTITE,p.quantite,SEJOUR,p.ddn.jour,SEMOIS,p.ddn.mois,SEANNEE,p.ddn.annee,-1) ;
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
int connexion(char *login)
{
    FILE *f = NULL;
    Don p;
    int userType; 
    f = fopen("don.txt", "r");
    
       while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)     
    {
        if (strcmp(login, p.cin) == 0)
        {
            
                userType = 3;
    }
    fclose(f);
    return userType;
}

void afficher_par_type_dusang(GtkWidget * liste);
{}
*/

int analysesang(char analysedusang[])
{


    int analyse;
    if (strcmp(analysedusang, "rien") == 0) {
        analyse = 0;
    } else if (strcmp(analysedusang, "Hepatite") == 0) {
        analyse = 1;
    } else if (strcmp(analysedusang, "VIH") == 0) {
        analyse= 2;
}
  
return analyse;
}
int quantite_type(char *don , char type[]){

 int q=0;
    Don p;
    FILE * f=fopen("don.txt","r" ) ;
 if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        { if(strcmp(p.typedusang,type)==0) {
               q+=atoi(p.quantite) ; 
}
} }
return q ;}

  int affichepartype(char * don , char  typesang[])
    {
int tr=0;
Don p;
 FILE *f=fopen("don.txt", "r");
 FILE *f2=fopen("affichetype.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
          {
              if(strcmp(p.typedusang,typesang)==0)
              {
                  fprintf(f2,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee);
                  tr++;
             
             }
          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }



// affichage
void afficher_type(GtkWidget *liste,char * don  ){

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  Don p;
  
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",SECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etablissement_du_don",renderer,"text",SEETABLISSEMENTDUDON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("typedusang",renderer,"text",SETYPEDUSANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("analysedusang",renderer,"text", SEANALYSEDUSANG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",SEQUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.jour",renderer,"text",SEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.mois",renderer,"text",SEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ddn.annee",renderer,"text",SEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);}





//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(SCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(don,"r");
 if(f==NULL)
{
  return;
}
else if(f!=NULL)
{
f=fopen(don,"a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.sexe,p.etablissement_du_don,p.typedusang,p.analysedusang,p.quantite,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)

{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,& iter,SECIN,p.cin,SESEXE,p.sexe,SEETABLISSEMENTDUDON,p.etablissement_du_don,SETYPEDUSANG,p.typedusang,SEANALYSEDUSANG,p.analysedusang,SEQUANTITE,p.quantite,SEJOUR,p.ddn.jour,SEMOIS,p.ddn.mois,SEANNEE,p.ddn.annee,-1) ;
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
   
}}

char* sang_rare(char * don ){
char typessang[][6]={"A","B","AB","O"};
int minq=500;
char sangrare[6]="";
//char resultat[6] ;
 char *resultat = (char *)malloc(6 * sizeof(char));
for(int i=0;i<4;i++){
int quantite= quantite_type("don.txt",typessang[i] );
if ( quantite <minq && quantite!=0){
minq=quantite ;
strcpy(sangrare ,typessang[i]);
}
strcpy(resultat,sangrare);
//free (resultat);
}
return resultat ;

}

////////////////////////////////////////////yb//////////////////yb////////////yb/////////////yb

//ajout:
int ajoutery(char * infirmier, inf p ){

    FILE * f=fopen("infirmier.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe);
        fclose(f);
        return 1;
    }
    else return 0;
}




//modifier
int modifiery( char *  infirmier, char * id, inf nouv )
{
    int tr=0;
    inf p;
    FILE * f=fopen("infirmier.txt","r" ) ;
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe)!=EOF)
        {
            if(strcmp(p.CIN,id)==0)
            {
fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",nouv.nom,nouv.prenom,nouv.CIN,nouv.email,nouv.num_de_telephone,nouv.etablissement_du_don,nouv.adresse,nouv.ddn.jour,nouv.ddn.mois,nouv.ddn.annee,nouv.sexe);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe);

        }
    }
    fclose(f);
    fclose(f2);
    remove("infirmier.txt");
    rename("nouv.txt", "infirmier.txt");
    return tr;

}

//supprimer
int supprimery(char * infirmier , char *id)
{
    int tr=0;
    inf  p;
    FILE * f=fopen("infirmier.txt", "r+");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe)!=EOF)
        {
          if (strcmp(p.CIN, id)==0){
                tr=1;
             } 
            else 
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe);
        
    }}
    fclose(f);
    fclose(f2);
    remove("infirmier.txt");
    rename("nouv.txt", "infirmier.txt");
    return tr;
}

//chercher
struct infirmier  cherchery(char * infirmier, char *id)
{
    inf p;
    int tr=0;
    FILE * f=fopen("infirmier.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe)!=EOF)
        {
            if (strcmp(p.CIN, id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(p.CIN,"-1");
return p;
}

//fct combobox etablissement du don
int choix_etablissement(char etablissement_du_don[])
{
int test;
if (strcmp(etablissement_du_don, "etab1")==0)
{ test= 0;}
else if (strcmp(etablissement_du_don, "etab2")==0)
{ test= 1;}
else if (strcmp(etablissement_du_don, "etab3")==0)
{test= 2;}
return test;
}

 int afficheparetablissement(char * don, char  etablissement[])
    {
int tr=0;
inf p;
 FILE *f=fopen("infirmier.txt", "r");
 FILE *f2=fopen("afficheetablissement.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe)!=EOF)
          {
              if(strcmp(p.etablissement_du_don,etablissement)==0)
              {
                  fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe);
                  tr++;
             
             }
          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }
enum 
{
YENOM,
YEPRENOM,
YECIN,
YEEMAIL,
YENUM_DE_TELEPHONE,
YEETABLISSEMENT_DU_DON,
YEADRESSE,
YEJOUR,
YEMOIS,
YEANNEE,
YESEXE,
YCOLUMNS
};
//affichage


//treeviewwww2222


 int afficherdv(char * don , char  etablissement[] , char jour[] , char mois[] , char annee[])
    {
int tr=0;
inf p;
 FILE *f=fopen("infirmier.txt", "r");
 FILE *f2=fopen("rdv.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe)!=EOF)
          {
              if((strcmp(p.etablissement_du_don,etablissement)==0)&&(strcmp(p.ddn.jour,jour)==0)&&(strcmp(p.ddn.mois,mois)==0)&&(strcmp(p.ddn.annee,annee)==0))
              {
                  fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",p.nom,p.prenom,p.CIN,p.email,p.num_de_telephone,p.etablissement_du_don,p.adresse,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.sexe);
                  tr++;
             
             }
          }
         fclose(f);
         fclose(f2);
return tr;

       }
    }

enum 
{
FEIDf,
FEJOURf,
FEMOISf,
FEANNEEf,
FEETSf,
FEHf,

FCOLUMNS
};
//affichage222
void afficher_rdv(GtkWidget *liste,char * infirmier ){

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  RDV p;
 //p.id,p.ddn.jour,p.ddn.mois,p.ddn.annee,p.Ets,p.h
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",FEIDf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",FEJOURf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",FEMOISf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",FEANNEEf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text", FEETSf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("h",renderer,"text",FEHf,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



}





//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(FCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(infirmier,"r");
 if(f==NULL)
{
  return;
}
else if(f!=NULL)
{
f=fopen(infirmier,"a+");
while(fscanf(f,"%s %s %s %s %s %s  \n",p.id,p.jour,p.mois,p.annee,p.Ets,p.h)!=EOF)

{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,& iter,FEIDf,p.id,FEJOURf,p.jour,FEMOISf,p.mois,FEANNEEf,p.annee,FEETSf,p.Ets,FEHf,p.h,-1) ;
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
   
}}



//tache de calcul 
//tache1

int listeRDV(char rendez_vous[], char *ETS, char *jour, char *mois , char *annee)
    {
int nbrdv=0;
RDV p;
 FILE *f=fopen("rendez-vous.txt", "r");
 FILE *f2=fopen("rdv.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s  \n",p.id,p.jour,p.mois,p.annee,p.Ets,p.h)!=EOF)
          {
              if((strcmp(p.Ets,ETS)==0)&&(strcmp(p.jour,jour)==0)&&(strcmp(p.mois,mois)==0)&&(strcmp(p.annee,annee)==0))
              {
                  fprintf(f2,"%s %s %s %s %s %s  \n",p.id,p.jour,p.mois,p.annee,p.Ets,p.h);
                  nbrdv++;
             
            }
          }
         fclose(f);
         fclose(f2);
return nbrdv;

       }

}


//tache2
int nbETS( char ETS[])
    {
etab p;
int nbrets=0;
 FILE *f=fopen(ETS, "r");
 FILE *f2=fopen("ets.txt", "w");
if(f!=NULL&& f2!=NULL)
       {
            while(fscanf(f,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable)!=EOF)
          {
                  fprintf(f2,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable);
                  nbrets++;
          }
         fclose(f);
         fclose(f2);
return nbrets;

       }
}
//tache3
float moyRDV_ETS (char nomFichier[], char *jour, char *mois , char *annee)
    {
int nbrdv=0,nbrets;
float i=0.0;

RDV p;
 FILE *f=fopen(nomFichier, "r");
 //FILE *f2=fopen("rdv.txt", "w");
if(f!=NULL/*&& f2!=NULL*/)
       {
            while(fscanf(f,"%s %s %s %s %s %s  \n",p.id,p.jour,p.mois,p.annee,p.Ets,p.h)!=EOF)
          {
              if((strcmp(p.jour,jour)==0)&&(strcmp(p.mois,mois)==0)&&(strcmp(p.annee,annee)==0))
              {
                  
                  nbrdv++;
             
             }
          }
nbrets= nbETS("etablissement.txt");
i=nbrdv/nbrets;
         fclose(f);
         //fclose(f2);
return i ;

       }
}
///////////////////////////////////////////////////firaaaaaaaaaaaaaaaaaaaaaas//////////////////////////////////////////////////////////////////////////////



bool chercherRDV(char *nomFichier, RDV r)
{
    FILE *f = fopen(nomFichier, "r");
    RDV d;
    bool trouve = false;

    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h) != EOF)
        {
            if (strcmp(d.id, r.id) == 0)
            {
                trouve = true;
                break;
            }
        }
        fclose(f);
    }
    return trouve;
}

RDV chercheraff(char * filename, char * id)
{ 
    RDV e;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f, "%s %s %s %s %s %s\n", e.id, e.jour, e.mois, e.annee, e.Ets, e.h) != EOF)
        {
            if(strcmp(e.id, id)==0)
                tr=1;// 1 si on trrouve la valeur 
        }
    }
    fclose(f);
    if(tr==0){
       strcpy( e.id,"-1");
       
      }
    return e;
}


int ajouterRDV(char *nomFichier, RDV r)
{
    RDV d;
    int rdv_sur_le_meme_jour = 0;
    FILE *f = fopen(nomFichier, "a+");

    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 0;
    }

    rewind(f);
    while (fscanf(f, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h) != EOF)
    {
        if (strcmp(d.id, r.id) == 0)
        {
            fclose(f);
            return -1;
        }
        if (strcmp(d.jour, r.jour) == 0 && strcmp(d.mois, r.mois) == 0 && strcmp(d.annee, r.annee) == 0)
        {
            rdv_sur_le_meme_jour++;
        }
    }
    if (rdv_sur_le_meme_jour >= 3)
    {
        fclose(f);
        return -2;
    }

    fprintf(f, "%s %s %s %s %s %s\n", r.id, r.jour, r.mois, r.annee, r.Ets, r.h);
    fclose(f);
    return 1;
}

int modifierRDV(char *nomFichier, RDV r) {
    FILE *f, *f2;
    RDV d;
    int trouve = 0;

    f = fopen(nomFichier, "r");
    f2 = fopen("temp.txt", "w");

    if (f == NULL && f2 == NULL) {
        if (f) fclose(f);
        if (f2) fclose(f2);
        return 0;
    }

    while (fscanf(f, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h) == 6) {
        if (strcmp(d.id, r.id) == 0) {
            fprintf(f2, "%s %s %s %s %s %s\n", r.id, r.jour, r.mois, r.annee, r.Ets, r.h);
            trouve = 1;
        } else {
            fprintf(f2, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h);
        }
    }

    fclose(f);
    fclose(f2);

    if (trouve) {
        remove(nomFichier);
        rename("temp.txt", nomFichier);
        return 1;
    } else {
        remove("temp.txt");
        return 0;
    }
}

int supprimerRDV(char *nomFichier, char *idToDelete)
{
    RDV d;
    bool trouve = false;
    FILE *f = fopen(nomFichier, "r");
    FILE *f2 = fopen("temp.txt", "w");

    if (f == NULL && f2 == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        if (f)
            fclose(f);
        if (f2)
            fclose(f2);
        return 0;
    }

    while (fscanf(f, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h) != EOF)
    {
        if (strcmp(d.id, idToDelete) != 0)
        {
            fprintf(f2, "%s %s %s %s %s %s\n", d.id, d.jour, d.mois, d.annee, d.Ets, d.h);
        }
        else
        {
            trouve = true;
        }
    }

    fclose(f);
    fclose(f2);

    if (trouve)
    {
        remove(nomFichier);
        rename("temp.txt", nomFichier);
        return 1;
    }
    else
    {
        remove("temp.txt");
        printf("Erreur: Aucun RDV avec l'ID %s n'a été trouvé pour la suppression.\n", idToDelete);
        return 0;
    }
}

int regionn(char *filename, char *id) {
    int tr = -1;
    char c[50];
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, "%49s", c) == 1) { // safer with width specifier to avoid buffer overrun
            tr++; // Increment tr for every string read
            if (strcmp(c, id) == 0) {
                fclose(f); // important to close the file here
                return tr; // Return the position where id was found (1-indexed)
            }
        }
        fclose(f); // Close file after completely reading it if id was not found
    } else {
        perror("File opening failed"); // optional: print an error message if the file isn't opened
        return -1; // return -1 to signify that the file couldn't be opened
    }
    return 0; // Return 0 to signify that id was not found in the file
}


enum
{
    FEID,
    FEETS,
    FEJOUR,
    FEMOIS,
    FEANNEE,
    FEH,
    FFCOLUMNS,
};




void afficher_his(GtkWidget * liste)
{

RDV p ;
GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
store=NULL ;

FILE *f;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",FEID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",FEETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",FEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",FEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text", FEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("h",renderer,"text",FEH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(FFCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("rendez-vous.txt","r");

if(f!=NULL)
{
f=fopen("rendez-vous.txt","a+") ;
while(fscanf(f,"%s %s %s %s %s %s\n",p.id, p.jour, p.mois, p.annee, p.Ets, p.h)!=EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,& iter,EID,p.id,FEJOUR,p.jour,FEMOIS,p.mois,FEANNEE,p.annee,FEETS,p.Ets,FEH,p.h,-1) ;
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}}}





void afficher_cr(char roleRCH[] ,char jourRCH[],char moisRCH[],char anneeRCH[],GtkWidget * liste)
{



GtkCellRenderer *renderer;
  GtkTreeViewColumn *fcolumn;
  GtkTreeIter iter;
  GtkListStore *store;


    char id[10];
    char jour[3];
    char mois[3];
    char annee[5];
    char Ets[50];
    char h[6];
store=NULL ;

FILE *f;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("id",renderer,"text",FEID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);


renderer=gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",FEETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);


renderer=gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);



renderer = gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",FEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);



renderer=gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("annee",renderer,"text", FEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);


renderer=gtk_cell_renderer_text_new();
fcolumn=gtk_tree_view_column_new_with_attributes("h",renderer,"text",FEH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),fcolumn);

}


//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(FCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("rendez-vous.txt","r");

if(f==NULL)
{
    return;
}
else{
f=fopen("rendez-vous.txt","a+") ;
while(fscanf(f,"%s %s %s %s %s %s\n",id, jour, mois, annee, Ets, h)!=EOF)
{
if ((strcmp(roleRCH,Ets)==0) && strcmp(jourRCH,jour)==0 && strcmp(moisRCH,mois)==0 && strcmp(anneeRCH,annee)==0)
{


gtk_list_store_append (store,&iter);
gtk_list_store_set (store,& iter,FEID,id,FEJOUR,jour,FEMOIS,mois,FEANNEE,annee,FEETS,Ets,FEH,h,-1) ;
}}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}}






void vider_treeview_firas(GtkWidget * liste)
{


GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
char id[10];
    char jour[3];
    char mois[3];
    char annee[5];
    char Ets[50];
    char h[6];
store=NULL ;

FILE *f;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",FEID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",FEETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",FEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",FEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text", FEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("h",renderer,"text",FEH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}




//renderer=gtk_cell_renderer_text_new();
store=gtk_list_store_new(FFCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}





























































