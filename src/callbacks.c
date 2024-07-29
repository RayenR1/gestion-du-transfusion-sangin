#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "etablissement.h"
/////global ala/////
int H_F_stat[2]={0,0};
/////global raslen////
int urgence1 ;
int status1;
int urgence2;
int status2;
char filename2[50]="gestionDemande.txt";


void on_connexion_admin_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    GtkWidget *input1, *input2,*fenetre_login;
   etab p;



    fenetre_login=lookup_widget(objet_graphique,"fixedadmin");
    input1 =lookup_widget(objet_graphique, "entry_login_admin");
    input2 =lookup_widget(objet_graphique, "entry_mot_de_passe_admin");
    
    strcpy(p.region,gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(p.numero,gtk_entry_get_text(GTK_ENTRY(input2)));
    int x = strcmp("admin", p.region);
    int y = strcmp("admin",p.numero);

    if (x == 0 && y == 0) {
        GtkWidget *menu_espace_admin, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
            menu_espace_admin = create_menu_espace_admin();
            gtk_widget_show(menu_espace_admin);
}
}


void
on_connexion_donneur_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *input1, *input2,*fenetre_login;
    char ch[20];
    fenetre_login=lookup_widget(objet_graphique,"fixeddonneur");
    input1=lookup_widget(objet_graphique, "entry_login_donneur");
   input2 =lookup_widget(objet_graphique, "entry_mot_de_passe_donneur");
    utl e;
    strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
   // strcpy(p.numero,gtk_entry_get_text(GTK_ENTRY(input2)));
    //int x = strcmp("admin", p.region);
   // int y = strcmp("admin",p.numero);
   e=chercher("utl.txt",ch);     

  if (strcmp(e.carte_d_identite,"-1")!=0&&strcmp(e.poste,"donneur")==0) {
        GtkWidget *gestion_donneur, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
            gestion_donneur = create_gestion_donneur();
            gtk_widget_show(gestion_donneur);
}
}





void
on_connexion_medecin_bio_clicked      (GtkWidget *objet_graphique, gpointer user_data)
{
 /*GtkWidget *input1, *input2,*fenetre_login;
    char ch[20];
    fenetre_login=lookup_widget(objet_graphique,"fixedmedecin_bio");
    input1=lookup_widget(objet_graphique, "entry_login_medecin_bio");
   input2 =lookup_widget(objet_graphique, "entry_mot_de_pass_medecin_bio");
    utl e;
    strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
    e=chercher("utl.txt",ch);     
    //poste*/
 // if (strcmp(e.carte_d_identite,"-1")!=0) {
      /* GtkWidget *gestionmedecin, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
          gestionmedecin= create_gestionmedecin();
  gtk_widget_show (gestionmedecin);*/
//}

}
void
on_connexionska_clicked (GtkWidget       *objet_graphique,gpointer         user_data)
{
GtkWidget *input1, *input2,*fenetre_login;
    char ch[20];
    fenetre_login=lookup_widget(objet_graphique,"fixedmedecin_bio");
    input1=lookup_widget(objet_graphique, "entry_login_medecin_bio");
   input2 =lookup_widget(objet_graphique, "entry_mot_de_pass_medecin_bio");
    utl e;
    strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
    e=chercher("utl.txt",ch);     
    //poste*/
 if (strcmp(e.carte_d_identite,"-1")!=0&&strcmp(e.poste,"medecin")==0) {
       GtkWidget *gestionmedecin, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
          gestionmedecin= create_gestionmedecin();
  gtk_widget_show (gestionmedecin);
}

}

void
on_connexion_responsable_clicked       (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *input1, *input2,*fenetre_login;
    char ch[20];
    fenetre_login=lookup_widget(objet_graphique,"fixedresponsable");
    input1=lookup_widget(objet_graphique, "entry_login_responsable");
   input2 =lookup_widget(objet_graphique, "entry_mot_de_passe_responsable");
    utl e;
    strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
    e=chercher("utl.txt",ch);     
    //poste*/
 if (strcmp(e.carte_d_identite,"-1")!=0) {
       GtkWidget *GDaffiche, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
          GDaffiche= create_GDaffiche();
          gtk_widget_show (GDaffiche);
}
}


void
on_acceder_a_utilisateur_clicked       (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *menu_espace_admin, *gestion_d_utilisateur;

       
            menu_espace_admin = lookup_widget(objet_graphique, "menu_espace_admin");
            gtk_widget_hide(menu_espace_admin);
            gestion_d_utilisateur = create_gestion_d_utilisateur();
            gtk_widget_show(gestion_d_utilisateur);
}


void
on_acceder_au_etablissement_clicked    (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *menu_espace_admin, *gestion_d_etablissement;

       
            menu_espace_admin = lookup_widget(objet_graphique, "menu_espace_admin");
            gtk_widget_hide(menu_espace_admin);
            gestion_d_etablissement = create_gestion_d_etablissement_();
            gtk_widget_show(gestion_d_etablissement);
            
}


void
on_RJajouter__clicked                 (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *input1, *input2, *input3, *input4 , *input5, *input6;
GtkWidget *fenetre_ajout ;
GtkWidget *output;
GtkWidget* comboboxentry2=lookup_widget(objet_graphique,"comboboxentry2");
GtkWidget* comboboxentry_etab_a_supprimer_RJ=lookup_widget(objet_graphique,"comboboxentry_etab_a_supprimer_RJ");//comboboxentry_etab_a_supprimer_RJ
int x;
etab p,e;
int v1,v2,v3,v4,i,per;
fenetre_ajout=lookup_widget(objet_graphique,"fixedajouter");
input1=lookup_widget(objet_graphique,"entry_nom_etablissement");//nom_etab
input2=lookup_widget(objet_graphique,"combobox_region");//region
input3=lookup_widget(objet_graphique,"spinbuttoncapaciteRJ");//capacite
input4=lookup_widget(objet_graphique,"entry_adresse_RJ");//adress
input5=lookup_widget(objet_graphique,"entrynumero_RJ");//numero
input6=lookup_widget(objet_graphique,"entry_responsableRJ");//responsable
output=lookup_widget(objet_graphique,"erreur_de_saisie_ajouter_RJ");
strcpy(p.nom_etablissement,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(p.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input2)));
snprintf(p.capacite, sizeof(p.capacite), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)));
strcpy(p.adress,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.responsable,gtk_entry_get_text(GTK_ENTRY(input6)));

v1=1;
i=0;
if(strlen(p.nom_etablissement)!=0){
while(i<strlen(p.nom_etablissement)&&v1==1){
if(p.nom_etablissement[i]<'a'||'z'<p.nom_etablissement[i])
{v1=0;}
i++;
}
}else {v1=0;}
if(v1==0){gtk_label_set_text(GTK_LABEL(output),"saisie du nom ETAB inaceptable ");}
 
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
if(v3==0){gtk_label_set_text(GTK_LABEL(output),"saisie du numero inaceptable ");}
   //controle du saisie responsable 
v4=1;
i=0;
if(strlen(p.responsable)!=0){
while(i<strlen(p.responsable)&&v4==1){ 
if(p.responsable[i]<'a'||'z'<p.responsable[i])
{v4=0;}
i++;
}}else v4=0;
if(v4==0){gtk_label_set_text(GTK_LABEL(output),"saisie du responsable inaceptable ");}
//region
v2=1;
if(strlen(p.adress)==0){v2=0;}
if(v2==0){gtk_label_set_text(GTK_LABEL(output),"il faut remplir adress ");}

    //enregistrement dans le fichier ou erreur 
per=unique("etablissement.txt", p.nom_etablissement);
       if(v1==1&&v2==1&&v3==1&&v4==1&&per==0){
   x=ajouterj("etablissement.txt",p);

}


//clear 

if (x == 1)
    {
        
        gtk_entry_set_text(GTK_ENTRY(input1), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(input2), -1); // Clear the combo box
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), 0);
        gtk_entry_set_text(GTK_ENTRY(input4), "");
        gtk_entry_set_text(GTK_ENTRY(input5), "");
        gtk_entry_set_text(GTK_ENTRY(input6), "");
    gtk_label_set_text(GTK_LABEL(output),"ajout avec succse");

        
      
    }
if(per==1/*strcmp(p.nom_etablissement,"-1")!=0*/){
gtk_label_set_text(GTK_LABEL(output),"ce nom detablissement deja existe");
}
}


void
on_RJmodifier_clicked                 (GtkWidget *objet_graphique, gpointer user_data)
{
int v1,v2,v3,v4,v5,x,i;
GtkWidget *input1, *input2, *input3, *input4 , *input5, *input6;
etab e,p;
GtkWidget *output;
//input1=lookup_widget(objet_graphique,"entry_nouv_nom_etab_RJ");//nom etab
input2=lookup_widget(objet_graphique,"comboboxentrynov_region_RJ");//region
input3=lookup_widget(objet_graphique,"spinbutton_nouv_capacite_RJ");//capacite
input5=lookup_widget(objet_graphique,"entry_nouv_numero_");//numero
input6=lookup_widget(objet_graphique,"entrey_nouv_responable__RJ");//responsable
input4=lookup_widget(objet_graphique,"entrynvadressrj");//adress
output=lookup_widget(objet_graphique,"erreur_modif_RJ");
GtkWidget* comboboxentry2=lookup_widget(objet_graphique,"comboboxentry2");


//strcpy(p.nom_etablissement,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(p.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input2)));
snprintf(p.capacite, sizeof(p.capacite), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)));
strcpy(p.adress,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.responsable,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.nom_etablissement,gtk_entry_get_text(GTK_ENTRY(comboboxentry2)));
e=chercherj("etablissement.txt",p.nom_etablissement);

v1=1;
i=0;
if(strlen(p.nom_etablissement)!=0){
while(i<strlen(p.nom_etablissement)&&v1==1){
if(p.nom_etablissement[i]<'a'||'z'<p.nom_etablissement[i])
{v1=0;}
i++;
}
}else {v1=0;}
if(v1==0){gtk_label_set_text(GTK_LABEL(output),"saisie du nom ETAB inaceptable ");}
 
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
if(v3==0){gtk_label_set_text(GTK_LABEL(output),"saisie du numero inaceptable ");}
   //controle du saisie responsable 
v4=1;
i=0;
if(strlen(p.responsable)!=0){
while(i<strlen(p.responsable)&&v4==1){ 
if(p.responsable[i]<'a'||'z'<p.responsable[i])
{v4=0;}
i++;
}}else v4=0;
if(v4==0){gtk_label_set_text(GTK_LABEL(output),"saisie du responsable inaceptable ");}
//region
v2=1;
if(strlen(p.adress)==0){v2=0;}
if(v2==0){gtk_label_set_text(GTK_LABEL(output),"il faut remplir adress ");}

    //enregistrement dans le fichier ou erreur 

       if(v2==1&&v3==1&&v4==1){

x=modifierj( "etablissement.txt", e.nom_etablissement, p);


}


//clear 

if (x == 1)
    {
        
        gtk_entry_set_text(GTK_ENTRY(input1), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(input2), -1); // Clear the combo box
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), 0);
        gtk_entry_set_text(GTK_ENTRY(input4), "");
        gtk_entry_set_text(GTK_ENTRY(input5), "");
        gtk_entry_set_text(GTK_ENTRY(input6), "");
    gtk_label_set_text(GTK_LABEL(output),"modif avec succse");

       gtk_entry_set_text(GTK_ENTRY(comboboxentry2)," "); 
      
    }








}



void
on_affiche_donner_pour_modifier_RJ_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
int per,f;
int j;
etab p,e,n;
GtkWidget *output1, *output2, *output3, *output4 , *output5, *output6;
//output1=lookup_widget(objet_graphique,"entry_nouv_nom_etab_RJ");//nom etab
output2=lookup_widget(objet_graphique,"comboboxentrynov_region_RJ");//region
output3=lookup_widget(objet_graphique,"spinbutton_nouv_capacite_RJ");//capacite
output4=lookup_widget(objet_graphique,"entry_nouv_numero_");//numero
output5=lookup_widget(objet_graphique,"entrey_nouv_responable__RJ");//responsable
output6=lookup_widget(objet_graphique,"entrynvadressrj");//adress
GtkWidget* comboboxentry2=lookup_widget(objet_graphique,"comboboxentry2");
strcpy(p.nom_etablissement,gtk_entry_get_text(GTK_ENTRY(comboboxentry2)));
e=chercherj("etablissement.txt",p.nom_etablissement);
f=region("region.txt",e.region);
j=atoi(e.capacite);
gtk_entry_set_text(GTK_ENTRY(comboboxentry2),e.nom_etablissement);
gtk_combo_box_set_active(GTK_COMBO_BOX(output2), f);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output3), j);
gtk_entry_set_text(GTK_ENTRY(output4),e.numero);
gtk_entry_set_text(GTK_ENTRY(output5),e.responsable);
gtk_entry_set_text(GTK_ENTRY(output6),e.adress);
}


void
on_supprimer_etab_RJ_clicked      (GtkWidget *objet_graphique, gpointer user_data)
{
etab p;
int x;
//GtkWidget *gestion_d_etablissement;
GtkWidget *input1;
GtkWidget *output1;
output1=lookup_widget(objet_graphique,"erreuresupprj");
input1=lookup_widget(objet_graphique,"comboboxentry_etab_a_supprimer_RJ");//comboboxentry_etab_a_supprimer_RJ
strcpy(p.nom_etablissement,gtk_entry_get_text(GTK_ENTRY(input1)));

GtkWidget *input2=lookup_widget(objet_graphique,"oui_modif_etab");
//if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2))))
x=supprimerj("etablissement.txt", p.nom_etablissement);
if(x==1){
gtk_label_set_text(GTK_LABEL(output1),"suppresion avec succse");
gtk_entry_set_text(GTK_ENTRY(input1)," ");}
else
gtk_label_set_text(GTK_LABEL(output1),"echec de suppression");



}


void
on_affichage_region_RJ_clicked     (GtkWidget *objet_graphique, gpointer user_data)
{
   GtkWidget *affichage_etablissement_par_region, *gestion_d_etablissement,*treeview_par_region_RJ;

       
            gestion_d_etablissement = lookup_widget(objet_graphique, "gestion_d_etablissement_");
            gtk_widget_hide(gestion_d_etablissement);
            affichage_etablissement_par_region = create_affichage_etablissement_par_region();
            gtk_widget_show(affichage_etablissement_par_region);
            

}

void
on_affichager_capacite_Rj_clicked    (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *affichage_par_capacite, *gestion_d_etablissement;

       
            gestion_d_etablissement = lookup_widget(objet_graphique, "gestion_d_etablissement_");
            gtk_widget_hide(gestion_d_etablissement);
            affichage_par_capacite = create_affichage_par_capacite_();
            gtk_widget_show(affichage_par_capacite);
}


void
on_deconnexion_RJ__clicked         (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *acceuille, *gestion_d_etablissement;
            
              acceuille = create_acceuille();
    gtk_widget_show(acceuille);
            gestion_d_etablissement = lookup_widget(objet_graphique, "gestion_d_etablissement_");
    gtk_widget_hide(gestion_d_etablissement);
          
}


void
on_retour_a_ge_RJ_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *affichage_etablissement_par_region, *gestion_d_etablissement;

       
            affichage_etablissement_par_region = lookup_widget(objet_graphique, "affichage_etablissement_par_region");
            gtk_widget_hide(affichage_etablissement_par_region);
            gestion_d_etablissement = create_gestion_d_etablissement_();
            gtk_widget_show(gestion_d_etablissement);
}


void
on_buttonaffreg_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
         GtkWidget *treeview_par_region_RJ,*affichage_etablissement_par_region;   
         affichage_etablissement_par_region = lookup_widget(objet_graphique, "affichage_etablissement_par_region");
         treeview_par_region_RJ=lookup_widget(affichage_etablissement_par_region,"treeview_par_region_RJ"); 
         char ch[50];  
         etab p;  
         GtkWidget *output1;
         output1=lookup_widget(objet_graphique,"cheraffrj");   
         GtkWidget *input1 =lookup_widget(objet_graphique, "comboboxentryaffichage_region_RJ");
         strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
         gtk_label_set_text(GTK_LABEL(output1),"ce nom n existe pas");
         p=chercherj("etablissement.txt",ch);
        if(p.nom_etablissement!="-1"){
         ETSparRegion("etablissement.txt", ch);
         afficher_etab(treeview_par_region_RJ,"affichereg.txt");
     }else{gtk_label_set_text(GTK_LABEL(output1),"ce nom n existe pas");}
}





void
on_retouraespace_etab_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *affichage_par_capacite, *gestion_d_etablissement;

       
            affichage_par_capacite = lookup_widget(objet_graphique, "affichage_par_capacite_");
            gtk_widget_hide(affichage_par_capacite);
            gestion_d_etablissement = create_gestion_d_etablissement_();
            gtk_widget_show(gestion_d_etablissement);
}



void
on_radiobuttontri1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttontri2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_capaciterj_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
int mode;
  GtkWidget *affichage_par_capacite_ = lookup_widget(objet_graphique, "affichage_par_capacite_");  
GtkWidget *treeview_par_region_RJ=lookup_widget(affichage_par_capacite_,"treeview2"); 
GtkWidget *input1= lookup_widget(objet_graphique, "radiobuttontri1");
GtkWidget *input2= lookup_widget(objet_graphique, "radiobuttontri2");

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input1)))//buton radio 
mode=1;
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2)))//buton radio 
mode=2;

ETSTriecapacite ("etablissement.txt",mode);
afficher_etab(treeview_par_region_RJ,"afficheparcap.txt");
}


void
on_radiobutton_homme_ABBr_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ABBR_ajouter_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{	GtkWidget*  poste;
	GtkWidget* nom_utilisateur;
	GtkWidget* prenom_utilisateur;
	GtkWidget* etablissement;
	GtkWidget* email;
	GtkWidget* carte_d_identite;
	GtkWidget* numero_de_telephone;
	GtkWidget* jour;
	GtkWidget* mois;
	GtkWidget* annee;
	GtkWidget* treeview_affich_parposte;
	GtkWidget* treeview_affiche_par_sexe;
	GtkWidget* homme;
	GtkWidget* femme;
       GtkWidget* alert;
        utl p;
        int x;
	
	alert=lookup_widget(objet_graphique,"erreure_ajout_ABBR");
	poste=lookup_widget(objet_graphique,"comboboxposte_utilisateur_ABBR");
	nom_utilisateur=lookup_widget(objet_graphique,"entrynom_Abbr");
if (nom_utilisateur == NULL) {
    g_warning("Failed to find nom_utilisateur widget");
    return;  // or handle the error appropriately
}

	prenom_utilisateur=lookup_widget(objet_graphique,"entry_prenom_Abbr_");
if (prenom_utilisateur == NULL) {
    g_warning("Failed to find or invalid prenom_utilisateur widget");
    return;  // or handle the error appropriately
}


	etablissement=lookup_widget(objet_graphique,"comboboxentry_etablissement_ABBR");
if (etablissement == NULL) {
    g_warning("Failed to find etablissement widget");
    return;  // or handle the error appropriately
}
	email=lookup_widget(objet_graphique,"entry_email_ABBR");
if (email == NULL) {
    g_warning("Failed to find email widget");
    return;  // or handle the error appropriately
}

	carte_d_identite=lookup_widget(objet_graphique,"entry_cin_abrr");
if (carte_d_identite == NULL) {
    g_warning("Failed to find carte_d_identite widget");
    return;  // or handle the error appropriately
}
	numero_de_telephone=lookup_widget(objet_graphique,"entry_numero_ABBR");
if (numero_de_telephone == NULL) {
    g_warning("Failed to find numero_de_telephone widget");
    return;  // or handle the error appropriately
}
	jour=lookup_widget(objet_graphique,"spinbutton_ddn_jour_Abbr");
if (jour == NULL) {
    g_warning("Failed to find jour widget");
    return;  // or handle the error appropriately
}
	mois=lookup_widget(objet_graphique,"spinbutton_ddn_mois_Abbr");
if (mois == NULL) {
    g_warning("Failed to find mois widget");
    return;  // or handle the error appropriately
}
	annee=lookup_widget(objet_graphique,"spinbutton_ddn_anne_Abbr");
if (annee == NULL) {
    g_warning("Failed to find annee widget");
    return;  // or handle the error appropriately
}
	homme=lookup_widget(objet_graphique,"radiobutton_homme_ABBr");
if (homme == NULL) {
    g_warning("Failed to find homme widget");
    return;  // or handle the error appropriately
}
	femme=lookup_widget(objet_graphique,"radiobutton_femme");
if (femme == NULL) {
    g_warning("Failed to find femme widget");
    return;  // or handle the error appropriately
}
	
	strcpy(p.nom_utilisateur,gtk_entry_get_text(GTK_ENTRY(nom_utilisateur)));
	strcpy(p.prenom_utilisateur,gtk_entry_get_text(GTK_ENTRY(prenom_utilisateur)));
	strcpy(p.numero_de_telephone,gtk_entry_get_text(GTK_ENTRY(numero_de_telephone)));
	strcpy(p.carte_d_identite,gtk_entry_get_text(GTK_ENTRY(carte_d_identite)));
 	strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email)));
	snprintf(p.ddn.jour, sizeof(p.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
	snprintf(p.ddn.mois, sizeof(p.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
	snprintf(p.ddn.annee, sizeof(p.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
	
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
		strcpy(p.sexe,"homme");
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
		strcpy(p.sexe,"femme");
poste= lookup_widget(objet_graphique, "comboboxposte_utilisateur_ABBR");
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX (poste)));
	
	

strcpy(p.etablissement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etablissement)));
 

	if((strlen(gtk_entry_get_text(GTK_ENTRY(carte_d_identite)))==8 )  &&
(strcmp("",gtk_entry_get_text(GTK_ENTRY(nom_utilisateur)))!=0)&&
(strcmp("",gtk_entry_get_text(GTK_ENTRY(prenom_utilisateur)))!=0) && 
(strcmp("",gtk_entry_get_text(GTK_ENTRY(numero_de_telephone)))!=0 ) &&
 (strcmp("",gtk_entry_get_text(GTK_ENTRY(email)))!=0 ))
{
	x=ajouter("utl.txt", p);
}
else
	
gtk_label_set_text(GTK_LABEL(alert), "erreur d'ajout");
if(x==1)
gtk_label_set_text(GTK_LABEL(alert), "ajouter avec succes");
else
gtk_label_set_text(GTK_LABEL(alert), "erreur d'ajout");
	/*afficher_utl_poste(treeview_affich_parposte,"utl.txt");
	afficher_utl_Sex(treeview_affiche_par_sexe,"utl.txt");*/

        }


void
on_affichage_donner_a_modifier_ABBr_clicked
                                        (GtkWidget *objet_graphique, gpointer user_data)
{
	GtkWidget*  poste= lookup_widget(objet_graphique, "comboboxentrynouv_poste");
	GtkWidget* nom_utilisateur= lookup_widget(objet_graphique, "entrynouv_nom");
	GtkWidget* prenom_utilisateur= lookup_widget(objet_graphique, "entrynouv_prenom_abbr");
	GtkWidget* etablissement= lookup_widget(objet_graphique, "comboboxentry_nouv_etab_abbr");
	GtkWidget* email= lookup_widget(objet_graphique, "entry_nouv_email_ABBR");
	GtkWidget* cin= lookup_widget(objet_graphique, "entrynouv_cin_abbr");
	GtkWidget* numero_de_telephone= lookup_widget(objet_graphique, "entry_nouv_numero_abbr");
	GtkWidget* jour= lookup_widget(objet_graphique, "spinbuttonnouv_ddn_jour");
	GtkWidget* mois= lookup_widget(objet_graphique, "spinbutton_nouv_ddn_mois");
	GtkWidget* annee= lookup_widget(objet_graphique, "spinbuttonnouv_ddn_anne");
	GtkWidget* homme= lookup_widget(objet_graphique, "radiobutton_nouv_hommme");
	GtkWidget* femme= lookup_widget(objet_graphique, "radiobutton_nouv_femme");
	GtkWidget* alert=lookup_widget(objet_graphique,"ancien_cin_Abbr");
	char CIN[10];
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(cin)));
   

   	utl found_user = chercher("utl.txt",CIN);
        if (strcmp(found_user.carte_d_identite , "-1")!=0) {
       
	int P,E,j,m,a;
	P= Poste(found_user.poste);
	
	E=Etablissement(found_user.etablissement);
        gtk_entry_set_text(GTK_ENTRY(nom_utilisateur), found_user.nom_utilisateur);
        gtk_entry_set_text(GTK_ENTRY(prenom_utilisateur), found_user.prenom_utilisateur);
        gtk_entry_set_text(GTK_ENTRY(email), found_user.email);
	gtk_entry_set_text(GTK_ENTRY(numero_de_telephone), found_user.numero_de_telephone);
	
	j=atoi(found_user.ddn.jour);
	m=atoi(found_user.ddn.mois);
	a=atoi(found_user.ddn.annee);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), j);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),m);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), a);


	gtk_combo_box_set_active(GTK_COMBO_BOX(poste), P);
	gtk_combo_box_set_active(GTK_COMBO_BOX(etablissement), E);

	if(strcmp(found_user.sexe,"homme")==0){
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme),TRUE);
	}else
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme),TRUE);

       
	
        
    } else if (strcmp(found_user.carte_d_identite , "-1")==0)  {
	gtk_label_set_text(GTK_LABEL(alert), "erreur");
        
        


	gtk_entry_set_text(GTK_ENTRY(nom_utilisateur), "");
        gtk_entry_set_text(GTK_ENTRY(prenom_utilisateur), "");
        gtk_entry_set_text(GTK_ENTRY(email), "");
	gtk_entry_set_text(GTK_ENTRY(cin), "");
	gtk_entry_set_text(GTK_ENTRY(numero_de_telephone), "");
	
	

        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), 0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois), 0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), 0);
        gtk_combo_box_set_active(GTK_COMBO_BOX(poste), 0);
	gtk_combo_box_set_active(GTK_COMBO_BOX(etablissement), 0);

    }
	
	
}


void
on_radiobutton_nouv_hommme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_nouv_femme_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ABBR_modifier_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
	
	GtkWidget* poste=lookup_widget(objet_graphique,"comboboxentrynouv_poste");
	GtkWidget* nom_utilisateur=lookup_widget(objet_graphique,"entrynouv_nom");
	GtkWidget* prenom_utilisateur=lookup_widget(objet_graphique,"entrynouv_prenom_abbr");
	GtkWidget* etablissement=lookup_widget(objet_graphique,"comboboxentry_nouv_etab_abbr");
	GtkWidget* email=lookup_widget(objet_graphique,"entry_nouv_email_ABBR");
	GtkWidget* carte_d_identite=lookup_widget(objet_graphique,"entrynouv_cin_abbr");
	GtkWidget* numero_de_telephone=lookup_widget(objet_graphique,"entry_nouv_numero_abbr");
	GtkWidget* jour=lookup_widget(objet_graphique,"spinbuttonnouv_ddn_jour");
	GtkWidget* mois=lookup_widget(objet_graphique,"spinbutton_nouv_ddn_mois");
	GtkWidget* annee=lookup_widget(objet_graphique,"spinbuttonnouv_ddn_anne");
	
	GtkWidget* homme=lookup_widget(objet_graphique,"radiobutton_nouv_hommme");
	GtkWidget* femme=lookup_widget(objet_graphique,"radiobutton_nouv_femme");
        utl nouv;
	int v;
	
	
	
	strcpy(nouv.nom_utilisateur,gtk_entry_get_text(GTK_ENTRY(nom_utilisateur)));
	strcpy(nouv.prenom_utilisateur,gtk_entry_get_text(GTK_ENTRY(prenom_utilisateur)));
	strcpy(nouv.carte_d_identite,gtk_entry_get_text(GTK_ENTRY(carte_d_identite)));
	strcpy(nouv.numero_de_telephone,gtk_entry_get_text(GTK_ENTRY(numero_de_telephone)));
	strcpy(nouv.email,gtk_entry_get_text(GTK_ENTRY(email)));  
	





        snprintf(nouv.ddn.jour, sizeof(nouv.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
	snprintf(nouv.ddn.mois, sizeof(nouv.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
	snprintf(nouv.ddn.annee, sizeof(nouv.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
	
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
		strcpy(nouv.sexe,"homme");
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
		strcpy(nouv.sexe,"femme");

	//strcpy(nouv.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX (poste)));
//strcpy(nouv.poste,"medecin");


   GtkWidget *entry_widget_modifier = gtk_bin_get_child(GTK_BIN(poste));
    const char *entry_text_modifier = gtk_entry_get_text(GTK_ENTRY(entry_widget_modifier));

if (entry_text_modifier && strlen(entry_text_modifier) < sizeof(nouv.poste)) {
    // Copy the text into mod_p.role if it's not NULL and within the buffer limit
    strcpy(nouv.poste, entry_text_modifier);
} else {
    // Set mod_p.role to an empty string if entry_text_modifier is NULL or too long
    nouv.poste[0] = '\0';
}
/////////////////////////////////////


 GtkWidget *entry_etab_modifier = gtk_bin_get_child(GTK_BIN(etablissement));
    const char *etab_text_modifier = gtk_entry_get_text(GTK_ENTRY(entry_etab_modifier));

if (etab_text_modifier && strlen(etab_text_modifier) < sizeof(nouv.etablissement)) {
    // Copy the text into mod_p.role if it's not NULL and within the buffer limit
    strcpy(nouv.etablissement, etab_text_modifier);
} else {
    // Set mod_p.role to an empty string if entry_text_modifier is NULL or too long
    nouv.etablissement[0] = '\0';
}
	
	

	//strcpy(nouv.etablissement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etablissement)));
 
	
	
	v=modifier("utl.txt",nouv.carte_d_identite,nouv);
/*if(x==1)
	gtk_label_set_text(GTK_LABEL(alert), "ajouter avec succes");
else
gtk_label_set_text(GTK_LABEL(alert), "erreur d'ajout");*/

	

}


void
on_supprimer_ABBr_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
int x;
char CIN_text[10];
GtkWidget *CIN_SUP = lookup_widget(GTK_WIDGET(button), "entrysuppabbr");

strcpy(CIN_text,gtk_entry_get_text(GTK_ENTRY(CIN_SUP)));
 x=supprimer("utl.txt",CIN_text) ;

}


void
on_affichage_par_sexe_abbr_clicked     (GtkWidget *objet_graphique, gpointer user_data)

{	
		GtkWidget *affichage_par_sexe_abbr, *gestion_d_utilisateur,*treeview_affich_parsexe;
            gestion_d_utilisateur = lookup_widget(objet_graphique, "gestion_d_utilisateur");
            gtk_widget_hide(gestion_d_utilisateur);
            affichage_par_sexe_abbr = create_affichage_par_sexe_abbr();
            gtk_widget_show(affichage_par_sexe_abbr);
            treeview_affich_parsexe=lookup_widget(affichage_par_sexe_abbr,"treeview_affiche_par_sexe"); 
        

}


void
on_affichage_par_role_abbr_clicked     (GtkWidget *objet_graphique, gpointer user_data)
{

		GtkWidget *affichage_par_role_abbr, *gestion_d_utilisateur,*treeview_affich_parposte;
            gestion_d_utilisateur = lookup_widget(objet_graphique, "gestion_d_utilisateur");
            gtk_widget_hide(gestion_d_utilisateur);
            affichage_par_role_abbr = create_affichage_par_role_abbr();
            gtk_widget_show(affichage_par_role_abbr);
	    
            //treeview_affich_parposte=lookup_widget(affichage_par_role_abbr,"treeview_affich_parposte"); 


            

}


void
on_deconnection_abbr_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *acceuille, *gestion_d_utilisateur;
            
              acceuille = create_acceuille();
    gtk_widget_show(acceuille);
            gestion_d_utilisateur = lookup_widget(objet_graphique, "gestion_d_utilisateur");
    gtk_widget_hide(gestion_d_utilisateur);

}


void
on_treeview_affiche_par_sexe_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retoure_abbr_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *gestion_d_utilisateur,*affichage_par_sexe_abbr;
            
            gestion_d_utilisateur = create_gestion_d_utilisateur();
    gtk_widget_show(gestion_d_utilisateur);
           affichage_par_sexe_abbr = lookup_widget(objet_graphique, "affichage_par_sexe_abbr");
    gtk_widget_hide(affichage_par_sexe_abbr);

}


void
on_checkbuttonhommeala_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{H_F_stat[0]=1;}
}


void
on_checkbutton2femmeala_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{H_F_stat[1]=1;}
}



void
on_affichersexeyalbbr_clicked          (GtkWidget *button, gpointer user_data)
{
char ch[10];
GtkWidget *affichage_par_sexe_abbr,*treeview_affich_parsexe;
GtkWidget *fenetre_1;
GtkWidget *fenetre_2;
affichage_par_sexe_abbr = lookup_widget(GTK_WIDGET(button), "affichage_par_sexe_abbr");
        
 GtkWidget *sexe= lookup_widget(GTK_WIDGET(button), "comboboxentrysexe_choix_affiche");
        

   GtkWidget *entry_widget_sexe = gtk_bin_get_child(GTK_BIN(sexe));
   const char *entry_text_sexe = gtk_entry_get_text(GTK_ENTRY(entry_widget_sexe));

if (entry_text_sexe !=NULL) {
   
    strncpy(ch,entry_text_sexe,sizeof(ch)-1);
    ch[sizeof(ch)-1]='\0';
}
      
  fenetre_1 =lookup_widget(GTK_WIDGET(button), "affichage_par_sexe_abbr");
  gtk_widget_hide (fenetre_1);	
   
  fenetre_2=create_affichage_par_sexe_abbr ();
  gtk_widget_show (fenetre_2);
  treeview_affich_parsexe=lookup_widget(fenetre_2,"treeview_affiche_par_sexe");
  vider_treeview_ala(treeview_affich_parsexe);
  afficher_utl_sexeala(ch,treeview_affich_parsexe); 
       

}

void
on_buttonafficherstatistiqueala_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ALERTE = lookup_widget(GTK_WIDGET(button), "labelalertealahf");
GdkColor color;
    float nb_h = 0.0f;
    float nb_f = 0.0f;
    char stat_text[50];
    char stat_text1[50];
    statistique(&nb_h, &nb_f, "utl.txt");

    if (H_F_stat[0] == 1 && H_F_stat[1] == 0 ) {
        sprintf(stat_text, "Hommes: %.2f%%", nb_h);
        gdk_color_parse("blue",&color);
 	gtk_widget_modify_fg(ALERTE,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(ALERTE), stat_text);
	H_F_stat[0] = 0;
    }
    if(H_F_stat[1] == 1 && H_F_stat[0] == 0 ) {
       
        sprintf(stat_text1, "Femmes: %.2f%%", nb_f);
	gdk_color_parse("red",&color);
 	gtk_widget_modify_fg(ALERTE,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(ALERTE), stat_text1);
	 H_F_stat[1] = 0;
    }
	if(H_F_stat[1] == 1 && H_F_stat[0] == 1 ) {
       
       
	gdk_color_parse("red",&color);
 	gtk_widget_modify_fg(ALERTE,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(ALERTE), "error");
	 H_F_stat[1] = 0;
         H_F_stat[0] = 0;
    }
}



void
on_treeview_affich_parposte_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retour_abbr_2_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *gestion_d_utilisateur,*affichage_par_role_abbr;
            
            gestion_d_utilisateur = create_gestion_d_utilisateur();
    gtk_widget_show(gestion_d_utilisateur);
           affichage_par_role_abbr = lookup_widget(objet_graphique, "affichage_par_role_abbr");
    gtk_widget_hide(affichage_par_role_abbr);

}


void
on_afiicheryalbbr_clicked              (GtkWidget *button, gpointer user_data)
{





char ch[10];
GtkWidget *affichage_par_role_abbr,*treeview_affich_parrole;
GtkWidget *fenetre_1;
GtkWidget *fenetre_2;
affichage_par_role_abbr = lookup_widget(GTK_WIDGET(button), "affichage_par_role_abbr");
        
 GtkWidget *role= lookup_widget(GTK_WIDGET(button), "comboboxentry_role_affiche");
        

   GtkWidget *entry_widget_role = gtk_bin_get_child(GTK_BIN(role));
   const char *entry_text_role = gtk_entry_get_text(GTK_ENTRY(entry_widget_role));

if (entry_text_role !=NULL) {
   
    strncpy(ch,entry_text_role,sizeof(ch)-1);
    ch[sizeof(ch)-1]='\0';
}
      
  fenetre_1 =lookup_widget(GTK_WIDGET(button), "affichage_par_role_abbr");
  gtk_widget_hide (fenetre_1);	
   
  fenetre_2=create_affichage_par_role_abbr ();
  gtk_widget_show (fenetre_2);
  treeview_affich_parrole=lookup_widget(fenetre_2,"treeview_affich_parposte");
  vider_treeview_ala(treeview_affich_parrole);
  afficher_utl_roleala(ch,treeview_affich_parrole); 
       

}











void
on__button__yb_supprimer_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_deconnexion_yb_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_retour_yb_1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retoure_2_yb_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sk_ajouter__clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_mdf_ya_sk_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_afficher_donner_skon__clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_affichage_par_type_du_sang_skon_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_affichage_par_quantite_skon_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconnexion_skon_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retoure1_skon_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retoure_2_skon_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}













//////////////////////////////////////////non///////////////////////////////////

void
on_afficher_les_donner_rmm_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Modifier_rm_mmm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supp_rm__clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_dxn_rm__clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}
/////////////////////////////////////////////////RASLEN///////////////////////////////////////////////////////

void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDstatistique,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDstatistique = lookup_widget(button,"GDstatistique");
     GDstatistique = create_GDstatistique();
     gtk_widget_show(GDstatistique);

}



void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDaffiche,*w1,*treeview;
      w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);

}


void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDsupprime = lookup_widget(button,"GDsupprime");
     GDsupprime = create_GDsupprime();
     gtk_widget_show(GDsupprime);
}


void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *GDmodife,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDmodife = lookup_widget(button,"GDmodife");
     GDmodife = create_GDmodife();
     gtk_widget_show(GDmodife);
}



void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *id ,*GDaffiche,*pInfo,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         GDaffiche  = lookup_widget(button,"GDaffiche");
           GDaffiche = create_GDaffiche();
        id = lookup_widget(button,"GDsearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       rechercherDemande(treeview,filename2,id1);

           }
}

void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDajoute,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDajoute = lookup_widget(button,"GDajoute");
     GDajoute = create_GDajoute();
     gtk_widget_show(GDajoute);
}


void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDsupprime,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
   char id1[50];
   GDsupprime = lookup_widget(button,"GDsupprime");
           GDsupprime = create_GDsupprime();
   id = lookup_widget(button,"GDidEntrySupprimer"); 
    label = lookup_widget(button,"GDcontroleSaisiSupprimer");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
        if(strcmp(id1,"")==0 ){
      
           b=0;
             }
                            if(b == 1){
       int t =  supprimerDemande(filename2,id1);
       if(t == 1){
      
          
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDsupprime);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
          


        
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Supprimer  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
   
}


void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDsupprime = lookup_widget(button,"GDsupprime");
   gtk_widget_destroy(GDsupprime);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *GDajoute,*GDaffiche;
     GDajoute = lookup_widget(button,"GDajoute");
   gtk_widget_destroy(GDajoute);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDajoute,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDajoute = lookup_widget(button,"GDajoute");
           GDajoute = create_GDajoute();
   id = lookup_widget(button,"GDidEntryAjout"); 
 etab= lookup_widget(button,"GDetabComboAjout1");
 jj =  lookup_widget(button,"GDjjSpinAjout");
        mm =  lookup_widget(button,"GDmmSpinAjout");
        yy =   lookup_widget(button,"GDyySpinAjout");
        quantite = lookup_widget(button,"GDquantiteSpinAjout");
        sangType =  lookup_widget(button,"GDtypeSangComboAjout1");
        label = lookup_widget(button,"GDcontroleSaisiAjout");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence1 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status1 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  ajouterDemande(filename2,d);
       if(t == 1){
        
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDajoute);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
              


 
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


           
}


void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status1=2;} 
}


void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton))
 {status1=1;} 
}


void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=2;} 
}


void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=1;} 
}


void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDmodife,*GDaffiche;
     GDmodife = lookup_widget(button,"GDmodife");
   gtk_widget_destroy(GDmodife);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=1;}
}


void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=2;}
}



void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=2;}
}


void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=1;}
}


void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDmodife,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDmodife = lookup_widget(button,"GDmodife");
           GDmodife = create_GDmodife();
   id = lookup_widget(button,"GDidEntryModifier"); 
 etab= lookup_widget(button,"GDetabComboModifier1");
 jj =  lookup_widget(button,"GDjjSpinModifier");
        mm =  lookup_widget(button,"GDmmSpinModifier");
        yy =   lookup_widget(button,"GDyySpinModifier");
        quantite = lookup_widget(button,"GDquantiteSpinModifier");
        sangType =  lookup_widget(button,"GDtypeSangComboModifier1");
        label = lookup_widget(button,"GDcontroleSaisiModifier");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence2 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status2 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  modifierDemande(filename2,d.id,d);
       if(t == 1){
        
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDmodife);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
              


       
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Modification  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


}



void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDstatistique,*GDaffiche;
     GDstatistique = lookup_widget(button,"GDstatistique");
   gtk_widget_destroy(GDstatistique);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget  *etab,*label1,*labelControlle,*GDstatistique;
      GDstatistique = lookup_widget(button,"GDstatistique");
           GDstatistique = create_GDstatistique();
    int b=1;
char etab1[50];
   etab = lookup_widget(button,"GDcomboEtabStatistique"); 
   label1 = lookup_widget(button,"GDpourcentageDemandeLabelStatistique");
    labelControlle = lookup_widget(button,"GDcontroleSaisiStatistique"); 
    strcpy(etab1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        if(strcmp(etab1,"")==0 ){
      
           b=0;
             }
         if (b == 1){
       float pourcentage = afficherPourcentageDemandes(filename2,etab1);
       char var[50];
    sprintf(var,"%.2f",pourcentage);

         gtk_label_set_text(GTK_LABEL(label1),var);


         }else{


           gtk_label_set_text(GTK_LABEL(labelControlle),"verifier vos donnée ❌️");

        }
     
}



void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *label;
   label = lookup_widget(button,"GDtypePlusDemandeLabelStatistique");
    gtk_label_set_text(GTK_LABEL(label),afficherTypeSangPlusDemande(filename2));
}


void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_affichagedutypedusangleplusrare13591222e_plus__clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *gestionmedecin;
gestionmedecin= lookup_widget(objet_graphique, "gestionmedecin");

 char ch3[50] ;
GtkWidget *output2;
output2=lookup_widget(objet_graphique,"type1359"); 

    strcpy(ch3,sang_rare("don.txt"));
    gtk_label_set_text(GTK_LABEL(output2),ch3);}


void
on_affichetypedusang1359_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeviewska2,*affichagepartypequantiteska2;  
         affichagepartypequantiteska2= lookup_widget(objet_graphique, "affichagepartypequantiteska2");
         treeviewska2=lookup_widget(affichagepartypequantiteska2,"treeviewska2");
         char ch[50];
char ch2[50];
         Don p;  
        GtkWidget *input1;
	GtkWidget *output;
      
	
        output=lookup_widget(objet_graphique,"resultat1359"); 
  int x ;
 



         input1=lookup_widget(objet_graphique,"entrytypedusang1359"); 
 
      
         strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
          x=quantite_type("don.txt",ch );
        sprintf(ch2,"%d" ,x);
         gtk_label_set_text(GTK_LABEL(output),ch2);
        // p=chercher("etablissement.txt",ch);
        //if(p.nom_etablissement!="-1"){
          affichepartype("don.txt", ch);
         afficher_type(treeviewska2,"affichetype.txt");  

     // }else{gtk_label_set_text(GTK_LABEL(output1),"ce nom n existe pas");}

}

void
on_ajoutska_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
 int x ; Don p;
GtkWidget *cin,*etablissement_du_don ,*typedusang ,*analysedusang,*jour,*mois,*annee,*homme,*femme,*quantite ; 
cin=lookup_widget(objet_graphique,"entrycinska1");
etablissement_du_don=lookup_widget(objet_graphique,"entryetsska1");
typedusang=lookup_widget(objet_graphique,"entrytypedusangska1");
 //GtkWidget* alert1=lookup_widget(objet_graphique,"alert1");
jour=lookup_widget(objet_graphique,"jourska1");
mois=lookup_widget(objet_graphique,"moisska1");
annee=lookup_widget(objet_graphique,"anneeska1");
quantite=lookup_widget(objet_graphique,"quantiteska1");
homme=lookup_widget(objet_graphique,"hommeska1");
femme=lookup_widget(objet_graphique,"femmeska1");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.etablissement_du_don,gtk_entry_get_text(GTK_ENTRY(etablissement_du_don)));
strcpy(p.typedusang,gtk_entry_get_text(GTK_ENTRY(typedusang)));
strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
analysedusang= lookup_widget(objet_graphique, "comboboxska1");
strcpy(p.analysedusang,gtk_combo_box_get_active_text(GTK_COMBO_BOX (analysedusang)));

strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
	snprintf(p.ddn.jour, sizeof(p.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
	snprintf(p.ddn.mois, sizeof(p.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
	snprintf(p.ddn.annee, sizeof(p.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
	
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
		strcpy(p.sexe,"homme");
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
		strcpy(p.sexe,"femme");
x=ajouters("don.txt",p);  

/*
if(x==1)
	gtk_label_set_text(GTK_LABEL(alert1), "ajout avec succes");
else
gtk_label_set_text(GTK_LABEL(alert1), "erreur d'ajout ");

*/


}

void
on_affichedoneeska_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{   Don found_don ;

	GtkWidget*  cin= lookup_widget(objet_graphique, "entrycinska2");
	GtkWidget* typedusang= lookup_widget(objet_graphique, "entrytypedusang2");
	GtkWidget* etablissement_du_don= lookup_widget(objet_graphique, "entryetsska2");
	GtkWidget* analysedusang= lookup_widget(objet_graphique, "comboboxska2");
	GtkWidget* quantite= lookup_widget(objet_graphique, "quantiteska2");
	GtkWidget* jour= lookup_widget(objet_graphique, "jourska2");
	GtkWidget* mois= lookup_widget(objet_graphique, "moisska2");
	GtkWidget* annee= lookup_widget(objet_graphique, "anneeska2");
	GtkWidget* homme= lookup_widget(objet_graphique, "hommeska2");
	GtkWidget* femme= lookup_widget(objet_graphique, "femmeska2");
	
	///GtkWidget* output=lookup_widget(objet_graphique,"alert2");
	char verif[20];
	strcpy(verif,gtk_entry_get_text(GTK_ENTRY(cin)));
   

     found_don = cherchers("don.txt",verif);
    
       
	int P,j,m,a;
	P= analysesang(found_don.analysedusang);
//gtk_combo_box_set_active(GTK_COMBO_BOX(analysedusang), P);
  gtk_combo_box_set_active(GTK_COMBO_BOX(analysedusang),0);
        gtk_entry_set_text(GTK_ENTRY(quantite), found_don.quantite);
 gtk_entry_set_text(GTK_ENTRY(etablissement_du_don), found_don.etablissement_du_don);
	 gtk_entry_set_text(GTK_ENTRY(typedusang), found_don.typedusang);
      
	j=atoi(found_don.ddn.jour);
	m=atoi(found_don.ddn.mois);
	a=atoi(found_don.ddn.annee);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), j);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),m);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), a);

	if(strcmp(found_don.sexe,"homme")==0){
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme),TRUE);
	}else{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme),TRUE);}

    
	
}


void
on_femmeska2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_hommeska2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_modifska_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*  cin= lookup_widget(objet_graphique, "entrycinska2");
	GtkWidget* typedusang= lookup_widget(objet_graphique, "entrytypedusang2");
	GtkWidget* etablissement_du_don= lookup_widget(objet_graphique, "entryetsska2");
	GtkWidget* analysedusang= lookup_widget(objet_graphique, "comboboxska2");
	GtkWidget* quantite= lookup_widget(objet_graphique, "quantiteska2");
	GtkWidget* jour= lookup_widget(objet_graphique, "jourska2");
	GtkWidget* mois= lookup_widget(objet_graphique, "moisska2");
	GtkWidget* annee= lookup_widget(objet_graphique, "anneeska2");
	GtkWidget* homme= lookup_widget(objet_graphique, "hommeska2");
	GtkWidget* femme= lookup_widget(objet_graphique, "femmeska2");
        GtkWidget* alert2=lookup_widget(objet_graphique,"alert2");
        Don nouv;int v ;
	
	strcpy(nouv.typedusang,gtk_entry_get_text(GTK_ENTRY(typedusang)));
	strcpy(nouv.etablissement_du_don,gtk_entry_get_text(GTK_ENTRY(etablissement_du_don)));
	strcpy(nouv.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(nouv.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
	  

        snprintf(nouv.ddn.jour, sizeof(nouv.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
	snprintf(nouv.ddn.mois, sizeof(nouv.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
	snprintf(nouv.ddn.annee, sizeof(nouv.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));
	
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
		strcpy(nouv.sexe,"homme");
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
		strcpy(nouv.sexe,"femme");


   GtkWidget *entry_widget_modifier = gtk_bin_get_child(GTK_BIN(analysedusang));
    const char *entry_text_modifier = gtk_entry_get_text(GTK_ENTRY(entry_widget_modifier));

if (entry_text_modifier && strlen(entry_text_modifier) < sizeof(nouv.analysedusang)) {
    
    strcpy(nouv.analysedusang, entry_text_modifier);
} else {
    
    nouv.analysedusang[0] = '\0';
}

 
	
	
	v=modifiers("don.txt",nouv.cin,nouv);
   if(v==1)
	gtk_label_set_text(GTK_LABEL(alert2), "modification avec succes");
else
gtk_label_set_text(GTK_LABEL(alert2), "erreur de modification ");
}


void
on_supprimeska_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Don p;
int x;
GtkWidget *input1;
GtkWidget *output1;
output1=lookup_widget(objet_graphique,"alert3");
input1=lookup_widget(objet_graphique,"entrycinska3");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
x=supprimers("don.txt",p.cin);
if(x==1)
gtk_label_set_text(GTK_LABEL(output1),"suppresion avec suc");
else{
gtk_label_set_text(GTK_LABEL(output1),"eureur de suppression");}
}
void
on_affichetousska_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestionmedecin;
	GtkWidget *affichagedetouslesdons;
	GtkWidget *treeviewska1;
 	
	

       
            gestionmedecin= lookup_widget(objet_graphique, "gestionmedecin");
            gtk_widget_hide(gestionmedecin);
            affichagedetouslesdons= create_affichagedetouslesdons();
            gtk_widget_show(affichagedetouslesdons);
            treeviewska1=lookup_widget(affichagedetouslesdons,"treeviewska1"); 
            afficher_tous(treeviewska1);
}


void
on_affichagepartypequantiteska_clicked (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestionmedecin;
	GtkWidget *affichagepartypequantiteska2;
	GtkWidget *treeviewska2;
 	
	

       
            gestionmedecin= lookup_widget(objet_graphique, "gestionmedecin");
            gtk_widget_hide(gestionmedecin);
            affichagepartypequantiteska2= create_affichagepartypequantiteska2();
            gtk_widget_show(affichagepartypequantiteska2);
            treeviewska2=lookup_widget(affichagepartypequantiteska2,"treeviewska2"); 
            afficher_type(treeviewska2,"affichetype.txt");
}

void
on_deconnexionska_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestionmedecin,*acceuille;
	           gestionmedecin=lookup_widget(objet_graphique,"gestionmedecin");

	gtk_widget_destroy(gestionmedecin);
	acceuille=create_acceuille();
	gtk_widget_show(acceuille); 
}



void
on_ouiska_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_nonska_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeviewska1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retoureska1_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  	GtkWidget *gestionmedecin,*affichagedetouslesdons;
	affichagedetouslesdons=lookup_widget(objet_graphique,"affichagedetouslesdons");
	gtk_widget_destroy(affichagedetouslesdons);
	gestionmedecin=create_gestionmedecin();
	gtk_widget_show(gestionmedecin); 
}



void
on_treeviewska2_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retoure2ska_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *gestionmedecin,*affichagepartypequantiteska2;
	           affichagepartypequantiteska2=lookup_widget(objet_graphique,"affichagepartypequantiteska2");

	gtk_widget_destroy(affichagepartypequantiteska2);
	gestionmedecin=create_gestionmedecin();
	gtk_widget_show(gestionmedecin); 
}





void
on_femmeska1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_hommeska1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_femmeyb_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_hommeyb_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_afficher_dooner_yb_clicked       (GtkWidget *objet_graphique, gpointer user_data) 
{


inf e;
int j,m,a,f;
GtkWidget *output1, *output2, *output3, *output4 , *output5, *output6, *output7, *output8, *output9;
output1=lookup_widget(objet_graphique,"entrynouv_nom_yb");//nom
output2=lookup_widget(objet_graphique,"entryprenom_nouv_yb");//prenom
output3=lookup_widget(objet_graphique,"entrynouvadresse");//adressse
output4=lookup_widget(objet_graphique,"entry_nouv_num_de_tel_yb_");//numero de telephone
output5=lookup_widget(objet_graphique,"entrynouv_email_yb_");//email
output6=lookup_widget(objet_graphique,"entrycin_cherche_yb_mdf");//cin
output7=lookup_widget(objet_graphique,"ddn_jour_yb_mdf");//jour
output8=lookup_widget(objet_graphique,"ddn_mois_mdf_yb");//mois
output9=lookup_widget(objet_graphique,"ddn_annee_mdf_yb");//annee
GtkWidget* homme= lookup_widget(objet_graphique,"nouvhommeyb");//homme
GtkWidget* femme= lookup_widget(objet_graphique,"nouvfemmeyb");//femme
GtkWidget* comboboxentrynouvmdfetab_yb=lookup_widget(objet_graphique,"comboboxentrynouvmdfetab_yb");//etablissement du don
char check[20];
strcpy(check,gtk_entry_get_text(GTK_ENTRY(output6)));
e=cherchery("infirmier.txt",check);
f=choix_etablissement( e.etablissement_du_don);
j=atoi(e.ddn.jour);
m=atoi(e.ddn.mois);
a=atoi(e.ddn.annee);
gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentrynouvmdfetab_yb), f);//etablissement du don


gtk_entry_set_text(GTK_ENTRY(output1),e.nom);
gtk_entry_set_text(GTK_ENTRY(output2),e.prenom);
gtk_entry_set_text(GTK_ENTRY(output3),e.adresse);
gtk_entry_set_text(GTK_ENTRY(output4),e.num_de_telephone);
gtk_entry_set_text(GTK_ENTRY(output5),e.email);
gtk_entry_set_text(GTK_ENTRY(output6),e.CIN);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7), j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output8), m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output9), a);

if(strcmp(e.sexe,"homme")==0){
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme),TRUE);
	}else{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme),TRUE);}}

void
on_ybmodifier__clicked                 (GtkWidget *objet_graphique, gpointer user_data)
{
int v1,v2,v3,v4,i;
GtkWidget *input1, *input2, *input3, *input4 , *input5, *input6, *input7, *input8, *input9;
inf nouv;
inf p;
int y;
GtkWidget *output;
input1=lookup_widget(objet_graphique,"entrynouv_nom_yb");//nom ***
input2=lookup_widget(objet_graphique,"entryprenom_nouv_yb");//prenom****
input3=lookup_widget(objet_graphique,"entrycin_cherche_yb_mdf");//cin
input4=lookup_widget(objet_graphique,"entrynouvadresse");//adresse ****
input5=lookup_widget(objet_graphique,"entrynouv_email_yb_");//email
input6=lookup_widget(objet_graphique,"entry_nouv_num_de_tel_yb_");//numero de telephone****
input7=lookup_widget(objet_graphique,"ddn_jour_yb_mdf");
input8=lookup_widget(objet_graphique,"ddn_mois_mdf_yb");
input9=lookup_widget(objet_graphique,"ddn_annee_mdf_yb");
output=lookup_widget(objet_graphique,"erreurmodifyb");
GtkWidget* comboboxentrynouvmdfetab_yb=lookup_widget(objet_graphique,"comboboxentrynouvmdfetab_yb");
GtkWidget* homme= lookup_widget(objet_graphique,"nouvhommeyb");//homme
GtkWidget* femme= lookup_widget(objet_graphique,"nouvfemmeyb");//femme


strcpy(nouv.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nouv.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nouv.CIN,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nouv.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nouv.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(nouv.num_de_telephone,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(nouv.etablissement_du_don,gtk_combo_box_get_active_text(GTK_COMBO_BOX (comboboxentrynouvmdfetab_yb)));


snprintf(nouv.ddn.jour, sizeof(nouv.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7)));
snprintf(nouv.ddn.mois, sizeof(nouv.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8)));
snprintf(nouv.ddn.annee, sizeof(nouv.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9)));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
		strcpy(nouv.sexe,"homme");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
		strcpy(nouv.sexe,"femme");


y=modifiery("infirmier.txt",nouv.CIN,nouv); 
if(y==1){
gtk_label_set_text(GTK_LABEL(output), "modification avec succes");}
}
void
on_supprimeryb_clicked                (GtkWidget *objet_graphique, gpointer user_data)
{
inf p;
int x;
GtkWidget *input1;
GtkWidget *output1;
output1=lookup_widget(objet_graphique,"messagesupprimeryb");
input1=lookup_widget(objet_graphique,"entrycinasupprimeryb");//comboboxentry_etab_a_supprimer_RJ
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
x=supprimery("infirmier.txt", p.CIN);
if(x==1 ){
gtk_label_set_text(GTK_LABEL(output1),"suppresion avec succee");
}
}
void
on_affichage_par_moyenne__clicked      (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *gestion_infirmier;
	GtkWidget *affichage_par_moyenne_du_jour_yb;
	GtkWidget *treeview1;
            gestion_infirmier= lookup_widget(objet_graphique, "gestion_infirmier");
            gtk_widget_hide(gestion_infirmier);
            affichage_par_moyenne_du_jour_yb=    		create_affichage_par_moyenne_du_jour_yb();
            gtk_widget_show(affichage_par_moyenne_du_jour_yb);
            treeview1=lookup_widget(affichage_par_moyenne_du_jour_yb,"treeview1"); 
}



void
on_deconnexionyb_clicked               (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *gestion_infirmier,*acceuille;
	           gestion_infirmier=lookup_widget(objet_graphique,"gestion_infirmier");

	gtk_widget_destroy(gestion_infirmier);
	acceuille=create_acceuille();
	gtk_widget_show(acceuille);

}
void
on_nonyb_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ouiyb_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}




void
on_afficherrdvyb_clicked               (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{



GtkWidget *affichage_par_moyenne_du_jour_yb;
	
	GtkWidget *treeview1;
	affichage_par_moyenne_du_jour_yb = lookup_widget(objet_graphique, "affichage_par_moyenne_du_jour_yb");

         treeview1=lookup_widget(affichage_par_moyenne_du_jour_yb,"treeview1");
        char ch[50];int x,y,z ;
         RDV p;  
         GtkWidget *input1,*input2,*input3,*input4;
         input1=lookup_widget(objet_graphique,"entryetabrdvyb");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
         input2=lookup_widget(objet_graphique,"spinbutton1");
         input3=lookup_widget(objet_graphique,"spinbutton2");
         input4=lookup_widget(objet_graphique,"spinbutton3");
       /* gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), atoi(p.jour));
         gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), atoi(p.mois));
         gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), atoi(p.annee));*/

char ch1[50],ch2[50],ch3[50];
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(input4)));
/*sprintf(ch1,sizeof(ch1),"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2)));
sprintf(ch2,sizeof(ch2),"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)));
sprintf(ch3,sizeof(ch3),"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4)));*/
//y=moyRDV_ETS ("rendez-vous.txt", ch1, ch2 ,ch3);
z=listeRDV("rendez-vous.txt",ch, ch1, ch2 ,ch3);
//int z;
//z=listeRDV("rendez-vous.txt","Kebili", "17", "1","2023");
 afficher_rdv(treeview1,"rdv.txt"); 




         // afficheparetablissement("infirmier.txt", ch);
        // afficher_type(treeview2,"afficheetablissement.txt");




}


void
on_retouryb1_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *affichage_par_moyenne_du_jour_yb, *gestion_infirmier ;

       
            affichage_par_moyenne_du_jour_yb = lookup_widget(objet_graphique, "affichage_par_moyenne_du_jour_yb");
            gtk_widget_hide(affichage_par_moyenne_du_jour_yb);
            gestion_infirmier = create_gestion_infirmier();
            gtk_widget_show(gestion_infirmier);
}

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retoure2yb_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *affichage_fiche_de_donneur_yb, *gestion_infirmier ;

       
            affichage_fiche_de_donneur_yb = lookup_widget(objet_graphique, "affichage_fiche_de_donneur_yb");
            gtk_widget_hide(affichage_fiche_de_donneur_yb);
            gestion_infirmier = create_gestion_infirmier();
            gtk_widget_show(gestion_infirmier);

}

void
on_ybajouter_clicked                   (GtkWidget *objet_graphique, gpointer user_data)
{
inf p ; int x;
int v1,v2,v3,v4,i,v5;
GtkWidget *nom,*prenom ,*CIN ,*email,*etablissement_du_don,*num_de_telephone,*adresse,*jour,*mois,*annee,*homme,*femme,*erreure ;
CIN=lookup_widget(objet_graphique,"entrycinyb");
nom=lookup_widget(objet_graphique,"entrynomyb");
prenom=lookup_widget(objet_graphique,"entryprenomyb");
num_de_telephone=lookup_widget(objet_graphique,"entrynumeroyb");
adresse=lookup_widget(objet_graphique,"entryadresseyb");
email=lookup_widget(objet_graphique,"entryemailyb");
jour=lookup_widget(objet_graphique,"ddnjouryb");
mois=lookup_widget(objet_graphique,"ddnmoisyb");
annee=lookup_widget(objet_graphique,"ddnanneeyb_");
homme=lookup_widget(objet_graphique,"hommeyb");
femme=lookup_widget(objet_graphique,"femmeyb");
erreure=lookup_widget(objet_graphique,"erreureajoutyb");
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(p.num_de_telephone,gtk_entry_get_text(GTK_ENTRY(num_de_telephone)));


etablissement_du_don= lookup_widget(objet_graphique, "comboboxentryetabyb");

strcpy(p.etablissement_du_don,gtk_combo_box_get_active_text(GTK_COMBO_BOX (etablissement_du_don)));


snprintf(p.ddn.jour, sizeof(p.ddn.jour), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour)));
snprintf(p.ddn.mois, sizeof(p.ddn.mois), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
snprintf(p.ddn.annee, sizeof(p.ddn.annee), "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme)))
strcpy(p.sexe,"homme");
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
{
strcpy(p.sexe,"femme");
}
//x=ajouter("infirmier.txt",p);

//controle de saisie nom 
v1=1;
i=0;
if(strlen(p.nom)!=0){
while(i<strlen(p.nom)&&v1==1){
if(p.nom[i]<'a'||'z'<p.nom[i])
{v1=0;}
i++;
}
}else {v1=0;}
if(v1==0){gtk_label_set_text(GTK_LABEL(erreure),"saisie du nom du donneur est inacceptable ");}
//controle de saisie prenom
v2=1;
i=0;
if(strlen(p.prenom)!=0){
while(i<strlen(p.prenom)&&v2==1){
if(p.prenom[i]<'a'||'z'<p.prenom[i])
{v2=0;}
i++;
}
}else {v2=0;}
if(v2==0){gtk_label_set_text(GTK_LABEL(erreure),"saisie du prenom du donneur est inacceptable ");}
//controle saisie numero de telephone
v3=1,i=0;
if(strlen(p.num_de_telephone)==8)
{
while(i<strlen(p.num_de_telephone)&&v3==1){
if(p.num_de_telephone[i]<'0'||'9'<p.num_de_telephone[i])
{v3=0;}
i++;
}
}else{v3=0;}
if(v3==0){gtk_label_set_text(GTK_LABEL(erreure),"saisie du numero de telephone est inaceptable ");}

//controle de saisie adresse
v4=1;
if(strlen(p.adresse)==0){v4=0;}
if(v4==0){gtk_label_set_text(GTK_LABEL(erreure),"il faut remplir l'adresse ");}
//controle de saisie cin 
v5=1,i=0;
if(strlen(p.CIN)==8)
{
while(i<strlen(p.CIN)&&v5==1){
if(p.CIN[i]<'0'||'9'<p.CIN[i])
{v5=0;}
i++;
}
}else{v5=0;}
if(v5==0){gtk_label_set_text(GTK_LABEL(erreure),"saisie du cin est inacceptable ");}
    //enregistrement dans le fichier ou erreur 
       if(v1==1&&v2==1&&v3==1&&v4==1&&v5==1){
x=ajoutery("infirmier.txt",p);

}


//clear 

if (x == 1)
    {
        
        gtk_entry_set_text(GTK_ENTRY(CIN), "");
        gtk_combo_box_set_active(GTK_COMBO_BOX(etablissement_du_don), -1); // Clear the combo box
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), 0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois), 0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), 0);
        gtk_entry_set_text(GTK_ENTRY(nom), "");
        gtk_entry_set_text(GTK_ENTRY(prenom), "");
        gtk_entry_set_text(GTK_ENTRY(adresse), "");
	gtk_entry_set_text(GTK_ENTRY(email), "");
	gtk_entry_set_text(GTK_ENTRY(num_de_telephone), "");
    gtk_label_set_text(GTK_LABEL(erreure),"ajout avec succse");

        
      
    }
else if(x==-2){
gtk_label_set_text(GTK_LABEL(erreure),"ce personne deja existe");
}
}


void
on_affichage_par_fiche_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *gestion_infirmier;
	GtkWidget *affichage_fiche_de_donneur_yb;
	GtkWidget *treeview2;      
            gestion_infirmier= lookup_widget(objet_graphique, "gestion_infirmier");
            gtk_widget_hide(gestion_infirmier);
            affichage_fiche_de_donneur_yb= create_affichage_fiche_de_donneur_yb();
            gtk_widget_show(affichage_fiche_de_donneur_yb);
            treeview2=lookup_widget(affichage_fiche_de_donneur_yb,"treeview2"); 
            afficher_type(treeview2,"afficheetablissement.txt");
}
void on_connexion_infirmier_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget *input1, *input2,*fenetre_login;
    char ch[20];
    fenetre_login=lookup_widget(objet_graphique,"fixedinfirmier");
    input1=lookup_widget(objet_graphique, "entry_login_infirmier");
   input2 =lookup_widget(objet_graphique, "entry_mot_de_passe_infirmier");
    utl e;
    strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
    e=chercher("utl.txt",ch);     
    //poste*/
 if (strcmp(e.carte_d_identite,"-1")!=0&&strcmp(e.poste,"infirmier")==0) {
       GtkWidget *gestion_infirmier, *acceuille;
            acceuille = lookup_widget(objet_graphique, "acceuille");
            gtk_widget_hide(acceuille);
            gtk_widget_destroy(acceuille);
          gestion_infirmier= create_gestion_infirmier();
        gtk_widget_show (gestion_infirmier);
}}
void on_afficherdonneuryb_clicked (GtkWidget *objet_graphique, gpointer user_data){}
void on_affichagedutypedusangleplusrare13591222e_plus_clicked (GtkWidget *objet_graphique, gpointer user_data) {}
 void on_retour2ska_clicked (GtkWidget *objet_graphique, gpointer user_data) {}

/////////////////////////////////////////////////////////////////////////////////////////////
void
on_h1a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_h2a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_h3a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_h4a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void on_boutton_ajouter_clicked(GtkWidget *objet_graphique,
                                gpointer user_data)
{
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9; // declaration
    GtkWidget *output;                                                                         // declaration
    RDV e;
    int x; // declaration
    input1 = lookup_widget(objet_graphique, "etba");
    input2 = lookup_widget(objet_graphique, "joura");
    input3 = lookup_widget(objet_graphique, "moisa");
    input4 = lookup_widget(objet_graphique, "anneea");
    input5 = lookup_widget(objet_graphique, "h1a");
    input6 = lookup_widget(objet_graphique, "h2a");
    input7 = lookup_widget(objet_graphique, "h3a");
    input8 = lookup_widget(objet_graphique, "h4a");
    input9 = lookup_widget(objet_graphique, "ida");
    output = lookup_widget(objet_graphique, "erreur");

    strcpy(e.Ets, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
    snprintf(e.jour, sizeof(e.jour), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2)));
    snprintf(e.mois, sizeof(e.mois), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)));
    snprintf(e.annee, sizeof(e.annee), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4)));
    snprintf(e.id, sizeof(e.id), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9)));

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input5))) // buton radio
        strcpy(e.h, "8:00");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6))) // buton radio
        strcpy(e.h, "9:00");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input7))) // buton radio
        strcpy(e.h, "10:00");
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input8))) // buton radio
        strcpy(e.h, "11:00");
    // erreur

    // Call the ajouterRDV function with the entered data
    x = ajouterRDV("rendez-vous.txt", e);

    // Display appropriate feedback to the user based on the response x
    if (x == 1)
    {
        // Successfully added - Update the UI accordingly
        gtk_label_set_text(GTK_LABEL(output), "RDV added successfully.");
    }
    else if (x == -1)
    {
        // Duplicate ID - Update the UI accordingly
        gtk_label_set_text(GTK_LABEL(output), "Error: meme id.");
    }
    else if (x == -2)
    {
        // Maximum number of RDVs reached for that date - Update the UI accordingly
        gtk_label_set_text(GTK_LABEL(output), "Error: Maximum RDV for this day exceeded.");
    }
    else
    {
        // Error in opening file - Update the UI accordingly
        gtk_label_set_text(GTK_LABEL(output), "Error in opening the file.");
    }
}



void on_h4m_toggled(GtkToggleButton *togglebutton,
                    gpointer user_data)
{
}

void on_h3mn_toggled(GtkToggleButton *togglebutton,
                     gpointer user_data)
{
}

void on_chercherm_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *id_spinbutton = lookup_widget(objet_graphique, "idm");
    int id = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id_spinbutton));
    int f;
    char id_str[10];
    snprintf(id_str, sizeof(id_str), "%d", id);

    RDV e = chercheraff("rendez-vous.txt", id_str);
    GtkWidget *erreurm_label = lookup_widget(objet_graphique, "erreurm");
    f = region("region.txt", e.Ets);

    if (strcmp(e.id, "-1") != 0)
    {
        GtkWidget *etbmn_combobox = lookup_widget(objet_graphique, "etbmn");
        GtkWidget *jourmn_spinbutton = lookup_widget(objet_graphique, "jourmn");
        GtkWidget *moismn_spinbutton = lookup_widget(objet_graphique, "moismn");
        GtkWidget *anneemn_spinbutton = lookup_widget(objet_graphique, "anneemn");

        gtk_combo_box_set_active(GTK_COMBO_BOX(etbmn_combobox), f);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jourmn_spinbutton), atoi(e.jour));
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(moismn_spinbutton), atoi(e.mois));
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(anneemn_spinbutton), atoi(e.annee));

        if (strcmp(e.h, "08:00") == 0)
        {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h1mn")), TRUE);
        }
        else if (strcmp(e.h, "09:00") == 0)
        {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h2mn")), TRUE);
        }
        else if (strcmp(e.h, "10:00") == 0)
        {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h3mn")), TRUE);
        }
        else if (strcmp(e.h, "11:00") == 0)
        {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h4mn")), TRUE);
        }

        gtk_label_set_text(GTK_LABEL(erreurm_label), "");
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(erreurm_label), "Error: The rendez-vous does not exist.");
    }
}


void
on_h2mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_h1mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}




void
on_h4mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}





void on_boutton_modifier_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
       GtkWidget *id_spinbutton = lookup_widget(objet_graphique, "idm");
    RDV e;
    int id = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id_spinbutton));

    // Fetch and assign values from the widgets to the RDV struct `e`
    GtkWidget *input1 = lookup_widget(objet_graphique,"etbmn");
    GtkWidget *input2 = lookup_widget(objet_graphique,"jourmn");
    GtkWidget *input3 = lookup_widget(objet_graphique,"moismn");
    GtkWidget *input4 = lookup_widget(objet_graphique,"anneemn");
    GtkWidget *output = lookup_widget(objet_graphique,"erreurmn");

    snprintf(e.id, sizeof(e.id), "%d", id);
    strcpy(e.Ets, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
    snprintf(e.jour, sizeof(e.jour), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2)));
    snprintf(e.mois, sizeof(e.mois), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)));
    snprintf(e.annee, sizeof(e.annee), "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4)));

    // Assuming you have buttons or other widgets for each hour entry named "h1mn", "h2mn", etc.
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h1mn")))) strcpy(e.h, "8:00");
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h2mn")))) strcpy(e.h, "9:00");
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h3mn")))) strcpy(e.h, "10:00");
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(lookup_widget(objet_graphique, "h4mn")))) strcpy(e.h, "11:00");

    // Call modifierRDV and check the result
    int result = modifierRDV("rendez-vous.txt", e);
    if (result == 1) {
        gtk_label_set_text(GTK_LABEL(output), "Modification réussie");
    } else {
        gtk_label_set_text(GTK_LABEL(output), "Échec de la modification");
    }
}


void on_button_supprimer_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    RDV p;
    int x;
    GtkWidget *input1;
    GtkWidget *output1;
    output1 = lookup_widget(objet_graphique, "erreursu");
    input1 = lookup_widget(objet_graphique, "idsup"); // comboboxentry_etab_a_supprimer_RJ
    strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input1)));
    x = supprimerRDV("rendez-vous.txt", p.id);
    if (x == 1)
    {
        gtk_label_set_text(GTK_LABEL(output1), "suppresion avec succse");
        gtk_entry_set_text(GTK_ENTRY(input1), " ");
    }
    else
        gtk_label_set_text(GTK_LABEL(output1), "echec de suppression");
}


void on_affichageh_clicked(GtkWidget *objet_graphique, gpointer user_data)
{

    GtkWidget *gestion_donneur;
    GtkWidget *afficher_par_historique;
    GtkWidget *treehistorique;

    gestion_donneur = lookup_widget(objet_graphique, "gestion_donneur");
    gtk_widget_hide(gestion_donneur);
    afficher_par_historique = create_afficher_par_historique();
    gtk_widget_show(afficher_par_historique);
    treehistorique = lookup_widget(afficher_par_historique, "treehistorique");
    afficher_his(treehistorique);
}


void
on_affichagec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void on_deconnexion_clicked(GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget *gestion_donneur,*accueille;
          gestion_donneur=lookup_widget(objet_graphique,"gestion_donneur");

gtk_widget_destroy(gestion_donneur);
accueille=create_acceuille();
gtk_widget_show(accueille); 
}


void
on_treeview_creneaux_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void on_confirmer_clicked(GtkButton *button,
                          gpointer user_data)
{
char jr[10];
char mi[10];

char an[10];

char ch[10];
GtkWidget *afficher_les_creneaux,*treeview_creneaux;
GtkWidget *fenetre_1;
GtkWidget *fenetre_2;
afficher_les_creneaux = lookup_widget(GTK_WIDGET(button), "afficher_les_creneaux");
        
 GtkWidget *role= lookup_widget(GTK_WIDGET(button), "combi");
 GtkWidget *jourr= lookup_widget(GTK_WIDGET(button), "entry1_jour");
   GtkWidget *moiss= lookup_widget(GTK_WIDGET(button), "entry2_mois");
   GtkWidget *anneee= lookup_widget(GTK_WIDGET(button), "entry3_annee");

   GtkWidget *entry_widget_role = gtk_bin_get_child(GTK_BIN(role));
   const char *entry_text_role = gtk_entry_get_text(GTK_ENTRY(entry_widget_role));
   const char*entry_text_jourr= gtk_entry_get_text(GTK_ENTRY(jourr));
   const char*entry_text_moiss= gtk_entry_get_text(GTK_ENTRY(moiss));
   const char*entry_text_anneee= gtk_entry_get_text(GTK_ENTRY(anneee));
if ((entry_text_role !=NULL)&& (entry_text_jourr!=NULL) && (entry_text_moiss!=NULL) && (entry_text_anneee!=NULL))
 {
   
    strncpy(ch,entry_text_role,sizeof(ch)-1);
    ch[sizeof(ch)-1]='\0';
      strncpy(jr,entry_text_jourr,sizeof(jr)-1);
    jr[sizeof(jr)-1]='\0';
  strncpy(mi,entry_text_moiss,sizeof(mi)-1);
    mi[sizeof(mi)-1]='\0';
      strncpy(an,entry_text_anneee,sizeof(an)-1);
    an[sizeof(an)-1]='\0';}
      
  fenetre_1 =lookup_widget(GTK_WIDGET(button), "afficher_les_creneaux");
  gtk_widget_hide (fenetre_1);	
   
  fenetre_2=create_afficher_les_creneaux ();
  gtk_widget_show (fenetre_2);
  treeview_creneaux=lookup_widget(fenetre_2,"treeview_creneaux");
  vider_treeview_firas(treeview_creneaux);
 afficher_cr(ch,jr,mi,an,treeview_creneaux); 
       

}


void
on_treehistorique_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

