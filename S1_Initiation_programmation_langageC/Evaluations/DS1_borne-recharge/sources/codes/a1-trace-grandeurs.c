int   puissance_kw = 22;
int   duree_min    = 150;
float tarif_kwh    = 0.22;
int   duree_h_ent;
float energie_kwh;
float cout_euros;

/* L1 */ duree_h_ent = duree_min / 60;
/* L2 */ energie_kwh = puissance_kw * duree_h_ent;
/* L3 */ cout_euros  = energie_kwh * tarif_kwh;
/* L4 */ energie_kwh = puissance_kw * (duree_min / 60.0);
/* L5 */ cout_euros  = energie_kwh * tarif_kwh + 0.50;
