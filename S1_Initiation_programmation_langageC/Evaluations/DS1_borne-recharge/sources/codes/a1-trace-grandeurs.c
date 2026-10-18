float puissance_kw = 7.0;
int   duree_min    = 150;
float tarif_kwh    = 0.22;
float duree_h;
float energie_kwh;
int   energie_kwh_ent;
float cout_euros;

/* L1 */ duree_h         = duree_min / 60.0;
/* L2 */ energie_kwh     = puissance_kw * duree_h;
/* L3 */ energie_kwh_ent = energie_kwh;
/* L4 */ energie_kwh     = puissance_kw * duree_h;
/* L5 */ cout_euros      = energie_kwh * tarif_kwh + 0.50;
