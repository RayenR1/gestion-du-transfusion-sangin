/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *acceuille;
  GtkWidget *menu_espace_admin;
  GtkWidget *gestion_d_etablissement_;
  GtkWidget *vous_ete_sure_modification_etablissement_;
  GtkWidget *affichage_etablissement_par_region;
  GtkWidget *affichage_par_capacite_;
  GtkWidget *gestion_d_utilisateur;
  GtkWidget *vous_ete_sure_modif_abbr;
  GtkWidget *affichage_par_sexe_abbr;
  GtkWidget *affichage_par_role_abbr;
  GtkWidget *gestion_infirmier;
  GtkWidget *vous_etes_sure_yb;
  GtkWidget *affichage_par_moyenne_du_jour_yb;
  GtkWidget *affichage_par_etab_yb;
  GtkWidget *gestion_medcin_;
  GtkWidget *vous_etes_suer_sk;
  GtkWidget *affichage_par_quantite_;
  GtkWidget *affichage_par_type_du_sang_le_plus_rare_skon;
  GtkWidget *gestion_donneur;
  GtkWidget *vous_etes_sur_fr_;
  GtkWidget *affich_par_etab_fr_;
  GtkWidget *affich_par_sexe_fr;
  GtkWidget *gestion_de_responsable_rm_;
  GtkWidget *vous_etes_sur_rm_;
  GtkWidget *affichage_type_1_rm_;
  GtkWidget *affichage_type_2_rm_;
  GtkWidget *GDaffiche;
  GtkWidget *gestionmedecin;
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  acceuille = create_acceuille ();
  gtk_widget_show (acceuille);
  /* GDaffiche=create_GDaffiche();
   gtk_widget_show (GDaffiche);
   gestionmedecin= create_gestionmedecin();
  gtk_widget_show (gestionmedecin);
 /* menu_espace_admin = create_menu_espace_admin ();
  gtk_widget_show (menu_espace_admin);
  gestion_d_etablissement_ = create_gestion_d_etablissement_ ();
  gtk_widget_show (gestion_d_etablissement_);
  vous_ete_sure_modification_etablissement_ = create_vous_ete_sure_modification_etablissement_ ();
  gtk_widget_show (vous_ete_sure_modification_etablissement_);
  affichage_etablissement_par_region = create_affichage_etablissement_par_region ();
  gtk_widget_show (affichage_etablissement_par_region);
  affichage_par_capacite_ = create_affichage_par_capacite_ ();
  gtk_widget_show (affichage_par_capacite_);
  gestion_d_utilisateur = create_gestion_d_utilisateur ();
  gtk_widget_show (gestion_d_utilisateur);
  vous_ete_sure_modif_abbr = create_vous_ete_sure_modif_abbr ();
  gtk_widget_show (vous_ete_sure_modif_abbr);
  affichage_par_sexe_abbr = create_affichage_par_sexe_abbr ();
  gtk_widget_show (affichage_par_sexe_abbr);
  affichage_par_role_abbr = create_affichage_par_role_abbr ();
  gtk_widget_show (affichage_par_role_abbr);*/
 /* gestion_infirmier = create_gestion_infirmier ();
  gtk_widget_show (gestion_infirmier);/*
  vous_etes_sure_yb = create_vous_etes_sure_yb ();
  gtk_widget_show (vous_etes_sure_yb);
  affichage_par_moyenne_du_jour_yb = create_affichage_par_moyenne_du_jour_yb ();
  gtk_widget_show (affichage_par_moyenne_du_jour_yb);
  affichage_par_etab_yb = create_affichage_par_etab_yb ();
  gtk_widget_show (affichage_par_etab_yb);
  gestion_medcin_ = create_gestion_medcin_ ();
  gtk_widget_show (gestion_medcin_);
  vous_etes_suer_sk = create_vous_etes_suer_sk ();
  gtk_widget_show (vous_etes_suer_sk);
  affichage_par_quantite_ = create_affichage_par_quantite_ ();
  gtk_widget_show (affichage_par_quantite_);
  affichage_par_type_du_sang_le_plus_rare_skon = create_affichage_par_type_du_sang_le_plus_rare_skon ();
  gtk_widget_show (affichage_par_type_du_sang_le_plus_rare_skon);
  gestion_donneur = create_gestion_donneur ();
  gtk_widget_show (gestion_donneur);
 vous_etes_sur_fr_ = create_vous_etes_sur_fr_ ();
  gtk_widget_show (vous_etes_sur_fr_);
  affich_par_etab_fr_ = create_affich_par_etab_fr_ ();
  gtk_widget_show (affich_par_etab_fr_);
  affich_par_sexe_fr = create_affich_par_sexe_fr ();
  gtk_widget_show (affich_par_sexe_fr);

  gestion_de_responsable_rm_ = create_gestion_de_responsable_rm_ ();
  gtk_widget_show (gestion_de_responsable_rm_);
  vous_etes_sur_rm_ = create_vous_etes_sur_rm_ ();
  gtk_widget_show (vous_etes_sur_rm_);
  affichage_type_1_rm_ = create_affichage_type_1_rm_ ();
  gtk_widget_show (affichage_type_1_rm_);
  affichage_type_2_rm_ = create_affichage_type_2_rm_ ();
  gtk_widget_show (affichage_type_2_rm_);
*/
  gtk_main ();
  return 0;
}

