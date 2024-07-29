#include <gtk/gtk.h>


void on_connexion_admin_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_connexion_donneur_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_connexion_infirmier_clicked         (GtkWidget *objet_graphique, gpointer user_data);


void
on_connexion_medecin_bio_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_connexion_responsable_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_acceder_a_utilisateur_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_acceder_au_etablissement_clicked    (GtkWidget *objet_graphique, gpointer user_data);

void
on_RJajouter__clicked               (GtkWidget *objet_graphique, gpointer user_data);
void
on_RJmodifier_clicked                 (GtkWidget *objet_graphique, gpointer user_data);

void
on_affiche_donner_pour_modifier_RJ_clicked (GtkWidget *objet_graphique, gpointer user_data);

void
on_supprimer_etab_RJ_clicked         (GtkWidget *objet_graphique, gpointer user_data);

void
on_affichage_region_RJ_clicked       (GtkWidget *objet_graphique, gpointer user_data);

void
on_affichager_capacite_Rj_clicked     (GtkWidget *objet_graphique, gpointer user_data);

void
on_deconnexion_RJ__clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_retour_a_ge_RJ_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_buttonaffreg_clicked                (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retouraespace_etab_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobuttontri1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttontri2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_capaciterj_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton_homme_ABBr_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ABBR_ajouter_clicked                (GtkWidget *objet_graphique, gpointer user_data);

void
on_affichage_donner_a_modifier_ABBr_clicked
                                        (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton_nouv_hommme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_nouv_femme_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ABBR_modifier_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_supprimer_ABBr_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_par_sexe_abbr_clicked     (GtkWidget *objet_graphique, gpointer user_data);

void
on_affichage_par_role_abbr_clicked     (GtkWidget *objet_graphique, gpointer user_data);

void
on_deconnection_abbr_clicked           (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeview_affiche_par_sexe_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retoure_abbr_clicked                (GtkWidget *objet_graphique, gpointer user_data);

void
on_checkbuttonhommeala_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2femmeala_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_affichersexeyalbbr_clicked         (GtkWidget *button, gpointer user_data);

void
on_buttonafficherstatistiqueala_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_affich_parposte_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_abbr_2_clicked               (GtkWidget *objet_graphique, gpointer user_data);

void
on_afiicheryalbbr_clicked              (GtkWidget *button, gpointer user_data);

void
on_ybajouter_clicked                   (GtkWidget *objet_graphique, gpointer user_data);

void
on_afficher_dooner_yb_clicked          (GtkWidget *objet_graphique, gpointer user_data);

void
on_yb_modifier__clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on__button__yb_supprimer_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_par_moyenne__clicked      (GtkWidget *objet_graphique, gpointer user_data);

void
on_deconnexion_yb_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_par_fiche_clicked        (GtkWidget *objet_graphique, gpointer user_data);

void
on_retour_yb_1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retoure_2_yb_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_sk_ajouter__clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mdf_ya_sk_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_donner_skon__clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_par_type_du_sang_skon_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_par_quantite_skon_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnexion_skon_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retoure1_skon_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retoure_2_skon_clicked              (GtkButton       *button,
                                        gpointer         user_data);









///////////////////////////////////////non/////////////////////////////////////////////
void
on_afficher_les_donner_rmm_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_rm_mmm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_rm__clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_dxn_rm__clicked                     (GtkButton       *button,
                                        gpointer         user_data);
/////////////////////////////RASLEN///////////////////////////////////

void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affichagedutypedusangleplusrare13591222e_plus_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichetypedusang1359_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajoutska_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichedoneeska_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_femmeska2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hommeska2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifska_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimeska_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichetousska_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichagepartypequantiteska_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichagedutypedusangleplusrare13591222e_plus_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_deconnexionska_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ouiska_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nonska_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewska1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retoureska1_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeviewska2_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour2ska_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichetypedusang1359_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_connexionska_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_femmeska1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hommeska1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femmeyb_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hommeyb_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficher_dooner_yb_clicked          (GtkWidget *objet_graphique, gpointer user_data);



void
on_ybmodifier__clicked                 (GtkWidget *objet_graphique, gpointer user_data);


void
on_supprimeryb_clicked               (GtkWidget *objet_graphique, gpointer user_data);


void
on_affichage_par_moyenne__clicked     (GtkWidget *objet_graphique, gpointer user_data);


void
on_deconnexionyb_clicked               (GtkWidget *objet_graphique, gpointer user_data);
void
on_nonyb_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ouiyb_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficherrdvyb_clicked               (GtkWidget *objet_graphique, gpointer user_data);



void
on_retouryb1_clicked                   (GtkWidget *objet_graphique, gpointer user_data);




void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_afficherdonneuryb_clicked          (GtkWidget *objet_graphique, gpointer user_data);




void
on_retoure2yb_clicked                  (GtkWidget *objet_graphique, gpointer user_data);



void
on_ybajouter_clicked                   (GtkWidget *objet_graphique, gpointer user_data);



void
on_affichage_par_fiche_clicked         (GtkWidget *objet_graphique, gpointer user_data);


void
on_h1a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h2a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h3a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h4a_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_boutton_ajouter_clicked             (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_h2mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h1mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h3mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_h4mn_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_chercherm_clicked                   (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_boutton_modifier_clicked            (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_button_supprimer_clicked            (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_affichageh_clicked                  (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_affichagec_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnexion_clicked                 (GtkWidget *objet_graphique,
                                gpointer user_data);

void
on_treeview_creneaux_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_confirmer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treehistorique_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_connexionska_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
